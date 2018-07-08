


#include	"main\main.h"
#include	"game\game.h"

#include	<math.h>


void	game_camera_script_create()
{
	if(camera.camera_mode == CAMERA_MODE_ROTATE)
	{
		g_game.camera_properties.script.script_length	= camera.camera_script_length_default;
	
		g_game.camera_properties.script.start_angle_h	= camera.rotate.angle_h + PI;
		g_game.camera_properties.script.start_angle_v	= -camera.rotate.angle_v;

		g_game.camera_properties.script.start_x			= camera.rotate.center_x + cos(camera.rotate.angle_h) * cos(camera.rotate.angle_v) * camera.rotate.radius;
		g_game.camera_properties.script.start_z			= camera.rotate.center_z + sin(camera.rotate.angle_h) * cos(camera.rotate.angle_v) * camera.rotate.radius;
		g_game.camera_properties.script.start_y			= camera.rotate.center_y + sin(camera.rotate.angle_v);
	}
	else
	if(camera.camera_mode == CAMERA_MODE_SCRIPT_ROTATE)
	{
		g_game.camera_properties.script.script_length	= camera.camera_script_length_default;
	
		g_game.camera_properties.script.start_angle_h	= camera.script_rotate.angle_h + PI;
		g_game.camera_properties.script.start_angle_v	= -camera.script_rotate.angle_v;

		g_game.camera_properties.script.start_x			= camera.script_rotate.center_x + cos(camera.script_rotate.angle_h) * cos(camera.script_rotate.angle_v) * camera.script_rotate.radius;
		g_game.camera_properties.script.start_z			= camera.script_rotate.center_z + sin(camera.script_rotate.angle_h) * cos(camera.script_rotate.angle_v) * camera.script_rotate.radius;
		g_game.camera_properties.script.start_y			= camera.script_rotate.center_y + sin(camera.script_rotate.angle_v) * camera.script_rotate.radius;
	}
	else
	if(camera.camera_mode == CAMERA_MODE_FREELOOK)
	{
		g_game.camera_properties.script.script_length	= camera.camera_script_length_default;
	
		g_game.camera_properties.script.start_angle_h	= camera.freelook.angle_h;
		g_game.camera_properties.script.start_angle_v	= camera.freelook.angle_v;

		g_game.camera_properties.script.start_x			= camera.freelook.position_x;
		g_game.camera_properties.script.start_z			= camera.freelook.position_z;
		g_game.camera_properties.script.start_y			= camera.freelook.position_y;
	}
	else
	if((camera.camera_mode	== CAMERA_MODE_SCRIPT) || (camera.camera_mode	== CAMERA_MODE_NONE))
	{
		g_game.camera_properties.script.script_length	= camera.camera_script_length_default;
	
		g_game.camera_properties.script.start_angle_h	= camera.script.current_angle_h;
		g_game.camera_properties.script.start_angle_v	= camera.script.current_angle_v;

		g_game.camera_properties.script.start_x			= camera.script.current_x;
		g_game.camera_properties.script.start_z			= camera.script.current_z;
		g_game.camera_properties.script.start_y			= camera.script.current_y;
	}

	camera_script_create(g_game.camera_properties.script);
}
