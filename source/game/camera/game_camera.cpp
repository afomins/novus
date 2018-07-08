


#include	"main\main.h"
#include	"game\game.h"

void	game_camera_process()
{
	if(camera.camera_mode == CAMERA_MODE_NONE)
	{
	}
	else
	if(camera.camera_mode == CAMERA_MODE_SCRIPT_ROTATE)
	{
	}
	else
	if(	(camera.camera_mode == CAMERA_MODE_ROTATE) && 
		(!g_game.game_camera_script_on))
	{
		game_camera_rotate_keyboard_process();
		game_camera_rotate_mouse_process();

		if(g_game.player_push_strength < g_game.player_push_strength_min)	g_game.player_push_strength	= g_game.player_push_strength_min;
		if(g_game.player_push_strength > g_game.player_push_strength_max)	g_game.player_push_strength	= g_game.player_push_strength_max;

		if(!g_game.game_motion_on)
		{
			if((g_game.player_active == 0) || (g_game.player_active == 2))
			{
				if(g_game.player[g_game.player_active].puck[0].coord.x	> g_game.model_table_plane_properties.width)
				{
					g_game.player[g_game.player_active].puck[0].coord.x	= g_game.model_table_plane_properties.width;
				}

				if(g_game.player[g_game.player_active].puck[0].coord.x	< -g_game.model_table_plane_properties.width)
				{
					g_game.player[g_game.player_active].puck[0].coord.x	= -g_game.model_table_plane_properties.width;
				}
			}

			if((g_game.player_active == 1) || (g_game.player_active == 3))
			{
				if(g_game.player[g_game.player_active].puck[0].coord.z	> g_game.model_table_plane_properties.width)
				{
					g_game.player[g_game.player_active].puck[0].coord.z	= g_game.model_table_plane_properties.width;
				}

				if(g_game.player[g_game.player_active].puck[0].coord.z	< -g_game.model_table_plane_properties.width)
				{
					g_game.player[g_game.player_active].puck[0].coord.z	= -g_game.model_table_plane_properties.width;
				}
			}

			camera.rotate.center_x	= g_game.player[g_game.player_active].puck[0].coord.x;
			camera.rotate.center_z	= g_game.player[g_game.player_active].puck[0].coord.z;
		}
	}
	else
	if((camera.camera_mode == CAMERA_MODE_FREELOOK) && (!g_game.game_camera_script_on))
	{
		game_camera_freelook_keyboard_process();
		game_camera_freelook_mouse_process();
	}
	if(camera.camera_mode == CAMERA_MODE_SCRIPT)
	{
		g_game.game_camera_script_on	= true;
	}

	if(camera.camera_mode != CAMERA_MODE_SCRIPT)
	{
		g_game.game_camera_script_on	= false;
	}

	camera_process();
}