


#include	"main\main.h"
#include	"camera\camera.h"
#include	"timer\timer.h"

#include	<math.h>


void	camera_script_process()
{
	if(timerCurrent - camera.script.script_start > camera.script.script_length)
	{
		camera.camera_mode	= camera.script.next_camera_mode;

		camera.script.current_angle_h	= camera.script.end_angle_h;
		camera.script.current_angle_v	= camera.script.end_angle_v;
		camera.script.current_x			= camera.script.end_x;
		camera.script.current_y			= camera.script.end_y;
		camera.script.current_z			= camera.script.end_z;
	}
	else
	{
		camera.script.current_angle_h	= camera.script.start_angle_h + camera.script.length_angle_h * (timerCurrent - camera.script.script_start) / (float)camera.script.script_length;
		camera.script.current_angle_v	= camera.script.start_angle_v + camera.script.length_angle_v * (timerCurrent - camera.script.script_start) / (float)camera.script.script_length;
		camera.script.current_x			= camera.script.start_x + camera.script.length_x * (timerCurrent - camera.script.script_start) / (float)camera.script.script_length;
		camera.script.current_y			= camera.script.start_y + camera.script.length_y * (timerCurrent - camera.script.script_start) / (float)camera.script.script_length;
		camera.script.current_z			= camera.script.start_z + camera.script.length_z * (timerCurrent - camera.script.script_start) / (float)camera.script.script_length;
	}

	viewport.camPosition.x	= camera.script.current_x;
	viewport.camPosition.z	= camera.script.current_z;
	viewport.camPosition.y	= camera.script.current_y;

	viewport.camCenter.x	= camera.script.current_x + cos(camera.script.current_angle_h) * cos(camera.script.current_angle_v);
	viewport.camCenter.z	= camera.script.current_z + sin(camera.script.current_angle_h) * cos(camera.script.current_angle_v);
	viewport.camCenter.y	= camera.script.current_y + sin(camera.script.current_angle_v);
}

void	camera_script_create(camera_script script)
{
//	float	angle_h0;
//	float	angle_h1;

	camera.camera_mode		= CAMERA_MODE_SCRIPT;
	camera.script			= script;

	if(camera.script.end_angle_h > 2 * PI)		camera.script.end_angle_h	-= 2 * PI;
	if(camera.script.end_angle_h < 0.0)			camera.script.end_angle_h	+= 2 * PI;
	if(camera.script.start_angle_h > 2 * PI)	camera.script.start_angle_h	-= 2 * PI;
	if(camera.script.start_angle_h < 0.0)		camera.script.start_angle_h += 2 * PI;

	if(camera.script.end_angle_v > PI / 2)		camera.script.end_angle_v	= PI / 2 -0.001;
	if(camera.script.end_angle_v < -PI / 2)		camera.script.end_angle_v	= -PI / 2 +0.001;
	if(camera.script.start_angle_v > PI / 2)	camera.script.start_angle_v	= PI / 2 -0.001;
	if(camera.script.start_angle_v < -PI / 2)	camera.script.start_angle_v	= -PI / 2 +0.001;

//	angle_h0	= abs(camera.script.end_angle_h - camera.script.start_angle_h);
//	angle_h1	= abs(camera.script.end_angle_h - camera.script.start_angle_h) - PI * 2;


//	if(angle_h0 < angle_h1)	camera.script.length_angle_h	= angle_h0;
//	if(angle_h1 < angle_h0)	camera.script.length_angle_h	= angle_h1;

	camera.script.length_angle_v	= camera.script.end_angle_v - camera.script.start_angle_v;
	camera.script.length_angle_h	= camera.script.end_angle_h - camera.script.start_angle_h;

	camera.script.length_x	= camera.script.end_x - camera.script.start_x;
	camera.script.length_y	= camera.script.end_y - camera.script.start_y;
	camera.script.length_z	= camera.script.end_z - camera.script.start_z;

	camera.script.script_start	= timerCurrent;

	camera.script.current_angle_h	= camera.script.start_angle_h;
	camera.script.current_angle_v	= camera.script.start_angle_v;
	camera.script.current_x			= camera.script.start_x;
	camera.script.current_y			= camera.script.start_y;
	camera.script.current_z			= camera.script.start_z;

	viewport.camPosition.x	= camera.script.current_x + cos(camera.script.current_angle_h) * cos(camera.script.current_angle_v);
	viewport.camPosition.z	= camera.script.current_z + sin(camera.script.current_angle_h) * cos(camera.script.current_angle_v);
	viewport.camPosition.y	= camera.script.current_y + sin(camera.script.current_angle_v);
}
