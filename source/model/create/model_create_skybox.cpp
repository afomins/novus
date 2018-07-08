


#include	"main\main.h"
#include	"model\model.h"
#include	"texture\texture.h"

void	model_create_skybox_front(float width)
{
	width	/=	2;

	const unsigned short	vertex_num		=	4;
	const unsigned short	triangle_num	=	2;
	unsigned short			loop;
	
	model_instance			*skybox_front;
	model_vertex_instance	*v[vertex_num];
	model_triangle_instance	*t[triangle_num];

		//	***	[	MODEL	]

	skybox_front	=	new	model_instance;

	model_create(skybox_front);

		//	***	[	VERTEX	]

	for(loop = 0; loop < vertex_num; loop++)
	{
		v[loop]	=	new model_vertex_instance;
	}

	model_vertex_create(skybox_front,	v[0],	-width,	-width,	width,	0.0,	0.0,	0.0);
	model_vertex_create(skybox_front,	v[1],	width,	-width,	width,	0.0,	0.0,	0.0);
	model_vertex_create(skybox_front,	v[2],	width,	width,	width,	0.0,	0.0,	0.0);
	model_vertex_create(skybox_front,	v[3],	-width,	width,	width,	0.0,	0.0,	0.0);

		//	***	[	TRIANGLE	]

	for(loop = 0; loop < triangle_num; loop++)
	{
		t[loop]	=	new model_triangle_instance;
	}

	model_triangle_create(skybox_front,		t[0],	v[0],	v[1],	v[2]);
	model_triangle_tex_coord_create(t[0],	0,	0.0,	0.0);
	model_triangle_tex_coord_create(t[0],	1,	1.0,	0.0);
	model_triangle_tex_coord_create(t[0],	2,	1.0,	1.0);

	model_triangle_create(skybox_front,		t[1],	v[0],	v[2],	v[3]);
	model_triangle_tex_coord_create(t[1],	0,	0.0,	0.0);
	model_triangle_tex_coord_create(t[1],	1,	1.0,	1.0);
	model_triangle_tex_coord_create(t[1],	2,	0.0,	1.0);
}

void	model_create_skybox_back(float width)
{
	width	/=	2;

	const unsigned short	vertex_num		=	4;
	const unsigned short	triangle_num	=	2;
	unsigned short			loop;
	
	model_instance			*skybox_back;
	model_vertex_instance	*v[vertex_num];
	model_triangle_instance	*t[triangle_num];

		//	***	[	MODEL	]

	skybox_back	=	new	model_instance;

	model_create(skybox_back);

		//	***	[	VERTEX	]

	for(loop = 0; loop < vertex_num; loop++)
	{
		v[loop]	=	new model_vertex_instance;
	}

	model_vertex_create(skybox_back,	v[1],	-width,	-width,	-width,	0.0,	0.0,	0.0);
	model_vertex_create(skybox_back,	v[0],	width,	-width,	-width,	0.0,	0.0,	0.0);
	model_vertex_create(skybox_back,	v[3],	width,	width,	-width,	0.0,	0.0,	0.0);
	model_vertex_create(skybox_back,	v[2],	-width,	width,	-width,	0.0,	0.0,	0.0);

		//	***	[	TRIANGLE	]

	for(loop = 0; loop < triangle_num; loop++)
	{
		t[loop]	=	new model_triangle_instance;
	}

	model_triangle_create(skybox_back,		t[0],	v[0],	v[1],	v[2]);
	model_triangle_tex_coord_create(t[0],	0,	0.0,	0.0);
	model_triangle_tex_coord_create(t[0],	1,	1.0,	0.0);
	model_triangle_tex_coord_create(t[0],	2,	1.0,	1.0);

	model_triangle_create(skybox_back,		t[1],	v[0],	v[2],	v[3]);
	model_triangle_tex_coord_create(t[1],	0,	0.0,	0.0);
	model_triangle_tex_coord_create(t[1],	1,	1.0,	1.0);
	model_triangle_tex_coord_create(t[1],	2,	0.0,	1.0);
}

