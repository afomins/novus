


#include	"main\main.h"
#include	"camera\camera.h"

#include	<math.h>


void	camera_freelook_speed_create(float s_k_rotate, float s_k_walk, float s_m_rotate, float s_m_walk)
{
	camera.freelook.speed_keyboard_rotate	= s_k_rotate;
	camera.freelook.speed_keyboard_walk		= s_k_walk;
	camera.freelook.speed_mouse_rotate		= s_m_rotate;
	camera.freelook.speed_mouse_walk		= s_m_walk;
}

void	camera_freelook_process()
{
	if(camera.freelook.angle_h	<	0)		camera.freelook.angle_h	+=	PI * 2;
	if(camera.freelook.angle_h	>	PI * 2)	camera.freelook.angle_h	-=	PI * 2;

	if(camera.freelook.angle_v	>	PI / 2)		camera.freelook.angle_v	=	PI / 2 - 0.001;
	if(camera.freelook.angle_v	<	-PI / 2)	camera.freelook.angle_v	=	-PI / 2 + 0.001;

	viewport.camPosition.x	=	camera.freelook.position_x;
	viewport.camPosition.y	=	camera.freelook.position_y;
	viewport.camPosition.z	=	camera.freelook.position_z;

	viewport.camCenter.x	=	camera.freelook.position_x + cos(camera.freelook.angle_h) * cos(camera.freelook.angle_v);
	viewport.camCenter.z	=	camera.freelook.position_z + sin(camera.freelook.angle_h) * cos(camera.freelook.angle_v);
	viewport.camCenter.y	=	camera.freelook.position_y + sin(camera.freelook.angle_v);
}

void	camera_freelook_create(camera_freelook free)
{
	camera.camera_mode		= CAMERA_MODE_FREELOOK;
	camera.freelook			= free;
}
