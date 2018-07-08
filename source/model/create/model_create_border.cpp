


#include	"main\main.h"
#include	"model\model.h"
#include	"texture\texture.h"

void	model_create_border(float width1, float width2, float height1, float height2)
{
	const unsigned short	vertex_num_max		=	16;
	const unsigned short	triangle_num_max	=	26;
	unsigned short			loop;

	float					w1					=	width1;
	float					w2					=	width2;
	float					h1					=	height1;
	float					h2					=	height2;

	model_instance			*border;
	model_vertex_instance	*v[vertex_num_max];
	model_triangle_instance	*t[triangle_num_max];

	//	***	[	MODEL	]

	border	=	new	model_instance;

	model_create(border);

	//	***	[	VERTEX	]

	for(loop = 0; loop < vertex_num_max; loop++)
	{
		v[loop]	=	new	model_vertex_instance;
	}

	model_vertex_create(border, v[0],	-w1,	0,	-w1,	0,	0,	0);
	model_vertex_create(border, v[1],	w1,		0,	-w1,	0,	0,	0);
	model_vertex_create(border, v[2],	w1,		0,	w1,		0,	0,	0);
	model_vertex_create(border, v[3],	-w1,	0,	w1,		0,	0,	0);

	model_vertex_create(border, v[4],	-w1,	h1,	-w1,	0,	0,	0);
	model_vertex_create(border, v[5],	w1,		h1,	-w1,	0,	0,	0);
	model_vertex_create(border, v[6],	w1,		h1,	w1,		0,	0,	0);
	model_vertex_create(border, v[7],	-w1,	h1,	w1,		0,	0,	0);

	model_vertex_create(border, v[8],	-w1 - w2,	h1,	-w1 - w2,	0,	0,	0);
	model_vertex_create(border, v[9],	w1 + w2,	h1,	-w1 - w2,	0,	0,	0);
	model_vertex_create(border, v[10],	w1 + w2,	h1,	w1 + w2,	0,	0,	0);
	model_vertex_create(border, v[11],	-w1 - w2,	h1,	w1 + w2,	0,	0,	0);

	model_vertex_create(border, v[12],	-w1 - w2,	h1 - h2,	-w1 - w2,	0,	0,	0);
	model_vertex_create(border, v[13],	w1 + w2,	h1 - h2,	-w1 - w2,	0,	0,	0);
	model_vertex_create(border, v[14],	w1 + w2,	h1 - h2,	w1 + w2,	0,	0,	0);
	model_vertex_create(border, v[15],	-w1 - w2,	h1 - h2,	w1 + w2,	0,	0,	0);

	//	***	[	TRIANGLE	]

	for(loop = 0; loop < triangle_num_max; loop++)
	{
		t[loop]	=	new	model_triangle_instance;
	}

	model_triangle_create(border, t[0],	v[0],	v[4],	v[5]);
	model_triangle_create(border, t[1],	v[0],	v[5],	v[1]);
	model_triangle_create(border, t[2],	v[4],	v[8],	v[9]);
	model_triangle_create(border, t[3],	v[4],	v[9],	v[5]);
	model_triangle_create(border, t[4],	v[8],	v[12],	v[13]);
	model_triangle_create(border, t[5],	v[8],	v[13],	v[9]);

	model_triangle_create(border, t[6],	v[1],	v[5],	v[6]);
	model_triangle_create(border, t[7],	v[1],	v[6],	v[2]);
	model_triangle_create(border, t[8],	v[5],	v[9],	v[10]);
	model_triangle_create(border, t[9],	v[5],	v[10],	v[6]);
	model_triangle_create(border, t[10],v[9],	v[13],	v[14]);
	model_triangle_create(border, t[11],v[9],	v[14],	v[10]);

	model_triangle_create(border, t[12],v[2],	v[6],	v[7]);
	model_triangle_create(border, t[13],v[2],	v[7],	v[3]);
	model_triangle_create(border, t[14],v[6],	v[10],	v[11]);
	model_triangle_create(border, t[15],v[6],	v[11],	v[7]);
	model_triangle_create(border, t[16],v[10],	v[14],	v[15]);
	model_triangle_create(border, t[17],v[10],	v[15],	v[11]);

	model_triangle_create(border, t[18],v[3],	v[7],	v[4]);
	model_triangle_create(border, t[19],v[3],	v[4],	v[0]);
	model_triangle_create(border, t[20],v[7],	v[11],	v[8]);
	model_triangle_create(border, t[21],v[7],	v[8],	v[4]);
	model_triangle_create(border, t[22],v[11],	v[15],	v[12]);
	model_triangle_create(border, t[23],v[11],	v[12],	v[8]);

	model_triangle_create(border, t[24],v[12],	v[15],	v[14]);
	model_triangle_create(border, t[25],v[12],	v[14],	v[13]);

	//	***	[	TEXTURE COORDINATE	]
 
	model_triangle_instance	*triangle	=	border->triangle_first;

	while(triangle	!=	border->triangle_last)
	{
		for(loop = 0; loop < 3; loop++)
		{
			if(triangle->normal_y != 0)
			{
				model_triangle_tex_coord_create(	triangle, loop, 
													triangle->vertex[loop]->z / 20.0,	
													triangle->vertex[loop]->x / 20.0);
			}
			if(triangle->normal_z != 0)
			{
				model_triangle_tex_coord_create(	triangle, loop, 
													triangle->vertex[loop]->z / 20.0 - triangle->vertex[loop]->y / 20.0,	
													triangle->vertex[loop]->x / 20.0);
			}
			if(triangle->normal_x != 0)
			{
				model_triangle_tex_coord_create(	triangle, loop, 
													triangle->vertex[loop]->z / 20.0,	
													triangle->vertex[loop]->x / 20.0 + triangle->vertex[loop]->y / 20.0);
			}
		}

		triangle	=	triangle->next;
	}

		for(loop = 0; loop < 3; loop++)
		{
			if(triangle->normal_y != 0)
			{
				model_triangle_tex_coord_create(	triangle, loop, 
													triangle->vertex[loop]->z / 20.0,	
													triangle->vertex[loop]->x / 20.0);
			}
			if(triangle->normal_z != 0)
			{
				model_triangle_tex_coord_create(	triangle, loop, 
													triangle->vertex[loop]->z / 20.0 - triangle->vertex[loop]->y / 20.0,	
													triangle->vertex[loop]->x / 20.0);
			}
			if(triangle->normal_x != 0)
			{
				model_triangle_tex_coord_create(	triangle, loop, 
													triangle->vertex[loop]->z / 20.0,	
													triangle->vertex[loop]->x / 20.0 + triangle->vertex[loop]->y / 20.0);
			}
		}
}