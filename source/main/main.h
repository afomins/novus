 


#include <windows.h>
#include <gl\gl.h>
#include <gl\glu.h>

#pragma warning(disable: 4305)
#pragma warning(disable: 4244)

#define		PI	3.14159265359

#define		sqr(x)				x * x
#define		rad(x)				x * PI / 180.0
#define		grad(x)				x * 180.0 / PI

	//	***	[window]

extern	HWND		hWnd;
extern	HINSTANCE	hInstance;
extern	HDC			hDC;
extern	HGLRC		hRC;

extern	bool		bool_temp;
extern	float		float_temp;
extern	long		long_temp;

struct	mainColor4f
{
	float	r;
	float	g;
	float	b;
	float	a;
};

struct	mainCoord3f
{
	float	x;
	float	y;
	float	z;
};

struct	mainWindow
{
	int						x;
	int						y;

	int						width;
	int						height;

	int						bpp;

	mainColor4f				clearColor;

	bool					active;
	bool					fullscreen;
	bool					exit;

	char					*className;
	char					*titleName;
};

struct	mainViewport
{
	int						x;
	int						y;
	int						width;
	int						height;

	float					camAspect;
	float					camFov;

	float					camNear;
	float					camFar;

	mainCoord3f				camPosition;
	mainCoord3f				camCenter;
	mainCoord3f				camVertical;
};


extern	mainWindow		window;
extern	mainViewport	viewport;


LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL	mainInitOGL(char* title, int width, int height, int bits, bool fullscreenflag);

void mainInit();
void mainWindowInit();
void mainViewportInit();
