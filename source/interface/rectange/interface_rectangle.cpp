


#include	"main\main.h"
#include	"interface\interface.h"
#include	"texture\texture.h"
#include	"dinput\dinput.h"
#include	"timer\timer.h"


void	interface_rectangle_create(interface_window_instance *window, interface_rectangle_instance *rectangle, int x, int y, int width, int height, unsigned short tex_id)
{
	if(window->rectangle_num == 0)
	{
		rectangle->next		= NULL;
		rectangle->prev		= NULL;

		window->rectangle_first	= rectangle;
		window->rectangle_last	= rectangle;
	}
	else
	{
		rectangle->next		= NULL;
		rectangle->prev		= window->rectangle_last;

		window->rectangle_last->next	= rectangle;
		window->rectangle_last			= rectangle;
	}

	rectangle->rectangle_on					=	false;

	rectangle->x							=	x;
	rectangle->y							=	y;
	rectangle->width						=	width;
	rectangle->height						=	height;
	rectangle->tex_id						=	tex_id;
	
	rectangle->fade_mode					=	FADE_MODE_NONE;
	rectangle->fade_way						=	FADE_WAY_IN;

	window->rectangle_num++;
}

void	interface_rectangle_delete(interface_window_instance *window, interface_rectangle_instance *rectangle)
{
	if(window->rectangle_num	==	0)		return;

	if(window->rectangle_num	==	1)
	{
		window->rectangle_first	=	NULL;
		window->rectangle_last	=	NULL;
	}
	else
	if(window->rectangle_first == rectangle)
	{
		window->rectangle_first			=	rectangle->next;
		window->rectangle_first->prev	=	NULL;
	}
	else
	if(window->rectangle_last	==	rectangle)
	{
		window->rectangle_last			=	rectangle->prev;
		window->rectangle_last->next	=	NULL;
	}
	else
	{
		rectangle->next->prev	=	rectangle->prev;
		rectangle->prev->next	=	rectangle->next;
	}

	window->rectangle_num--;

	delete	rectangle;
}

void	interface_rectangle_delete_all(interface_window_instance *window)
{
	interface_rectangle_instance	*rectangle;

	while(window->rectangle_num	!=	0)
	{
		rectangle	=	window->rectangle_first;
		interface_rectangle_delete(window, rectangle);
	}
}

void	interface_rectangle_draw(interface_window_instance *window)
{
	interface_rectangle_instance	*rectangle	=	window->rectangle_first;
	unsigned short					loop;

	for(loop = 0; loop < window->rectangle_num; loop++)
	{
		if(rectangle->rectangle_on)
		{
			if(rectangle->tex_id != TEX_NONE)
			{
				glEnable(GL_TEXTURE_2D);
			}

									//	***	[	TEX_ID	]

			glColor4f(	rectangle->color_current.r,
						rectangle->color_current.g,
						rectangle->color_current.b,
						rectangle->color_current.a);

			glBindTexture(GL_TEXTURE_2D, tex[rectangle->tex_id].texID);

			glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0);
				glVertex2i(rectangle->x,					rectangle->y);
				glTexCoord2f(1.0, 0.0);
				glVertex2i(rectangle->x + rectangle->width,	rectangle->y);
				glTexCoord2f(1.0, 1.0);
				glVertex2i(rectangle->x + rectangle->width,	rectangle->y + rectangle->height);
				glTexCoord2f(0.0, 1.0);
				glVertex2i(rectangle->x,					rectangle->y + rectangle->height);
			glEnd();

			glDisable(GL_TEXTURE_2D);

		}
		rectangle	=	rectangle->next;
	}
}

void	interface_rectangle_color_normal_create(interface_rectangle_instance *rectangle, float r, float g, float b, float a) 
{
	rectangle->color_normal.r	=	r;
	rectangle->color_normal.g	=	g;
	rectangle->color_normal.b	=	b;
	rectangle->color_normal.a	=	a;
}

