


#include	"main\main.h"
#include	"game\game.h"
#include	"dinput\dinput.h"

void	game_dinput_keyboard_init()
{
	//	***	[	ALL				]

	g_game.dinput_keyboard_properties.all_menu_on			= k_ESCAPE;
	g_game.dinput_keyboard_properties.all_quit_game			= k_F10;

	//	***	[	ROTATE			]

	g_game.dinput_keyboard_properties.rot_invert_x_axis		= 1;
	g_game.dinput_keyboard_properties.rot_invert_y_axis		= 1;

	g_game.dinput_keyboard_properties.rot_rotate_left		= k_LEFT;
	g_game.dinput_keyboard_properties.rot_rotate_right		= k_RIGHT;
	g_game.dinput_keyboard_properties.rot_rotate_up			= k_UP;
	g_game.dinput_keyboard_properties.rot_rotate_down		= k_DOWN;

	g_game.dinput_keyboard_properties.rot_move_left			= k_COMMA;
	g_game.dinput_keyboard_properties.rot_move_right		= k_PERIOD;

	g_game.dinput_keyboard_properties.rot_radius_inc		= k_PRIOR;
	g_game.dinput_keyboard_properties.rot_radius_dec		= k_NEXT;

	g_game.dinput_keyboard_properties.rot_push_strength_inc	= k_INSERT;
	g_game.dinput_keyboard_properties.rot_push_strength_dec	= k_DELETE;

	g_game.dinput_keyboard_properties.rot_push				= k_SPACE;

	//	***	[	FREELOOK		]

	g_game.dinput_keyboard_properties.free_invert_x_axis	= 1;
	g_game.dinput_keyboard_properties.free_invert_y_axis	= 1;

	g_game.dinput_keyboard_properties.free_rotate_left		= k_LEFT;
	g_game.dinput_keyboard_properties.free_rotate_right		= k_RIGHT;
	g_game.dinput_keyboard_properties.free_rotate_up		= k_UP;
	g_game.dinput_keyboard_properties.free_rotate_down		= k_DOWN;

	g_game.dinput_keyboard_properties.free_move_left		= k_S;
	g_game.dinput_keyboard_properties.free_move_right		= k_F;
	g_game.dinput_keyboard_properties.free_move_forward		= k_E;
	g_game.dinput_keyboard_properties.free_move_backward	= k_D;
	g_game.dinput_keyboard_properties.free_move_up			= k_T;
	g_game.dinput_keyboard_properties.free_move_down		= k_G;
}