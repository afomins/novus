


#include	"game\game.h"
#include	"main\main.h"

#include	<math.h>

camera_instance		camera;

void	game_camera_init()
{
	g_game.game_camera_script_on		= true;
	camera.camera_script_length_default	= 1500;

	//	***	[	FREELOOK	]

	camera_freelook	*free			= &g_game.camera_properties.freelook;

	free->speed_keyboard_rotate		= 0.005;
	free->speed_keyboard_walk		= 0.05;
	free->speed_mouse_rotate		= 0.01;
	free->speed_mouse_walk			= 0.05;

	free->angle_h					= 0.0;
	free->angle_v					= 0.0;

	free->position_x				= 10.0;
	free->position_y				= 10.0;
	free->position_z				= -10.0;

	//	***	[	ROTATE		]

	camera_rotate	*rot			= &g_game.camera_properties.rotate;
		
	rot->speed_keyboard_rotate		= 0.003;
	rot->speed_keyboard_walk		= 0.01;
	rot->speed_mouse_rotate			= 0.005;
	rot->speed_mouse_walk			= 0.01;
	rot->speed_mouse_wheel			= 20.0;

	rot->angle_h					= PI / 4;
	rot->angle_v					= PI / 3;

	rot->center_x					= 0.0;
	rot->center_y					= 0.0;
	rot->center_z					= 0.0;

	rot->radius						= 50.0;
	rot->radius_max					= 80.0;
	rot->radius_min					= 3.0;

	//	***	[	SCRIPT_ROTATE	]

	camera_script_rotate	*s_rot	= &g_game.camera_properties.script_rotate;

	s_rot->center_x					= 0.0;
	s_rot->center_y					= 0.0;
	s_rot->center_z					= 0.0;

	s_rot->radius					= 50.0;

	s_rot->speed_h					= 0.0001;
	s_rot->speed_v					= 0.0;

	s_rot->angle_h					= 5 * PI / 4;
	s_rot->angle_v					= PI / 6;

	//	***	[	SCRIPT	]

	camera_script	*script			= &g_game.camera_properties.script;

	script->start_angle_h			= 0;
	script->start_angle_v			= -PI / 3;

	script->start_x					= -100.0;
	script->start_y					= 80.0;
	script->start_z					= 10.0;

	script->end_angle_h				= s_rot->angle_h + PI;
	script->end_angle_v				= -s_rot->angle_v;
													
	script->end_x					= s_rot->center_x + cos(s_rot->angle_h) * cos(s_rot->angle_v) * s_rot->radius;
	script->end_z					= s_rot->center_z + sin(s_rot->angle_h) * cos(s_rot->angle_v) * s_rot->radius;
	script->end_y					= s_rot->center_y + sin(s_rot->angle_v) * s_rot->radius;

	script->next_camera_mode		= CAMERA_MODE_SCRIPT_ROTATE;
	script->script_length			= 7000;

	//	***	[	]

	camera_freelook_create(*free);
	camera_rotate_create(*rot);
	camera_script_rotate_create(*s_rot);
	camera_script_create(*script);

	//	***	[	]
}