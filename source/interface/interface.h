


#define				HIGHLIGHT_MODE_NONE			0
#define				HIGHLIGHT_MODE_MIDDLE		1
#define				HIGHLIGHT_MODE_END			2

#define				HIGHLIGHT_WAY_DOWN			0
#define				HIGHLIGHT_WAY_UP			1

#define				FADE_MODE_START				0
#define				FADE_MODE_NONE				1
#define				FADE_MODE_MIDDLE			2

#define				FADE_WAY_IN					0
#define				FADE_WAY_OUT				1

#define				SCROLL_BAR_MODE_VERTICAL	0
#define				SCROLL_BAR_MODE_HORIZONTAL	1

struct	interface_color_instance
{
	float	r;
	float	g;
	float	b;
	float	a;
};

	//	***	[	cursor ]

struct	interface_cursor_instance
{
	bool						cursor_on;
	bool						shadow_on;

	unsigned short				tex_id;

	int							*x;
	int							*y;
	int							width;
	int							height;

	int							shadow_offset_x;
	int							shadow_offset_y;

	interface_color_instance	color_cursor;
	interface_color_instance	color_shadow;
};

	//	***	[	scroll_bar ]

struct	interface_scroll_bar_instance
{
	interface_scroll_bar_instance	*next;
	interface_scroll_bar_instance	*prev;

	unsigned short					scroll_bar_mode;

	bool							scroll_bar_on;

	bool							scroll_bar_press[4];
	bool							scroll_bar_select[4];

	int								x[4];
	int								y[4];
	int								width[4];
	int								height[4];

	unsigned short					tex_id[4][2];

	interface_color_instance		color_normal[4][2];
	interface_color_instance		color_active[4][2];
	interface_color_instance		color_current[4][2];

	unsigned int					highlight_length[4];
	unsigned int					highlight_current[4];
	unsigned int					highlight_start[4];

	unsigned short					highlight_mode[4];
	unsigned short					highlight_way[4];

	unsigned short					fade_mode;
	unsigned short					fade_way;

	unsigned int					fade_current;
	unsigned int					fade_length;
	unsigned int					fade_start;

	interface_color_instance		fade_color_start[4][2];
	interface_color_instance		fade_color_end[4][2];

	float							scroll_bar_step;
	float							scroll_bar_max;
	float							scroll_bar_min;
	float							scroll_bar_current;
};

	//	***	[	button ]

struct	interface_button_instance
{
	interface_button_instance	*next;
	interface_button_instance	*prev;

	bool						button_on;
	bool						button_press;
	bool						button_select;
	bool						button_active;
	bool						button_lock;

	int							x;
	int							y;
	int							width;
	int							height;

	unsigned short				tex_id[2];

	interface_color_instance	color_normal[2];
	interface_color_instance	color_active[2];
	interface_color_instance	color_current[2];

	unsigned int				highlight_length;
	unsigned int				highlight_current;
	unsigned int				highlight_start;

	unsigned short				highlight_mode;
	unsigned short				highlight_way;

	unsigned short				fade_mode;
	unsigned short				fade_way;

	unsigned int				fade_current;
	unsigned int				fade_length;
	unsigned int				fade_start;

	interface_color_instance	fade_color_start[2];
	interface_color_instance	fade_color_end[2];
};

	//	***	[	rectangle ]

struct	interface_rectangle_instance
{
	interface_rectangle_instance	*next;
	interface_rectangle_instance	*prev;

	bool							rectangle_on;

	int								x;
	int								y;
	int								width;
	int								height;

	unsigned short					tex_id;

	interface_color_instance		color_normal;
	interface_color_instance		color_current;

	unsigned short					fade_mode;
	unsigned short					fade_way;

	unsigned int					fade_current;
	unsigned int					fade_length;
	unsigned int					fade_start;

	interface_color_instance		fade_color_start;
	interface_color_instance		fade_color_end;
};

	//	***	[	window ]

struct	interface_window_instance
{
	interface_window_instance		*next;
	interface_window_instance		*prev;

	bool							window_on;
	bool							active_on;

	unsigned short					fade_mode;
	unsigned short					fade_way;

	interface_button_instance		*button_first;
	interface_button_instance		*button_last;
	unsigned short					button_num;

