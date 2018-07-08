


#include	"main\main.h"
#include	"game\game.h"
#include	"dinput\dinput.h"
#include	"timer\timer.h"

#include	"math.h"


void	game_camera_freelook_keyboard_process()
{
	//	***	[	ROTATE_RIGHT	]
	if(keyboard.statuss[g_game.dinput_keyboard_properties.free_rotate_right]	==	b_HOLD)
	{
		camera.freelook.angle_h		-=	camera.freelook.speed_keyboard_rotate * timerFrameLength;
		camera.process		=	true;
	}

	//	***	[	ROTATE_LEFT	]
	if(keyboard.statuss[g_game.dinput_keyboard_properties.free_rotate_left]		==	b_HOLD)
	{
		camera.freelook.angle_h		+=	camera.freelook.speed_keyboard_rotate * timerFrameLength;
		camera.process		=	true;
	}

	//	***	[	ROTATE_UP	]
	if(keyboard.statuss[g_game.dinput_keyboard_properties.free_rotate_up]		==	b_HOLD)
	{
		camera.freelook.angle_v		+=	camera.freelook.speed_keyboard_rotate * timerFrameLength;
		camera.process		=	true;
	}

	//	***	[	ROTATE_DOWN	]
	if(keyboard.statuss[g_game.dinput_keyboard_properties.free_rotate_down]		==	b_HOLD)
	{
		camera.freelook.angle_v		-=	camera.freelook.speed_keyboard_rotate * timerFrameLength;
		camera.process		=	true;
	}

	//	***	[	MOVE_FORWARD	]
	if(keyboard.statuss[g_game.dinput_keyboard_properties.free_move_forward]		==	b_HOLD)
	{
		camera.freelook.position_x	+=	camera.freelook.speed_keyboard_walk * cos(camera.freelook.angle_h) * timerFrameLength * cos(camera.freelook.angle_v);
		camera.freelook.position_z	+=	camera.freelook.speed_keyboard_walk * sin(camera.freelook.angle_h) * timerFrameLength * cos(camera.freelook.angle_v);
		camera.freelook.position_y	+=	camera.freelook.speed_keyboard_walk * timerFrameLength * sin(camera.freelook.angle_v);
		camera.process		=	true;
	}

	//	***	[	MOVE_BACKWARD	]
	if(keyboard.statuss[g_game.dinput_keyboard_properties.free_move_backward]		==	b_HOLD)
	{
		camera.freelook.position_x	-=	camera.freelook.speed_keyboard_walk * cos(camera.freelook.angle_h) * timerFrameLength * cos(camera.freelook.angle_v);
		camera.freelook.position_z	-=	camera.freelook.speed_keyboard_walk * sin(camera.freelook.angle_h) * timerFrameLength * cos(camera.freelook.angle_v);
		camera.freelook.position_y	-=	camera.freelook.speed_keyboard_walk * timerFrameLength * sin(camera.freelook.angle_v);
		camera.process		=	true;
	}

	//	***	[	MOVE_RIGHT	]
	if(keyboard.statuss[g_game.dinput_keyboard_properties.free_move_right]		==	b_HOLD)
	{
		camera.freelook.position_x	-=	camera.freelook.speed_keyboard_walk * cos(camera.freelook.angle_h + PI / 2) * timerFrameLength;
		camera.freelook.position_z	-=	camera.freelook.speed_keyboard_walk * sin(camera.freelook.angle_h + PI / 2) * timerFrameLength;
		camera.process		=	true;
	}

	//	***	[	MOVE_LEFT	]
	if(keyboard.statuss[g_game.dinput_keyboard_properties.free_move_left]		==	b_HOLD)
	{
		camera.freelook.position_x	-=	camera.freelook.speed_keyboard_walk * cos(camera.freelook.angle_h - PI / 2) * timerFrameLength;
		camera.freelook.position_z	-=	camera.freelook.speed_keyboard_walk * sin(camera.freelook.angle_h - PI / 2) * timerFrameLength;
		camera.process		=	true;
	}

	//	***	[	MOVE_DOWN	]
	if(keyboard.statuss[g_game.dinput_keyboard_properties.free_move_down]	==	b_HOLD)
	{
		camera.freelook.position_y	-=	camera.freelook.speed_keyboard_walk * timerFrameLength;
		camera.process		=	true;
	}

	//	***	[	MOVE_UP	]
	if(keyboard.statuss[g_game.dinput_keyboard_properties.free_move_up]		==	b_HOLD)
	{
		camera.freelook.position_y	+=	camera.freelook.speed_keyboard_walk * timerFrameLength;
		camera.process		=	true;
	}
}

void	game_camera_freelook_mouse_process()
{
	if(camera.camera_mode	==	CAMERA_MODE_FREELOOK)
	{
		//	***	[	ROTATE_HORIZONTAL	]
		if(mouse.move_x	!=	0)
		{
			camera.freelook.angle_h	-= mouse.move_x * camera.freelook.speed_mouse_rotate;
			camera.freelook.angle_h *= g_game.dinput_mouse_properties.free_invert_x_axis;
			camera.process		=	true;
		}

		//	***	[	ROTATE_VERTICAL	]
		if(mouse.move_y	!=	0)
		{
			camera.freelook.angle_v	-= mouse.move_y * camera.freelook.speed_mouse_rotate;
			camera.freelook.angle_v *= g_game.dinput_mouse_properties.free_invert_y_axis;
			camera.process		=	true;
		}

		//	***	[	MOVE_VERTICAL	]
		if(mouse.statuss[g_game.dinput_mouse_properties.free_move_up]	==	b_HOLD)
		{
			camera.freelook.position_y	+=	camera.freelook.speed_mouse_walk * timerFrameLength;
			camera.process		=	true;
		}
	}
}

