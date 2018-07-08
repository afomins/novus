


#include	"main\main.h"
#include	"interface\interface.h"
#include	"texture\texture.h"
#include	"dinput\dinput.h"
#include	"timer\timer.h"


void	interface_button_create(interface_window_instance *window, interface_button_instance *button, int x, int y, int width, int height, unsigned short tex_id_0, unsigned short tex_id_1)
{
	if(window->button_num == 0)
	{
		button->next		= NULL;
		button->prev		= NULL;

		window->button_first	= button;
		window->button_last		= button;
	}
	else
	{
		button->next		= NULL;
		button->prev		= window->button_last;

		window->button_last->next	= button;
		window->button_last			= button;
	}

	button->button_on					= false;
	button->button_select				= false;
	button->button_active				= false;
	button->button_press				= false;
	button->button_lock					= false;

	button->highlight_mode				= HIGHLIGHT_MODE_NONE;
	button->highlight_way				= HIGHLIGHT_WAY_UP;

	button->x							= x;
	button->y							= y;
	button->width						= width;
	button->height						= height;
	button->tex_id[0]					= tex_id_0;
	button->tex_id[1]					= tex_id_1;
	
	button->fade_mode					= FADE_MODE_NONE;
	button->fade_way					= FADE_WAY_IN;

	window->button_num++;
}

void	interface_button_delete(interface_window_instance *window, interface_button_instance *button)
{
	if(window->button_num == 0) return;

	if(window->button_num == 1)
	{
		window->button_first	= NULL;
		window->button_last	= NULL;
	}
	else
	if(window->button_first == button)
	{
		window->button_first			= button->next;
		window->button_first->prev	= NULL;
	}
	else
	if(window->button_last	==	button)
	{
		window->button_last			=	button->prev;
		window->button_last->next	=	NULL;
	}
	else
	{
		button->next->prev	=	button->prev;
		button->prev->next	=	button->next;
	}

	window->button_num--;

	delete	button;
}

void	interface_button_delete_all(interface_window_instance *window)
{
	interface_button_instance	*button;

	while(window->button_num	!=	0)
	{
		button	=	window->button_first;
		interface_button_delete(window, button);
	}
}

void	interface_button_draw(interface_window_instance *window)
{
	interface_button_instance	*button	=	window->button_first;
	unsigned short				loop;

	glEnable(GL_TEXTURE_2D);

	for(loop = 0; loop < window->button_num; loop++)
	{
		if(button->button_on)
		{
									//	***	[	TEX_ID_00	]

			glColor4f(	button->color_current[0].r,
						button->color_current[0].g,
						button->color_current[0].b,
						button->color_current[0].a);

			glBindTexture(GL_TEXTURE_2D, tex[button->tex_id[0]].texID);

			glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0);
				glVertex2i(button->x,					button->y);
				glTexCoord2f(1.0, 0.0);
				glVertex2i(button->x + button->width,	button->y);
				glTexCoord2f(1.0, 1.0);
				glVertex2i(button->x + button->width,	button->y + button->height);
				glTexCoord2f(0.0, 1.0);
				glVertex2i(button->x,					button->y + button->height);
			glEnd();

									//	***	[	TEX_ID_01	]

			glColor4f(	button->color_current[1].r,
						button->color_current[1].g,
						button->color_current[1].b,
						button->color_current[1].a);

			glBindTexture(GL_TEXTURE_2D, tex[button->tex_id[1]].texID);

			glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0);
				glVertex2i(button->x,					button->y);
				glTexCoord2f(1.0, 0.0);
				glVertex2i(button->x + button->width,	button->y);
				glTexCoord2f(1.0, 1.0);
				glVertex2i(button->x + button->width,	button->y + button->height);
				glTexCoord2f(0.0, 1.0);
				glVertex2i(button->x,					button->y + button->height);
			glEnd();
		}
		
		button	=	button->next;
	}

	glDisable(GL_TEXTURE_2D);
}