	interface_rectangle_instance	*rectangle_first;
	interface_rectangle_instance	*rectangle_last;
	unsigned short					rectangle_num;

	interface_scroll_bar_instance	*scroll_bar_first;
	interface_scroll_bar_instance	*scroll_bar_last;
	unsigned short					scroll_bar_num;
};

struct	interface_global_instance
{
	interface_cursor_instance		cursor;

	interface_window_instance		*window_first;
	interface_window_instance		*window_last;
	unsigned short					window_num;

	unsigned int					highlight_length_default;
	unsigned int					fade_length_default;
};

extern	interface_global_instance	g_interface;

	//	***	[	INTERFACE	]

void	interface_draw();
void	interface_process();
void	interface_delete();

void	interface_check_resolution(int x_from, int y_from, int x_to, int y_to);

	//	***	[	BUTTON		]

void	interface_button_create(interface_window_instance *window, interface_button_instance *button, int x, int y, int width, int height, unsigned short tex_id_0, unsigned short tex_id_1);
void	interface_button_delete(interface_window_instance *window, interface_button_instance *button);
void	interface_button_delete_all(interface_window_instance *window);
void	interface_button_draw(interface_window_instance *window);
void	interface_button_color_normal_create(interface_button_instance *button, unsigned short tex_id, float r, float g, float b, float a);
void	interface_button_color_active_create(interface_button_instance *button, unsigned short tex_id, float r, float g, float b, float a);
void	interface_button_select_process(interface_window_instance *window);
void	interface_button_highlight_process(interface_window_instance *window);
void	interface_button_fade_process(interface_window_instance *window);
void	interface_button_press_process(interface_window_instance *window);

	//	***	[	CURSOR		]

void	interface_cursor_create(int *x, int *y, int width, int height, unsigned short tex_id, bool shadow_on, int shadow_offset_x, int shadow_offset_y);
void	interface_cursor_color_create(float r, float g, float b, float a);
void	interface_cursor_shadow_color_create(float r, float g, float b, float a);
void	interface_cursor_draw();

	//	***	[	RECTANGLE	]

void	interface_rectangle_create(interface_window_instance *window, interface_rectangle_instance *rectangle, int x, int y, int width, int height, unsigned short tex_id);
void	interface_rectangle_delete(interface_window_instance *window, interface_rectangle_instance *rectangle);
void	interface_rectangle_delete_all(interface_window_instance *window);
void	interface_rectangle_draw(interface_window_instance *window);
void	interface_rectangle_color_normal_create(interface_rectangle_instance *rectangle, float r, float g, float b, float a) ;
void	interface_rectangle_fade_process(interface_window_instance *window);

	//	***	[	WINDOW		]

void	interface_window_create(interface_window_instance *window);
void	interface_window_delete(interface_window_instance *window);
void	interface_window_delete_all();
void	interface_window_draw();
void	interface_window_process();

	//	***	[	scroll_bar ]

void	interface_scroll_bar_create(interface_window_instance *window, interface_scroll_bar_instance *scroll_bar, unsigned short scroll_bar_mode, float scroll_start, float scroll_end, float scroll_step, float current);
void	interface_scroll_bar_element_create(interface_scroll_bar_instance *scroll_bar, unsigned short element_id, int x, int y, int width, int height, unsigned short tex_id_0, unsigned short tex_id_1);
void	interface_scroll_bar_delete(interface_window_instance *window, interface_scroll_bar_instance *scroll_bar);
void	interface_scroll_bar_delete_all(interface_window_instance *window);
void	interface_scroll_bar_draw(interface_window_instance *window);
void	interface_scroll_bar_color_normal_create(interface_scroll_bar_instance *scroll_bar, unsigned short element_id, unsigned short tex_id, float r, float g, float b, float a);
void	interface_scroll_bar_color_active_create(interface_scroll_bar_instance *scroll_bar, unsigned short element_id, unsigned short tex_id, float r, float g, float b, float a);
void	interface_scroll_bar_select_process(interface_window_instance *window);
void	interface_scroll_bar_highlight_process(interface_window_instance *window);
void	interface_scroll_bar_fade_process(interface_window_instance *window);
void	interface_scroll_bar_press_process(interface_window_instance *window);



