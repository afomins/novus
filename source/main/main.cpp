


#include	"main\main.h"
#include	"dinput\dinput.h"
#include	"draw\draw2d.h"
#include	"texture\texture.h"
#include	"write\write.h"
#include	"timer\timer.h"
//#include	"camera\camera.h"
//#include	"model\model.h"
//#include	"interface\interface.h"
#include	"game\game.h"


void main3d()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();


	glViewport(	viewport.x, 
				viewport.y, 
				viewport.width, 
				viewport.height);


	gluPerspective(	viewport.camFov,
					-viewport.camAspect,
					viewport.camNear,
					viewport.camFar);

	gluLookAt(	viewport.camPosition.x, 
				viewport.camPosition.y, 
				viewport.camPosition.z, 

				viewport.camCenter.x, 
				viewport.camCenter.y, 
				viewport.camCenter.z, 

				viewport.camVertical.x, 
				viewport.camVertical.y, 
				viewport.camVertical.z);


	glMatrixMode(GL_MODELVIEW);
	glPolygonMode(GL_FRONT, GL_FILL);

	//	***	[		]

	game_model_draw_all();
}

void main2d()
{
	glPushAttrib(GL_DEPTH_BUFFER_BIT | GL_TEXTURE_BIT);
 	glMatrixMode(GL_PROJECTION);
	glViewport(0, 0, window.width, window.height);
	glLoadIdentity();
	gluOrtho2D(0.0, window.width, 0.0, window.height);
	glPolygonMode(GL_FRONT, GL_FILL);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);

	unsigned short	loop;

		//	***
	
	interface_draw();

	if(!g_game.game_menu_on)
	{
		if(g_game.player[0].player_on)
		{
			if(g_game.player_active == 0)	glColor3f(1.0, 1.0, 0.0);
			else							glColor3f(1.0, 1.0, 1.0);

			write(20, window.height - 40, g_game.player[0].name, 1, 1, 0);
			write(20 + 90, window.height - 40, g_game.player[0].score, 0, 1, 1, 0);
		}

		if(g_game.player[1].player_on)
		{
			if(g_game.player_active == 1)	glColor3f(1.0, 1.0, 0.0);
			else							glColor3f(1.0, 1.0, 1.0);

			write(20, window.height - 60, g_game.player[1].name, 1, 1, 0);
			write(20 + 90, window.height - 60, g_game.player[1].score, 0, 1, 1, 0);
		}

		if(g_game.player[2].player_on)
		{
			if(g_game.player_active == 2)	glColor3f(1.0, 1.0, 0.0);
			else							glColor3f(1.0, 1.0, 1.0);

			write(window.width - 128, window.height - 40, g_game.player[2].name, 1, 1, 0);
			write(window.width - 38, window.height - 40, g_game.player[2].score, 0, 1, 1, 0);
		}

		if(g_game.player[3].player_on)
		{
			if(g_game.player_active == 3)	glColor3f(1.0, 1.0, 0.0);
			else							glColor3f(1.0, 1.0, 1.0);

			write(window.width - 128, window.height - 60, g_game.player[3].name, 1, 1, 0);
			write(window.width - 38, window.height - 60, g_game.player[3].score, 0, 1, 1, 0);
		}
	}
	else
	{
		glColor3f(1.0, 1.0, 1.0);
		write(0, window.height - 17, timerCurrentSec, 0, "  seconds running", 1, 1, 0);
		write(window.width - 80, 0, "from_manny", 1, 1, 0);

		if(g_game.interface_properties.b_main_menu_stat->button_active)
		{
			glColor3f(1.0, 1.0, 1.0);

			for(loop = 0 ;loop < 4; loop++)
			{
				write(340, 230 - loop * 15, g_game.player[loop].name, 1, 1, 0);

				write(460, 230 - loop * 15, g_game.stat.player_win[loop], 0, 1, 1, 0);
				write(540, 230 - loop * 15, g_game.stat.player_loose[loop], 0, 1, 1, 0);
			}
		}

		if(g_game.interface_properties.w_game_result->window_on)
		{
			glColor3f(1.0, 1.0, 1.0);

			if(g_game.player[0].player_on)
			{
				write(340, 240, g_game.player[0].name, 1, 1, 0);
				write(340 + 90, 240, g_game.player[0].score, 0, 1, 1, 0);
			}

			if(g_game.player[1].player_on)
			{
				write(340, 240 - 20, g_game.player[1].name, 1, 1, 0);
				write(340 + 90, 240 - 20, g_game.player[1].score, 0, 1, 1, 0);
			}

			if(g_game.player[2].player_on)
			{
				write(340 + 138, 240, g_game.player[2].name, 1, 1, 0);
				write(340 + 90 + 138, 240, g_game.player[2].score, 0, 1, 1, 0);
			}

			if(g_game.player[3].player_on)
			{
				write(340 + 138, 240 - 20, g_game.player[3].name, 1, 1, 0);
				write(340 + 90 + 138, 240 - 20, g_game.player[3].score, 0, 1, 1, 0);
			}
		}
	}

	glColor3f(1.0, 1.0, 1.0);
	write(0, 0, timerFps, 0, " fps", 1, 1, 0);
	
	glMatrixMode(GL_MODELVIEW);
	glPopAttrib();
}

