


#include	"main\main.h"
#include	"game\game.h"
#include	"texture\texture.h"

void	game_player_create(unsigned short player_id, char *name)
{
	unsigned short	loop;
	float			r;
	float			h;
	float			w1;
	float			w2;

	g_game.player[player_id].player_on	= true;
	g_game.player[player_id].name		= name;
	r									= g_game.model_puck_properties[PUCK_TYPE_SMALL].radius;
	h									= g_game.model_puck_properties[PUCK_TYPE_SMALL].height;
	w1									= g_game.model_table_plane_properties.width;
	w2									= g_game.model_table_plane_properties.side_width;

	g_game.player[player_id].score	= 0;

	if(player_id == 0)
	{
		for(loop = 1; loop < PUCK_MAX_NUM; loop++)
		{
			game_model_puck_create(player_id, loop, PUCK_TYPE_SMALL);
			game_model_puck_coord_create(player_id, loop, 
										 (-r * 2 * 1.1) * 4 + (r * 2 * 1.1) * loop - r * 1.1, 
										 h / 2.0, 
										 -w1 - w2 + (r * 2 * 1.1) / 2.0);
			g_game.player[player_id].puck[loop].motion_speed	= 0.0;
		}

		game_model_puck_create(player_id, 0, PUCK_TYPE_BIG);
		game_model_puck_coord_create(player_id, 0, 0.0, h / 2.0, -w1);
		g_game.player[player_id].puck[0].motion_speed	= 0.0;
		g_game.player[player_id].puck[0].puck_on	= false;

		g_game.player[player_id].camera_start	= g_game.camera_properties.rotate;

		g_game.player[player_id].camera_start.center_x	= 0.0;
		g_game.player[player_id].camera_start.center_y	= h / 2.0;
		g_game.player[player_id].camera_start.center_z	= -w1;
		g_game.player[player_id].camera_start.angle_h	= 3 * PI / 2;

		g_game.player[player_id].camera_start.quater_enable	= QUATER_ENABLE_2_3;
		g_game.player[player_id].team	= 0;
	}

	if(player_id == 1)
	{
		for(loop = 1; loop < PUCK_MAX_NUM; loop++)
		{
			game_model_puck_create(player_id, loop, PUCK_TYPE_SMALL);
			game_model_puck_coord_create(player_id, loop, 
										 w1 + w2 - (r * 2 * 1.1) / 2.0, 
										 h / 2.0, 
										 (-r * 2 * 1.1) * 4 + (r * 2 * 1.1) * loop - r * 1.1);

			g_game.player[player_id].puck[loop].motion_speed	= 0.0;
		}

		game_model_puck_create(player_id, 0, PUCK_TYPE_BIG);
		game_model_puck_coord_create(player_id, 0, w1, h / 2.0, 0.0);
		g_game.player[player_id].puck[0].motion_speed	= 0.0;
		g_game.player[player_id].puck[0].puck_on	= false;

		g_game.player[player_id].camera_start	= g_game.camera_properties.rotate;

		g_game.player[player_id].camera_start.center_x	= w1;
		g_game.player[player_id].camera_start.center_y	= h / 2.0;
		g_game.player[player_id].camera_start.center_z	= 0.0;
		g_game.player[player_id].camera_start.angle_h	= 0.0;

		g_game.player[player_id].camera_start.quater_enable	= QUATER_ENABLE_3_0;
		g_game.player[player_id].team	= 0;
	}

	if(player_id == 2)
	{
		for(loop = 1; loop < PUCK_MAX_NUM; loop++)
		{
			game_model_puck_create(player_id, loop, PUCK_TYPE_SMALL);
			game_model_puck_coord_create(player_id, loop, 
										 (-r * 2 * 1.1) * 4 + (r * 2 * 1.1) * loop - r * 1.1, 
										 h / 2.0, 
										 w1 + w2 - (r * 2 * 1.1) / 2.0);

			g_game.player[player_id].puck[loop].motion_speed	= 0.0;
		}

		game_model_puck_create(player_id, 0, PUCK_TYPE_BIG);
		game_model_puck_coord_create(player_id, 0, 0.0, h / 2.0, w1);
		g_game.player[player_id].puck[0].motion_speed	= 0.0;
		g_game.player[player_id].puck[0].puck_on	= false;

		g_game.player[player_id].camera_start	= g_game.camera_properties.rotate;

		g_game.player[player_id].camera_start.center_x	= 0.0;
		g_game.player[player_id].camera_start.center_y	= h / 2.0;
		g_game.player[player_id].camera_start.center_z	= w1;
		g_game.player[player_id].camera_start.angle_h	= PI / 2;

		g_game.player[player_id].camera_start.quater_enable	= QUATER_ENABLE_0_1;
		g_game.player[player_id].team	= 1;
	}

	if(player_id == 3)
	{
		for(loop = 1; loop < PUCK_MAX_NUM; loop++)
		{
			game_model_puck_create(player_id, loop, PUCK_TYPE_SMALL);
			game_model_puck_coord_create(player_id, loop, 
										 -w1 - w2 + (r * 2 * 1.1) / 2.0, 
										 h / 2.0, 
										 (-r * 2 * 1.1) * 4 + (r * 2 * 1.1) * loop - r * 1.1);
			g_game.player[player_id].puck[loop].motion_speed	= 0.0;
		}

		game_model_puck_create(player_id, 0, PUCK_TYPE_BIG);
		game_model_puck_coord_create(player_id, 0, -w1, h / 2.0, 0.0);
		g_game.player[player_id].puck[0].motion_speed	= 0.0;
		g_game.player[player_id].puck[0].puck_on	= false;

		g_game.player[player_id].camera_start	= g_game.camera_properties.rotate;

		g_game.player[player_id].camera_start.center_x	= -w1;
		g_game.player[player_id].camera_start.center_y	= h / 2.0;
		g_game.player[player_id].camera_start.center_z	= 0.0;
		g_game.player[player_id].camera_start.angle_h	= PI;

		g_game.player[player_id].camera_start.quater_enable	= QUATER_ENABLE_1_2;
		g_game.player[player_id].team	= 1;
	}
}

void	game_player_color_create(unsigned short player_id, float r, float g, float b, unsigned short tex_id)
{
	g_game.player[player_id].texture_id	= tex_id;
	g_game.player[player_id].color.r	= r;
	g_game.player[player_id].color.g	= g;
	g_game.player[player_id].color.b	= b;
	g_game.player[player_id].color.a	= 1.0;

	unsigned short loop;

	for(loop = 1; loop < PUCK_MAX_NUM; loop++)
	{
		game_model_puck_color_create(player_id, loop, r, g, b, 1.0, TEX_NONE);
	}

		game_model_puck_color_create(player_id, 0, r / 2.0, g / 2.0, b / 2.0, 1.0, TEX_NONE);
}

void	game_player_sequence_create(int player_num)
{
	if(player_num == 2)
	{
		g_game.player[0].player_next	= 2;
		g_game.player[2].player_next	= 0;
	}

	if(player_num == 4)
	{
		g_game.player[0].player_next	= 1;
		g_game.player[1].player_next	= 2;
		g_game.player[2].player_next	= 3;
		g_game.player[3].player_next	= 0;
	}
}