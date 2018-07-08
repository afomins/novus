


#include	"main\main.h"
#include	"model\model.h"
#include	"texture\texture.h"

#include	<math.h>

void	model_triangle_create(model_instance *model, model_triangle_instance *triangle, 
								model_vertex_instance *v0, 
								model_vertex_instance *v1,
								model_vertex_instance *v2)
{
	if(model->triangle_num == 0)
	{
		triangle->next		= NULL;
		triangle->prev		= NULL;

		model->triangle_first	= triangle;
		model->triangle_last	= triangle;
	}
	else
	{
		triangle->next		= NULL;
		triangle->prev		= model->triangle_last;

		model->triangle_last->next	= triangle;
		model->triangle_last		= triangle;
	}

	triangle->vertex[0]	=	v0;
	triangle->vertex[1]	=	v1;
	triangle->vertex[2]	=	v2;

	model_triangle_normal_create(triangle);

	model->triangle_num++;
}

void	model_triangle_update(model_triangle_instance *triangle, 
							  model_vertex_instance *v0, 
							  model_vertex_instance *v1, 
							  model_vertex_instance *v2)
{
	triangle->vertex[0]	=	v0;
	triangle->vertex[1]	=	v1;
	triangle->vertex[2]	=	v2;

	model_triangle_normal_create(triangle);
}

void	model_triangle_delete(model_instance *model, model_triangle_instance *triangle)
{
	if(model->triangle_num	==	0)		return;

	if(model->triangle_num	==	1)
	{
		model->triangle_first	=	NULL;
		model->triangle_last	=	NULL;
	}
	else
	if(model->triangle_first	== triangle)
	{
		model->triangle_first		=	triangle->next;
		model->triangle_first->prev	=	NULL;
	}
	else
	if(model->triangle_last	==	triangle)
	{
		model->triangle_last		=	triangle->prev;
		model->triangle_last->next	=	NULL;
	}
	else
	{
		triangle->next->prev	=	triangle->prev;
		triangle->prev->next	=	triangle->next;
	}

	model->triangle_num--;

	delete	triangle;
}

void	model_triangle_delete_all(model_instance *model)
{
	model_triangle_instance		*triangle;

	while(model->triangle_num	!=	0)
	{
		triangle	=	model->triangle_first;
		model_triangle_delete(model, triangle);
	}
}

void	model_triangle_draw(model_instance *model, float x, float y, float z, float r, float g, float b, float a, unsigned short tex_id)
{
	unsigned short			loop;
	model_triangle_instance	*triangle;

	glPointSize(1.0);

	triangle	=	model->triangle_first;

	if(tex_id != TEX_NONE)	glEnable(GL_TEXTURE_2D);

	glColor4f(r, g, b, a);

	for(loop = 0; loop < model->triangle_num; loop++)
	{
		glBindTexture(GL_TEXTURE_2D, tex[tex_id].texID);

		glBegin(GL_TRIANGLES);
			glNormal3f(triangle->normal_x, triangle->normal_y, triangle->normal_z);
			glTexCoord2f(triangle->tx[0], triangle->ty[0]);
			glVertex3f(	x + triangle->vertex[0]->x,
						y + triangle->vertex[0]->y,
						z + triangle->vertex[0]->z);

			glNormal3f(triangle->normal_x, triangle->normal_y, triangle->normal_z);
			glTexCoord2f(triangle->tx[1], triangle->ty[1]);
			glVertex3f(	x + triangle->vertex[1]->x,
						y + triangle->vertex[1]->y,
						z + triangle->vertex[1]->z);

			glNormal3f(triangle->normal_x, triangle->normal_y, triangle->normal_z);
			glTexCoord2f(triangle->tx[2], triangle->ty[2]);
			glVertex3f(	x + triangle->vertex[2]->x,
						y + triangle->vertex[2]->y,
						z + triangle->vertex[2]->z);
		glEnd();

		triangle	=	triangle->next;
	}

	glDisable(GL_TEXTURE_2D);

	triangle	=	model->triangle_first;

	glColor4f(	g_model.color_triangle_normal.r,
				g_model.color_triangle_normal.g,
				g_model.color_triangle_normal.b,
				g_model.color_triangle_normal.a);

	if(g_model.triangle_normal_on)
	{
		glDisable(GL_LIGHTING);
		glBegin(GL_LINES);

			glLineWidth(g_model.triangle_normal_size);
	
			for(loop = 0; loop < model->triangle_num; loop++)
			{
				glVertex3f(	x + (triangle->vertex[0]->x + triangle->vertex[1]->x + triangle->vertex[2]->x) / 3,
							y + (triangle->vertex[0]->y + triangle->vertex[1]->y + triangle->vertex[2]->y) / 3,
							z + (triangle->vertex[0]->z + triangle->vertex[1]->z + triangle->vertex[2]->z) / 3);

				glVertex3f(	x + g_model.triangle_normal_width * triangle->normal_x + (triangle->vertex[0]->x + triangle->vertex[1]->x + triangle->vertex[2]->x) / 3,
							y + g_model.triangle_normal_width * triangle->normal_y + (triangle->vertex[0]->y + triangle->vertex[1]->y + triangle->vertex[2]->y) / 3,
							z + g_model.triangle_normal_width * triangle->normal_z + (triangle->vertex[0]->z + triangle->vertex[1]->z + triangle->vertex[2]->z) / 3);

				triangle	=	triangle->next;
			}

			glLineWidth(1.0);

		glEnd();
		glEnable(GL_LIGHTING);
	}
}

void	model_triangle_tex_coord_create(model_triangle_instance *triangle, unsigned short vertexID, float tx, float ty)
{
	triangle->tx[vertexID]	=	tx;
	triangle->ty[vertexID]	=	ty;
}

void	model_triangle_normal_create(model_triangle_instance *triangle)
{
	model_vertex_instance	v0;
	model_vertex_instance	v1;

	float					lenght;

	v0.x	=	triangle->vertex[1]->x - triangle->vertex[0]->x;
	v0.y	=	triangle->vertex[1]->y - triangle->vertex[0]->y;
	v0.z	=	triangle->vertex[1]->z - triangle->vertex[0]->z;

	v1.x	=	triangle->vertex[2]->x - triangle->vertex[0]->x;
	v1.y	=	triangle->vertex[2]->y - triangle->vertex[0]->y;
	v1.z	=	triangle->vertex[2]->z - triangle->vertex[0]->z;

	triangle->normal_x	=	v0.y * v1.z - v0.z * v1.y;
	triangle->normal_y	=	v0.z * v1.x - v0.x * v1.z;
	triangle->normal_z	=	v0.x * v1.y - v0.y * v1.x;

	lenght	=	sqr(triangle->normal_x) + sqr(triangle->normal_y) + sqr(triangle->normal_z);
	lenght	=	sqrt(lenght);
	lenght	=	1 / lenght;

	triangle->normal_x	*=	-lenght;
	triangle->normal_y	*=	-lenght;
	triangle->normal_z	*=	-lenght;
}

void	model_triangle_color_normal_create(float r, float g, float b, float a)
{
	g_model.color_triangle_normal.r	=	r;
	g_model.color_triangle_normal.g	=	g;
	g_model.color_triangle_normal.b	=	b;
	g_model.color_triangle_normal.a	=	a;
}