void	interface_button_color_normal_create(interface_button_instance *button, unsigned short tex_id, float r, float g, float b, float a) 
{
	button->color_normal[tex_id].r	=	r;
	button->color_normal[tex_id].g	=	g;
	button->color_normal[tex_id].b	=	b;
	button->color_normal[tex_id].a	=	a;
}

void	interface_button_color_active_create(interface_button_instance *button, unsigned short tex_id, float r, float g, float b, float a) 
{
	button->color_active[tex_id].r	=	r;
	button->color_active[tex_id].g	=	g;
	button->color_active[tex_id].b	=	b;
	button->color_active[tex_id].a	=	a;
}

void	interface_button_select_process(interface_window_instance *window)
{
	interface_button_instance	*button	=	window->button_first;
	unsigned short				loop;

	if(!g_interface.cursor.cursor_on)	return;

	for(loop = 0; loop < window->button_num; loop++)
	{
		if(button->button_on)
		{
			button->button_select			=	false;

			if((!button->button_active) && (button->highlight_mode == HIGHLIGHT_MODE_NONE))
			{
				button->color_current[0].r	= button->color_normal[0].r;
				button->color_current[0].g	= button->color_normal[0].g;
				button->color_current[0].b	= button->color_normal[0].b;
				button->color_current[0].a	= button->color_normal[0].a;

				button->color_current[1].r	= button->color_normal[1].r;
				button->color_current[1].g	= button->color_normal[1].g;
				button->color_current[1].b	= button->color_normal[1].b;
				button->color_current[1].a	= button->color_normal[1].a;
			}

			if(	(mouse.x > button->x) && (mouse.x < button->x + button->width) &&
				(mouse.y > button->y) && (mouse.y < button->y + button->height))
			{
				button->button_select		=	true;
			}
		}

		button	=	button->next;
	}
}

