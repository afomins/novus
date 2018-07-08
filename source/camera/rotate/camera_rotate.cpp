


#include	"main\main.h"
#include	"camera\camera.h"

#include	<math.h>


void	camera_rotate_speed_create(float s_k_rotate, float s_k_walk, float s_m_rotate, float s_m_walk, float s_m_wheel)
{
	camera.rotate.speed_keyboard_rotate		= s_k_rotate;
	camera.rotate.speed_keyboard_walk		= s_k_walk;
	camera.rotate.speed_mouse_walk			= s_m_walk;
	camera.rotate.speed_mouse_rotate		= s_m_rotate;
	camera.rotate.speed_mouse_wheel			= s_m_wheel;
}

void	camera_rotate_process()
{
	if(camera.rotate.angle_h	<	0.0)		camera.rotate.angle_h	+=	PI * 2;
	if(camera.rotate.angle_h	>	PI * 2)		camera.rotate.angle_h	-=	PI * 2;

	if(camera.rotate.angle_v	>	PI / 2)		camera.rotate.angle_v	=	PI / 2 - 0.00001;
	if(camera.rotate.angle_v	<	0)		camera.rotate.angle_v	=	0;

	if(camera.rotate.radius	>	camera.rotate.radius_max)	camera.rotate.radius	=	camera.rotate.radius_max;
	if(camera.rotate.radius	<	camera.rotate.radius_min)	camera.rotate.radius	=	camera.rotate.radius_min;

	if(camera.rotate.quater_enable == QUATER_ENABLE_2_3)
	{
		if((camera.rotate.angle_h > 0.0) && (camera.rotate.angle_h < PI / 2))	camera.rotate.angle_h	= 0.0;
		if((camera.rotate.angle_h < PI) && (camera.rotate.angle_h > PI / 2))	camera.rotate.angle_h	= PI;
	}

	if(camera.rotate.quater_enable == QUATER_ENABLE_3_0)
	{
		if((camera.rotate.angle_h > PI / 2) && (camera.rotate.angle_h < PI))		camera.rotate.angle_h	= PI / 2;
		if((camera.rotate.angle_h < 3 * PI / 2) && (camera.rotate.angle_h > PI))	camera.rotate.angle_h	= 3 * PI / 2;
	}

	if(camera.rotate.quater_enable == QUATER_ENABLE_0_1)
	{
		if((camera.rotate.angle_h < 2 * PI) && (camera.rotate.angle_h > 3 * PI / 2))		camera.rotate.angle_h	= 0.0 + 0.0001;
		if((camera.rotate.angle_h > PI) && (camera.rotate.angle_h < 3 * PI / 2))			camera.rotate.angle_h	= PI;
	}

	if(camera.rotate.quater_enable == QUATER_ENABLE_1_2)
	{
		if((camera.rotate.angle_h < PI / 2) && (camera.rotate.angle_h > 0.0))			camera.rotate.angle_h	= PI / 2;
		if((camera.rotate.angle_h < 2 * PI) && (camera.rotate.angle_h > 3 * PI / 2))	camera.rotate.angle_h	= 3 * PI / 2;
	}

	viewport.camCenter.x		=	camera.rotate.center_x;
	viewport.camCenter.y		=	camera.rotate.center_y;
	viewport.camCenter.z		=	camera.rotate.center_z;

	viewport.camPosition.x		=	camera.rotate.center_x + cos(camera.rotate.angle_h) * cos(camera.rotate.angle_v) * camera.rotate.radius;
	viewport.camPosition.z		=	camera.rotate.center_z + sin(camera.rotate.angle_h) * cos(camera.rotate.angle_v) * camera.rotate.radius;
	viewport.camPosition.y		=	camera.rotate.center_y + sin(camera.rotate.angle_v) * camera.rotate.radius;
}

void	camera_rotate_create(camera_rotate rot)
{
	camera.camera_mode	= CAMERA_MODE_ROTATE;
	camera.rotate		= rot;
}