  


#include	"dinput\dinput.h"

dinput_keyboard		keyboard;

void dinput_keyboard_init()
{
	int	loop;

	for(loop = 0; loop < KEY_BUTTON_NUM; loop++)
	{
		keyboard.statuss[loop] = b_NULL;
	}

	keyboard.key[0]		=	DIK_GRAVE;				//	~
	keyboard.key[1]		=	DIK_1;					//	1
	keyboard.key[2]		=	DIK_2;					//	2
	keyboard.key[3]		=	DIK_3;					//	3
	keyboard.key[4]		=	DIK_4;					//	4
	keyboard.key[5]		=	DIK_5;					//	5
	keyboard.key[6]		=	DIK_6;					//	6
	keyboard.key[7]		=	DIK_7;					//	7
	keyboard.key[8]		=	DIK_8;					//	8
	keyboard.key[9]		=	DIK_9;					//	9
	keyboard.key[10]	=	DIK_0;					//	0
	keyboard.key[11]	=	DIK_MINUS;				//	-
	keyboard.key[12]	=	DIK_EQUALS;				//	=
	keyboard.key[13]	=	DIK_BACKSLASH;			//	\ 
	keyboard.key[14]	=	DIK_Q;					//	Q
	keyboard.key[15]	=	DIK_W;					//	W
	keyboard.key[16]	=	DIK_E;					//	E
	keyboard.key[17]	=	DIK_R;					//	R
	keyboard.key[18]	=	DIK_T;					//	T
	keyboard.key[19]	=	DIK_Y;					//	Y
	keyboard.key[20]	=	DIK_U;					//	U
	keyboard.key[21]	=	DIK_I;					//	I
	keyboard.key[22]	=	DIK_O;					//	O
	keyboard.key[23]	=	DIK_P;					//	P
	keyboard.key[24]	=	DIK_LBRACKET;			//	[
	keyboard.key[25]	=	DIK_RBRACKET;			//	]
	keyboard.key[26]	=	DIK_A;					//	A
	keyboard.key[27]	=	DIK_S;					//	S
	keyboard.key[28]	=	DIK_D;					//	D
	keyboard.key[29]	=	DIK_F;					//	F
	keyboard.key[30]	=	DIK_G;					//	G
	keyboard.key[31]	=	DIK_H;					//	H
	keyboard.key[32]	=	DIK_J;					//	J
	keyboard.key[33]	=	DIK_K;					//	K
	keyboard.key[34]	=	DIK_L;					//	L
	keyboard.key[35]	=	DIK_SEMICOLON;			//	;
	keyboard.key[36]	=	DIK_APOSTROPHE;			//	'
	keyboard.key[37]	=	DIK_Z;					//	Z
	keyboard.key[38]	=	DIK_X;					//	X
	keyboard.key[39]	=	DIK_C;					//	C
	keyboard.key[40]	=	DIK_V;					//	V
	keyboard.key[41]	=	DIK_B;					//	B
	keyboard.key[42]	=	DIK_N;					//	N
	keyboard.key[43]	=	DIK_M;					//	M
	keyboard.key[44]	=	DIK_COMMA;				//	,
	keyboard.key[45]	=	DIK_PERIOD;				//	.
	keyboard.key[46]	=	DIK_SLASH;				//	/
	keyboard.key[47]	=	DIK_SPACE;				//	" "
	keyboard.key[48]	=	DIK_NUMPAD0;			//	0	(numpad)
	keyboard.key[49]	=	DIK_NUMPAD1;			//	1	(numpad)
	keyboard.key[50]	=	DIK_NUMPAD2;			//	2	(numpad)
	keyboard.key[51]	=	DIK_NUMPAD3;			//	3	(numpad)
	keyboard.key[52]	=	DIK_NUMPAD4;			//	4	(numpad)
	keyboard.key[53]	=	DIK_NUMPAD5;			//	5	(numpad)
	keyboard.key[54]	=	DIK_NUMPAD6;			//	6	(numpad)
	keyboard.key[55]	=	DIK_NUMPAD7;			//	7	(numpad)
	keyboard.key[56]	=	DIK_NUMPAD8;			//	8	(numpad)
	keyboard.key[57]	=	DIK_NUMPAD9;			//	9	(numpad)
	keyboard.key[58]	=	DIK_DIVIDE;				//	/ 	(numpad)
	keyboard.key[59]	=	DIK_MULTIPLY;			//	*	(numpad)
	keyboard.key[60]	=	DIK_SUBTRACT;			//	-	(numpad)
	keyboard.key[61]	=	DIK_ADD;				//	+	(numpad)
	keyboard.key[62]	=	DIK_DECIMAL;			//	.	(numpad)

	keyboard.key[63]	=	DIK_ESCAPE;				//	Esc
	keyboard.key[64]	=	DIK_F1;					//	F1
	keyboard.key[65]	=	DIK_F2;					//	F2
	keyboard.key[66]	=	DIK_F3;					//	F3
	keyboard.key[67]	=	DIK_F4;					//	F4
	keyboard.key[68]	=	DIK_F5;					//	F5
	keyboard.key[69]	=	DIK_F6;					//	F6
	keyboard.key[70]	=	DIK_F7;					//	F7
	keyboard.key[71]	=	DIK_F8;					//	F8
	keyboard.key[72]	=	DIK_F9;					//	F9
	keyboard.key[73]	=	DIK_F10;				//	F10
	keyboard.key[74]	=	DIK_F11;				//	F11
	keyboard.key[75]	=	DIK_F12;				//	F12
	keyboard.key[76]	=	DIK_SYSRQ;				//	Sys Rq
	keyboard.key[77]	=	DIK_SCROLL;				//	Scroll Lock
	keyboard.key[78]	=	DIK_PAUSE;				//	Pause
	keyboard.key[79]	=	DIK_INSERT;				//	Insert
	keyboard.key[80]	=	DIK_DELETE;				//	Delete
	keyboard.key[81]	=	DIK_HOME;				//	Home
	keyboard.key[82]	=	DIK_END;				//	End
	keyboard.key[83]	=	DIK_PRIOR;				//	Page Up
	keyboard.key[84]	=	DIK_NEXT;				//	Page Down
	keyboard.key[85]	=	DIK_LEFT;				//	Left
	keyboard.key[86]	=	DIK_RIGHT;				//	Right
	keyboard.key[87]	=	DIK_UP;					//	Up
	keyboard.key[88]	=	DIK_DOWN;				//	Down
	keyboard.key[89]	=	DIK_NUMLOCK;			//	Num Lock
	keyboard.key[90]	=	DIK_NUMPADENTER;		//	Enter	(numpad)
	keyboard.key[91]	=	DIK_TAB;				//	Tab
	keyboard.key[92]	=	DIK_CAPITAL;			//	Caps Lock
	keyboard.key[93]	=	DIK_LSHIFT;				//	Left Shift
	keyboard.key[94]	=	DIK_LCONTROL;			//	Left Ctrl
	keyboard.key[95]	=	DIK_LWIN;				//	Left Win
	keyboard.key[96]	=	DIK_LMENU;				//	Left Alt
	keyboard.key[97]	=	DIK_BACK;				//	Backspace
	keyboard.key[98]	=	DIK_RETURN;				//	ENTER
	keyboard.key[99]	=	DIK_RSHIFT;				//	Right Shift
	keyboard.key[100]	=	DIK_RMENU;				//	Right Alt
	keyboard.key[101]	=	DIK_RWIN;				//	Right Win
	keyboard.key[102]	=	DIK_APPS;				//	Apps
	keyboard.key[103]	=	DIK_RCONTROL;			//	Right Ctrl
}