void	interface_rectangle_fade_process(interface_window_instance *window)
{
	interface_rectangle_instance	*rectangle	=	window->rectangle_first;
	unsigned short					loop;
	unsigned short					loop1;

	for(loop = 0; loop < window->rectangle_num; loop++)
	{
		if(rectangle->fade_mode	==	FADE_MODE_START)
		{
			rectangle->fade_mode					=	FADE_MODE_MIDDLE;
			rectangle->fade_current					=	timerCurrent;
			rectangle->fade_start					=	timerCurrent;
			rectangle->fade_length					=	g_interface.fade_length_default;
			rectangle->rectangle_on					=	true;

			if(rectangle->fade_way	==	FADE_WAY_IN)
			{
				for(loop1 = 0; loop1 < 2; loop1++)
				{
					rectangle->fade_color_start.r		=	rectangle->color_normal.r;
					rectangle->fade_color_start.g		=	rectangle->color_normal.g;
					rectangle->fade_color_start.b		=	rectangle->color_normal.b;
					rectangle->fade_color_start.a		=	0.0;

					rectangle->fade_color_end.r			=	rectangle->color_normal.r;
					rectangle->fade_color_end.g			=	rectangle->color_normal.g;
					rectangle->fade_color_end.b			=	rectangle->color_normal.b;
					rectangle->fade_color_end.a			=	rectangle->color_normal.a;
				}
			}
			else	//	***	[	FADE_WAY_OUT	]
			{
				for(loop1 = 0; loop1 < 2; loop1++)
				{
					rectangle->fade_color_start.r		=	rectangle->color_current.r;
					rectangle->fade_color_start.g		=	rectangle->color_current.g;
					rectangle->fade_color_start.b		=	rectangle->color_current.b;
					rectangle->fade_color_start.a		=	rectangle->color_current.a;

					rectangle->fade_color_end.r			=	rectangle->color_current.r;
					rectangle->fade_color_end.g			=	rectangle->color_current.g;
					rectangle->fade_color_end.b			=	rectangle->color_current.b;
					rectangle->fade_color_end.a			=	0.0;
				}
			}
		}
		else
		if(rectangle->fade_mode	==	FADE_MODE_MIDDLE)
		{
			rectangle->fade_current				=	timerCurrent;

			if(rectangle->fade_current - rectangle->fade_start > rectangle->fade_length)
			{
				rectangle->fade_mode			=	FADE_MODE_NONE;

				if(rectangle->fade_way	==	FADE_WAY_IN)	
				{
					rectangle->fade_way		=	FADE_WAY_OUT;
					rectangle->rectangle_on	=	true;
				}
				else
				{
					rectangle->fade_way		=	FADE_WAY_IN;
					rectangle->rectangle_on	=	false;
				}

 				for(loop1 = 0; loop1 < 2; loop1++)
				{
					rectangle->color_current.r	=	rectangle->fade_color_end.r;
					rectangle->color_current.g	=	rectangle->fade_color_end.g;
					rectangle->color_current.b	=	rectangle->fade_color_end.b;
					rectangle->color_current.a	=	rectangle->fade_color_end.a;
				}

				return;
			}
		}

		//	***	[	FADE_PROCESS	]

		if((rectangle->rectangle_on) && (rectangle->fade_mode != FADE_MODE_NONE))
		{
			float	r,	g,	b,	a;

			r	=	rectangle->fade_color_end.r - rectangle->fade_color_start.r;
			g	=	rectangle->fade_color_end.g - rectangle->fade_color_start.g;
			b	=	rectangle->fade_color_end.b - rectangle->fade_color_start.b;
			a	=	rectangle->fade_color_end.a - rectangle->fade_color_start.a;

			rectangle->color_current.r	=	rectangle->fade_color_start.r + r * ((rectangle->fade_current - rectangle->fade_start) / (float)rectangle->fade_length);
			rectangle->color_current.g	=	rectangle->fade_color_start.g + g * ((rectangle->fade_current - rectangle->fade_start) / (float)rectangle->fade_length);
			rectangle->color_current.b	=	rectangle->fade_color_start.b + b * ((rectangle->fade_current - rectangle->fade_start) / (float)rectangle->fade_length);
			rectangle->color_current.a	=	rectangle->fade_color_start.a + a * ((rectangle->fade_current - rectangle->fade_start) / (float)rectangle->fade_length);
		}
 		rectangle	=	rectangle->next;
	}
}