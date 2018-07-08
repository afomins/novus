


#include	"main\main.h"
#include	"game\game.h"

#include	"math.h"

void	game_model_draw_all()
{
	if(g_game.model_table_plane.table_plane_on)		game_model_draw_table_plane();
	if(g_game.model_table_border.table_border_on)	game_model_draw_table_border();
	if(g_game.model_skybox.skybox_on)				game_model_draw_skybox();

	game_model_draw_puck();
}

void	game_model_draw_skybox()
{
	if(g_game.model_skybox_properties.light_on)
	{
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
	}
	else
	{
		glDisable(GL_LIGHTING);
		glDisable(GL_LIGHT0);
	}

	model_draw(g_game.model_skybox_properties.front, 
			   *g_game.model_skybox.x,
			   *g_game.model_skybox.y,
			   *g_game.model_skybox.z,
			   g_game.model_skybox.color.r,
			   g_game.model_skybox.color.g,
			   g_game.model_skybox.color.b,
			   g_game.model_skybox.color.a,
			   g_game.model_skybox.tex_id_front);

	model_draw(g_game.model_skybox_properties.back, 
			   *g_game.model_skybox.x,
			   *g_game.model_skybox.y,
			   *g_game.model_skybox.z,
			   g_game.model_skybox.color.r,
			   g_game.model_skybox.color.g,
			   g_game.model_skybox.color.b,
			   g_game.model_skybox.color.a,
			   g_game.model_skybox.tex_id_back);

	model_draw(g_game.model_skybox_properties.left, 
			   *g_game.model_skybox.x,
			   *g_game.model_skybox.y,
			   *g_game.model_skybox.z,
			   g_game.model_skybox.color.r,
			   g_game.model_skybox.color.g,
			   g_game.model_skybox.color.b,
			   g_game.model_skybox.color.a,
			   g_game.model_skybox.tex_id_left);

	model_draw(g_game.model_skybox_properties.right, 
			   *g_game.model_skybox.x,
			   *g_game.model_skybox.y,
			   *g_game.model_skybox.z,
			   g_game.model_skybox.color.r,
			   g_game.model_skybox.color.g,
			   g_game.model_skybox.color.b,
			   g_game.model_skybox.color.a,
			   g_game.model_skybox.tex_id_right);

	model_draw(g_game.model_skybox_properties.up, 
			   *g_game.model_skybox.x,
			   *g_game.model_skybox.y,
			   *g_game.model_skybox.z,
			   g_game.model_skybox.color.r,
			   g_game.model_skybox.color.g,
			   g_game.model_skybox.color.b,
			   g_game.model_skybox.color.a,
			   g_game.model_skybox.tex_id_up);

	model_draw(g_game.model_skybox_properties.down, 
			   *g_game.model_skybox.x,
			   *g_game.model_skybox.y,
			   *g_game.model_skybox.z,
			   g_game.model_skybox.color.r,
			   g_game.model_skybox.color.g,
			   g_game.model_skybox.color.b,
			   g_game.model_skybox.color.a,
			   g_game.model_skybox.tex_id_down);
}

void	game_model_draw_table_plane()
{
	if(g_game.model_table_plane_properties.light_on)
	{
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
	}
	else
	{
		glDisable(GL_LIGHTING);
		glDisable(GL_LIGHT0);
	}

	model_draw(g_game.model_table_plane_properties.model_plane, 
			   g_game.model_table_plane.coord.x,
			   g_game.model_table_plane.coord.y,
			   g_game.model_table_plane.coord.z,
			   g_game.model_table_plane.color.r,
			   g_game.model_table_plane.color.g,
			   g_game.model_table_plane.color.b,
			   g_game.model_table_plane.color.a,
			   g_game.model_table_plane.tex_id);
}

void	game_model_draw_table_border()
{
	if(g_game.model_table_border_properties.light_on)
	{
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
	}
	else
	{
		glDisable(GL_LIGHTING);
		glDisable(GL_LIGHT0);
	}

	model_draw(g_game.model_table_border_properties.model_border, 
			   g_game.model_table_border.coord.x,
			   g_game.model_table_border.coord.y,
			   g_game.model_table_border.coord.z,
			   g_game.model_table_border.color.r,
			   g_game.model_table_border.color.g,
			   g_game.model_table_border.color.b,
			   g_game.model_table_border.color.a,
			   g_game.model_table_border.tex_id);
}

void	game_model_draw_puck()
{
	unsigned short		loop_player;
	unsigned short		loop_puck;
	unsigned short		puck_type;
//	unsigned short		loop;

	for(loop_player = 0; loop_player < PLAYER_MAX_NUM; loop_player++)
	{
		if(g_game.player[loop_player].player_on)
		{
			for(loop_puck = 0; loop_puck < PUCK_MAX_NUM; loop_puck++)
			{
				if(g_game.player[loop_player].puck[loop_puck].puck_on)
				{
					puck_type	= g_game.player[loop_player].puck[loop_puck].puck_type;

					if(g_game.model_puck_properties[puck_type].light_on)
					{
						glEnable(GL_LIGHTING);
						glEnable(GL_LIGHT0);
					}
					else
					{
						glDisable(GL_LIGHTING);
						glDisable(GL_LIGHT0);
					}

					model_draw(g_game.model_puck_properties[puck_type].model_puck, 
							   g_game.player[loop_player].puck[loop_puck].coord.x,
							   g_game.player[loop_player].puck[loop_puck].coord.y,
							   g_game.player[loop_player].puck[loop_puck].coord.z,
							   g_game.player[loop_player].puck[loop_puck].color.r,
							   g_game.player[loop_player].puck[loop_puck].color.g,
							   g_game.player[loop_player].puck[loop_puck].color.b,
							   g_game.player[loop_player].puck[loop_puck].color.a,
			    			   g_game.player[loop_player].puck[loop_puck].tex_id);
				}
			}
		}
	}

	if(	(camera.camera_mode == CAMERA_MODE_ROTATE) &&
		(!g_game.game_motion_on))
	{
		glDisable(GL_LIGHTING);

		glColor4f(	g_game.player[g_game.player_active].color.r,
					g_game.player[g_game.player_active].color.g,
					g_game.player[g_game.player_active].color.b, 0.5);

		glLineWidth(2.0);

		glBegin(GL_LINES);
/*
		for(loop = 0; loop < 3; loop++)
		{
			if(g_game.aim_on[loop])
			{
				glVertex3f(	g_game.aim_start[loop].x,
							g_game.aim_start[loop].y,
							g_game.aim_start[loop].z);

				glVertex3f(	g_game.aim_start[loop].x + cos(g_game.aim_angle[loop]) * g_game.aim_length[loop],
							g_game.aim_start[loop].y,
							g_game.aim_start[loop].z + sin(g_game.aim_angle[loop]) * g_game.aim_length[loop]);
			}
		}
*/

			glVertex3f(	camera.rotate.center_x,
						camera.rotate.center_y,
						camera.rotate.center_z);

			glVertex3f(	camera.rotate.center_x + cos(camera.rotate.angle_h + PI) * g_game.player_push_strength,
						camera.rotate.center_y,
						camera.rotate.center_z + sin(camera.rotate.angle_h + PI) * g_game.player_push_strength);
		glEnd();

		glEnable(GL_LIGHTING);
	}
}