


#include	"main\main.h"
#include	"game\game.h"
#include	"dinput\dinput.h"
#include	"timer\timer.h"

#include	"math.h"


void	game_camera_rotate_keyboard_process()
{
	//	***	[	ROTATE_CAMERA_LEFT	]
	if(keyboard.statuss[g_game.dinput_keyboard_properties.rot_rotate_left]		==	b_HOLD)
	{
		camera.rotate.angle_h		-=	camera.rotate.speed_keyboard_rotate * timerFrameLength;
		camera.process		=	true;
	}

	//	***	[	ROTATE_CAMERA_RIGHT	]
	if(keyboard.statuss[g_game.dinput_keyboard_properties.rot_rotate_right]	==	b_HOLD)
	{
		camera.rotate.angle_h		+=	camera.rotate.speed_keyboard_rotate * timerFrameLength;
		camera.process		=	true;
	}

	//	***	[	ROTATE_CAMERA_UP	]
	if(keyboard.statuss[g_game.dinput_keyboard_properties.rot_rotate_up]		==	b_HOLD)
	{
		camera.rotate.angle_v		+=	camera.rotate.speed_keyboard_rotate * timerFrameLength;
		camera.process		=	true;
	}

	//	***	[	ROTATE_CAMERA_DOWN	]
	if(keyboard.statuss[g_game.dinput_keyboard_properties.rot_rotate_down]		==	b_HOLD)
	{
		camera.rotate.angle_v		-=	camera.rotate.speed_keyboard_rotate * timerFrameLength;
		camera.process		=	true;
	}

	//	***	[	DECREASE_RADIUS	]
	if(keyboard.statuss[g_game.dinput_keyboard_properties.rot_radius_dec]	==	b_HOLD)
	{
		camera.rotate.radius		-=	camera.rotate.radius * camera.rotate.speed_keyboard_rotate * timerFrameLength;
		camera.process		=	true;
	}

	//	***	[	INCREASE_RADIUS	]
	if(keyboard.statuss[g_game.dinput_keyboard_properties.rot_radius_inc]	==	b_HOLD)
	{
		camera.rotate.radius		+=	camera.rotate.radius * camera.rotate.speed_keyboard_rotate * timerFrameLength;
		camera.process		=	true;
	}

	//	***	[	INCREASE_PUCH_STRENGTH	]
	if(keyboard.statuss[g_game.dinput_keyboard_properties.rot_push_strength_inc]	==	b_HOLD)
	{
		g_game.player_push_strength	+=	timerFrameLength / 10.0;
	}

	//	***	[	DECREASE_PUSH_STRENGTH	]
	if(keyboard.statuss[g_game.dinput_keyboard_properties.rot_push_strength_dec]	==	b_HOLD)
	{
		g_game.player_push_strength	-=	timerFrameLength / 10.0;
	}

	//	***	[	MOVE_PUCK_LEFT	]
	if(keyboard.statuss[g_game.dinput_keyboard_properties.rot_move_left]	==	b_HOLD)
	{
		if((g_game.player_active	== 0) && (!g_game.game_motion_on))
		{
			g_game.player[g_game.player_active].puck[0].coord.x -= timerFrameLength / 30.0;;
		}
	}

	//	***	[	MOVE_PUCK_RIGHT	]
	if(keyboard.statuss[g_game.dinput_keyboard_properties.rot_move_right]	==	b_HOLD)
	{
		if((g_game.player_active	== 0) && (!g_game.game_motion_on))
		{
			g_game.player[g_game.player_active].puck[0].coord.x += timerFrameLength / 30.0;
		}
	}

	//	***	[	PUSH_PUCK	]
	if(	(keyboard.statuss[g_game.dinput_keyboard_properties.rot_push] == b_PRESS) &&
		(!g_game.game_motion_on))
	{
		game_phiziks_push_puck(g_game.player_active, 0, camera.rotate.angle_h + PI, g_game.player_push_strength);
	}
}

void	game_camera_rotate_mouse_process()
{
	//	***	[	NOT_MOVING_PUCK	]
	if((mouse.statuss[g_game.dinput_mouse_properties.rot_move_puck] != b_HOLD))
	{
		//	***	[	ROTATE_CAMERA_HORIZONTAL	]
		if((mouse.statuss[m_LBUTTON] != b_HOLD) && (mouse.move_x !=	0))
		{
			camera.rotate.angle_h	-=	mouse.move_x * camera.rotate.speed_mouse_rotate;
			camera.rotate.angle_h	*= g_game.dinput_mouse_properties.rot_invert_x_axis;
			camera.process		=	true;
		}

		//	***	[	ROTATE_CAMERA_VERTICAL	]
		if((mouse.statuss[m_LBUTTON] != b_HOLD) && (mouse.move_y !=	0))
		{
			camera.rotate.angle_v	-=	mouse.move_y * camera.rotate.speed_mouse_rotate;
			camera.rotate.angle_v	*= g_game.dinput_mouse_properties.rot_invert_y_axis;
			camera.process		=	true;
		}

		//	***	[	CHANGING_ROTATE_RADIUS	]
		if((mouse.statuss[m_LBUTTON] == b_HOLD) && (mouse.move_y != 0))
		{
			camera.rotate.radius	+=	mouse.move_y * camera.rotate.speed_mouse_rotate * 30;
			camera.process		=	true;
		}
	}
	//	***	[	MOVING_PUCK	]
	else
	{
		//	***	[	MOVE_PUCK_LEFT_RIGHT	]
		if((!g_game.game_motion_on) && (mouse.move_x !=	0))
		{
			if(g_game.player_active == 0)	g_game.player[g_game.player_active].puck[0].coord.x  += mouse.move_x * camera.rotate.speed_keyboard_walk * timerFrameLength * camera.rotate.radius / 40;
			if(g_game.player_active == 1)	g_game.player[g_game.player_active].puck[0].coord.z  += mouse.move_x * camera.rotate.speed_keyboard_walk * timerFrameLength * camera.rotate.radius / 40;
			if(g_game.player_active == 2)	g_game.player[g_game.player_active].puck[0].coord.x  -= mouse.move_x * camera.rotate.speed_keyboard_walk * timerFrameLength * camera.rotate.radius / 40;
			if(g_game.player_active == 3)	g_game.player[g_game.player_active].puck[0].coord.z  -= mouse.move_x * camera.rotate.speed_keyboard_walk * timerFrameLength * camera.rotate.radius / 40;
		}
	}

	//	***	[	CHANGE_PUSH_STRENGTH	]
	if(mouse.move_z	!=	0)
	{
		g_game.player_push_strength	+= mouse.move_z * 3;
	}
}
