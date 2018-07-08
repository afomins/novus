 


#define		FONT_MAX_NUM		2

struct	noVfontInstance
{
	int		fontTex;

	int		symbolHeigth;
	int		symbolWidth[256];

	int		width;
	int		heigth;
};

extern	noVfontInstance		font[FONT_MAX_NUM];


int		write(int x, int y, char* text, float sizeX, float sizeY, int fontNum);
int		write(int x, int y, float num, int level, float sizeX, float sizeY, int fontNum);
void	write(int x, int y, char* text, float num, int level, float sizeX, float sizeY, int fontNum);
void	write(int x, int y, float num, int level, char* text, float sizeX, float sizeY, int fontNum);
void	write(int x, int y, unsigned short num, float sizeX, float sizeY, int fontNum);

int		writeStringGetLength(char *text);

void	writeInit();
