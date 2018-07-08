


#include	"main\main.h"
#include	"game\game.h"

#include	<stdio.h>

void	game_process()
{
	//	***	[	DINPUT		]

	game_dinput_process();

	//	***	[	INTERFACE	]

	if(g_game.game_menu_on)
	{
		if(	(g_game.interface_properties.b_main_menu_new_game->button_active) &&
			(!g_game.interface_properties.w_new_game->window_on))
		{
			g_game.interface_properties.w_new_game->fade_mode	= FADE_MODE_START;
		}

		if(	(!g_game.interface_properties.b_main_menu_new_game->button_active) &&
			(g_game.interface_properties.w_new_game->window_on) &&
			(g_game.interface_properties.w_new_game->fade_mode == FADE_MODE_NONE))
		{
			g_game.interface_properties.w_new_game->fade_mode	= FADE_MODE_START;
		}
	}
	else
	{
		g_game.interface_properties.r_strength_bar->height	= g_game.interface_properties.r_strength_normal_height * (g_game.player_push_strength / 100.0);
	}

	if(g_game.game_on)
	{
		g_game.interface_properties.b_main_menu_save_game->button_lock	= false;

		interface_button_color_normal_create(g_game.interface_properties.b_main_menu_save_game, 0,	1.0, 1.0, 1.0, 1.0);
		interface_button_color_active_create(g_game.interface_properties.b_main_menu_save_game, 0,	1.0, 1.0, 1.0, 0.7);
		interface_button_color_active_create(g_game.interface_properties.b_main_menu_save_game, 1,	1.0, 1.0, 0.0, 0.3);

		g_game.interface_properties.b_main_menu_resume_game->button_lock	= false;

		interface_button_color_normal_create(g_game.interface_properties.b_main_menu_resume_game, 0,	1.0, 1.0, 1.0, 1.0);
		interface_button_color_active_create(g_game.interface_properties.b_main_menu_resume_game, 0,	1.0, 1.0, 1.0, 0.7);
		interface_button_color_active_create(g_game.interface_properties.b_main_menu_resume_game, 1,	1.0, 1.0, 0.0, 0.3);
	}
	else
	{
		g_game.interface_properties.b_main_menu_save_game->button_lock	= true;

		interface_button_color_normal_create(g_game.interface_properties.b_main_menu_save_game, 0,	1.0, 1.0, 1.0, 0.5);
		interface_button_color_active_create(g_game.interface_properties.b_main_menu_save_game, 0,	1.0, 1.0, 1.0, 0.0);
		interface_button_color_normal_create(g_game.interface_properties.b_main_menu_save_game, 1,	1.0, 1.0, 1.0, 0.0);
		interface_button_color_active_create(g_game.interface_properties.b_main_menu_save_game, 1,	1.0, 0.0, 0.0, 0.0);
	}

	game_interface_button_process();
	interface_process();

	//	***	[	PHIZIKS		]

	if((!g_game.game_menu_on)	&& (g_game.game_motion_on) && (!g_game.game_camera_script_on))
	{
		game_phiziks_process();
	}

	//	***	[	CAMERA		]

	game_camera_process();
}


void	game_save_statistic(int win0, int win1, int win2, int win3)
{
	FILE					*stat_file;
	game_statistic_instance	stat;

	stat_file	= fopen("data/stat.st", "r");

	fseek(stat_file,SEEK_SET, 0);

	fread(	&stat,
			sizeof(stat),
			1,
			stat_file);

	fclose(stat_file);

	stat_file	= fopen("data/stat.st", "w");

	if(win0 > 0)	stat.player_win[0]++;
	if(win0 == 0)	stat.player_loose[0]++;

	if(win1 > 0)	stat.player_win[1]++;
	if(win1 == 0)	stat.player_loose[1]++;

	if(win2 > 0)	stat.player_win[2]++;
	if(win2 == 0)	stat.player_loose[2]++;

	if(win3 > 0)	stat.player_win[3]++;
	if(win3 == 0)	stat.player_loose[3]++;

	fwrite(	&stat, 
			sizeof(stat), 
			1, stat_file);

	fclose(stat_file);
}

void	game_load_statistic()
{
	FILE					*stat_file;
	game_statistic_instance	stat;

	stat_file	= fopen("data/stat.st", "r");

	fseek(stat_file,SEEK_SET, 0);

	fread(	&stat,
			sizeof(stat),
			1,
			stat_file);

	fclose(stat_file);

	g_game.stat	= stat;
}