void main()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	game_process();

	main3d();	
	main2d();

	timerProcess();
}

void mainKillOGL()
{
	if(	window.fullscreen)
	{
		ChangeDisplaySettings(NULL, 0);
		ShowCursor(TRUE);
	}

	if(	hRC)
	{
		if(	!wglMakeCurrent(NULL, NULL))
		{
			MessageBox(NULL, "inKillGL -> wglMakeCurrent", "fuck...", MB_OK | MB_ICONINFORMATION);
		}

		if(	!wglDeleteContext(hRC))
		{
			MessageBox(NULL, "inKillGL -> wglDeleteContext", "fuck...", MB_OK | MB_ICONINFORMATION);
		}

		hRC = NULL;
	}

	if(	hDC && !ReleaseDC(hWnd, hDC))
	{
		MessageBox(NULL, "inKillGL -> ReleaseDC", "fuck...", MB_OK | MB_ICONINFORMATION);

		hDC = NULL;
	}

	if(	hWnd && !DestroyWindow(hWnd))
	{
		MessageBox(NULL, "inKillGL -> DestroyWindow", "fuck...", MB_OK | MB_ICONINFORMATION);

		hWnd = NULL;
	}

	if(	!UnregisterClass(window.className, hInstance))
	{
		MessageBox(NULL, "inKillGL -> UnregisterClass", "fuck...", MB_OK | MB_ICONINFORMATION);

		hInstance = NULL;
	}
}

