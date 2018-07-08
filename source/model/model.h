


#define			OFF		0.1

struct	model_color_instance
{
	float						r;
	float						g;
	float						b;
	float						a;
};

struct	model_vertex_instance
{
	model_vertex_instance		*next;
	model_vertex_instance		*prev;

	float						x;
	float						y;
	float						z;

	float						off_x;
	float						off_y;
	float						off_z;
};

struct	model_triangle_instance
{
	model_triangle_instance		*next;
	model_triangle_instance		*prev;

	model_vertex_instance		*vertex[3];

	float						tx[3];
	float						ty[3];

	float						normal_x;
	float						normal_y;
	float						normal_z;
};

struct	model_line_instance
{
	model_line_instance			*next;
	model_line_instance			*prev;

	model_vertex_instance		*vertex[2];

	model_color_instance		color;
};

struct	model_instance
{
	model_instance				*next;
	model_instance				*prev;

	model_vertex_instance		*vertex_first;
	model_vertex_instance		*vertex_last;
	unsigned short				vertex_num;

	model_triangle_instance		*triangle_first;
	model_triangle_instance		*triangle_last;
	unsigned short				triangle_num;

	model_line_instance			*line_first;
	model_line_instance			*line_last;
	unsigned short				line_num;
};

struct	model_global_instance
{
	model_instance				*first;
	model_instance				*last;
	unsigned short				model_num;

	bool						line_on;
	bool						vertex_on;
	bool						triangle_on;
	bool						triangle_normal_on;

	float						vertex_size;
	float						line_size;
	float						triangle_normal_width;
	float						triangle_normal_size;

	model_color_instance		color_triangle_normal;
	model_color_instance		color_line;
};

extern	model_global_instance	g_model;

	//	***	[	MODEL	]

void	model_create(model_instance	*model);
void	model_delete(model_instance *model);
void	model_delete_all();
void	model_draw(model_instance *model, float x, float y, float z, float r, float g, float b, float a, unsigned short tex_id);

	//	***	[	VERTEX	]

void	model_vertex_create(model_instance	*model, model_vertex_instance *vertex, float x, float y, float z, float off_x, float off_y, float off_z);
void	model_vertex_delete(model_instance *model, model_vertex_instance *vertex);
void	model_vertex_delete_all(model_instance *model);
void	model_vertex_draw(model_instance *model, float x, float y, float z, float r, float g, float b, float a);
void	model_vertex_update(model_vertex_instance *vertex, float x, float y, float z);

	//	***	[	LINE	]

void	model_line_create(model_instance	*model, model_line_instance *line, model_vertex_instance *v0, model_vertex_instance *v1);
void	model_line_delete(model_instance *model, model_line_instance *line);
void	model_line_delete_all(model_instance *model);
void	model_line_draw(model_instance *model, float x, float y, float z);
void	model_line_update(model_line_instance *line, float x, float y, float z);
void	model_line_color_create(float r, float g, float b, float a);

	//	***	[	TRIANGLE	]

void	model_triangle_create(model_instance *model, model_triangle_instance *triangle,	model_vertex_instance *v0, model_vertex_instance *v1, model_vertex_instance *v2);
void	model_triangle_delete(model_instance *model, model_triangle_instance *triangle);
void	model_triangle_delete_all(model_instance *model);
void	model_triangle_draw(model_instance *model, float x, float y, float z, float r, float g, float b, float a, unsigned short tex_id);
void	model_triangle_tex_coord_create(model_triangle_instance *triangle, unsigned short vertexID, float tx, float ty);
void	model_triangle_update(model_triangle_instance *triangle, model_vertex_instance *v0, model_vertex_instance *v1, model_vertex_instance *v2);
void	model_triangle_normal_create(model_triangle_instance *triangle);
void	model_triangle_color_normal_create(float r, float g, float b, float a);

	//	***	[	MODEL CREATE	]

void	model_create_skybox_front(float width);
void	model_create_skybox_back(float width);
void	model_create_skybox_left(float width);
void	model_create_skybox_right(float width);
void	model_create_skybox_up(float width);
void	model_create_skybox_down(float width);
void	model_create_plane(float width, float side_width, float hole_radius, unsigned short hole_detail, float center_radius, unsigned short center_detail);
void	model_create_border(float width1, float width2, float height1, float height2);
void	model_create_puck(float radius, float height, unsigned short puck_detail);

void	model_init();

