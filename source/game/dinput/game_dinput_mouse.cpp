


#include	"main\main.h"
#include	"game\game.h"
#include	"dinput\dinput.h"

void	game_dinput_mouse_init()
{
	//	***	[	ROTATE			]

	g_game.dinput_mouse_properties.rot_invert_x_axis	= 1;
	g_game.dinput_mouse_properties.rot_invert_y_axis	= 1;
	g_game.dinput_mouse_properties.rot_invert_z_axis	= 1;

	g_game.dinput_mouse_properties.rot_sensitivity_x	= 1;
	g_game.dinput_mouse_properties.rot_sensitivity_y	= 1;

	g_game.dinput_mouse_properties.rot_move_puck		= m_RBUTTON;

	//	***	[	FREELOOK		]

	g_game.dinput_mouse_properties.free_invert_x_axis	= 1;
	g_game.dinput_mouse_properties.free_invert_y_axis	= 1;

	g_game.dinput_mouse_properties.free_sensitivity_x	= 1;
	g_game.dinput_mouse_properties.free_sensitivity_y	= 1;

	g_game.dinput_mouse_properties.free_move_up			= m_RBUTTON;
	g_game.dinput_mouse_properties.free_move_down		= m_NONE;
}