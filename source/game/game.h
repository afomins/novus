


#include		"model\model.h"
#include		"camera\camera.h"
#include		"interface\interface.h"

#define			PUCK_MAX_NUM					9
#define			PLAYER_MAX_NUM					4

#define			PUCK_TYPE_BIG					0
#define			PUCK_TYPE_SMALL					1


struct	game_statistic_instance
{
	int	player_win[PLAYER_MAX_NUM];
	int	player_loose[PLAYER_MAX_NUM];
};

struct	game_color_instance
{
	float					r;
	float					g;
	float					b;
	float					a;
};

struct	game_coord_instance
{
	float					x;
	float					y;
	float					z;
};

	//	***	[	MODEL_PUCK	]

struct	game_puck_properties
{
	model_instance			*model_puck;
	float					radius;
	float					height;
	float					mass;
	unsigned short			puck_detail;
	bool					light_on;
};

struct	game_puck_instance
{
	bool					puck_on;
	bool					puck_on_old;
	unsigned short			tex_id;
	unsigned short			puck_type;
	game_color_instance		color;

	game_coord_instance		coord;
	game_coord_instance		coord_new;
	game_coord_instance		coord_old;

	float					motion_angle;
	float					motion_angle_new;
	float					motion_speed;
	float					motion_speed_new;
};

	//	***	[	MODEL_TABLE_PLANE	]

struct	game_table_plane_properties
{
	model_instance			*model_plane;

	float					width;
	float					side_width;
	float					hole_radius;
	float					center_radius;
	unsigned short			hole_detail;
	unsigned short			center_detail;
	bool					light_on;

	game_coord_instance		hole[4];
};

struct	game_table_plane_instance
{
	bool					table_plane_on;
	unsigned short			tex_id;
	game_color_instance		color;
	game_coord_instance		coord;
};

	//	***	[	MODEL_TABLE_BORDER	]

struct	game_table_border_properties
{
	model_instance			*model_border;
	float					height1;
	float					height2;
	float					width1;
	float					width2;
	bool					light_on;
};

struct	game_table_border_instance
{
	bool					table_border_on;
	unsigned short			tex_id;
	game_color_instance		color;
	game_coord_instance		coord;
};

	//	***	[	MODEL_SKYBOX	]

struct	game_skybox_properties
{
	model_instance			*front;
	model_instance			*back;
	model_instance			*left;
	model_instance			*right;
	model_instance			*up;
	model_instance			*down;
	float					width;
	bool					light_on;
};

struct	game_skybox_instance
{
	bool					skybox_on;
	unsigned short			tex_id_front;
	unsigned short			tex_id_back;
	unsigned short			tex_id_left;
	unsigned short			tex_id_right;
	unsigned short			tex_id_up;
	unsigned short			tex_id_down;
	game_color_instance		color;
	float					*x;
	float					*y;
	float					*z;
};

	//	***	[	PLAYER		]

struct	game_player_instance
{
	bool					player_on;
	game_color_instance		color;
	unsigned short			texture_id;
	char					*name;
	game_puck_instance		puck[PUCK_MAX_NUM];

	camera_rotate			camera_start;

	unsigned short			player_next;

	float					score;

	unsigned short			team;
};

	//	***	[	DINPUT_MOUSE	]

struct	game_dinput_mouse_properties
{
	//	***	[	ROTATE			]

	short					rot_invert_x_axis;
	short					rot_invert_y_axis;
	short					rot_invert_z_axis;

	float					rot_sensitivity_x;
	float					rot_sensitivity_y;

	unsigned short			rot_move_puck;

	//	***	[	FREELOOK		]

	short					free_invert_x_axis;
	short					free_invert_y_axis;

	float					free_sensitivity_x;
	float					free_sensitivity_y;

	unsigned short			free_move_up;
	unsigned short			free_move_down;
};

struct	game_dinput_keyboard_properties
{
	//	***	[	ALL				]

	unsigned short			all_menu_on;
	unsigned short			all_quit_game;

	//	***	[	ROTATE			]

	short					rot_invert_x_axis;
	short					rot_invert_y_axis;

	unsigned short			rot_rotate_left;
	unsigned short			rot_rotate_right;
	unsigned short			rot_rotate_up;
	unsigned short			rot_rotate_down;

	unsigned short			rot_move_left;
	unsigned short			rot_move_right;

	unsigned short			rot_radius_inc;
	unsigned short			rot_radius_dec;

	unsigned short			rot_push_strength_inc;
	unsigned short			rot_push_strength_dec;

	unsigned short			rot_push;

	//	***	[	FREELOOK		]

	short					free_invert_x_axis;
	short					free_invert_y_axis;

	unsigned short			free_rotate_left;
	unsigned short			free_rotate_right;
	unsigned short			free_rotate_up;
	unsigned short			free_rotate_down;

	unsigned short			free_move_left;
	unsigned short			free_move_right;
	unsigned short			free_move_up;
	unsigned short			free_move_down;
	unsigned short			free_move_forward;
	unsigned short			free_move_backward;
};

	//	***	[	INTERFACE	]

struct	game_interface_properties
{
	interface_window_instance		*w_main_menu;
	interface_window_instance		*w_new_game;
	interface_window_instance		*w_game_screen;
	interface_window_instance		*w_stat;
	interface_window_instance		*w_game_result;
	interface_window_instance		*w_help;

	interface_button_instance		*b_main_menu_resume_game;
	interface_button_instance		*b_main_menu_new_game;
	interface_button_instance		*b_main_menu_exit_game;
	interface_button_instance		*b_main_menu_stat;
	interface_button_instance		*b_main_menu_load_game;
	interface_button_instance		*b_main_menu_save_game;
	interface_button_instance		*b_main_menu_help;