void	game_check_end_game()
{
		int		loop_puck;
		int		loop_player;
		int		puck_num[4];
		bool	team_off[2];
		

		puck_num[0]	=	-1;
		puck_num[1]	=	-1;
		puck_num[2]	=	-1;
		puck_num[3]	=	-1;

		team_off[0]	= false;
		team_off[1]	= false;

		for(loop_player = 0; loop_player < 4; loop_player++)
		{
			if(g_game.player[loop_player].player_on)
			{
				puck_num[loop_player]	=	0;

				for(loop_puck = 1; loop_puck < 9; loop_puck++)
				{
					if(g_game.player[loop_player].puck[loop_puck].puck_on)	puck_num[loop_player]++;
				}
			}
		}

		if(	((puck_num[0] == 0)		&& (puck_num[1] == 0)) ||
			((puck_num[0] == -1)	&& (puck_num[1] == 0)) ||
			((puck_num[0] == 0)		&& (puck_num[1] == -1)))
		{
			team_off[0]	= true;
		}

		if(	((puck_num[2] == 0)		&& (puck_num[3] == 0)) ||
			((puck_num[2] == -1)	&& (puck_num[3] == 0)) ||
			((puck_num[2] == 0)		&& (puck_num[3] == -1)))
		{
			team_off[1]	= true;
		}

		if(team_off[0])
		{
			g_game.game_on					= false;
			g_game.game_menu_on				= true;
			g_interface.cursor.cursor_on	= true;

			g_game.interface_properties.w_game_result->window_on	= true;
			g_game.interface_properties.w_game_result->fade_mode	= FADE_MODE_START;
			g_game.interface_properties.r_result_blue->rectangle_on	= true;
			g_game.interface_properties.r_result_red->rectangle_on	= false;

			g_game.interface_properties.w_main_menu->window_on		= true;
			g_game.interface_properties.w_main_menu->fade_mode		= FADE_MODE_START;

			g_game.interface_properties.w_game_screen->fade_mode	= FADE_MODE_START;

			camera.camera_mode	= CAMERA_MODE_SCRIPT_ROTATE;
			camera.script_rotate.angle_h	= camera.rotate.angle_h;
			camera.script_rotate.angle_v	= camera.rotate.angle_v;
			camera.script_rotate.center_x	= camera.rotate.center_x;
			camera.script_rotate.center_y	= camera.rotate.center_y;
			camera.script_rotate.center_z	= camera.rotate.center_z;
			camera.script_rotate.radius		= camera.rotate.radius;

			g_game.interface_properties.b_main_menu_resume_game->button_lock	= true;

			interface_button_color_normal_create(g_game.interface_properties.b_main_menu_resume_game, 0,	1.0, 1.0, 1.0, 0.5);
			interface_button_color_active_create(g_game.interface_properties.b_main_menu_resume_game, 0,	1.0, 1.0, 1.0, 0.0);
			interface_button_color_normal_create(g_game.interface_properties.b_main_menu_resume_game, 1,	1.0, 1.0, 1.0, 0.0);
			interface_button_color_active_create(g_game.interface_properties.b_main_menu_resume_game, 1,	1.0, 0.0, 0.0, 0.0);

			game_save_statistic(puck_num[0], puck_num[1], puck_num[2], puck_num[3]);
		}

		if(team_off[1])
		{
			g_game.game_on					= false;
			g_game.game_menu_on				= true;
			g_interface.cursor.cursor_on	= true;

			g_game.interface_properties.w_game_result->window_on	= true;
			g_game.interface_properties.w_game_result->fade_mode	= FADE_MODE_START;
			g_game.interface_properties.r_result_blue->rectangle_on	= false;
			g_game.interface_properties.r_result_red->rectangle_on	= true;

			g_game.interface_properties.w_main_menu->window_on		= true;
			g_game.interface_properties.w_main_menu->fade_mode		= FADE_MODE_START;

//			g_game.interface_properties.w_game_screen->window_on	= true;
			g_game.interface_properties.w_game_screen->fade_mode	= FADE_MODE_START;

			camera.camera_mode	= CAMERA_MODE_SCRIPT_ROTATE;
			camera.script_rotate.angle_h	= camera.rotate.angle_h;
			camera.script_rotate.angle_v	= camera.rotate.angle_v;
			camera.script_rotate.center_x	= camera.rotate.center_x;
			camera.script_rotate.center_y	= camera.rotate.center_y;
			camera.script_rotate.center_z	= camera.rotate.center_z;
			camera.script_rotate.radius		= camera.rotate.radius;

			g_game.interface_properties.b_main_menu_resume_game->button_lock	= true;

			interface_button_color_normal_create(g_game.interface_properties.b_main_menu_resume_game, 0,	1.0, 1.0, 1.0, 0.5);
			interface_button_color_active_create(g_game.interface_properties.b_main_menu_resume_game, 0,	1.0, 1.0, 1.0, 0.0);
			interface_button_color_normal_create(g_game.interface_properties.b_main_menu_resume_game, 1,	1.0, 1.0, 1.0, 0.0);
			interface_button_color_active_create(g_game.interface_properties.b_main_menu_resume_game, 1,	1.0, 0.0, 0.0, 0.0);

			game_save_statistic(puck_num[0], puck_num[1], puck_num[2], puck_num[3]);	
		}
}

void	game_save()
{
	FILE					*save_file;
	save_game_instance		save;

	save_file	= fopen("data/save_game.st", "w");

	save.game_motion_on			= g_game.game_motion_on;
	save.player_active			= g_game.player_active;
//	save.camera					= camera;

	save.player[0]				= g_game.player[0];
	save.player[1]				= g_game.player[1];
	save.player[2]				= g_game.player[2];
	save.player[3]				= g_game.player[3];

	fwrite(	&save, 
			sizeof(save), 
			1, save_file);

	fclose(save_file);

	save_file = NULL;
}

void	game_load()
{
	FILE					*save_file;
	save_game_instance		save;

	save_file	= fopen("data/save_game.st", "r");

	fseek(save_file, SEEK_SET, 0);

	fread(	&save,
			sizeof(save),
			1,
			save_file);

	g_game.game_motion_on			= save.game_motion_on;
	g_game.player_active			= save.player_active;
//	camera							= save.camera;
	g_game.player[0]				= save.player[0];
	g_game.player[1]				= save.player[1];
	g_game.player[2]				= save.player[2];
	g_game.player[3]				= save.player[3];

	g_game.game_menu_on				= true;

	fclose(save_file);
}
