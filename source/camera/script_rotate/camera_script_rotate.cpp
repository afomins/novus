


#include	"main\main.h"
#include	"camera\camera.h"
#include	"timer\timer.h"

#include	<math.h>


void	camera_script_rotate_create(camera_script_rotate script_rot)
{
	camera.camera_mode		= CAMERA_MODE_SCRIPT_ROTATE;
	camera.script_rotate	= script_rot;
}

void	camera_script_rotate_process()
{
	camera.script_rotate.angle_h	+= camera.script_rotate.speed_h * timerFrameLength;

	if(camera.script_rotate.angle_h	<	0)			camera.script_rotate.angle_h	+= PI * 2;
	if(camera.script_rotate.angle_h	>	PI * 2)		camera.script_rotate.angle_h	-= PI * 2;

	if(camera.script_rotate.angle_v	>	PI / 2)		camera.script_rotate.angle_v	= PI / 2 - 0.00001;
	if(camera.script_rotate.angle_v	<	-PI / 2)	camera.script_rotate.angle_v	= -PI / 2 + 0.00001;

	viewport.camCenter.x		=	camera.script_rotate.center_x;
	viewport.camCenter.y		=	camera.script_rotate.center_y;
	viewport.camCenter.z		=	camera.script_rotate.center_z;

	viewport.camPosition.x		=	camera.script_rotate.center_x + cos(camera.script_rotate.angle_h) * cos(camera.script_rotate.angle_v) * camera.script_rotate.radius;
	viewport.camPosition.z		=	camera.script_rotate.center_z + sin(camera.script_rotate.angle_h) * cos(camera.script_rotate.angle_v) * camera.script_rotate.radius;
	viewport.camPosition.y		=	camera.script_rotate.center_y + sin(camera.script_rotate.angle_v) * camera.script_rotate.radius;
}
