


#include	"main\main.h"
#include	"game\game.h"
#include	"texture\texture.h"
#include	"dinput\dinput.h"

interface_global_instance	g_interface;

void	game_interface_init()
{
	unsigned short		loop;

	g_interface.fade_length_default			=	1000;
	g_interface.highlight_length_default	=	500;

		//	***	[	window]

	interface_window_instance	*w[6];

	for(loop = 0; loop < 6; loop++)
	{
		w[loop]	= new interface_window_instance;
	}

	interface_window_create(w[0]);
	g_game.interface_properties.w_main_menu	= g_interface.window_last;

	interface_window_create(w[1]);
	g_game.interface_properties.w_new_game				= g_interface.window_last;
	g_game.interface_properties.w_new_game->fade_mode	= FADE_MODE_NONE;

	interface_window_create(w[2]);
	g_game.interface_properties.w_game_screen				= g_interface.window_last;
	g_game.interface_properties.w_game_screen->fade_mode	= FADE_MODE_NONE;

	interface_window_create(w[3]);
	g_game.interface_properties.w_stat				= g_interface.window_last;
	g_game.interface_properties.w_stat->fade_mode	= FADE_MODE_NONE;

	interface_window_create(w[4]);
	g_game.interface_properties.w_game_result				= g_interface.window_last;
	g_game.interface_properties.w_game_result->fade_mode	= FADE_MODE_NONE;

	interface_window_create(w[5]);
	g_game.interface_properties.w_help				= g_interface.window_last;
	g_game.interface_properties.w_help->fade_mode	= FADE_MODE_NONE;
	
		//	***	[	button	window1]

	interface_button_instance	*b[14];

	for(loop = 0; loop < 14; loop++)
	{
		b[loop]	=	new	interface_button_instance;
	}

	interface_button_create(w[0], b[0], 45,	280 - 32 * 0, 256, 32,	TEX_BUTTON_RESUME_GAME_00,	TEX_BUTTON_RESUME_GAME_01);
	g_game.interface_properties.b_main_menu_resume_game	=	g_game.interface_properties.w_main_menu->button_last;

	interface_button_create(w[0], b[1], 30,	280 - 32 * 1, 256, 32,	TEX_BUTTON_NEW_GAME_00,		TEX_BUTTON_NEW_GAME_01);
	g_game.interface_properties.b_main_menu_new_game	=	g_game.interface_properties.w_main_menu->button_last;

	interface_button_create(w[0], b[2], 20,	280 - 32 * 2, 256, 32,	TEX_BUTTON_SAVE_GAME_00,	TEX_BUTTON_SAVE_GAME_01);
	g_game.interface_properties.b_main_menu_save_game	=	g_game.interface_properties.w_main_menu->button_last;

	interface_button_create(w[0], b[3], 12,	280 - 32 * 3, 256, 32,	TEX_BUTTON_LOAD_GAME_00,	TEX_BUTTON_LOAD_GAME_01);
	g_game.interface_properties.b_main_menu_load_game	=	g_game.interface_properties.w_main_menu->button_last;

	interface_button_create(w[0], b[4], 5,	280 - 32 * 4, 256, 32,	TEX_BUTTON_LOAD_REPLAY_00,	TEX_BUTTON_LOAD_REPLAY_01);
	interface_button_create(w[0], b[5], 7,	280 - 32 * 5, 256, 32,	TEX_BUTTON_OPTIONS_00,		TEX_BUTTON_OPTIONS_01);
	interface_button_create(w[0], b[6], 10,	280 - 32 * 6, 256, 32,	TEX_BUTTON_HELP_00,			TEX_BUTTON_HELP_01);
	g_game.interface_properties.b_main_menu_help		=	g_game.interface_properties.w_main_menu->button_last;

	interface_button_create(w[0], b[7], 15,	280 - 32 * 7, 256, 32,	TEX_BUTTON_STATISTICS_00,	TEX_BUTTON_STATISTICS_01);
	g_game.interface_properties.b_main_menu_stat		=	g_game.interface_properties.w_main_menu->button_last;

	interface_button_create(w[0], b[8], 30,	280 - 32 * 8, 256, 32,	TEX_BUTTON_EXIT_00,			TEX_BUTTON_EXIT_01);
	g_game.interface_properties.b_main_menu_exit_game	=	g_game.interface_properties.w_main_menu->button_last;

	interface_button_create(w[0], b[9], 60,	310, 280, 160, TEX_TERRA_NOVUS_LOGO_00, TEX_TERRA_NOVUS_LOGO_01);

	for(loop = 0; loop < 9; loop++)
	{
		interface_button_color_normal_create(b[loop], 0,	1.0, 1.0, 1.0, 0.5);
		interface_button_color_active_create(b[loop], 0,	1.0, 1.0, 1.0, 0.0);
		interface_button_color_normal_create(b[loop], 1,	1.0, 1.0, 1.0, 0.0);
		interface_button_color_active_create(b[loop], 1,	1.0, 0.0, 0.0, 0.0);
	}

	interface_button_color_normal_create(b[9], 0,		1.0, 1.0, 1.0, 1.0);
	interface_button_color_active_create(b[9], 0,		1.0, 1.0, 1.0, 0.0);
	interface_button_color_normal_create(b[9], 1,		1.0, 1.0, 1.0, 0.0);
	interface_button_color_active_create(b[9], 1,		1.0, 1.0, 1.0, 1.0);
	b[9]->button_lock	=	true;

	for(loop = 0; loop < 10 + 2; loop++)
	{
		b[loop]->button_lock	= true;
	}
		b[1]->button_lock		= false;	//	NEW
		b[8]->button_lock		= false;	//	EXIT
		b[7]->button_lock		= false;	//	STAT
		b[3]->button_lock		= false;	//	LOAD
		b[6]->button_lock		= false;	//	HELP

	interface_button_color_normal_create(b[1], 0,	1.0, 1.0, 1.0, 1.0);
	interface_button_color_active_create(b[1], 0,	1.0, 1.0, 1.0, 0.7);
	interface_button_color_active_create(b[1], 1,	1.0, 1.0, 0.0, 0.3);

	interface_button_color_normal_create(b[8], 0,	1.0, 1.0, 1.0, 1.0);
	interface_button_color_active_create(b[8], 0,	1.0, 1.0, 1.0, 0.7);
	interface_button_color_active_create(b[8], 1,	1.0, 1.0, 0.0, 0.3);

	interface_button_color_normal_create(b[7], 0,	1.0, 1.0, 1.0, 1.0);
	interface_button_color_active_create(b[7], 0,	1.0, 1.0, 1.0, 0.7);
	interface_button_color_active_create(b[7], 1,	1.0, 1.0, 0.0, 0.3);

	interface_button_color_normal_create(b[3], 0,	1.0, 1.0, 1.0, 1.0);
	interface_button_color_active_create(b[3], 0,	1.0, 1.0, 1.0, 0.7);
	interface_button_color_active_create(b[3], 1,	1.0, 1.0, 0.0, 0.3);

	interface_button_color_normal_create(b[6], 0,	1.0, 1.0, 1.0, 1.0);
	interface_button_color_active_create(b[6], 0,	1.0, 1.0, 1.0, 0.7);
	interface_button_color_active_create(b[6], 1,	1.0, 1.0, 0.0, 0.3);

		//	***	[	new game button]	*******************************************

	interface_button_create(w[1], b[12], 410, 350, 64, 32, TEX_B_PLAYERS, TEX_B_2PLAYERS);
	g_game.interface_properties.b_new_game_player_num2	= w[1]->button_last;
	interface_button_color_normal_create(b[12], 0,	0.5, 0.5, 0.5, 1.0);
	interface_button_color_active_create(b[12], 0,	0.3, 0.3, 0.9, 1.0);
	interface_button_color_normal_create(b[12], 1,	1.0, 1.0, 1.0, 1.0);
	interface_button_color_active_create(b[12], 1,	1.0, 1.0, 0.0, 1.0);
	b[12]->button_active	= true;
	b[12]->button_lock		= true;

	interface_button_create(w[1], b[13], 490, 350, 64, 32, TEX_B_PLAYERS, TEX_B_4PLAYERS);
	g_game.interface_properties.b_new_game_player_num4	= w[1]->button_last;
	interface_button_color_normal_create(b[13], 0,	0.5, 0.5, 0.5, 1.0);
	interface_button_color_active_create(b[13], 0,	0.9, 0.3, 0.3, 1.0);
	interface_button_color_normal_create(b[13], 1,	1.0, 1.0, 1.0, 1.0);
	interface_button_color_active_create(b[13], 1,	1.0, 1.0, 0.0, 1.0);


	interface_button_instance	*b1[9];

	for(loop = 0; loop < 10; loop++)
	{
		b1[loop]	=	new	interface_button_instance;
	}

		//	***	[player 0]
	interface_button_create(w[1], b1[0], 445, 55, 64, 16, TEX_B_NEW_GAME_PLAYER_00, TEX_B_NEW_GAME_PLAYER_01);
	g_game.interface_properties.b_new_game_player[0]	=	g_game.interface_properties.w_new_game->button_last;
	b1[0]->button_active	= true;

	interface_button_create(w[1], b1[1], 445, 55 - 20, 64, 16, TEX_B_NEW_GAME_PLAYER_00, TEX_B_NEW_GAME_AI_01);
	g_game.interface_properties.b_new_game_ai[0]	=	g_game.interface_properties.w_new_game->button_last;
		
	for(loop = 0; loop < 2; loop++)
	{
		b1[loop]->button_lock	= true;
		interface_button_color_normal_create(b1[loop], 0,	0.4, 0.3, 1.0, 1.0);
		interface_button_color_active_create(b1[loop], 0,	0.4, 0.4, 0.4, 1.0);
		interface_button_color_normal_create(b1[loop], 1,	1.0, 1.0, 1.0, 1.0);
		interface_button_color_active_create(b1[loop], 1,	1.0, 1.0, 0.0, 1.0);
	}

		interface_button_color_active_create(b1[1], 0,	0.4, 0.3, 1.0, 0.0);
		interface_button_color_active_create(b1[1], 1,	1.0, 1.0, 1.0, 0.0);

		//	***	[player 1]
	interface_button_create(w[1], b1[2], 550, 180, 64, 16, TEX_B_NEW_GAME_PLAYER_00, TEX_B_NEW_GAME_PLAYER_01);
	g_game.interface_properties.b_new_game_player[1]	=	g_game.interface_properties.w_new_game->button_last;
	b1[2]->button_active	= true;

	interface_button_create(w[1], b1[3], 550, 180 - 20, 64, 16, TEX_B_NEW_GAME_PLAYER_00, TEX_B_NEW_GAME_AI_01);
	g_game.interface_properties.b_new_game_ai[1]	=	g_game.interface_properties.w_new_game->button_last;
		
	for(loop = 2; loop < 4; loop++)
	{
		b1[loop]->button_lock	= true;
		interface_button_color_normal_create(b1[loop], 0,	1.0, 0.3, 0.4, 1.0);
		interface_button_color_active_create(b1[loop], 0,	0.4, 0.4, 0.4, 1.0);
		interface_button_color_normal_create(b1[loop], 1,	1.0, 1.0, 1.0, 1.0);
		interface_button_color_active_create(b1[loop], 1,	1.0, 1.0, 0.0, 1.0);
	}

		interface_button_color_active_create(b1[3], 0,	0.4, 0.4, 0.4, 0.0);
		interface_button_color_active_create(b1[3], 1,	1.0, 1.0, 1.0, 0.0);

		//	***	[player 2]
	interface_button_create(w[1], b1[4], 445, 290, 64, 16, TEX_B_NEW_GAME_PLAYER_00, TEX_B_NEW_GAME_PLAYER_01);
	g_game.interface_properties.b_new_game_player[2]	=	g_game.interface_properties.w_new_game->button_last;
	b1[4]->button_active	= true;

	interface_button_create(w[1], b1[5], 445, 290 - 20, 64, 16, TEX_B_NEW_GAME_PLAYER_00, TEX_B_NEW_GAME_AI_01);
	g_game.interface_properties.b_new_game_ai[2]	=	g_game.interface_properties.w_new_game->button_last;
		
	for(loop = 4; loop < 6; loop++)
	{
		b1[loop]->button_lock	= true;
		interface_button_color_normal_create(b1[loop], 0,	1.0, 0.3, 0.4, 1.0);
		interface_button_color_active_create(b1[loop], 0,	0.4, 0.4, 0.4, 1.0);
		interface_button_color_normal_create(b1[loop], 1,	1.0, 1.0, 1.0, 1.0);
		interface_button_color_active_create(b1[loop], 1,	1.0, 1.0, 0.0, 1.0);
	}

		interface_button_color_active_create(b1[5], 0,	0.4, 0.3, 1.0, 0.0);
		interface_button_color_active_create(b1[5], 1,	1.0, 1.0, 1.0, 0.0);


		//	***	[player 3]
	interface_button_create(w[1], b1[6], 340, 180, 64, 16, TEX_B_NEW_GAME_PLAYER_00, TEX_B_NEW_GAME_PLAYER_01);
	g_game.interface_properties.b_new_game_player[3]	=	g_game.interface_properties.w_new_game->button_last;
	b1[6]->button_active	= true;

	interface_button_create(w[1], b1[7], 340, 180 - 20, 64, 16, TEX_B_NEW_GAME_PLAYER_00, TEX_B_NEW_GAME_AI_01);
	g_game.interface_properties.b_new_game_ai[3]	=	g_game.interface_properties.w_new_game->button_last;
		
	for(loop = 6; loop < 8; loop++)
	{
		b1[loop]->button_lock	= true;
		interface_button_color_normal_create(b1[loop], 0,	1.0, 0.3, 0.4, 1.0);
		interface_button_color_active_create(b1[loop], 0,	0.4, 0.4, 0.4, 1.0);
		interface_button_color_normal_create(b1[loop], 1,	1.0, 1.0, 1.0, 1.0);
		interface_button_color_active_create(b1[loop], 1,	1.0, 1.0, 0.0, 1.0);
	}

		interface_button_color_active_create(b1[7], 0,	0.4, 0.3, 1.0, 0.0);
		interface_button_color_active_create(b1[7], 1,	1.0, 1.0, 1.0, 0.0);

		//	***	[	go button]
	interface_button_create(w[1], b1[8], 443, 137 + 16, 64, 32, TEX_B_NEW_GAME_GO_00, TEX_B_NEW_GAME_GO_01);
	g_game.interface_properties.b_new_game_go	=	g_game.interface_properties.w_new_game->button_last;

	interface_button_color_normal_create(b1[8], 0,	0.2, 0.3, 1.0, 1.0);
	interface_button_color_active_create(b1[8], 0,	0.3, 0.3, 0.3, 0.8);
	interface_button_color_normal_create(b1[8], 1,	1.0, 1.0, 1.0, 1.0);
	interface_button_color_active_create(b1[8], 1,	1.0, 1.0, 0.0, 1.0);

		//	***	[	CURSOR		]	***********************************************

	interface_cursor_create(&mouse.x, &mouse.y, 64, 32, TEX_CURSOR_0, true, -3, -3);
	interface_cursor_color_create(1.0, 1.0, 1.0, 1.0);
	interface_cursor_shadow_color_create(0.3, 0.3, 0.3, 0.4);

		//	***	[	RECTANGLE	]

	interface_rectangle_instance	*r[11];

	for(loop = 0; loop < 11; loop++)
	{
		r[loop]	=	new	interface_rectangle_instance;
	}

	interface_rectangle_create(w[0], r[0], -2, -2, 644, 484, TEX_MENU_00);
	interface_rectangle_color_normal_create(r[0], 0.6, 0.6, 0.6, 0.8);

	interface_rectangle_create(w[2], r[1], 600 + 2, 50 + 2, 32 - 4, 156 - 4, TEX_STRENGTH_BAR_01);
	interface_rectangle_color_normal_create(r[1], 1.0, 0.0, 0.0, 0.8);
	g_game.interface_properties.r_strength_bar	= g_game.interface_properties.w_game_screen->rectangle_last;
	
	interface_rectangle_create(w[2], r[2], 600, 50, 32, 256, TEX_STRENGTH_BAR_00);
	interface_rectangle_color_normal_create(r[2], 1.0, 1.0, 1.0, 0.8);
	g_game.interface_properties.r_strength_normal_height	= g_game.interface_properties.w_game_screen->rectangle_last->height - 4;

	//	***	[	name_bar]
	
	interface_rectangle_create(w[2], r[3], 10, 480 - 64 - 10, 128, 64, TEX_NAME_BAR);
	interface_rectangle_color_normal_create(r[3], 0.4, 0.3, 1.0, 1.0);

	interface_rectangle_create(w[2], r[4], 640 - 128 - 10, 480 - 64 - 10, 128, 64, TEX_NAME_BAR);
	interface_rectangle_color_normal_create(r[4], 1.0, 0.3, 0.4, 1.0);

	//	***	[	sat_tab]

	interface_rectangle_create(w[3], r[5], 330, 150, 256, 128, TEX_STAT_TAB);
	interface_rectangle_color_normal_create(r[5], 0.7, 0.7, 0.7, 0.7);

	//	***	[	help]

	interface_rectangle_create(w[5], r[10], 350, 40, 256, 256, TEX_HELP);
	interface_rectangle_color_normal_create(r[10], 1.0, 1.0, 0.7, 1.0);

	//	***	[	game result]

	interface_rectangle_create(w[4], r[6], 330, 200, 128, 64, TEX_NAME_BAR);
	interface_rectangle_color_normal_create(r[6], 0.2, 0.1, 1.0, 1.0);

	interface_rectangle_create(w[4], r[7], 330 + 138, 200, 128, 64, TEX_NAME_BAR);
	interface_rectangle_color_normal_create(r[7], 1.0, 0.2, 0.1, 1.0);

	interface_rectangle_create(w[4], r[8], 400, 270, 128, 16, TEX_RED_WINS);
	interface_rectangle_color_normal_create(r[8], 1.0, 1.0, 1.0, 1.0);
	g_game.interface_properties.r_result_red	= g_game.interface_properties.w_game_result->rectangle_last;

	interface_rectangle_create(w[4], r[9], 400, 270, 128, 16, TEX_BLUE_WINS);
	interface_rectangle_color_normal_create(r[9], 1.0, 1.0, 1.0, 1.0);
	g_game.interface_properties.r_result_blue	= g_game.interface_properties.w_game_result->rectangle_last;

		//	***	[	]

	interface_check_resolution(640, 480, window.width, window.height);

		//	***	[	camera new game]

	g_game.interface_properties.cam_new_game_camera.end_angle_h			= PI / 2;
	g_game.interface_properties.cam_new_game_camera.end_angle_v			= -PI / 2;
													
	g_game.interface_properties.cam_new_game_camera.end_x				= -13.0 - 15.0;
	g_game.interface_properties.cam_new_game_camera.end_z				= 13.0;
	g_game.interface_properties.cam_new_game_camera.end_y				= 75.0;

	g_game.interface_properties.cam_new_game_camera.next_camera_mode	= CAMERA_MODE_NONE;
	g_game.interface_properties.cam_new_game_camera.script_length		= camera.camera_script_length_default;
}