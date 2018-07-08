  


#include "main\main.h"
#include "dinput\dinput.h"

dinput_mouse	mouse;

void dinput_mouse_init()
{
	int	loop;

	for(loop = 0; loop < MOUSE_BUTTON_NUM; loop++)
	{
		mouse.statuss[loop] = b_NULL;
	}

	mouse.sensitivity	=	2.0;

	mouse.x				=	window.width / 2;
	mouse.y				=	window.height / 2;
}
