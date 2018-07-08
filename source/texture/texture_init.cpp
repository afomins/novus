  


#include "texture\texture.h"

texImageInstance	tex[TEXTURE_MAX_NUM];

void textureInit()
{
	textureLoadTGA(&tex[TEX_FONT_0],"data/font/font0.tga", false, false);
	textureLoadTGA(&tex[TEX_FONT_1],"data/font/font1.tga", false, false);

	textureLoadTGA(&tex[TEX_CURSOR_0],"data/cursor/cursor0.tga", true, false);
	textureLoadTGA(&tex[TEX_CURSOR_1],"data/cursor/cursor1.tga", true, false);
	textureLoadTGA(&tex[TEX_CURSOR_2],"data/cursor/cursor2.tga", true, false);
	textureLoadTGA(&tex[TEX_CURSOR_3],"data/cursor/cursor3.tga", true, false);

	textureLoadTGA(&tex[TEX_SKY_FRONT],	"data/sky/hl_00_front.tga", false, false);
	textureLoadTGA(&tex[TEX_SKY_BACK],	"data/sky/hl_00_back.tga",	false, false);
	textureLoadTGA(&tex[TEX_SKY_LEFT],	"data/sky/hl_00_left.tga",	false, false);
	textureLoadTGA(&tex[TEX_SKY_RIGHT],	"data/sky/hl_00_right.tga", false, false);
	textureLoadTGA(&tex[TEX_SKY_UP],	"data/sky/hl_00_up.tga",	false, false);
	textureLoadTGA(&tex[TEX_SKY_DOWN],	"data/sky/hl_00_down.tga",	false, false);
/*
	textureLoadTGA(&tex[TEX_SKY_FRONT],	"data/sky/lake/front.tga", false, false);
	textureLoadTGA(&tex[TEX_SKY_BACK],	"data/sky/lake/back.tga",	false, false);
	textureLoadTGA(&tex[TEX_SKY_LEFT],	"data/sky/lake/left.tga",	false, false);
	textureLoadTGA(&tex[TEX_SKY_RIGHT],	"data/sky/lake/right.tga", false, false);
	textureLoadTGA(&tex[TEX_SKY_UP],	"data/sky/lake/up.tga",	false, false);
	textureLoadTGA(&tex[TEX_SKY_DOWN],	"data/sky/lake/down.tga",	false, false);
*/
	textureLoadTGA(&tex[TEX_WOOD_00],	"data/tex/surface_wood_00.tga",	true, true);
	textureLoadTGA(&tex[TEX_STONE_00],	"data/tex/surface_stone_00.tga",true, true);

	textureLoadTGA(&tex[TEX_BUTTON_GRIM_00],	"data/button/button_grim_00.tga",true, false);
	textureLoadTGA(&tex[TEX_BUTTON_GRIM_01],	"data/button/button_grim_01.tga",true, false);

	textureLoadTGA(&tex[TEX_MENU_00],				"data/menu/menu_00.tga",true, false);
	textureLoadTGA(&tex[TEX_MENU_01],				"data/menu/menu_01.tga",true, false);

	textureLoadTGA(&tex[TEX_BUTTON_NEW_GAME_00],	"data/button/button_menu_new_game_ru_00.tga",true, false);
	textureLoadTGA(&tex[TEX_BUTTON_NEW_GAME_01],	"data/button/button_menu_new_game_ru_01.tga",true, false);
	textureLoadTGA(&tex[TEX_BUTTON_SAVE_GAME_00],	"data/button/button_menu_save_game_ru_00.tga",true, false);
	textureLoadTGA(&tex[TEX_BUTTON_SAVE_GAME_01],	"data/button/button_menu_save_game_ru_01.tga",true, false);
	textureLoadTGA(&tex[TEX_BUTTON_LOAD_GAME_00],	"data/button/button_menu_load_game_ru_00.tga",true, false);
	textureLoadTGA(&tex[TEX_BUTTON_LOAD_GAME_01],	"data/button/button_menu_load_game_ru_01.tga",true, false);
	textureLoadTGA(&tex[TEX_BUTTON_LOAD_REPLAY_00],	"data/button/button_menu_load_replay_ru_00.tga",true, false);
	textureLoadTGA(&tex[TEX_BUTTON_LOAD_REPLAY_01],	"data/button/button_menu_load_replay_ru_01.tga",true, false);
	textureLoadTGA(&tex[TEX_BUTTON_OPTIONS_00],		"data/button/button_menu_options_ru_00.tga",true, false);
	textureLoadTGA(&tex[TEX_BUTTON_OPTIONS_01],		"data/button/button_menu_options_ru_01.tga",true, false);
	textureLoadTGA(&tex[TEX_BUTTON_HELP_00],		"data/button/button_menu_help_ru_00.tga",true, false);
	textureLoadTGA(&tex[TEX_BUTTON_HELP_01],		"data/button/button_menu_help_ru_01.tga",true, false);
	textureLoadTGA(&tex[TEX_BUTTON_STATISTICS_00],	"data/button/button_menu_statistics_ru_00.tga",true, false);
	textureLoadTGA(&tex[TEX_BUTTON_STATISTICS_01],	"data/button/button_menu_statistics_ru_01.tga",true, false);
	textureLoadTGA(&tex[TEX_BUTTON_EXIT_00],		"data/button/button_menu_exit_ru_00.tga",true, false);
	textureLoadTGA(&tex[TEX_BUTTON_EXIT_01],		"data/button/button_menu_exit_ru_01.tga",true, false);
	textureLoadTGA(&tex[TEX_BUTTON_RESUME_GAME_00],	"data/button/button_menu_resume_game_ru_00.tga",true, false);
	textureLoadTGA(&tex[TEX_BUTTON_RESUME_GAME_01],	"data/button/button_menu_resume_game_ru_01.tga",true, false);


	textureLoadTGA(&tex[TEX_TERRA_NOVUS_LOGO_00],	"data/tex/terra_novus_logo_00.tga",true, false);
	textureLoadTGA(&tex[TEX_TERRA_NOVUS_LOGO_01],	"data/tex/terra_novus_logo_01.tga",true, false);

	textureLoadTGA(&tex[TEX_S_TEST_0_0],	"data/scroll_bar/s_test_0_0.tga",true, false);
	textureLoadTGA(&tex[TEX_S_TEST_0_1],	"data/scroll_bar/s_test_0_1.tga",true, false);
	textureLoadTGA(&tex[TEX_S_TEST_1_0],	"data/scroll_bar/s_test_1_0.tga",true, false);
	textureLoadTGA(&tex[TEX_S_TEST_1_1],	"data/scroll_bar/s_test_1_1.tga",true, false);
	textureLoadTGA(&tex[TEX_S_TEST_2_0],	"data/scroll_bar/s_test_2_0.tga",true, false);
	textureLoadTGA(&tex[TEX_S_TEST_2_1],	"data/scroll_bar/s_test_2_1.tga",true, false);
	textureLoadTGA(&tex[TEX_S_TEST_3_0],	"data/scroll_bar/s_test_3_0.tga",true, false);
	textureLoadTGA(&tex[TEX_S_TEST_3_1],	"data/scroll_bar/s_test_3_1.tga",true, false);

	textureLoadTGA(&tex[TEX_B_NEW_GAME_PLAYER_00],	"data/button/b_new_game_player_eng_00.tga",true, false);
	textureLoadTGA(&tex[TEX_B_NEW_GAME_PLAYER_01],	"data/button/b_new_game_player_eng_01.tga",true, false);
	textureLoadTGA(&tex[TEX_B_NEW_GAME_NONE_01],	"data/button/b_new_game_none_eng_01.tga",true, false);
	textureLoadTGA(&tex[TEX_B_NEW_GAME_AI_01],		"data/button/b_new_game_ai_eng_01.tga",true, false);

	textureLoadTGA(&tex[TEX_B_NEW_GAME_GO_00],	"data/button/b_new_game_go_eng_00.tga",true, false);
	textureLoadTGA(&tex[TEX_B_NEW_GAME_GO_01],	"data/button/b_new_game_go_eng_01.tga",true, false);

	textureLoadTGA(&tex[TEX_STRENGTH_BAR_00],	"data/tex/strength_bar_00.tga",true, false);
	textureLoadTGA(&tex[TEX_STRENGTH_BAR_01],	"data/tex/strength_bar_01.tga",true, false);

	textureLoadTGA(&tex[TEX_NAME_BAR],			"data/tex/name_bar.tga",true, false);
	textureLoadTGA(&tex[TEX_STAT_TAB],			"data/tex/stat_tab.tga",true, false);

	textureLoadTGA(&tex[TEX_RED_WINS],			"data/tex/red_team_wins.tga",true, false);
	textureLoadTGA(&tex[TEX_BLUE_WINS],			"data/tex/blue_team_wins.tga",true, false);

	textureLoadTGA(&tex[TEX_B_PLAYERS],			"data/button/b_players.tga",true, false);
	textureLoadTGA(&tex[TEX_B_2PLAYERS],		"data/button/b_2players.tga",true, false);
	textureLoadTGA(&tex[TEX_B_4PLAYERS],		"data/button/b_4players.tga",true, false);

	textureLoadTGA(&tex[TEX_HELP],				"data/tex/help.tga",true, false);
}
	