void	interface_button_highlight_process(interface_window_instance *window)
{
	interface_button_instance	*button	=	window->button_first;
	unsigned short				loop;
	unsigned short				loop1;

	for(loop = 0; loop < window->button_num; loop++)
	{
		if((button->button_on) && (button->fade_mode == FADE_MODE_NONE))
		{
			if((button->button_select) || (button->button_active))
			{
				if(button->highlight_mode == HIGHLIGHT_MODE_NONE)
				{
					button->highlight_start		=	timerCurrent;
					button->highlight_current	=	timerCurrent;
					button->highlight_length	=	g_interface.highlight_length_default;
					button->highlight_mode		=	HIGHLIGHT_MODE_MIDDLE;
					button->highlight_way		=	HIGHLIGHT_WAY_UP;
				}
				else
				if(button->highlight_mode == HIGHLIGHT_MODE_MIDDLE)
				{
					if(button->highlight_way == HIGHLIGHT_WAY_DOWN)
					{
						button->highlight_start		=	button->highlight_current - (button->highlight_start + button->highlight_length - button->highlight_current);
						button->highlight_way		=	HIGHLIGHT_WAY_UP;
					}

					if(button->highlight_current - button->highlight_start > button->highlight_length)
					{
						button->highlight_start		=	0.0;
						button->highlight_current	=	0.0;
						button->highlight_length	=	0.0;
						button->highlight_mode		=	HIGHLIGHT_MODE_END;
					}
					else
					{
						button->highlight_current	=	timerCurrent;
						button->highlight_way		=	HIGHLIGHT_WAY_UP;
					}
				}
			}
			else
			if((!button->button_select) && (!button->button_active))
			{
				if(button->highlight_way == HIGHLIGHT_WAY_UP)
				{
					button->highlight_start		=	button->highlight_current - (button->highlight_start + button->highlight_length - button->highlight_current);
					button->highlight_way		=	HIGHLIGHT_WAY_DOWN;
				}

				if(button->highlight_mode == HIGHLIGHT_MODE_END)
				{
					button->highlight_start		=	timerCurrent;
					button->highlight_current	=	timerCurrent;
					button->highlight_length	=	g_interface.highlight_length_default;
					button->highlight_mode		=	HIGHLIGHT_MODE_MIDDLE;
					button->highlight_way		=	HIGHLIGHT_WAY_DOWN;
				}
				else
				if(button->highlight_mode == HIGHLIGHT_MODE_MIDDLE)
				{
					if(button->highlight_current - button->highlight_start > button->highlight_length)
					{
						button->highlight_start		=	0.0;
						button->highlight_current	=	0.0;
						button->highlight_length	=	0.0;
						button->highlight_mode		=	HIGHLIGHT_MODE_NONE;
					}
					else
					{
						button->highlight_current	=	timerCurrent;
						button->highlight_way		=	HIGHLIGHT_WAY_DOWN;
					}
				}
			}

			//	***	[	HIGHTLIGHT_PROCESS		]

			float	r,	g,	b,	a;

			if(button->highlight_mode == HIGHLIGHT_MODE_MIDDLE)
			{
				for(loop1 = 0; loop1 < 2; loop1++)
				{
					r	=	button->color_active[loop1].r - button->color_normal[loop1].r;
					g	=	button->color_active[loop1].g - button->color_normal[loop1].g;
					b	=	button->color_active[loop1].b - button->color_normal[loop1].b;
					a	=	button->color_active[loop1].a - button->color_normal[loop1].a;

					if(button->highlight_way == HIGHLIGHT_WAY_UP)
					{
						button->color_current[loop1].r	=	button->color_normal[loop1].r + r * ((button->highlight_current - button->highlight_start) / (float)button->highlight_length);
						button->color_current[loop1].g	=	button->color_normal[loop1].g + g * ((button->highlight_current - button->highlight_start) / (float)button->highlight_length);
						button->color_current[loop1].b	=	button->color_normal[loop1].b + b * ((button->highlight_current - button->highlight_start) / (float)button->highlight_length);
						button->color_current[loop1].a	=	button->color_normal[loop1].a + a * ((button->highlight_current - button->highlight_start) / (float)button->highlight_length);
					}
					else
					{
						button->color_current[loop1].r	=	button->color_active[loop1].r - r * ((button->highlight_current - button->highlight_start) / (float)button->highlight_length);
						button->color_current[loop1].g	=	button->color_active[loop1].g - g * ((button->highlight_current - button->highlight_start) / (float)button->highlight_length);
						button->color_current[loop1].b	=	button->color_active[loop1].b - b * ((button->highlight_current - button->highlight_start) / (float)button->highlight_length);
						button->color_current[loop1].a	=	button->color_active[loop1].a - a * ((button->highlight_current - button->highlight_start) / (float)button->highlight_length);
					}
				}
			}
		}

 		button	=	button->next;
	}
}

