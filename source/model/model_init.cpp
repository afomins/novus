


#include	"main\main.h"
#include	"model\model.h"

model_global_instance	g_model;

void	model_init()
{
	g_model.model_num	=	0;

	g_model.line_on					=	true;
	g_model.triangle_on				=	true;
	g_model.vertex_on				=	false;
	g_model.triangle_normal_on		=	false;

	g_model.vertex_size				=	3.0;
	g_model.line_size				=	1.0;
	g_model.triangle_normal_size	=	2.0;
	g_model.triangle_normal_width	=	1.0;
/*
	model_create_skybox_front(250);
	model_create_skybox_back(250);
	model_create_skybox_left(250);
	model_create_skybox_right(250);
	model_create_skybox_up(250);
	model_create_skybox_down(250);

	model_create_plane(20, 5, 2, 8, 7, 16);
	model_create_border(25, 2, 2, 3);
	model_create_puck(0.5, 0.3, 12);
*/
	model_triangle_color_normal_create(0.9, 0.9, 0.0, 1.0);
	model_line_color_create(1.0, 1.0, 1.0, 0.6);
}