void	model_create_skybox_left(float width)
{
	width	/=	2;

	const unsigned short	vertex_num		=	4;
	const unsigned short	triangle_num	=	2;
	unsigned short			loop;
	
	model_instance			*skybox_left;
	model_vertex_instance	*v[vertex_num];
	model_triangle_instance	*t[triangle_num];

		//	***	[	MODEL	]

	skybox_left	=	new	model_instance;

	model_create(skybox_left);

		//	***	[	VERTEX	]

	for(loop = 0; loop < vertex_num; loop++)
	{
		v[loop]	=	new model_vertex_instance;
	}

	model_vertex_create(skybox_left,	v[0],	-width,	-width,	-width,	0.0,	0.0,	0.0);
	model_vertex_create(skybox_left,	v[1],	-width,	-width,	width,	0.0,	0.0,	0.0);
	model_vertex_create(skybox_left,	v[2],	-width,	width,	width,	0.0,	0.0,	0.0);
	model_vertex_create(skybox_left,	v[3],	-width,	width,	-width,	0.0,	0.0,	0.0);

		//	***	[	TRIANGLE	]

	for(loop = 0; loop < triangle_num; loop++)
	{
		t[loop]	=	new model_triangle_instance;
	}

	model_triangle_create(skybox_left,		t[0],	v[0],	v[1],	v[2]);
	model_triangle_tex_coord_create(t[0],	0,	0.0,	0.0);
	model_triangle_tex_coord_create(t[0],	1,	1.0,	0.0);
	model_triangle_tex_coord_create(t[0],	2,	1.0,	1.0);

	model_triangle_create(skybox_left,		t[1],	v[0],	v[2],	v[3]);
	model_triangle_tex_coord_create(t[1],	0,	0.0,	0.0);
	model_triangle_tex_coord_create(t[1],	1,	1.0,	1.0);
	model_triangle_tex_coord_create(t[1],	2,	0.0,	1.0);
}

void	model_create_skybox_right(float width)
{
	width	/=	2;

	const unsigned short	vertex_num		=	4;
	const unsigned short	triangle_num	=	2;
	unsigned short			loop;
	
	model_instance			*skybox_right;
	model_vertex_instance	*v[vertex_num];
	model_triangle_instance	*t[triangle_num];

		//	***	[	MODEL	]

	skybox_right	=	new	model_instance;

	model_create(skybox_right);

		//	***	[	VERTEX	]

	for(loop = 0; loop < vertex_num; loop++)
	{
		v[loop]	=	new model_vertex_instance;
	}

	model_vertex_create(skybox_right,	v[1],	width,	-width,	-width,	0.0,	0.0,	0.0);
	model_vertex_create(skybox_right,	v[0],	width,	-width,	width,	0.0,	0.0,	0.0);
	model_vertex_create(skybox_right,	v[3],	width,	width,	width,	0.0,	0.0,	0.0);
	model_vertex_create(skybox_right,	v[2],	width,	width,	-width,	0.0,	0.0,	0.0);

		//	***	[	TRIANGLE	]

	for(loop = 0; loop < triangle_num; loop++)
	{
		t[loop]	=	new model_triangle_instance;
	}

	model_triangle_create(skybox_right,		t[0],	v[0],	v[1],	v[2]);
	model_triangle_tex_coord_create(t[0],	0,	0.0,	0.0);
	model_triangle_tex_coord_create(t[0],	1,	1.0,	0.0);
	model_triangle_tex_coord_create(t[0],	2,	1.0,	1.0);

	model_triangle_create(skybox_right,		t[1],	v[0],	v[2],	v[3]);
	model_triangle_tex_coord_create(t[1],	0,	0.0,	0.0);
	model_triangle_tex_coord_create(t[1],	1,	1.0,	1.0);
	model_triangle_tex_coord_create(t[1],	2,	0.0,	1.0);
}

