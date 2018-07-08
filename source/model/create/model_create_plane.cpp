


#include	"main\main.h"
#include	"model\model.h"
#include	"texture\texture.h"

#include	<math.h>

void	model_create_plane(float width, float side_width, float hole_radius, unsigned short hole_detail, float center_radius, unsigned short center_detail)
{
	const unsigned short	vertex_num_max		=	200;
	const unsigned short	triangle_num_max	=	200;
	const unsigned short	line_num_max		=	100;
	float					w1					=	width;
	float					w2					=	side_width;
	unsigned short			loop;

	model_instance			*plane;
	model_vertex_instance	*v[vertex_num_max];
	model_triangle_instance	*t[triangle_num_max];
	model_line_instance		*l[line_num_max];

	//	***	[	MODEL	]

	plane	=	new	model_instance;

	model_create(plane);

	//	***	[	VERTEX	]

	for(loop = 0; loop < 25 + hole_detail * 4 + center_detail; loop++)
	{
		v[loop]	=	new	model_vertex_instance;
	}

	//	***	[	VERTEX MAIN	]

	model_vertex_create(plane,	v[0],	-w1 - w2,	0,	-w1 - w2,	OFF,	OFF,	OFF);
	model_vertex_create(plane,	v[1],	-w1,		0,	-w1 - w2,	0,		OFF,	OFF);
	model_vertex_create(plane,	v[2],	0,			0,	-w1 - w2,	0,		OFF,	OFF);
	model_vertex_create(plane,	v[3],	w1,			0,	-w1 - w2,	0,		OFF,	OFF);
	model_vertex_create(plane,	v[4],	w1 + w2,	0,	-w1 - w2,	-OFF,	OFF,	OFF);
	model_vertex_create(plane,	v[5],	w1 + w2,	0,	-w1,		-OFF,	OFF,	0);
	model_vertex_create(plane,	v[6],	w1 + w2,	0,	0,			-OFF,	OFF,	0);
	model_vertex_create(plane,	v[7],	w1 + w2,	0,	w1,			-OFF,	OFF,	0);
	model_vertex_create(plane,	v[8],	w1 + w2,	0,	w1 + w2,	-OFF,	OFF,	-OFF);
	model_vertex_create(plane,	v[9],	w1,			0,	w1 + w2,	0,		OFF,	-OFF);
	model_vertex_create(plane,	v[10],	0,			0,	w1 + w2,	0,		OFF,	-OFF);
	model_vertex_create(plane,	v[11],	-w1,		0,	w1 + w2,	0,		OFF,	-OFF);
	model_vertex_create(plane,	v[12],	-w1 - w2,	0,	w1 + w2,	OFF,	OFF,	-OFF);
	model_vertex_create(plane,	v[13],	-w1 - w2,	0,	w1,			OFF,	OFF,	0);
	model_vertex_create(plane,	v[14],	-w1 - w2,	0,	0,			OFF,	OFF,	0);
	model_vertex_create(plane,	v[15],	-w1 - w2,	0,	-w1,		OFF,	OFF,	0);

	model_vertex_create(plane,	v[16],	-w1,		0,	-w1,	0,	OFF,	0);
	model_vertex_create(plane,	v[17],	0,			0,	-w1,	0,	OFF,	0);
	model_vertex_create(plane,	v[18],	w1,			0,	-w1,	0,	OFF,	0);
	model_vertex_create(plane,	v[19],	w1,			0,	0,		0,	OFF,	0);
	model_vertex_create(plane,	v[20],	w1,			0,	w1,		0,	OFF,	0);
	model_vertex_create(plane,	v[21],	0,			0,	w1,		0,	OFF,	0);
	model_vertex_create(plane,	v[22],	-w1,		0,	w1,		0,	OFF,	0);
	model_vertex_create(plane,	v[23],	-w1,		0,	0,		0,	OFF,	0);

	model_vertex_create(plane,	v[24],	0,			0,	0,		0,	OFF,	0);

	//	***	[	VERTEX HOLE	]

	unsigned short		hole_id		=	0;
	unsigned short		vertex_id	=	25;
	float				c_x			=	0.0;
	float				c_y			=	0.0;
	float				c_z			=	0.0;
	float				angle		=	0.0;
	float				step		=	0.0;

	for(hole_id = 0; hole_id < 4; hole_id++)
	{
		if(hole_id	==	0)	
		{
			c_x	=	-w1 - w2 / 2.0;
			c_z	=	-w1 - w2 / 2.0;
		}

		if(hole_id	==	1)	
		{
			c_x	=	w1 + w2 / 2.0;
			c_z	=	-w1 - w2 / 2.0;
		}

		if(hole_id	==	2)	
		{
			c_x	=	w1 + w2 / 2.0;
			c_z	=	w1 + w2 / 2.0;
		}

		if(hole_id	==	3)	
		{
			c_x	=	-w1 - w2 / 2.0;
			c_z	=	w1 + w2 / 2.0;
		}

		step	=	2 * PI / hole_detail;

		for(loop = 0; loop < hole_detail; loop++)
		{
			model_vertex_create(	plane, v[vertex_id], 
									c_x + cos(angle) * hole_radius, c_y,
									c_z + sin(angle) * hole_radius,
									0,	OFF,	0);

			angle	+=	step;
			vertex_id++;
		}
	}

	//	***	[	VERTEX CENTER	]

	unsigned short	vertex_first	=	vertex_id;
	angle							=	0.0;
	step							=	2 * PI / center_detail;

	for(loop = 0; loop < center_detail; loop++)
	{
		model_vertex_create(	plane, v[vertex_id], 
								cos(angle) * center_radius, c_y,
								sin(angle) * center_radius,
								0,	OFF,	0);

		angle	+=	step;
		vertex_id++;
	}

	//	***	[	LINE	]

	for(loop = 0; loop < line_num_max; loop++)
	{
		l[loop]	=	new	model_line_instance;
	}

	//	***	[	LINE MAIN	]

//	model_line_create(plane, l[0],	v[0],	v[4]);
//	model_line_create(plane, l[1],	v[4],	v[8]);
//	model_line_create(plane, l[2],	v[8],	v[12]);
//	model_line_create(plane, l[3],	v[12],	v[0]);

	model_line_create(plane, l[4],	v[15],	v[5]);
	model_line_create(plane, l[5],	v[3],	v[9]);
	model_line_create(plane, l[6],	v[7],	v[13]);
	model_line_create(plane, l[7],	v[11],	v[1]);

	model_line_create(plane, l[8],	v[2],	v[17]);
	model_line_create(plane, l[9],	v[6],	v[19]);
	model_line_create(plane, l[10],	v[10],	v[21]);
	model_line_create(plane, l[11],	v[14],	v[23]);
	
	for(loop = 0; loop < (center_detail - 1); loop++)
	{
		model_line_create(plane, l[12 + loop], v[vertex_first + loop], v[vertex_first + loop + 1]);
	}

	model_line_create(plane, l[12 + loop],	v[vertex_first + loop],	v[vertex_first]);
	model_line_create(plane, l[13 + loop],	v[vertex_first + center_detail / 4],	v[vertex_first + 3 * center_detail / 4]);
	model_line_create(plane, l[14 + loop],	v[vertex_first + 2 * center_detail / 4],	v[vertex_first]);

	//	***	[	TRIANGLE	]

	for(loop = 0; loop < triangle_num_max; loop++)
	{
		t[loop]	=	new	model_triangle_instance;
	}

	//	***	[	TRIANGLE MAIN	]

	model_triangle_create(plane, t[0],	v[15],	v[22],	v[13]);
	model_triangle_create(plane, t[1],	v[15],	v[16],	v[22]);
	model_triangle_create(plane, t[2],	v[1],	v[9],	v[11]);
	model_triangle_create(plane, t[3],	v[1],	v[3],	v[9]);
	model_triangle_create(plane, t[4],	v[18],	v[7],	v[20]);
	model_triangle_create(plane, t[5],	v[18],	v[5],	v[7]);

	//	***	[	TRIANGLE HOLE	]

	unsigned short	quater_id		=	0;
	unsigned short	triangle_id		=	6;
	
	int	index;
	
	model_vertex_instance	*v0, *v1, *v2;
	model_vertex_instance	*a, *b, *c, *d;

	vertex_id	=	25;

	for(hole_id = 0; hole_id < 4; hole_id++)
	{
		if(hole_id	==	0)	{a	=	v[0];	b	=	v[1];	c	=	v[16];	d	=	v[15];}
		if(hole_id	==	1)	{a	=	v[3];	b	=	v[4];	c	=	v[5];	d	=	v[18];}
		if(hole_id	==	2)	{a	=	v[20];	b	=	v[7];	c	=	v[8];	d	=	v[9];}
		if(hole_id	==	3)	{a	=	v[13];	b	=	v[22];	c	=	v[11];	d	=	v[12];}

		for(quater_id = 0; quater_id < 4; quater_id++)
		{
			if(quater_id	==	0)	v0	=	c;
			if(quater_id	==	1)	v0	=	d;
			if(quater_id	==	2)	v0	=	a;
			if(quater_id	==	3)	v0	=	b;
			
			for(loop = 0; loop < hole_detail / 4; loop++)
			{
				index	=	vertex_id + hole_id * hole_detail + quater_id * hole_detail / 4 + loop + 1;	

				v1	=	v[index];
				v2	=	v[index - 1];

				model_triangle_create(plane, t[triangle_id], v0, v1, v2);

				triangle_id++;
			}
		}

		model_triangle_update(	t[triangle_id - 1], 
								b, 
								v[vertex_id + hole_id * hole_detail], 
								v[vertex_id + (hole_id + 1) * hole_detail - 1]);

		model_triangle_create(	plane,
								t[triangle_id],
								c, 
								d, 
								v[vertex_id + hole_id * hole_detail + 1 * hole_detail / 4]);

		model_triangle_create(	plane,
								t[triangle_id + 1],
								d, 
								a, 
								v[vertex_id + hole_id * hole_detail + 2 * hole_detail / 4]);

		model_triangle_create(	plane,
								t[triangle_id + 2],
								a, 
								b, 
								v[vertex_id + hole_id * hole_detail + 3 * hole_detail / 4]);

		model_triangle_create(	plane,
								t[triangle_id + 3],
								b, 
								c, 
								v[vertex_id + hole_id * hole_detail + 0 * hole_detail / 4]);

		triangle_id	+=	4;
	}

	//	***	[	TEXTURE COORDINATES	]

	model_triangle_instance	*triangle	=	plane->triangle_first;

	while(triangle	!=	plane->triangle_last)
	{
		for(loop = 0; loop < 3; loop++)
		{
			triangle->tx[loop]	=	triangle->vertex[loop]->x / (w1 * 2) + 0.5;
			triangle->ty[loop]	=	triangle->vertex[loop]->z / (w1 * 2) + 0.5;
		}

		triangle	=	triangle->next;
	}

	for(loop = 0; loop < 3; loop++)
	{
		triangle->tx[loop]	=	triangle->vertex[loop]->x / (w1 * 2) + 0.5;
		triangle->ty[loop]	=	triangle->vertex[loop]->z / (w1 * 2) + 0.5;
	}
}
