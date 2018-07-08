


#define		CAMERA_MODE_NONE			0
#define		CAMERA_MODE_ROTATE			1
#define		CAMERA_MODE_FREELOOK		2
#define		CAMERA_MODE_SCRIPT			3
#define		CAMERA_MODE_SCRIPT_ROTATE	4

#define		CAMERA_SCRIPT_MODE_MIDDLE	1
#define		CAMERA_SCRIPT_MODE_NONE		2

#define		QUATER_ENABLE_2_3			0
#define		QUATER_ENABLE_3_0			1
#define		QUATER_ENABLE_0_1			2
#define		QUATER_ENABLE_1_2			3

struct	camera_freelook
{
	float				position_x;
	float				position_y;
	float				position_z;

	float				angle_h;
	float				angle_v;

	float				speed_mouse_walk;
	float				speed_mouse_rotate;

	float				speed_keyboard_walk;
	float				speed_keyboard_rotate;
};

struct	camera_rotate
{
	float				center_x;
	float				center_y;
	float				center_z;

	float				radius;

	float				angle_h;
	float				angle_v;

	float				speed_mouse_rotate;
	float				speed_keyboard_rotate;

	float				speed_mouse_walk;
	float				speed_keyboard_walk;

	float				speed_mouse_wheel;

	float				radius_max;
	float				radius_min;

	unsigned short		quater_enable;
};

struct	camera_script
{
	float				start_x;
	float				start_y;
	float				start_z;
	float				start_angle_h;
	float				start_angle_v;

	float				end_x;
	float				end_y;
	float				end_z;
	float				end_angle_h;
	float				end_angle_v;

	float				current_x;
	float				current_y;
	float				current_z;
	float				current_angle_h;
	float				current_angle_v;

	float				length_x;
	float				length_y;
	float				length_z;
	float				length_angle_h;
	float				length_angle_v;

	unsigned int		script_start;
	unsigned int		script_length;

	unsigned short		next_camera_mode;
};

struct	camera_script_rotate
{
	float				center_x;
	float				center_y;
	float				center_z;

	float				radius;

	float				angle_h;
	float				angle_v;

	float				speed_h;
	float				speed_v;
};

struct	camera_instance
{
	camera_freelook			freelook;
	camera_rotate			rotate;
	camera_script			script;
	camera_script_rotate	script_rotate;

	unsigned short			camera_mode;

	unsigned int			camera_script_length_default;

	bool					process;
};

extern	camera_instance		camera;


	//	***	[		]

void	camera_process();

	//	***	[	SCRIPT_ROTATE	]

void	camera_script_rotate_create(camera_script_rotate script_rot);
void	camera_script_rotate_speed_create(float speed_h, float speed_v);
void	camera_script_rotate_process();

	//	***	[	SCRIPT			]

void	camera_script_create(camera_script script);
void	camera_script_process();

	//	***	[	ROTATE			]

void	camera_rotate_create(camera_rotate rot);
void	camera_rotate_speed_create(float s_k_rotate, float s_k_walk, float s_m_rotate, float s_m_walk, float s_m_wheel);
void	camera_rotate_process();

	//	***	[	FREELOOK		]

void	camera_freelook_create(camera_freelook free);
void	camera_freelook_speed_create(float s_k_rotate, float s_k_walk, float s_m_rotate, float s_m_walk);
void	camera_freelook_process();

	//	***	[		]
