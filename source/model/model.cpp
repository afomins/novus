


#include	"main\main.h"
#include	"model\model.h"
#include	"texture\texture.h"

#include	<math.h>


void	model_create(model_instance	*model)
{
	if(g_model.model_num == 0)
	{
		model->next		= NULL;
		model->prev		= NULL;

		g_model.first	= model;
		g_model.last	= model;
	}
	else
	{
		model->next		= NULL;
		model->prev		= g_model.last;

		g_model.last->next	= model;
		g_model.last		= model;
	}

	model->triangle_num	=	0;
	model->vertex_num	=	0;
	model->line_num		=	0;

	g_model.model_num++;
}

void	model_delete(model_instance *model)
{
	if(g_model.model_num	==	0)		return;

	if(g_model.model_num	==	1)
	{
		g_model.first	=	NULL;
		g_model.last	=	NULL;
	}
	else
	if(g_model.first == model)
	{
		g_model.first		=	model->next;
		g_model.first->prev	=	NULL;
	}
	else
	if(g_model.last	==	model)
	{
		g_model.last		=	model->prev;
		g_model.last->next	=	NULL;
	}
	else
	{
		model->next->prev	=	model->prev;
		model->prev->next	=	model->next;
	}

	model_triangle_delete_all(model);
	model_vertex_delete_all(model);
	model_line_delete_all(model);

	g_model.model_num--;

	delete	model;
}

void	model_delete_all()
{
	model_instance	*model;

	while(g_model.model_num	!=	0)
	{
		model	=	g_model.first;
		model_delete(model);
	}
}

void	model_draw(model_instance *model, float x, float y, float z, float r, float g, float b, float a, unsigned short tex_id)
{
	if(g_model.triangle_on)
	{
		model_triangle_draw(model,	x, y, z, 
									r, g, b, a, tex_id);
	}

	if(g_model.vertex_on)
	{
		model_vertex_draw(model,	x, y, z, 
									r, g, b, a);
	}

	if(g_model.line_on)
	{
		model_line_draw(model, x, y, z);
	}
}


