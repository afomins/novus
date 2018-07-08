 


#include	<dinput.h>

bool	WINAPI	dinput_create();
void	WINAPI	dinput_delete();
void			dinput_access(bool active);

void	dinput_keyboard_process();
void	dinput_keyboard_init();

void	dinput_mouse_process();
void	dinput_mouse_button_process();
void	dinput_mouse_init();
void	dinput_mouse_coord_set();

#define		KEYDOWN(name, key) (name[key] & 0x80)
#define		KEY_BUTTON_NUM		104
#define		MOUSE_BUTTON_NUM	3

#define		k_GRAVE			0
#define		k_1				1	
#define		k_2				2
#define		k_3				3	
#define		k_4				4	
#define		k_5				5	
#define		k_6				6	
#define		k_7				7	
#define		k_8				8	
#define		k_9				9	
#define		k_0				10	
#define		k_MINUS			11
#define		k_EQUALS		12
#define		k_BACKSLASH		13
#define		k_Q				14
#define		k_W				15
#define		k_E				16
#define		k_R				17
#define		k_T				18
#define		k_Y				19
#define		k_U				20
#define		k_I				21
#define		k_O				22
#define		k_P				23
#define		k_LBRACKET		24
#define		k_RBRACKET		25
#define		k_A				26
#define		k_S				27
#define		k_D				28
#define		k_F				29
#define		k_G				30
#define		k_H				31
#define		k_J				32
#define		k_K				33
#define		k_L				34
#define		k_SEMICOLON		35
#define		k_APOSTROPHE	36
#define		k_Z				37
#define		k_X				38
#define		k_C				39
#define		k_V				40
#define		k_B				41
#define		k_N				42
#define		k_M				43
#define		k_COMMA			44
#define		k_PERIOD		45
#define		k_SLASH			46
#define		k_SPACE			47
#define		k_NUMPAD0		48
#define		k_NUMPAD1		49
#define		k_NUMPAD2		50
#define		k_NUMPAD3		51
#define		k_NUMPAD4		52
#define		k_NUMPAD5		53
#define		k_NUMPAD6		54
#define		k_NUMPAD7		55
#define		k_NUMPAD8		56
#define		k_NUMPAD9		57
#define		k_DIVIDE		58
#define		k_MULTIPLY		59
#define		k_SUBTRACT		60
#define		k_ADD			61
#define		k_DECIMAL		62

#define		k_ESCAPE		63
#define		k_F1			64
#define		k_F2			65
#define		k_F3			66
#define		k_F4			67
#define		k_F5			68
#define		k_F6			69
#define		k_F7			70
#define		k_F8			71
#define		k_F9			72
#define		k_F10			73
#define		k_F11			74
#define		k_F12			75
#define		k_SYSRQ			76
#define		k_SCROLL		77
#define		k_PAUSE			78
#define		k_INSERT		79
#define		k_DELETE		80
#define		k_HOME			81
#define		k_END			82
#define		k_PRIOR			83
#define		k_NEXT			84
#define		k_LEFT			85
#define		k_RIGHT			86
#define		k_UP			87
#define		k_DOWN			88
#define		k_NUMLOCK		89
#define		k_NUMPADENTER	90
#define		k_TAB			91
#define		k_CAPITAL		92
#define		k_LSHIFT		93
#define		k_LCONTROL		94
#define		k_LWIN			95
#define		k_LMENU			96
#define		k_BACK			97
#define		k_RETURN		98
#define		k_RSHIFT		99
#define		k_RMENU			100
#define		k_RWIN			101
#define		k_APPS			102
#define		k_RCONTROL		103
#define		k_NONE			200

#define		m_LBUTTON		0
#define		m_RBUTTON		1
#define		m_MBUTTON		2
#define		m_WHEEL			3
#define		m_NONE			200

#define		b_NULL			-1
#define		b_PRESS			0
#define		b_HOLD			1
#define		b_RELEASE		2

struct	dinput_mouse
{
	int		x;
	int		y;

	float	move_x;
	float	move_y;
	float	move_z;

	float	sensitivity;

	int		statuss[MOUSE_BUTTON_NUM];

	bool	press[MOUSE_BUTTON_NUM];
	bool	prev_press[MOUSE_BUTTON_NUM];
};

struct	dinput_keyboard
{
	int		key[KEY_BUTTON_NUM];

	int		statuss[KEY_BUTTON_NUM];

	bool	pressed[KEY_BUTTON_NUM];
	bool	prev_press[KEY_BUTTON_NUM];
};

extern	dinput_mouse		mouse;
extern	dinput_keyboard		keyboard;