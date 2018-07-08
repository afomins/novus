  


#include	"main\main.h"
#include	"dinput\dinput.h"
#include	"draw\draw2d.h"
#include	"texture\texture.h"
#include	"write\write.h"
//#include	"model\model.h"
//#include	"camera\camera.h"
//#include	"interface\interface.h"
#include	"game\game.h"

	//	***	[window]

HWND		hWnd;
HINSTANCE	hInstance;
HDC			hDC					=	NULL;
HGLRC		hRC					=	NULL;

bool		bool_temp	= false;
float		float_temp;
long		long_temp;


	//	***	[temp]

mainWindow		window;
mainViewport	viewport;

void mainInit()
{
	mainWindowInit();
	mainViewportInit();
	
	mainInitOGL(	window.titleName, 
					window.width, 
					window.height, 
					window.bpp, 
					window.fullscreen);

	dinput_create();
	dinput_keyboard_init();
	dinput_mouse_init();
	textureInit();
	writeInit();
	game_init();
	model_init();
}

void mainWindowInit()
{
	window.active		=	true;
	window.fullscreen	=	true;
	window.exit			=	false;

	window.width		=	1024;
	window.height		=	768;
	window.width		=	640;
	window.height		=	480;
//	window.width		=	800;
//	window.height		=	600;
	window.bpp			=	16;

	window.clearColor.r	=	0.3;
	window.clearColor.g	=	0.3;
	window.clearColor.b	=	0.3;
	window.clearColor.a	=	1.0;

	window.className	=	"ogl";
	window.titleName	=	"nov4";
}

void mainViewportInit()
{
	viewport.x				=	0;
	viewport.y				=	0;
	viewport.width			=	window.width;
	viewport.height			=	window.height;

	viewport.camVertical.x	=	0.0;
	viewport.camVertical.y	=	1.0;
	viewport.camVertical.z	=	0.0;

	viewport.camPosition.x	=	0.0;
	viewport.camPosition.y	=	50.0;
	viewport.camPosition.z	=	-5.0;

	viewport.camCenter.x	=	0.0;
	viewport.camCenter.y	=	0.0;
	viewport.camCenter.z	=	0.0;

	viewport.camAspect		=	window.width / (float)window.height;
	viewport.camFov			=	60.0;
	viewport.camNear		=	0.1;
	viewport.camFar			=	700;
}
