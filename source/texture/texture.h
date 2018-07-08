 


#include <windows.h>


#define		TEXTURE_MAX_NUM					100

#define		TEX_NONE						121

#define		TEX_FONT_0						0
#define		TEX_FONT_1						1

#define		TEX_CURSOR_0					2
#define		TEX_CURSOR_1					3
#define		TEX_CURSOR_2					4
#define		TEX_CURSOR_3					5

#define		TEX_SKY_FRONT					6
#define		TEX_SKY_BACK					7
#define		TEX_SKY_LEFT					8
#define		TEX_SKY_RIGHT					9
#define		TEX_SKY_UP						10
#define		TEX_SKY_DOWN					11

#define		TEX_WOOD_00						12
#define		TEX_STONE_00					13

#define		TEX_BUTTON_GRIM_00				14
#define		TEX_BUTTON_GRIM_01				15

#define		TEX_MENU_00						16

#define		TEX_BUTTON_NEW_GAME_00			17
#define		TEX_BUTTON_NEW_GAME_01			18

#define		TEX_BUTTON_SAVE_GAME_00			19
#define		TEX_BUTTON_SAVE_GAME_01			20

#define		TEX_BUTTON_LOAD_GAME_00			21
#define		TEX_BUTTON_LOAD_GAME_01			22

#define		TEX_BUTTON_LOAD_REPLAY_00		23
#define		TEX_BUTTON_LOAD_REPLAY_01		24

#define		TEX_BUTTON_OPTIONS_00			25
#define		TEX_BUTTON_OPTIONS_01			26

#define		TEX_BUTTON_HELP_00				27
#define		TEX_BUTTON_HELP_01				28

#define		TEX_BUTTON_EXIT_00				29
#define		TEX_BUTTON_EXIT_01				30

#define		TEX_BUTTON_STATISTICS_00		31
#define		TEX_BUTTON_STATISTICS_01		32

#define		TEX_BUTTON_RESUME_GAME_00		33
#define		TEX_BUTTON_RESUME_GAME_01		34

#define		TEX_TERRA_NOVUS_LOGO_00			35
#define		TEX_TERRA_NOVUS_LOGO_01			36

#define		TEX_MENU_01						37

#define		TEX_S_TEST_0_0					38
#define		TEX_S_TEST_0_1					39
#define		TEX_S_TEST_1_0					40
#define		TEX_S_TEST_1_1					41
#define		TEX_S_TEST_2_0					42
#define		TEX_S_TEST_2_1					43
#define		TEX_S_TEST_3_0					44
#define		TEX_S_TEST_3_1					45

#define		TEX_B_NEW_GAME_PLAYER_00		46
#define		TEX_B_NEW_GAME_PLAYER_01		47
#define		TEX_B_NEW_GAME_NONE_01			48
#define		TEX_B_NEW_GAME_AI_01			49

#define		TEX_B_NEW_GAME_GO_00			50
#define		TEX_B_NEW_GAME_GO_01			51

#define		TEX_STRENGTH_BAR_00				52
#define		TEX_STRENGTH_BAR_01				53

#define		TEX_NAME_BAR					54
#define		TEX_STAT_TAB					55

#define		TEX_RED_WINS					56
#define		TEX_BLUE_WINS					57

#define		TEX_B_PLAYERS					58
#define		TEX_B_2PLAYERS					59
#define		TEX_B_4PLAYERS					60

#define		TEX_HELP						61

struct	texImageInstance
{
	byte				*imageData;

	unsigned	int		bpp;
	unsigned	int		width;
	unsigned	int		height;
	unsigned	int		texID;
};

extern	texImageInstance	tex[TEXTURE_MAX_NUM];

	//	***

bool textureLoadTGA(texImageInstance *texture, char *filename, bool smooth, bool mipmap);

void	textureInit();