void	interface_button_fade_process(interface_window_instance *window)
{
	interface_button_instance	*button	=	window->button_first;
	unsigned short				loop;
	unsigned short				loop1;

	for(loop = 0; loop < window->button_num; loop++)
	{
		if(button->fade_mode	==	FADE_MODE_START)
		{
			button->fade_mode					=	FADE_MODE_MIDDLE;
			button->fade_current				=	timerCurrent;
			button->fade_start					=	timerCurrent;
			button->fade_length					=	g_interface.fade_length_default;
			button->button_on					=	true;

			if(button->fade_way	==	FADE_WAY_IN)
			{
				for(loop1 = 0; loop1 < 2; loop1++)
				{
					button->fade_color_start[loop1].r		=	button->color_normal[loop1].r;
					button->fade_color_start[loop1].g		=	button->color_normal[loop1].g;
					button->fade_color_start[loop1].b		=	button->color_normal[loop1].b;
					button->fade_color_start[loop1].a		=	0.0;

					button->fade_color_end[loop1].r			=	button->color_normal[loop1].r;
					button->fade_color_end[loop1].g			=	button->color_normal[loop1].g;
					button->fade_color_end[loop1].b			=	button->color_normal[loop1].b;
					button->fade_color_end[loop1].a			=	button->color_normal[loop1].a;
				}
			}
			else	//	***	[	FADE_WAY_OUT	]
			{
				for(loop1 = 0; loop1 < 2; loop1++)
				{
					button->fade_color_start[loop1].r		=	button->color_current[loop1].r;
					button->fade_color_start[loop1].g		=	button->color_current[loop1].g;
					button->fade_color_start[loop1].b		=	button->color_current[loop1].b;
					button->fade_color_start[loop1].a		=	button->color_current[loop1].a;

					button->fade_color_end[loop1].r			=	button->color_current[loop1].r;
					button->fade_color_end[loop1].g			=	button->color_current[loop1].g;
					button->fade_color_end[loop1].b			=	button->color_current[loop1].b;
					button->fade_color_end[loop1].a			=	0.0;
				}
			}
		}
		else
		if(button->fade_mode	==	FADE_MODE_MIDDLE)
		{
			button->fade_current				=	timerCurrent;

			if(button->fade_current - button->fade_start > button->fade_length)
			{
				button->fade_mode				=	FADE_MODE_NONE;

				if(button->fade_way	==	FADE_WAY_IN)	
				{
					button->fade_way	=	FADE_WAY_OUT;
					button->button_on	=	true;
				}
				else
				{
					button->fade_way	=	FADE_WAY_IN;
					button->button_on	=	false;
				}

				button->highlight_mode	=	HIGHLIGHT_MODE_NONE;

				for(loop1 = 0; loop1 < 2; loop1++)
				{
					button->color_current[loop1].r	=	button->fade_color_end[loop1].r;
					button->color_current[loop1].g	=	button->fade_color_end[loop1].g;
					button->color_current[loop1].b	=	button->fade_color_end[loop1].b;
					button->color_current[loop1].a	=	button->fade_color_end[loop1].a;
				}

				return;
			}
		}

		//	***	[	FADE_PROCESS	]

		if((button->button_on) && (button->fade_mode != FADE_MODE_NONE))
		{
			float	r,	g,	b,	a;

			for(loop1 = 0; loop1 < 2; loop1++)
			{
				r	=	button->fade_color_end[loop1].r - button->fade_color_start[loop1].r;
				g	=	button->fade_color_end[loop1].g - button->fade_color_start[loop1].g;
				b	=	button->fade_color_end[loop1].b - button->fade_color_start[loop1].b;
				a	=	button->fade_color_end[loop1].a - button->fade_color_start[loop1].a;

				button->color_current[loop1].r	=	button->fade_color_start[loop1].r + r * ((button->fade_current - button->fade_start) / (float)button->fade_length);
				button->color_current[loop1].g	=	button->fade_color_start[loop1].g + g * ((button->fade_current - button->fade_start) / (float)button->fade_length);
				button->color_current[loop1].b	=	button->fade_color_start[loop1].b + b * ((button->fade_current - button->fade_start) / (float)button->fade_length);
				button->color_current[loop1].a	=	button->fade_color_start[loop1].a + a * ((button->fade_current - button->fade_start) / (float)button->fade_length);
			}
		}

 		button	=	button->next;
	}
}

void	interface_button_press_process(interface_window_instance *window)
{
	interface_button_instance	*button	=	window->button_first;
	unsigned short				loop;

	for(loop = 0; loop < window->button_num; loop++)
	{
		button->button_press	= false;

		if(	(button->button_on) && (button->button_select) && 
			(!button->button_lock) &&
			(button->fade_mode == FADE_MODE_NONE) &&
			(mouse.statuss[m_LBUTTON] == b_PRESS))
		{
			if(button->button_active)
			{
				button->button_active	= false;
			}
			else
			{
				button->button_active	= true;
			}

			button->button_press	= true;
		}

		button	=	button->next;
	}
}	
