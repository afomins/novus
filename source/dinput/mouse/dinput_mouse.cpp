  


#include "dinput\dinput.h"
#include "main\main.h"
#include "texture\texture.h"


void dinput_mouse_button_process()
{
	dinput_mouse_coord_set();
}

void dinput_mouse_coord_set()
{
	mouse.x	+=	mouse.move_x * mouse.sensitivity;
	mouse.y	-=	mouse.move_y * mouse.sensitivity;

	if(mouse.x > window.width)	mouse.x = window.width - 1;
	if(mouse.y > window.height)	mouse.y = window.height;

	if(mouse.x < 0)	mouse.x	= 0;
	if(mouse.y < 0)	mouse.y	= 1;

	SetCursorPos(GetSystemMetrics(SM_CXSCREEN) / 2, 
				GetSystemMetrics(SM_CYSCREEN) / 2);
}

