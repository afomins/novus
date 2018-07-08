


#include	"main\main.h"
#include	"interface\interface.h"
#include	"texture\texture.h"
#include	"draw\draw2d.h"


void	interface_cursor_create(int *x, int *y, int width, int height, unsigned short tex_id, bool shadow_on, int shadow_offset_x, int shadow_offset_y)
{
	g_interface.cursor.cursor_on		=	true;
	g_interface.cursor.shadow_on		=	shadow_on;

	g_interface.cursor.x				=	x;
	g_interface.cursor.y				=	y;
	g_interface.cursor.width			=	width;
	g_interface.cursor.height			=	height;
	g_interface.cursor.tex_id			=	tex_id;

	g_interface.cursor.shadow_offset_x	=	shadow_offset_x;
	g_interface.cursor.shadow_offset_y	=	shadow_offset_y;
}

void	interface_cursor_color_create(float r, float g, float b, float a)
{
	g_interface.cursor.color_cursor.r	=	r;
	g_interface.cursor.color_cursor.g	=	g;
	g_interface.cursor.color_cursor.b	=	b;
	g_interface.cursor.color_cursor.a	=	a;
}

void	interface_cursor_shadow_color_create(float r, float g, float b, float a)
{
	g_interface.cursor.color_shadow.r	=	r;
	g_interface.cursor.color_shadow.g	=	g;
	g_interface.cursor.color_shadow.b	=	b;
	g_interface.cursor.color_shadow.a	=	a;
}

void	interface_cursor_draw()
{
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, tex[g_interface.cursor.tex_id].texID);

	glBegin(GL_QUADS);		//	***	[	SHADOW_TEXTURE	]
		glColor4f(	g_interface.cursor.color_shadow.r,
					g_interface.cursor.color_shadow.g,
					g_interface.cursor.color_shadow.b,
					g_interface.cursor.color_shadow.a);

		glTexCoord2f(0.0, 1.0);
		glVertex2i(*g_interface.cursor.x + g_interface.cursor.shadow_offset_x,								*g_interface.cursor.y + g_interface.cursor.shadow_offset_y);
		glTexCoord2f(0.0, 0.0);
		glVertex2i(*g_interface.cursor.x + g_interface.cursor.shadow_offset_x,								*g_interface.cursor.y - g_interface.cursor.height + g_interface.cursor.shadow_offset_y);
		glTexCoord2f(1.0, 0.0);
		glVertex2i(*g_interface.cursor.x + g_interface.cursor.width + g_interface.cursor.shadow_offset_x,	*g_interface.cursor.y - g_interface.cursor.height + g_interface.cursor.shadow_offset_y);
		glTexCoord2f(1.0, 1.0);
		glVertex2i(*g_interface.cursor.x + g_interface.cursor.width + g_interface.cursor.shadow_offset_x,	*g_interface.cursor.y + g_interface.cursor.shadow_offset_y);
	glEnd();	

	glBegin(GL_QUADS);		//	***	[	MAIN_TEXTURE	]
		glColor4f(	g_interface.cursor.color_cursor.r,
					g_interface.cursor.color_cursor.g,
					g_interface.cursor.color_cursor.b,
					g_interface.cursor.color_cursor.a);

		glTexCoord2f(0.0, 1.0);
		glVertex2i(*g_interface.cursor.x,								*g_interface.cursor.y);
		glTexCoord2f(0.0, 0.0);
		glVertex2i(*g_interface.cursor.x,								*g_interface.cursor.y - g_interface.cursor.height);
		glTexCoord2f(1.0, 0.0);
		glVertex2i(*g_interface.cursor.x + g_interface.cursor.width,	*g_interface.cursor.y - g_interface.cursor.height);
		glTexCoord2f(1.0, 1.0);
		glVertex2i(*g_interface.cursor.x + g_interface.cursor.width,	*g_interface.cursor.y);
	glEnd();

	glDisable(GL_TEXTURE_2D);
}
