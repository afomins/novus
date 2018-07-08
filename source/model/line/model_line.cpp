


#include	"main\main.h"
#include	"model\model.h"
#include	"texture\texture.h"

void	model_line_create(model_instance	*model, model_line_instance *line, 
								model_vertex_instance *v0,
								model_vertex_instance *v1)
{
	if(model->line_num == 0)
	{
		line->next		= NULL;
		line->prev		= NULL;

		model->line_first	= line;
		model->line_last	= line;
	}
	else
	{
		line->next		= NULL;
		line->prev		= model->line_last;

		model->line_last->next	= line;
		model->line_last		= line;
	}

	line->vertex[0]	=	v0;
	line->vertex[1]	=	v1;

	model->line_num++;
}

void	model_line_update(model_line_instance *line, model_vertex_instance *v0, model_vertex_instance *v1)
{
	line->vertex[0]	=	v0;
	line->vertex[1]	=	v1;
}

void	model_line_delete(model_instance *model, model_line_instance *line)
{
	if(model->line_num	==	0)		return;

	if(model->line_num	==	1)
	{
		model->line_first	=	NULL;
		model->line_last	=	NULL;
	}
	else
	if(model->line_first	== line)
	{
		model->line_first		=	line->next;
		model->line_first->prev	=	NULL;
	}
	else
	if(model->line_last	==	line)
	{
		model->line_last		=	line->prev;
		model->line_last->next	=	NULL;
	}
	else
	{
		line->next->prev	=	line->prev;
		line->prev->next	=	line->next;
	}

	model->line_num--;

	delete	line;
}

void	model_line_delete_all(model_instance *model)
{
	model_line_instance	*line;

	while(model->line_num	!=	0)
	{
		line	=	model->line_first;
		model_line_delete(model, line);
	}
}

void	model_line_draw(model_instance *model, float x, float y, float z)
{
	unsigned short			loop;
	model_line_instance		*line;

	glLineWidth(g_model.line_size);

	glColor4f(	g_model.color_line.r,
				g_model.color_line.g,
				g_model.color_line.b,
				g_model.color_line.a);

	line	=	model->line_first;

	glEnable(GL_LINE_SMOOTH);

	glBegin(GL_LINES);
		for(loop = 0; loop < model->line_num; loop++)
		{
			glVertex3f(	x + line->vertex[0]->x + line->vertex[0]->off_x,
						y + line->vertex[0]->y + line->vertex[0]->off_y,
						z + line->vertex[0]->z + line->vertex[0]->off_z);

			glVertex3f(	x + line->vertex[1]->x + line->vertex[1]->off_x,
						y + line->vertex[1]->y + line->vertex[1]->off_y,
						z + line->vertex[1]->z + line->vertex[1]->off_z);

			line	=	line->next;
		}
	glEnd();

	glLineWidth(1.0);

	glDisable(GL_LINE_SMOOTH);
}

void	model_line_color_create(float r, float g, float b, float a)
{
	g_model.color_line.r	=	r;
	g_model.color_line.g	=	g;
	g_model.color_line.b	=	b;
	g_model.color_line.a	=	a;
}
