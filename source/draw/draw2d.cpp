  


#include	"draw\draw2d.h"
#include	"texture\texture.h"
#include	"main\main.h"
#include	"write\write.h"

void	draw2dTex(int x, int y, float scaleX, float scaleY, int texID)
{
	int	width	=	(float)tex[texID].width * scaleX;
	int	height	=	(float)tex[texID].height * scaleY;

	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, tex[texID].texID);

		glBegin(GL_QUADS);
				glTexCoord2f(0, 0);
			glVertex2i(x,			y);
				glTexCoord2f(1, 0);
			glVertex2i(x + width,	y);
				glTexCoord2f(1, 1);
			glVertex2i(x + width,	y + height);
				glTexCoord2f(0, 1);
			glVertex2i(x,			y + height);
		glEnd();

	glDisable(GL_TEXTURE_2D);
}

void draw2dSymbol(int symbolID, int fontID)
{
	int		textureID	=	font[fontID].fontTex;

	int		width		=	font[fontID].width;
	int		heigth		=	font[fontID].heigth;

	int		x			=	symbolID % width;
	int		y			=	heigth - symbolID / heigth;

	float	x0			=	x * (1.0 / width);
	float	y0			=	y * (1.0 / heigth) - 1.0 / heigth;

	float	x1			=	x0 + 1.0 / width;
	float	y1			=	y0 + 1.0 / heigth;

	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, tex[fontID].texID);

		glBegin(GL_QUADS);
				glTexCoord2f(x0, y0);
			glVertex2i(0, 0);
				glTexCoord2f(x1, y0);
			glVertex2i(width, 0);
				glTexCoord2f(x1, y1);
			glVertex2i(width, heigth);
				glTexCoord2f(x0, y1);
			glVertex2i(0, heigth);
		glEnd();

	glDisable(GL_TEXTURE_2D);
}

void	draw2dQuad(int x, int y, int width, int height)
{
	glBegin(GL_QUADS);
		glVertex2i(x,			y);
		glVertex2i(x + width,	y);
		glVertex2i(x + width,	y + height);
		glVertex2i(x,			y + height);
	glEnd();
}