


#include	"game\game.h"
#include	"main\main.h"
#include	"texture\texture.h"
#include	"timer\timer.h"

#include	<math.h>


void	game_interface_button_process()
{
	unsigned short				loop;
	interface_window_instance	*w;
	interface_button_instance	*b;

	//	***	[	RESUME	]
	if(g_game.interface_properties.b_main_menu_resume_game->button_active)
	{
		//	***
			w	= g_game.interface_properties.w_main_menu;
			b	= w->button_first;

			for(loop = 0; loop < w->button_num; loop++)
			{
				b->button_active	= false;
				b	= b->next;
			}

			g_interface.cursor.cursor_on			= false;
			g_game.game_menu_on						= false;

			if(g_game.interface_properties.w_stat->window_on)
			{
				g_game.interface_properties.w_stat->fade_mode	= FADE_MODE_START;
				g_game.interface_properties.w_stat->window_on	= false;
			}

			if(g_game.interface_properties.w_game_result->window_on)	
			{
				g_game.interface_properties.w_game_result->window_on	= false;
				g_game.interface_properties.w_game_result->fade_mode	= FADE_MODE_START;
			}

			if(g_game.interface_properties.w_help->window_on)
			{
				g_game.interface_properties.w_help->fade_mode	= FADE_MODE_START;
				g_game.interface_properties.w_help->window_on	= false;
			}

		//	***

		g_game.interface_properties.w_main_menu->fade_mode		= FADE_MODE_START;
		g_game.interface_properties.w_game_screen->fade_mode	= FADE_MODE_START;
//		g_game.interface_properties.w_help->fade_mode			= FADE_MODE_START;

		g_game.camera_properties.rotate.quater_enable	= camera.rotate.quater_enable;

		g_game.camera_properties.rotate.angle_h		= camera.script_rotate.angle_h;
		g_game.camera_properties.rotate.angle_v		= camera.script_rotate.angle_v;
		g_game.camera_properties.rotate.radius		= camera.script_rotate.radius;
		g_game.camera_properties.rotate.center_x	= camera.script_rotate.center_x;
		g_game.camera_properties.rotate.center_y	= camera.script_rotate.center_y;
		g_game.camera_properties.rotate.center_z	= camera.script_rotate.center_z;
		camera_rotate_create(g_game.camera_properties.rotate);

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

	interface_button_instance	*player;
	interface_button_instance	*ai;

	//	***	[	NEW		]
	if(g_game.interface_properties.b_main_menu_new_game->button_press)
	{
		if(g_game.interface_properties.b_main_menu_new_game->button_active)
		{
			//	***	[	]
			w	= g_game.interface_properties.w_main_menu;
			b	= w->button_first;

			for(loop = 0; loop < w->button_num; loop++)
			{
				b->button_active	= false;
				b	= b->next;
			}

			if(g_game.interface_properties.w_stat->window_on)
			{
				g_game.interface_properties.w_stat->fade_mode	= FADE_MODE_START;
				g_game.interface_properties.w_stat->window_on	= false;
			}

			if(g_game.interface_properties.w_help->window_on)
			{
				g_game.interface_properties.w_help->fade_mode	= FADE_MODE_START;
				g_game.interface_properties.w_help->window_on	= false;
			}

			g_game.interface_properties.b_main_menu_new_game->button_active	= true;

			if(g_game.interface_properties.w_game_result->window_on)	
			{
				g_game.interface_properties.w_game_result->window_on	= false;
				g_game.interface_properties.w_game_result->fade_mode	= FADE_MODE_START;
			}
			
			//	***	[	new game window ]

			if(g_game.interface_properties.b_new_game_player_num2->button_active)
			{
				player	= g_game.interface_properties.b_new_game_player[2];
				ai		= g_game.interface_properties.b_new_game_ai[2];

				interface_button_color_normal_create(player, 0,	1.0, 0.3, 0.4, 1.0);
				interface_button_color_active_create(player, 0,	0.4, 0.4, 0.4, 1.0);
				interface_button_color_normal_create(player, 1,	1.0, 1.0, 1.0, 1.0);
				interface_button_color_active_create(player, 1,	1.0, 1.0, 0.0, 1.0);

				interface_button_color_normal_create(ai, 0,	1.0, 0.3, 0.4, 1.0);
				interface_button_color_active_create(ai, 0,	0.4, 0.4, 0.4, 0.0);
				interface_button_color_normal_create(ai, 1,	1.0, 1.0, 1.0, 1.0);
				interface_button_color_active_create(ai, 1,	1.0, 1.0, 0.0, 0.0);

				g_game.interface_properties.b_new_game_player[1]->color_active[0].a	= 0.0;
				g_game.interface_properties.b_new_game_player[1]->color_normal[0].a	= 0.0;
				g_game.interface_properties.b_new_game_player[1]->color_active[1].a	= 0.0;
				g_game.interface_properties.b_new_game_player[1]->color_normal[1].a	= 0.0;
				g_game.interface_properties.b_new_game_ai[1]->color_active[0].a	= 0.0;
				g_game.interface_properties.b_new_game_ai[1]->color_normal[0].a	= 0.0;
				g_game.interface_properties.b_new_game_ai[1]->color_active[1].a	= 0.0;
				g_game.interface_properties.b_new_game_ai[1]->color_normal[1].a	= 0.0;

				g_game.interface_properties.b_new_game_player[3]->color_active[0].a	= 0.0;
				g_game.interface_properties.b_new_game_player[3]->color_normal[0].a	= 0.0;
				g_game.interface_properties.b_new_game_player[3]->color_active[1].a	= 0.0;
				g_game.interface_properties.b_new_game_player[3]->color_normal[1].a	= 0.0;
				g_game.interface_properties.b_new_game_ai[3]->color_active[0].a	= 0.0;
				g_game.interface_properties.b_new_game_ai[3]->color_normal[0].a	= 0.0;
				g_game.interface_properties.b_new_game_ai[3]->color_active[1].a	= 0.0;
				g_game.interface_properties.b_new_game_ai[3]->color_normal[1].a	= 0.0;
			}

			if(g_game.interface_properties.b_new_game_player_num4->button_active)
			{
				player	= g_game.interface_properties.b_new_game_player[2];
				ai		= g_game.interface_properties.b_new_game_ai[2];

				interface_button_color_normal_create(player, 0,	0.4, 0.3, 1.0, 1.0);
				interface_button_color_active_create(player, 0,	0.4, 0.4, 0.4, 1.0);
				interface_button_color_normal_create(player, 1,	1.0, 1.0, 1.0, 1.0);
				interface_button_color_active_create(player, 1,	1.0, 1.0, 0.0, 1.0);

				interface_button_color_normal_create(ai, 0,	0.4, 0.3, 1.0, 1.0);
				interface_button_color_active_create(ai, 0,	0.4, 0.4, 0.4, 0.0);
				interface_button_color_normal_create(ai, 1,	1.0, 1.0, 1.0, 1.0);
				interface_button_color_active_create(ai, 1,	1.0, 1.0, 0.0, 0.0);

				g_game.interface_properties.b_new_game_player[1]->color_active[0].a	= 1.0;
				g_game.interface_properties.b_new_game_player[1]->color_normal[0].a	= 1.0;
				g_game.interface_properties.b_new_game_player[1]->color_active[1].a	= 1.0;
				g_game.interface_properties.b_new_game_player[1]->color_normal[1].a	= 1.0;
				g_game.interface_properties.b_new_game_ai[1]->color_active[0].a	= 0.0;
				g_game.interface_properties.b_new_game_ai[1]->color_normal[0].a	= 1.0;
				g_game.interface_properties.b_new_game_ai[1]->color_active[1].a	= 0.0;
				g_game.interface_properties.b_new_game_ai[1]->color_normal[1].a	= 1.0;

				g_game.interface_properties.b_new_game_player[3]->color_active[0].a	= 1.0;
				g_game.interface_properties.b_new_game_player[3]->color_normal[0].a	= 1.0;
				g_game.interface_properties.b_new_game_player[3]->color_active[1].a	= 1.0;
				g_game.interface_properties.b_new_game_player[3]->color_normal[1].a	= 1.0;
				g_game.interface_properties.b_new_game_ai[3]->color_active[0].a	= 0.0;
				g_game.interface_properties.b_new_game_ai[3]->color_normal[0].a	= 1.0;
				g_game.interface_properties.b_new_game_ai[3]->color_active[1].a	= 0.0;
				g_game.interface_properties.b_new_game_ai[3]->color_normal[1].a	= 1.0;
			}

			g_game.camera_properties.script	= g_game.interface_properties.cam_new_game_camera;

			game_camera_script_create();
		}
		else
		{
			g_game.interface_properties.b_main_menu_new_game->button_active	= false;

			g_game.interface_properties.w_new_game->fade_mode	= FADE_MODE_START;

			g_game.camera_properties.script.next_camera_mode	= CAMERA_MODE_SCRIPT_ROTATE;
			g_game.camera_properties.script.end_angle_h			= camera.script_rotate.angle_h + PI;
			g_game.camera_properties.script.end_angle_v			= -camera.script_rotate.angle_v;
													
			g_game.camera_properties.script.end_x				= camera.script_rotate.center_x + cos(camera.script_rotate.angle_h) * cos(camera.script_rotate.angle_v) * camera.script_rotate.radius;
			g_game.camera_properties.script.end_z				= camera.script_rotate.center_z + sin(camera.script_rotate.angle_h) * cos(camera.script_rotate.angle_v) * camera.script_rotate.radius;
			g_game.camera_properties.script.end_y				= camera.script_rotate.center_y + sin(camera.script_rotate.angle_v) * camera.script_rotate.radius;

			game_camera_script_create();
		}
	}

	//	***	[	new game window]

		//	***	[	go]

	if(	(g_game.interface_properties.b_new_game_go->button_press) &&
		(g_game.interface_properties.b_new_game_go->button_active))
	{
		g_game.interface_properties.w_main_menu->fade_mode		= FADE_MODE_START;
		g_game.interface_properties.w_new_game->fade_mode		= FADE_MODE_START;
		g_game.interface_properties.w_game_screen->fade_mode	= FADE_MODE_START;

		g_game.interface_properties.b_main_menu_new_game->button_active	= false;
		g_game.interface_properties.b_new_game_go->button_active		= false;

		g_game.game_menu_on				= false;
		g_game.game_on					= true;
		g_game.game_camera_script_on	= true;
		g_interface.cursor.cursor_on	= false;
		g_game.game_motion_on			= false;

		g_game.player[0].player_on		= false;
		g_game.player[1].player_on		= false;
		g_game.player[2].player_on		= false;
		g_game.player[3].player_on		= false;

		interface_button_color_normal_create(g_game.interface_properties.b_main_menu_resume_game, 0, 1.0, 1.0, 1.0, 1.0);
		interface_button_color_active_create(g_game.interface_properties.b_main_menu_resume_game, 0, 1.0, 1.0, 1.0, 0.7);
		interface_button_color_active_create(g_game.interface_properties.b_main_menu_resume_game, 1, 1.0, 1.0, 0.0, 0.3);

		g_game.interface_properties.b_main_menu_resume_game->button_lock	= false;

		g_game.player_active	= 0;

		if(g_game.interface_properties.b_new_game_player_num2->button_active)
		{
			game_player_create(0, "manny");
			game_player_color_create(0, 0.4, 0.3, 1.0, TEX_NONE);

			game_player_create(2, "hector");
			game_player_color_create(2, 1.0, 0.1, 0.1, TEX_NONE);

//			game_player_create(1, "meche");
//			game_player_color_create(1, 0.4, 0.3, 1.0, TEX_NONE);

//			game_player_create(3, "domino");
//			game_player_color_create(3, 1.0, 0.1, 0.1, TEX_NONE);

			game_player_sequence_create(2);

			g_game.player[0].team	= 0;
			g_game.player[2].team	= 1;
		}

		if(g_game.interface_properties.b_new_game_player_num4->button_active)
		{
			game_player_create(0, "manny");
			game_player_color_create(0, 0.4, 0.3, 1.0, TEX_NONE);

			game_player_create(1, "hector");
			game_player_color_create(1, 1.0, 0.1, 0.1, TEX_NONE);

			game_player_create(2, "meche");
			game_player_color_create(2, 0.4, 0.3, 1.0, TEX_NONE);

			game_player_create(3, "domino");
			game_player_color_create(3, 1.0, 0.1, 0.1, TEX_NONE);

			game_player_sequence_create(4);

			g_game.player[0].team	= 0;
			g_game.player[1].team	= 1;
			g_game.player[2].team	= 0;
			g_game.player[3].team	= 1;
		}



		g_game.player[g_game.player_active].puck[0].puck_on	= true;

		camera_rotate_create(g_game.player[g_game.player_active].camera_start);

		g_game.camera_properties.script.next_camera_mode	= CAMERA_MODE_ROTATE;
		g_game.camera_properties.script.end_angle_h			= g_game.player[g_game.player_active].camera_start.angle_h + PI;
		g_game.camera_properties.script.end_angle_v			= -g_game.player[g_game.player_active].camera_start.angle_v;
													
		g_game.camera_properties.script.end_x				= g_game.player[g_game.player_active].camera_start.center_x + cos(g_game.player[g_game.player_active].camera_start.angle_h) * cos(g_game.player[g_game.player_active].camera_start.angle_v) * g_game.player[g_game.player_active].camera_start.radius;
		g_game.camera_properties.script.end_z				= g_game.player[g_game.player_active].camera_start.center_z + sin(g_game.player[g_game.player_active].camera_start.angle_h) * cos(g_game.player[g_game.player_active].camera_start.angle_v) * g_game.player[g_game.player_active].camera_start.radius;
		g_game.camera_properties.script.end_y				= g_game.player[g_game.player_active].camera_start.center_y + sin(g_game.player[g_game.player_active].camera_start.angle_v) * g_game.player[g_game.player_active].camera_start.radius;

		camera.camera_mode	= CAMERA_MODE_NONE;
		game_camera_script_create();
	}



	//	***	[	select player number]

	if(g_game.interface_properties.b_new_game_player_num2->button_press)
	{
		g_game.interface_properties.b_new_game_player_num2->button_lock		= true;
		g_game.interface_properties.b_new_game_player_num2->button_active	= true;

		g_game.interface_properties.b_new_game_player_num4->button_lock		= false;
		g_game.interface_properties.b_new_game_player_num4->button_active	= false;

			player	= g_game.interface_properties.b_new_game_player[2];
			ai		= g_game.interface_properties.b_new_game_ai[2];

			interface_button_color_normal_create(player, 0,	1.0, 0.3, 0.4, 1.0);
			interface_button_color_active_create(player, 0,	0.4, 0.4, 0.4, 1.0);
			interface_button_color_normal_create(player, 1,	1.0, 1.0, 1.0, 1.0);
			interface_button_color_active_create(player, 1,	1.0, 1.0, 0.0, 1.0);

			interface_button_color_normal_create(ai, 0,	1.0, 0.3, 0.4, 1.0);
			interface_button_color_active_create(ai, 0,	0.4, 0.4, 0.4, 0.0);
			interface_button_color_normal_create(ai, 1,	1.0, 1.0, 1.0, 1.0);
			interface_button_color_active_create(ai, 1,	1.0, 1.0, 0.0, 0.0);

//		g_game.interface_properties.b_new_game_ai[1]->button_on	= false;
		g_game.interface_properties.b_new_game_ai[1]->fade_mode	= FADE_MODE_START;
		g_game.interface_properties.b_new_game_ai[1]->fade_way	= FADE_WAY_OUT;

//		g_game.interface_properties.b_new_game_player[1]->button_on	= false;
		g_game.interface_properties.b_new_game_player[1]->fade_mode	= FADE_MODE_START;
		g_game.interface_properties.b_new_game_player[1]->fade_way	= FADE_WAY_OUT;

//		g_game.interface_properties.b_new_game_ai[3]->button_on	= false;
		g_game.interface_properties.b_new_game_ai[3]->fade_mode	= FADE_MODE_START;
		g_game.interface_properties.b_new_game_ai[3]->fade_way	= FADE_WAY_OUT;

//		g_game.interface_properties.b_new_game_player[3]->button_on	= false;
		g_game.interface_properties.b_new_game_player[3]->fade_mode	= FADE_MODE_START;
		g_game.interface_properties.b_new_game_player[3]->fade_way	= FADE_WAY_OUT;


		g_game.interface_properties.b_new_game_player[1]->color_active[0].a	= 0.0;
		g_game.interface_properties.b_new_game_player[1]->color_normal[0].a	= 0.0;
		g_game.interface_properties.b_new_game_player[1]->color_active[1].a	= 0.0;
		g_game.interface_properties.b_new_game_player[1]->color_normal[1].a	= 0.0;
		g_game.interface_properties.b_new_game_ai[1]->color_active[0].a	= 0.0;
		g_game.interface_properties.b_new_game_ai[1]->color_normal[0].a	= 0.0;
		g_game.interface_properties.b_new_game_ai[1]->color_active[1].a	= 0.0;
		g_game.interface_properties.b_new_game_ai[1]->color_normal[1].a	= 0.0;

		g_game.interface_properties.b_new_game_player[3]->color_active[0].a	= 0.0;
		g_game.interface_properties.b_new_game_player[3]->color_normal[0].a	= 0.0;
		g_game.interface_properties.b_new_game_player[3]->color_active[1].a	= 0.0;
		g_game.interface_properties.b_new_game_player[3]->color_normal[1].a	= 0.0;
		g_game.interface_properties.b_new_game_ai[3]->color_active[0].a	= 0.0;
		g_game.interface_properties.b_new_game_ai[3]->color_normal[0].a	= 0.0;
		g_game.interface_properties.b_new_game_ai[3]->color_active[1].a	= 0.0;
		g_game.interface_properties.b_new_game_ai[3]->color_normal[1].a	= 0.0;
	}

	if(g_game.interface_properties.b_new_game_player_num4->button_press)
	{
		g_game.interface_properties.b_new_game_player_num4->button_lock		= true;
		g_game.interface_properties.b_new_game_player_num4->button_active	= true;

		g_game.interface_properties.b_new_game_player_num2->button_lock		= false;
		g_game.interface_properties.b_new_game_player_num2->button_active	= false;


			player	= g_game.interface_properties.b_new_game_player[2];
			ai		= g_game.interface_properties.b_new_game_ai[2];

			interface_button_color_normal_create(player, 0,	0.4, 0.3, 1.0, 1.0);
			interface_button_color_active_create(player, 0,	0.4, 0.4, 0.4, 1.0);
			interface_button_color_normal_create(player, 1,	1.0, 1.0, 1.0, 1.0);
			interface_button_color_active_create(player, 1,	1.0, 1.0, 0.0, 1.0);

			interface_button_color_normal_create(ai, 0,	0.4, 0.3, 1.0, 1.0);
			interface_button_color_active_create(ai, 0,	0.4, 0.4, 0.4, 0.0);
			interface_button_color_normal_create(ai, 1,	1.0, 1.0, 1.0, 1.0);
			interface_button_color_active_create(ai, 1,	1.0, 1.0, 0.0, 0.0);

		g_game.interface_properties.b_new_game_ai[1]->button_on	= false;
		g_game.interface_properties.b_new_game_ai[1]->fade_mode	= FADE_MODE_START;
		g_game.interface_properties.b_new_game_ai[1]->fade_way	= FADE_WAY_IN;

		g_game.interface_properties.b_new_game_player[1]->button_on	= false;
		g_game.interface_properties.b_new_game_player[1]->fade_mode	= FADE_MODE_START;
		g_game.interface_properties.b_new_game_player[1]->fade_way	= FADE_WAY_IN;

		g_game.interface_properties.b_new_game_ai[3]->button_on	= false;
		g_game.interface_properties.b_new_game_ai[3]->fade_mode	= FADE_MODE_START;
		g_game.interface_properties.b_new_game_ai[3]->fade_way	= FADE_WAY_IN;

		g_game.interface_properties.b_new_game_player[3]->button_on	= false;
		g_game.interface_properties.b_new_game_player[3]->fade_mode	= FADE_MODE_START;
		g_game.interface_properties.b_new_game_player[3]->fade_way	= FADE_WAY_IN;


		g_game.interface_properties.b_new_game_player[1]->color_active[0].a	= 1.0;
		g_game.interface_properties.b_new_game_player[1]->color_normal[0].a	= 1.0;
		g_game.interface_properties.b_new_game_player[1]->color_active[1].a	= 1.0;
		g_game.interface_properties.b_new_game_player[1]->color_normal[1].a	= 1.0;
		g_game.interface_properties.b_new_game_ai[1]->color_active[0].a	= 0.0;
		g_game.interface_properties.b_new_game_ai[1]->color_normal[0].a	= 1.0;
		g_game.interface_properties.b_new_game_ai[1]->color_active[1].a	= 0.0;
		g_game.interface_properties.b_new_game_ai[1]->color_normal[1].a	= 1.0;

		g_game.interface_properties.b_new_game_player[3]->color_active[0].a	= 1.0;
		g_game.interface_properties.b_new_game_player[3]->color_normal[0].a	= 1.0;
		g_game.interface_properties.b_new_game_player[3]->color_active[1].a	= 1.0;
		g_game.interface_properties.b_new_game_player[3]->color_normal[1].a	= 1.0;
		g_game.interface_properties.b_new_game_ai[3]->color_active[0].a	= 0.0;
		g_game.interface_properties.b_new_game_ai[3]->color_normal[0].a	= 1.0;
		g_game.interface_properties.b_new_game_ai[3]->color_active[1].a	= 0.0;
		g_game.interface_properties.b_new_game_ai[3]->color_normal[1].a	= 1.0;
	}

	//	***	[	stat tab]
	if(	(g_game.interface_properties.b_main_menu_stat->button_press) &&
		(g_game.interface_properties.w_stat->fade_mode	== FADE_MODE_NONE))
	{
		if(g_game.interface_properties.w_stat->window_on)
		{
			g_game.interface_properties.w_stat->fade_mode	= FADE_MODE_START;
			g_game.interface_properties.w_stat->window_on	= false;
		}
		else
		{
			g_game.interface_properties.w_stat->window_on	= true;
			g_game.interface_properties.w_stat->fade_mode	= FADE_MODE_START;

			game_load_statistic();
		}

			if(g_game.interface_properties.w_game_result->window_on)	
			{
				g_game.interface_properties.w_game_result->window_on	= false;
				g_game.interface_properties.w_game_result->fade_mode	= FADE_MODE_START;
			}

			if(g_game.interface_properties.w_help->window_on)
			{
				g_game.interface_properties.w_help->fade_mode	= FADE_MODE_START;
				g_game.interface_properties.w_help->window_on	= false;
			}
	}

	//	***	[	help]
	if(	(g_game.interface_properties.b_main_menu_help->button_press) &&
		(g_game.interface_properties.w_help->fade_mode	== FADE_MODE_NONE))
	{
		if(g_game.interface_properties.w_help->window_on)
		{
			g_game.interface_properties.w_help->fade_mode	= FADE_MODE_START;
			g_game.interface_properties.w_help->window_on	= false;
		}
		else
		{
			g_game.interface_properties.w_help->window_on	= true;
			g_game.interface_properties.w_help->fade_mode	= FADE_MODE_START;
		}

		if(g_game.interface_properties.w_help->window_on)	
		{
			g_game.interface_properties.w_help->window_on	= false;
			g_game.interface_properties.w_help->fade_mode	= FADE_MODE_START;
		}

		if(g_game.interface_properties.w_stat->window_on)
		{
			g_game.interface_properties.w_stat->fade_mode	= FADE_MODE_START;
			g_game.interface_properties.w_stat->window_on	= false;
		}
	}

	//	***	[	save game]
	if(g_game.interface_properties.b_main_menu_save_game->button_press)
	{
		//	***
			w	= g_game.interface_properties.w_main_menu;
			b	= w->button_first;

			for(loop = 0; loop < w->button_num; loop++)
			{
				b->button_active	= false;
				b	= b->next;
			}

			if(g_game.interface_properties.w_stat->window_on)
			{
				g_game.interface_properties.w_stat->fade_mode	= FADE_MODE_START;
				g_game.interface_properties.w_stat->window_on	= false;
			}

			if(g_game.interface_properties.w_game_result->window_on)	
			{
				g_game.interface_properties.w_game_result->window_on	= false;
				g_game.interface_properties.w_game_result->fade_mode	= FADE_MODE_START;
			}

		//	***

		game_save();
	}

	//	***	[	load game]
	if(g_game.interface_properties.b_main_menu_load_game->button_press)
	{
		//	***
			w	= g_game.interface_properties.w_main_menu;
			b	= w->button_first;

			for(loop = 0; loop < w->button_num; loop++)
			{
				b->button_active	= false;
				b	= b->next;
			}

		//	***

		game_load();

		g_game.game_on		= true;
		g_game.game_menu_on	= true;
	}

	//	***	[	EXIT	]
	if(g_game.interface_properties.b_main_menu_exit_game->button_active)
	{
		window.exit	= true;
	}
}