


#include		"main\main.h"
#include		"game\game.h"


	//	***	[	TABLE_PLANE		]

void	game_model_plane_properties_create(float width, float side_width, float hole_radius, unsigned short hole_detail, float center_radius, unsigned short center_detail, bool light_on)
{
	model_create_plane(width, side_width, hole_radius, hole_detail, center_radius, center_detail);

	g_game.model_table_plane_properties.width			= width;
	g_game.model_table_plane_properties.side_width		= side_width;
	g_game.model_table_plane_properties.hole_radius		= hole_radius;
	g_game.model_table_plane_properties.hole_detail		= hole_detail;
	g_game.model_table_plane_properties.center_radius	= center_radius;
	g_game.model_table_plane_properties.center_detail	= center_detail;
	g_game.model_table_plane_properties.light_on		= light_on;
	g_game.model_table_plane_properties.model_plane		= g_model.last;

	g_game.model_table_plane_properties.hole[0].x		= -(width + side_width / 2.0);
	g_game.model_table_plane_properties.hole[0].z		= -(width + side_width / 2.0);

	g_game.model_table_plane_properties.hole[1].x		= (width + side_width / 2.0);
	g_game.model_table_plane_properties.hole[1].z		= -(width + side_width / 2.0);

	g_game.model_table_plane_properties.hole[2].x		= (width + side_width / 2.0);
	g_game.model_table_plane_properties.hole[2].z		= (width + side_width / 2.0);

	g_game.model_table_plane_properties.hole[3].x		= -(width + side_width / 2.0);
	g_game.model_table_plane_properties.hole[3].z		= (width + side_width / 2.0);
}

void	game_model_plane_color_create(float r, float g, float b, float a, unsigned short tex_id)
{
	g_game.model_table_plane.color.r	= r;
	g_game.model_table_plane.color.g	= g;
	g_game.model_table_plane.color.b	= b;
	g_game.model_table_plane.color.a	= a;
	g_game.model_table_plane.tex_id	= tex_id;
}

void	game_model_plane_coord_create(float x, float y, float z)
{
	g_game.model_table_plane.table_plane_on	= true;
	g_game.model_table_plane.coord.x			= x;
	g_game.model_table_plane.coord.y			= y;
	g_game.model_table_plane.coord.z			= z;
}

	//	***	[	TABLE_BORDER	]

void	game_model_border_properties_create(float width1, float width2, float height1, float height2, bool light_on)
{
	model_create_border(width1, width2, height1, height2);

	g_game.model_table_border_properties.height1		= height1;
	g_game.model_table_border_properties.height2		= height2;
	g_game.model_table_border_properties.width1		= width1;
	g_game.model_table_border_properties.width2		= width2;
	g_game.model_table_border_properties.light_on		= light_on;
	g_game.model_table_border_properties.model_border	= g_model.last;
}

void	game_model_border_color_create(float r, float g, float b, float a, unsigned short tex_id)
{
	g_game.model_table_border.color.r	= r;
	g_game.model_table_border.color.g	= g;
	g_game.model_table_border.color.b	= b;
	g_game.model_table_border.color.a	= a;
	g_game.model_table_border.tex_id	= tex_id;
}

void	game_model_border_coord_create(float x, float y, float z)
{
	g_game.model_table_border.table_border_on	= true;
	g_game.model_table_border.coord.x			= x;
	g_game.model_table_border.coord.y			= y;
	g_game.model_table_border.coord.z			= z;
}

	//	***	[	PUCK	]

void	game_model_puck_properties_create(unsigned short puck_type, float radius, float height, float mass, unsigned short puck_detail, bool light_on)
{
	model_create_puck(radius, height, puck_detail);

	g_game.model_puck_properties[puck_type].radius		= radius;
	g_game.model_puck_properties[puck_type].height		= height;
	g_game.model_puck_properties[puck_type].puck_detail	= puck_detail;
	g_game.model_puck_properties[puck_type].model_puck	= g_model.last;
	g_game.model_puck_properties[puck_type].light_on		= light_on;
	g_game.model_puck_properties[puck_type].mass			= mass;
}

void	game_model_puck_create(unsigned short player_id, unsigned short puck_id, unsigned short puck_type)
{
	g_game.player[player_id].puck[puck_id].puck_type	= puck_type;
}

void	game_model_puck_color_create(unsigned short player_id, unsigned short puck_id, float r, float g, float b, float a, unsigned short tex_id)
{
	g_game.player[player_id].puck[puck_id].color.r	= r;
	g_game.player[player_id].puck[puck_id].color.g	= g;
	g_game.player[player_id].puck[puck_id].color.b	= b;
	g_game.player[player_id].puck[puck_id].color.a	= a;
	g_game.player[player_id].puck[puck_id].tex_id	= tex_id;
}

void	game_model_puck_coord_create(unsigned short player_id, unsigned short puck_id, float x, float y, float z)
{
	g_game.player[player_id].puck[puck_id].puck_on	= true;
	g_game.player[player_id].puck[puck_id].coord.x	= x;
	g_game.player[player_id].puck[puck_id].coord.y	= y;
	g_game.player[player_id].puck[puck_id].coord.z	= z;

	g_game.player[player_id].puck[puck_id].coord_new.x	= x;
	g_game.player[player_id].puck[puck_id].coord_new.y	= y;
	g_game.player[player_id].puck[puck_id].coord_new.z	= z;
}

	//	***	[	SKYBOX	]

void	game_model_skybox_properties_create(float width, bool light_on)
{
	model_create_skybox_front(width);
	g_game.model_skybox_properties.front	= g_model.last;
	model_create_skybox_back(width);
	g_game.model_skybox_properties.back		= g_model.last;
	model_create_skybox_left(width);
	g_game.model_skybox_properties.left		= g_model.last;
	model_create_skybox_right(width);
	g_game.model_skybox_properties.right	= g_model.last;
	model_create_skybox_up(width);
	g_game.model_skybox_properties.up		= g_model.last;
	model_create_skybox_down(width);
	g_game.model_skybox_properties.down		= g_model.last;

	g_game.model_skybox_properties.width	= width;
	g_game.model_skybox_properties.light_on	= light_on;
}

void	game_model_skybox_create(unsigned short tex_id_front, unsigned short tex_id_back,
								 unsigned short tex_id_left,  unsigned short tex_id_right,
								 unsigned short tex_id_up,	  unsigned short tex_id_down)
{
	g_game.model_skybox.tex_id_front	= tex_id_front;
	g_game.model_skybox.tex_id_back	= tex_id_back;
	g_game.model_skybox.tex_id_left	= tex_id_left;
	g_game.model_skybox.tex_id_right	= tex_id_right;
	g_game.model_skybox.tex_id_up		= tex_id_up;
	g_game.model_skybox.tex_id_down	= tex_id_down;
}

void	game_model_skybox_color_create(float r, float g, float b, float a)
{
	g_game.model_skybox.color.r	= r;
	g_game.model_skybox.color.g	= g;
	g_game.model_skybox.color.b	= b;
	g_game.model_skybox.color.a	= a;
}

void	game_model_skybox_coord_create(float *x, float *y, float *z)
{
	g_game.model_skybox.skybox_on	= true;
	g_game.model_skybox.x			= x;
	g_game.model_skybox.y			= y;
	g_game.model_skybox.z			= z;
}
