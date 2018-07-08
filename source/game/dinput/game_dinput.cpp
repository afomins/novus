


#include	"main\main.h"
#include	"game\game.h"
#include	"dinput\dinput.h"
#include	"texture\texture.h"

#include	<math.h>


void	game_dinput_process()
{
	//	***	[	MENU_ON ]
	if((keyboard.statuss[g_game.dinput_keyboard_properties.all_menu_on] == b_PRESS) && (g_game.game_on))
	{
		if(	(g_game.interface_properties.w_main_menu->fade_mode == FADE_MODE_NONE) &&
			(g_game.interface_properties.w_new_game->fade_mode == FADE_MODE_NONE))
		{
			if(g_game.interface_properties.w_main_menu->fade_way == FADE_WAY_OUT)
			{
				g_interface.window_first->fade_mode = FADE_MODE_START;
				g_game.interface_properties.w_game_screen->fade_mode	= FADE_MODE_START;

				g_game.camera_properties.rotate.angle_h			= camera.script_rotate.angle_h;
				g_game.camera_properties.rotate.angle_v			= camera.script_rotate.angle_v;
				g_game.camera_properties.rotate.radius			= camera.script_rotate.radius;
				g_game.camera_properties.rotate.center_x		= camera.script_rotate.center_x;
				g_game.camera_properties.rotate.center_y		= camera.script_rotate.center_y;
				g_game.camera_properties.rotate.center_z		= camera.script_rotate.center_z;
				g_game.camera_properties.rotate.quater_enable	= camera.rotate.quater_enable;

				camera_rotate_create(g_game.camera_properties.rotate);

				g_interface.cursor.cursor_on	= false;
				g_game.game_menu_on				= false;
				g_game.game_camera_script_on	= true;

			if(g_game.interface_properties.w_stat->window_on)
			{
				g_game.interface_properties.w_stat->fade_mode	= FADE_MODE_START;
				g_game.interface_properties.w_stat->window_on	= false;
			}


				if(g_game.interface_properties.w_new_game->window_on)
				{
					g_game.interface_properties.b_main_menu_new_game->button_active	= false;
					g_game.interface_properties.w_new_game->fade_mode	= FADE_MODE_START;

					g_game.camera_properties.script.next_camera_mode	= CAMERA_MODE_ROTATE;
					g_game.camera_properties.script.end_angle_h			= camera.rotate.angle_h + PI;
					g_game.camera_properties.script.end_angle_v			= -camera.rotate.angle_v;
													
					g_game.camera_properties.script.end_x				= camera.rotate.center_x + cos(camera.rotate.angle_h) * cos(camera.rotate.angle_v) * camera.rotate.radius;
					g_game.camera_properties.script.end_z				= camera.rotate.center_z + sin(camera.rotate.angle_h) * cos(camera.rotate.angle_v) * camera.rotate.radius;
					g_game.camera_properties.script.end_y				= camera.rotate.center_y + sin(camera.rotate.angle_v) * camera.rotate.radius;

					camera.camera_mode	= CAMERA_MODE_NONE;
					game_camera_script_create();
				}
			}

			if(	(g_game.interface_properties.w_main_menu->fade_way == FADE_WAY_IN) &&
				(!g_game.game_camera_script_on))
			{
				g_interface.window_first->fade_mode = FADE_MODE_START;
				g_game.interface_properties.w_game_screen->fade_mode	= FADE_MODE_START;

				g_game.camera_properties.script_rotate.angle_h	= camera.rotate.angle_h;
				g_game.camera_properties.script_rotate.angle_v	= camera.rotate.angle_v;
				g_game.camera_properties.script_rotate.radius	= camera.rotate.radius;
				g_game.camera_properties.script_rotate.center_x	= camera.rotate.center_x;
				g_game.camera_properties.script_rotate.center_y	= camera.rotate.center_y;
				g_game.camera_properties.script_rotate.center_z	= camera.rotate.center_z;

				camera_script_rotate_create(g_game.camera_properties.script_rotate);

				g_interface.cursor.cursor_on	= true;
				g_game.game_menu_on				= true;
			}
		}
	}

	if(keyboard.statuss[g_game.dinput_keyboard_properties.all_quit_game] == b_PRESS)
	{
		window.exit		= true;
	}

	if(keyboard.statuss[k_F12] == b_PRESS)
	{
		if(bool_temp)
		{
			bool_temp = false;

			textureLoadTGA(&tex[TEX_SKY_FRONT],	"data/sky/hl_00_front.tga", false, false);
			textureLoadTGA(&tex[TEX_SKY_BACK],	"data/sky/hl_00_back.tga",	false, false);
			textureLoadTGA(&tex[TEX_SKY_LEFT],	"data/sky/hl_00_left.tga",	false, false);
			textureLoadTGA(&tex[TEX_SKY_RIGHT],	"data/sky/hl_00_right.tga", false, false);
			textureLoadTGA(&tex[TEX_SKY_UP],	"data/sky/hl_00_up.tga",	false, false);
			textureLoadTGA(&tex[TEX_SKY_DOWN],	"data/sky/hl_00_down.tga",	false, false);
		}
		else
		{
			bool_temp = true;

			textureLoadTGA(&tex[TEX_SKY_FRONT],	"data/sky/lake/front.tga", false, false);
			textureLoadTGA(&tex[TEX_SKY_BACK],	"data/sky/lake/back.tga",	false, false);
			textureLoadTGA(&tex[TEX_SKY_LEFT],	"data/sky/lake/left.tga",	false, false);
			textureLoadTGA(&tex[TEX_SKY_RIGHT],	"data/sky/lake/right.tga", false, false);
			textureLoadTGA(&tex[TEX_SKY_UP],	"data/sky/lake/up.tga",	false, false);
			textureLoadTGA(&tex[TEX_SKY_DOWN],	"data/sky/lake/down.tga",	false, false);
		}
	}
}