BOOL mainInitOGL(char* title, int width, int height, int bits, bool fullscreenflag)
{
	GLuint		pixelFormat;
	WNDCLASS	wc;
	DWORD		dwExStyle;
	DWORD		dwStyle;
	RECT		windowRect;

	windowRect.left		= (long)0;
	windowRect.right	= (long)width;
	windowRect.top		= (long)0;
	windowRect.bottom	= (long)height;

	window.fullscreen	= fullscreenflag;

	hInstance			= GetModuleHandle(NULL);
	wc.style			= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc		= (WNDPROC) WndProc;
	wc.cbClsExtra		= 0;
	wc.cbWndExtra		= 0;
	wc.hInstance		= hInstance;
	wc.hIcon			= LoadIcon(NULL, IDI_WINLOGO);
	wc.hCursor			= LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground	= NULL;
	wc.lpszMenuName		= NULL;
	wc.lpszClassName	= window.className;

	if(	!RegisterClass(&wc))
	{
		MessageBox(NULL, "createGL -> RegisterClass", "fuck...", MB_OK | MB_ICONINFORMATION);

		return FALSE;
	}
	
	if(	window.fullscreen)
	{
		DEVMODE dmScreenSettings;

		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));
		
		dmScreenSettings.dmSize			= sizeof(dmScreenSettings);
		dmScreenSettings.dmPelsWidth	= width;
		dmScreenSettings.dmPelsHeight	= height;
		dmScreenSettings.dmBitsPerPel	= bits;
		dmScreenSettings.dmDisplayFrequency = 75; 
		dmScreenSettings.dmFields		= DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		if(	ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
		{
				MessageBox(NULL, "createGL -> ChangeDisplaySettings", "fuck...", MB_OK | MB_ICONINFORMATION);

				return FALSE;
		}
	}

	if(	window.fullscreen)
	{
		window.x	=	0;
		window.y	=	0;

		dwExStyle	= WS_EX_APPWINDOW;
		dwStyle		= WS_POPUP;
		
		ShowCursor(FALSE);
	}
	else
	{
		window.x	=	GetSystemMetrics(SM_CXSCREEN) / 2 - window.width / 2;
		window.y	=	GetSystemMetrics(SM_CYSCREEN) / 2 - window.height / 2;	

		dwExStyle	= WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;
		dwStyle		= WS_POPUP;

		ShowCursor(FALSE);
	}

	AdjustWindowRectEx(&windowRect, dwStyle, FALSE, dwExStyle);


	if(	!(hWnd = CreateWindowEx(	dwExStyle,
									window.className,
									title,
									dwStyle | WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
									window.x, window.y,
									width,
									height,
									NULL,
									NULL,
									hInstance,
									NULL)))
	{
		mainKillOGL();

		MessageBox(NULL, "createGL -> CreateWindowEx", "fuck...", MB_OK | MB_ICONINFORMATION);
		return FALSE;
	}

	static PIXELFORMATDESCRIPTOR pfd=
	{
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
		PFD_TYPE_RGBA,
		bits,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		16,
		0, 0,
		PFD_MAIN_PLANE,
		0, 0, 0, 0
	};
	
	if(	!(hDC = GetDC(hWnd)))
	{
		mainKillOGL();
		MessageBox(NULL, "createGL -> GetDC", "fuck...", MB_OK | MB_ICONINFORMATION);

		return FALSE;
	}

	if(	!(pixelFormat = ChoosePixelFormat(hDC, &pfd)))
	{
		mainKillOGL();
		MessageBox(NULL, "createGL -> ChoosePixelFormat", "fuck...", MB_OK | MB_ICONINFORMATION);

		return FALSE;
	}

	if(	!SetPixelFormat(hDC, pixelFormat, &pfd))
	{
		mainKillOGL();
		MessageBox(NULL, "createGL -> SetPixelFormat", "fuck...", MB_OK | MB_ICONINFORMATION);

		return FALSE;
	}

	if(	!(hRC = wglCreateContext(hDC)))
	{
		mainKillOGL();
		MessageBox(NULL, "createGL -> wglCreateContext", "fuck...", MB_OK | MB_ICONINFORMATION);

		return FALSE;
	}

	if(	!wglMakeCurrent(hDC, hRC))
	{
		mainKillOGL();
		MessageBox(NULL, "createGL -> wglMakeCurrent", "fuck...", MB_OK | MB_ICONINFORMATION);

		return FALSE;
	}

	ShowWindow(hWnd, SW_SHOW);

	SetForegroundWindow(hWnd);
	SetFocus(hWnd);

//	***

	glClearColor(	window.clearColor.r, 
					window.clearColor.g, 
					window.clearColor.b, 
					window.clearColor.a);

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glClearDepth(1.0);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);

	glAlphaFunc(GL_GREATER, 0.1);
	glEnable(GL_ALPHA_TEST);

	glDisable(GL_POINT_SMOOTH);
	glShadeModel(GL_SMOOTH);

	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CCW);

	//	***	[light]

	glEnable(GL_COLOR_MATERIAL);
	
	float light_pos[4] = {10, 100, 20, 1.0};
//	float light_dir[3] = {-1, -1, -1};
	float light_dir[3] = {0, -1, 0};

	float mat_ambient[] = {0.9, 0.9, 0.9, 1};
	float lmodel_ambient[] = {0.4, 0.4, 0.4, 1};

	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light_dir);

//	glColorMaterial(GL_FRONT, GL_AMBIENT);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
	
//	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
//	glMaterialf(GL_FRONT, GL_SHININESS, 10.0);

   	//	***	[]


//	***

	return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		case WM_ACTIVATE :
		{
			if (!HIWORD(wParam))
			{
				window.active = true;

				dinput_access(window.active);
			}
			else
			{
				window.active = false;
			}

			return 0;
		}

		case WM_CLOSE:
		{
			PostQuitMessage(0);
			return 0;
		}
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG		msg;

	mainInit();

	while(!window.exit)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				window.exit = true;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			if(window.active)
			{
				if(!window.exit)	main();

				dinput_keyboard_process();
				dinput_mouse_process();

				SwapBuffers(hDC);
			}
		}
	}

//	***	[exit app]

	model_delete_all();
	interface_delete();
	mainKillOGL();
	dinput_delete();

//	***

	return (msg.wParam);
}

