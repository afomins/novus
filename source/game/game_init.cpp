


#include	"main\main.h"
#include	"game\game.h"
#include	"texture\texture.h"

game_global_instance	g_game;

void	game_init()
{
	//	***	[	TABLE_LANE		]

	game_model_plane_properties_create(20.0, 5.0, 2.0, 8, 7.0, 16, true);
	game_model_plane_color_create(1.0, 1.0, 1.0, 1.0, TEX_WOOD_00);
	game_model_plane_coord_create(0.0, 0.0, 0.0);

	//	***	[	TABLE_BORDER	]

	game_model_border_properties_create(25.0, 2.0, 1.0, 2.0, true);
	game_model_border_color_create(1.0, 1.0, 1.0, 1.0, TEX_STONE_00);
	game_model_border_coord_create(0.0, 0.0, 0.0);

	//	***	[	SKYBOX			]

	game_model_skybox_properties_create(250.0, false);
	game_model_skybox_create(TEX_SKY_FRONT, TEX_SKY_BACK, TEX_SKY_LEFT,  
								 TEX_SKY_RIGHT, TEX_SKY_UP,	  TEX_SKY_DOWN);

	game_model_skybox_color_create(1.0, 1.0, 1.0, 1.0);
	game_model_skybox_coord_create(&viewport.camPosition.x, &viewport.camPosition.y, &viewport.camPosition.z);

	//	***	[	PUCK			]

	game_model_puck_properties_create(PUCK_TYPE_BIG, 0.7, 0.4, 2.0, 12, true);
	game_model_puck_properties_create(PUCK_TYPE_SMALL, 0.5, 0.3, 1.5, 12, true);

	//	***	[	PLAYER			]

//	game_player_create(0, "manny");
//	game_player_color_create(0, 0.8, 0.0, 0.0, TEX_NONE);

//	game_player_create(1, "hector");
//	game_player_color_create(1, 0.0, 0.8, 0.0, TEX_NONE);

//	game_player_create(2, "eva");
//	game_player_color_create(2, 0.8, 0.8, 0.0, TEX_NONE);

//	game_player_create(3, "domino");
//	game_player_color_create(3, 0.8, 0.0, 8.0, TEX_NONE);

	//	***	[	DINPUT			]

	game_dinput_keyboard_init();
	game_dinput_mouse_init();

	//	***	[	INTERFACE		]

	game_interface_init();

	//	***	[	CAMERA			]

	game_camera_init();

	//	***	[	PHIZIKS			]

	//	***	[	]

	g_game.game_menu_on		= true;
	g_game.game_on			= false;
	g_game.game_motion_on	= false;

	g_game.player_active			= 0;
	g_game.player_push_strength		= 33;
	g_game.player_push_strength_max	= 100;
	g_game.player_push_strength_min	= 1;

	g_game.aim_length[0]	= 30.0;
	g_game.aim_on[0]		= true;

	g_game.player[0].name	= "manny";
	g_game.player[1].name	= "meche";
	g_game.player[2].name	= "hector";
	g_game.player[3].name	= "domino";

//	game_save_statistic(true, true, true, true);
}