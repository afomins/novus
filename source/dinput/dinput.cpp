  


#include	"main\main.h"
#include	"dinput\dinput.h"

LPDIRECTINPUT8				di; 
LPDIRECTINPUTDEVICE8		di_keyboard; 
LPDIRECTINPUTDEVICE8		di_mouse;

void WINAPI dinput_delete() 
{ 
	if(di) 
	{ 
		if(di_keyboard) 
		{ 
			di_keyboard->Unacquire(); 
			di_keyboard->Release();
			di_keyboard	= NULL; 
		}
		if(di_mouse)
		{
			di_mouse->Unacquire(); 
			di_mouse->Release();
			di_mouse = NULL; 
		}

		di->Release();
		di = NULL; 
	} 
} 

bool WINAPI dinput_create() 
{ 
	HRESULT hr;
 
	hr = DirectInput8Create(hInstance, 
							DIRECTINPUT_VERSION, 
							IID_IDirectInput8, 
							(void**)&di, NULL); 
 
	if(FAILED(hr)) return false; 
 
	hr = di->CreateDevice(GUID_SysKeyboard, &di_keyboard, NULL); 
	hr = di->CreateDevice(GUID_SysMouse, &di_mouse, NULL);
 
	if(FAILED(hr))
	{ 
		dinput_delete(); 

		return false; 
	}
	
	hr = di_keyboard->SetDataFormat(&c_dfDIKeyboard); 
	hr = di_mouse->SetDataFormat(&c_dfDIMouse);

	if(FAILED(hr))
	{ 
		dinput_delete(); 

		return false; 
	} 

	hr = di_keyboard->SetCooperativeLevel(hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE); 
	hr = di_mouse->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);

	if(FAILED(hr)) 
	{
		return false;
	}
 
	hr = di_keyboard->Acquire(); 
	hr = di_mouse->Acquire(); 


	if(FAILED(hr))
	{ 
		dinput_delete(); 

		return false; 
	} 

	return true; 
}

void dinput_access(bool active)
{
	if(di_keyboard)
	{
		if(active)
		{
			di_keyboard->Acquire();
		}
		else
		{
			di_keyboard->Unacquire();
		}
	}

	if(di_mouse)
	{
		if(active)
		{
			di_mouse->Acquire();
		}
		else
		{
			di_mouse->Unacquire();
		}
	}
}

void dinput_keyboard_process()
{
	HRESULT		hRet;
	BYTE		bKeyBuffer[256];
	int			loop;
	
	hRet = di_keyboard -> GetDeviceState(sizeof(bKeyBuffer), bKeyBuffer);

	if(hRet == DIERR_INPUTLOST)
	{
		di_keyboard->Acquire();
		hRet = di_keyboard->GetDeviceState(sizeof(bKeyBuffer), bKeyBuffer);
	}

	if(hRet != DI_OK) return;

	for(loop = 0; loop < KEY_BUTTON_NUM; loop++)
	{
		keyboard.pressed[loop] = FALSE;

		if(keyboard.statuss[loop] == b_RELEASE)	keyboard.statuss[loop] = b_NULL;

		if(KEYDOWN(bKeyBuffer, keyboard.key[loop]))					//	 нопка зажата
		{
			keyboard.pressed[loop]		= TRUE;
			keyboard.statuss[loop]		= b_HOLD;
		}

		if((keyboard.pressed[loop]) & (!keyboard.prev_press[loop]))	//	 нопка	первый раз нажата
		{
			keyboard.prev_press[loop]	= TRUE;
			keyboard.statuss[loop]		= b_PRESS;
		}

		if(!(keyboard.pressed[loop]) & (keyboard.prev_press[loop]))	//	 нопка отпущена
		{
			keyboard.prev_press[loop]	= FALSE;
			keyboard.statuss[loop]		= b_RELEASE;
		}
	}
}

void dinput_mouse_process()
{
	HRESULT			hRet;
	DIMOUSESTATE	ms;
	int				loop;

	hRet = di_mouse->GetDeviceState(sizeof(DIMOUSESTATE), &ms);

	if(hRet == DIERR_INPUTLOST)
	{
		di_mouse->Acquire();
		hRet = di_mouse->GetDeviceState(sizeof(DIMOUSESTATE), &ms);
	}

	if(hRet != DI_OK)	return;

	for(loop = 0; loop < MOUSE_BUTTON_NUM; loop++)
	{
		mouse.press[loop] = FALSE;

		if(mouse.statuss[loop] == b_RELEASE)	mouse.statuss[loop] = b_NULL;

		if(ms.rgbButtons[loop] && 0x80)							//	 нопка зажата
		{
			mouse.press[loop]		= TRUE;
			mouse.statuss[loop]		= b_HOLD;
		}

		if((mouse.press[loop]) & (!mouse.prev_press[loop]))		//	 нопка	первый раз нажата
		{
			mouse.prev_press[loop]	= TRUE;
			mouse.statuss[loop]		= b_PRESS;
		}

		if(!(mouse.press[loop]) & (mouse.prev_press[loop]))		//	 нопка отпущена
		{
			mouse.prev_press[loop]	= FALSE;
			mouse.statuss[loop]		= b_RELEASE;
		}
	}
		
	mouse.move_x	=	0.0;
	mouse.move_y	=	0.0;
	mouse.move_z	=	0.0;

	if(ms.lX != 0)
	{
		mouse.move_x += ms.lX;
	}
	
	if(ms.lY != 0)
	{
		mouse.move_y += ms.lY;	
	}

	if(ms.lZ != 0)
	{
		mouse.move_z = ms.lZ / 120.0;
	}
	
	dinput_mouse_button_process();
}
