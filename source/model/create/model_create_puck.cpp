


#include	"main\main.h"
#include	"model\model.h"
#include	"texture\texture.h"

#include	<math.h>

void	model_create_puck(float radius, float height, unsigned short puck_detail)
{
	const unsigned short	vertex_num_max		=	32 * 2 + 2;
	const unsigned short	triangle_num_max	=	32 * 3;
	unsigned short			loop;

	model_instance			*puck;
	model_vertex_instance	*v[vertex_num_max];
	model_triangle_instance	*t[triangle_num_max];

	//	***	[	MODEL	]

	puck	=	new	model_instance;

	model_create(puck);

	//	***	[	VERTEX	]

	for(loop = 0; loop < puck_detail * 2 + 2; loop++)
	{
		v[loop]	=	new	model_vertex_instance;
	}

	model_vertex_create(puck, v[0],	0,	height / 2.0,	0,	0,	0,	0);
	model_vertex_create(puck, v[1],	0,	-height / 2.0,	0,	0,	0,	0);

	float	angle	=	0.0;
	float	step	=	2 * PI / puck_detail;

	for(loop = 0; loop < puck_detail; loop++)
	{
		model_vertex_create(puck, v[2 + loop], sin(angle) * radius, height / 2.0, cos(angle) * radius, 0.0, 0.0, 0.0);
		model_vertex_create(puck, v[2 + loop + puck_detail], sin(angle) * radius, -height / 2.0, cos(angle) * radius, 0.0, 0.0, 0.0);

		angle	+=	step;
	}

	//	***	[	TRIANGLE	]

	for(loop = 0; loop < puck_detail * 3; loop++)
	{
		t[loop]	=	new	model_triangle_instance;
	}

	for(loop = 0; loop < puck_detail - 1; loop++)
	{
		model_triangle_create(puck, t[loop], v[0], v[2 + loop + 1], v[2 + loop]);
	}
		model_triangle_create(puck, t[loop], v[0], v[2], v[2 + loop]);

	
	unsigned short	triangle_last	=	loop + 1;

	for(loop = 0; loop < puck_detail - 1; loop++)
	{
		model_triangle_create(puck, t[triangle_last + loop],				v[2 + loop],		v[2 + loop + 1],				v[2 + loop + puck_detail]);
		model_triangle_create(puck, t[triangle_last + puck_detail + loop],	v[2 + loop + 1],	v[2 + loop + 1 + puck_detail],	v[2 + loop + puck_detail]);
	}

		model_triangle_create(puck, t[triangle_last + loop],				v[2],	v[2 + loop + puck_detail], v[2 + puck_detail - 1]);

		model_triangle_create(puck, t[triangle_last + puck_detail + loop],	v[2],	v[2 + puck_detail],	v[2 + 2 * puck_detail - 1]);


		//	***	[	TEXTURE COORDINATES	]

	angle	=	0.0;
	
	for(loop = 0; loop < puck_detail; loop++)
	{
		model_triangle_tex_coord_create(t[loop],	0,	0.5,				0.5);
		model_triangle_tex_coord_create(t[loop],	1,	sin(angle),			cos(angle));
		model_triangle_tex_coord_create(t[loop],	2,	sin(angle - step),	cos(angle - step));

		angle	+=	step;
	}
}