void	model_create_skybox_up(float width)
{
	width	/=	2;

	const unsigned short	vertex_num		=	4;
	const unsigned short	triangle_num	=	2;
	unsigned short			loop;
	
	model_instance			*skybox_up;
	model_vertex_instance	*v[vertex_num];
	model_triangle_instance	*t[triangle_num];

		//	***	[	MODEL	]

	skybox_up	=	new	model_instance;

	model_create(skybox_up);

		//	***	[	VERTEX	]

	for(loop = 0; loop < vertex_num; loop++)
	{
		v[loop]	=	new model_vertex_instance;
	}

	model_vertex_create(skybox_up,	v[0],	-width,	width,	width,	0.0,	0.0,	0.0);
	model_vertex_create(skybox_up,	v[1],	width,	width,	width,	0.0,	0.0,	0.0);
	model_vertex_create(skybox_up,	v[2],	width,	width,	-width,	0.0,	0.0,	0.0);
	model_vertex_create(skybox_up,	v[3],	-width,	width,	-width,	0.0,	0.0,	0.0);

		//	***	[	TRIANGLE	]

	for(loop = 0; loop < triangle_num; loop++)
	{
		t[loop]	=	new model_triangle_instance;
	}

	model_triangle_create(skybox_up,		t[0],	v[0],	v[1],	v[2]);
	model_triangle_tex_coord_create(t[0],	0,	0.0,	0.0);
	model_triangle_tex_coord_create(t[0],	1,	1.0,	0.0);
	model_triangle_tex_coord_create(t[0],	2,	1.0,	1.0);

	model_triangle_create(skybox_up,		t[1],	v[0],	v[2],	v[3]);
	model_triangle_tex_coord_create(t[1],	0,	0.0,	0.0);
	model_triangle_tex_coord_create(t[1],	1,	1.0,	1.0);
	model_triangle_tex_coord_create(t[1],	2,	0.0,	1.0);
}

void	model_create_skybox_down(float width)
{
	width	/=	2;

	const unsigned short	vertex_num		=	4;
	const unsigned short	triangle_num	=	2;
	unsigned short			loop;
	
	model_instance			*skybox_down;
	model_vertex_instance	*v[vertex_num];
	model_triangle_instance	*t[triangle_num];

		//	***	[	MODEL	]

	skybox_down	=	new	model_instance;

	model_create(skybox_down);

		//	***	[	VERTEX	]

	for(loop = 0; loop < vertex_num; loop++)
	{
		v[loop]	=	new model_vertex_instance;
	}

	model_vertex_create(skybox_down,	v[3],	-width,	-width,	width,	0.0,	0.0,	0.0);
	model_vertex_create(skybox_down,	v[2],	width,	-width,	width,	0.0,	0.0,	0.0);
	model_vertex_create(skybox_down,	v[1],	width,	-width,	-width,	0.0,	0.0,	0.0);
	model_vertex_create(skybox_down,	v[0],	-width,	-width,	-width,	0.0,	0.0,	0.0);

		//	***	[	TRIANGLE	]

	for(loop = 0; loop < triangle_num; loop++)
	{
		t[loop]	=	new model_triangle_instance;
	}

	model_triangle_create(skybox_down,		t[0],	v[0],	v[1],	v[2]);
	model_triangle_tex_coord_create(t[0],	0,	0.0,	0.0);
	model_triangle_tex_coord_create(t[0],	1,	1.0,	0.0);
	model_triangle_tex_coord_create(t[0],	2,	1.0,	1.0);

	model_triangle_create(skybox_down,		t[1],	v[0],	v[2],	v[3]);
	model_triangle_tex_coord_create(t[1],	0,	0.0,	0.0);
	model_triangle_tex_coord_create(t[1],	1,	1.0,	1.0);
	model_triangle_tex_coord_create(t[1],	2,	0.0,	1.0);
}