	interface_button_instance		*b_new_game_player_num2;
	interface_button_instance		*b_new_game_player_num4;

	interface_button_instance		*b_new_game_player[4];
	interface_button_instance		*b_new_game_ai[4];
	interface_button_instance		*b_new_game_go;

	interface_rectangle_instance	*r_strength_bar;
	int								r_strength_normal_height;

	interface_rectangle_instance	*r_name_bar_0;
	interface_rectangle_instance	*r_name_bar_1;
	int								r_mane_bar_normal_height;

	interface_rectangle_instance	*r_result_red;
	interface_rectangle_instance	*r_result_blue;

	camera_script					cam_new_game_camera;
};

struct	game_camera_properties
{
	camera_freelook			freelook;
	camera_rotate			rotate;
	camera_script			script;
	camera_script_rotate	script_rotate;
};

struct	save_game_instance
{
	bool					game_motion_on;

	camera_instance			camera;
	game_player_instance	player[PLAYER_MAX_NUM];
	unsigned short			player_active;
};

struct	game_global_instance
{
	//	***	[	GAME		]

	bool							game_on;
	bool							game_menu_on;
	bool							game_motion_on;
	bool							game_camera_script_on;

	game_coord_instance				aim_start[3];
	float							aim_on[3];
	float							aim_angle[3];
	float							aim_length[3];
	float							aim_total_length;

	game_statistic_instance			stat;
	
	//	***	[	PLAYER		]

	game_player_instance			player[PLAYER_MAX_NUM];
	unsigned short					player_active;
	float							player_push_strength;
	float							player_push_strength_max;
	float							player_push_strength_min;

	float							player_puck_min_speed;
	float							player_puck_max_speed;

	//	***	[	MODEL		]

	game_skybox_properties			model_skybox_properties;
	game_skybox_instance			model_skybox;

	game_table_plane_properties		model_table_plane_properties;
	game_table_plane_instance		model_table_plane;

	game_table_border_properties	model_table_border_properties;
	game_table_border_instance		model_table_border;

	game_puck_properties			model_puck_properties[2];

	//	***	[	DINPUT		]

	game_dinput_mouse_properties	dinput_mouse_properties;
	game_dinput_keyboard_properties	dinput_keyboard_properties;

	//	***	[	CAMERA		]

	game_camera_properties			camera_properties;

	//	***	[	INTERFACE	]

	game_interface_properties		interface_properties;

	//	***	[	PHIZIKS		]
};

extern	game_global_instance	g_game;


void	game_init();

	//	***	[	TABLE_PLANE		]

void	game_model_plane_properties_create(float width, float side_width, float hole_radius, unsigned short hole_detail, float center_radius, unsigned short center_detail, bool light_on);
void	game_model_plane_color_create(float r, float g, float b, float a, unsigned short tex_id);
void	game_model_plane_coord_create(float x, float y, float z);

	//	***	[	TABLE_BORDER	]

void	game_model_border_properties_create(float width1, float width2, float height1, float height2, bool light_on);
void	game_model_border_color_create(float r, float g, float b, float a, unsigned short tex_id);
void	game_model_border_coord_create(float x, float y, float z);

	//	***	[	PUCK			]

void	game_model_puck_properties_create(unsigned short puck_id, float radius, float height, float mass, unsigned short puck_detail, bool light_on);
void	game_model_puck_create(unsigned short player_id, unsigned short puck_id, unsigned short puck_type);
void	game_model_puck_color_create(unsigned short player_id, unsigned short puck_id, float r, float g, float b, float a, unsigned short tex_id);
void	game_model_puck_coord_create(unsigned short player_id, unsigned short puck_id, float x, float y, float z);

	//	***	[	SKYBOX			]

void	game_model_skybox_properties_create(float width, bool light_on);
void	game_model_skybox_create(unsigned short tex_id_front, unsigned short tex_id_back,
								 unsigned short tex_id_left,  unsigned short tex_id_right,
								 unsigned short tex_id_up,	  unsigned short tex_id_down);
void	game_model_skybox_color_create(float r, float g, float b, float a);
void	game_model_skybox_coord_create(float *x, float *y, float *z);

	//	***	[	DRAW			]

void	game_model_draw_all();
void	game_model_draw_skybox();
void	game_model_draw_table_plane();
void	game_model_draw_table_border();
void	game_model_draw_puck();

	//	***	[	PLAYER			]

void	game_player_create(unsigned short player_id, char *name);
void	game_player_color_create(unsigned short player_id, float r, float g, float b, unsigned short tex_id);
void	game_player_sequence_create(int player_num);

	//	***	[	CAMERA			]

void	game_camera_freelook_keyboard_process();
void	game_camera_freelook_mouse_process();
void	game_camera_rotate_keyboard_process();
void	game_camera_rotate_mouse_process();
void	game_camera_process();
void	game_camera_init();
void	game_camera_script_create();

	//	***	[	DINPUT			]

void	game_dinput_process();
void	game_dinput_keyboard_init();
void	game_dinput_mouse_init();

	//	***	[	INTERFACE		]

void	game_interface_init();
void	game_interface_button_process();
	
	//	***	[	GAME			]

void	game_process();

void	game_save_statistic(int win0, int win1, int win2, int win3);
void	game_load_statistic();
void	game_check_end_game();

void	game_save();
void	game_load();

	//	***	[	GAME_PHIZIKS	]

void	game_phiziks_process();
void	game_phiziks_push_puck(unsigned short player_id, unsigned short puck_id, float angle, float push_strength);
void	game_phiziks_puck_to_border_collision_process();
void	game_phiziks_puck_to_puck_collision_process();
void	game_phiziks_puck_speed_process();
void	game_phiziks_puck_hole_collision_process();
void	game_phiziks_aim_process();



