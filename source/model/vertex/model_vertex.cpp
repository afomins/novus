


#include	"main\main.h"
#include	"model\model.h"
#include	"texture\texture.h"

void	model_vertex_create(model_instance	*model, model_vertex_instance *vertex, 
							float x, float y, float z, 
							float off_x, float off_y, float off_z)
{
	if(model->vertex_num == 0)
	{
		vertex->next		= NULL;
		vertex->prev		= NULL;

		model->vertex_first	= vertex;
		model->vertex_last	= vertex;
	}
	else
	{
		vertex->next		= NULL;
		vertex->prev		= model->vertex_last;

		model->vertex_last->next	= vertex;
		model->vertex_last			= vertex;
	}

	vertex->x	=	x;
	vertex->y	=	y;
	vertex->z	=	z;

	vertex->off_x	=	off_x;
	vertex->off_y	=	off_y;
	vertex->off_z	=	off_z;

	model->vertex_num++;
}

void	model_vertex_update(model_vertex_instance *vertex, 
							float x, float y, float z)
{
	vertex->x	=	x;
	vertex->y	=	y;
	vertex->z	=	z;
}

void	model_vertex_delete(model_instance *model, model_vertex_instance *vertex)
{
	if(model->vertex_num	==	0)		return;

	if(model->vertex_num	==	1)
	{
		model->vertex_first	=	NULL;
		model->vertex_last	=	NULL;
	}
	else
	if(model->vertex_first	== vertex)
	{
		model->vertex_first			=	vertex->next;
		model->vertex_first->prev	=	NULL;
	}
	else
	if(model->vertex_last	==	vertex)
	{
		model->vertex_last			=	vertex->prev;
		model->vertex_last->next	=	NULL;
	}
	else
	{
		vertex->next->prev	=	vertex->prev;
		vertex->prev->next	=	vertex->next;
	}

	model->vertex_num--;

	delete	vertex;
}

void	model_vertex_delete_all(model_instance *model)
{
	model_vertex_instance	*vertex;

	while(model->vertex_num	!=	0)
	{
		vertex	=	model->vertex_first;
		model_vertex_delete(model, vertex);
	}
}

void	model_vertex_draw(model_instance *model, float x, float y, float z, float r, float g, float b, float a)
{
	unsigned short			loop;
	model_vertex_instance	*vertex;

	glPointSize(g_model.vertex_size);

	glColor4f(r, g, b, a);

	vertex	=	model->vertex_first;

	glBegin(GL_POINTS);
		for(loop = 0; loop < model->vertex_num; loop++)
		{
			glVertex3f(	x + vertex->x + vertex->off_x,
						y + vertex->y + vertex->off_y,
						z + vertex->z + vertex->off_z);

			vertex	=	vertex->next;
		}
	glEnd();

	glPointSize(1.0);
}
