


#include	"main\main.h"
#include	"interface\interface.h"
#include	"texture\texture.h"
#include	"dinput\dinput.h"
#include	"timer\timer.h"


void	interface_scroll_bar_create(interface_window_instance *window, interface_scroll_bar_instance *scroll_bar, unsigned short scroll_bar_mode, float scroll_start, float scroll_end, float scroll_step, float scroll_current)
{
	if(window->scroll_bar_num == 0)
	{
		scroll_bar->next				= NULL;
		scroll_bar->prev				= NULL;

		window->scroll_bar_first		= scroll_bar;
		window->scroll_bar_last			= scroll_bar;
	}
	else
	{
		scroll_bar->next				= NULL;
		scroll_bar->prev				= window->scroll_bar_last;

		window->scroll_bar_last->next	= scroll_bar;
		window->scroll_bar_last			= scroll_bar;
	}

	scroll_bar->scroll_bar_on			= false;

	scroll_bar->scroll_bar_select[0]	= false;
	scroll_bar->scroll_bar_select[1]	= false;
	scroll_bar->scroll_bar_select[2]	= false;
	scroll_bar->scroll_bar_select[3]	= false;

	scroll_bar->scroll_bar_press[0]		= false;
	scroll_bar->scroll_bar_press[1]		= false;
	scroll_bar->scroll_bar_press[2]		= false;
	scroll_bar->scroll_bar_press[3]		= false;

	scroll_bar->scroll_bar_mode			= scroll_bar_mode;

	scroll_bar->highlight_mode[0]		= HIGHLIGHT_MODE_NONE;
	scroll_bar->highlight_mode[1]		= HIGHLIGHT_MODE_NONE;
	scroll_bar->highlight_mode[2]		= HIGHLIGHT_MODE_NONE;
	scroll_bar->highlight_mode[3]		= HIGHLIGHT_MODE_NONE;

	scroll_bar->highlight_way[0]		= HIGHLIGHT_WAY_UP;
	scroll_bar->highlight_way[1]		= HIGHLIGHT_WAY_UP;
	scroll_bar->highlight_way[2]		= HIGHLIGHT_WAY_UP;
	scroll_bar->highlight_way[3]		= HIGHLIGHT_WAY_UP;

	scroll_bar->fade_mode				= FADE_MODE_NONE;
	scroll_bar->fade_way				= FADE_WAY_IN;

	scroll_bar->scroll_bar_max			= scroll_end;
	scroll_bar->scroll_bar_min			= scroll_start;
	scroll_bar->scroll_bar_current		= scroll_current;
	scroll_bar->scroll_bar_step			= scroll_step;

	window->scroll_bar_num++;
}

void	interface_scroll_bar_element_create(interface_scroll_bar_instance *scroll_bar, unsigned short element_id, int x, int y, int width, int height, unsigned short tex_id_0, unsigned short tex_id_1)
{
	scroll_bar->x[element_id]			= x;
	scroll_bar->y[element_id]			= y;
	scroll_bar->width[element_id]		= width;
	scroll_bar->height[element_id]		= height;
	scroll_bar->tex_id[element_id][0]	= tex_id_0;
	scroll_bar->tex_id[element_id][1]	= tex_id_1;
}

void	interface_scroll_bar_delete(interface_window_instance *window, interface_scroll_bar_instance *scroll_bar)
{
	if(window->scroll_bar_num == 0) return;

	if(window->scroll_bar_num == 1)
	{
		window->scroll_bar_first	= NULL;
		window->scroll_bar_last		= NULL;
	}
	else
	if(window->scroll_bar_first == scroll_bar)
	{
		window->scroll_bar_first		= scroll_bar->next;
		window->scroll_bar_first->prev	= NULL;
	}
	else
	if(window->scroll_bar_last	==	scroll_bar)
	{
		window->scroll_bar_last			=	scroll_bar->prev;
		window->scroll_bar_last->next	=	NULL;
	}
	else
	{
		scroll_bar->next->prev	=	scroll_bar->prev;
		scroll_bar->prev->next	=	scroll_bar->next;
	}

	window->scroll_bar_num--;

	delete	scroll_bar;
}

void	interface_scroll_bar_delete_all(interface_window_instance *window)
{
	interface_scroll_bar_instance	*scroll_bar;

	while(window->scroll_bar_num	!=	0)
	{
		scroll_bar	=	window->scroll_bar_first;
		interface_scroll_bar_delete(window, scroll_bar);
	}
}

void	interface_scroll_bar_draw(interface_window_instance *window)
{
	interface_scroll_bar_instance	*scroll_bar	=	window->scroll_bar_first;
	unsigned short					loop;
	unsigned short					loop1;

	glEnable(GL_TEXTURE_2D);

	for(loop = 0; loop < window->scroll_bar_num; loop++)
	{
		for(loop1 = 0; loop1 < 4; loop1++)
		{
			if(scroll_bar->scroll_bar_on)
			{
				if(loop1 == 3)
				{
					if(scroll_bar->scroll_bar_mode == SCROLL_BAR_MODE_HORIZONTAL)
					{
						scroll_bar->x[3]	= scroll_bar->x[2] +scroll_bar->width[3] / 2.0 + scroll_bar->scroll_bar_current / (scroll_bar->scroll_bar_max - scroll_bar->scroll_bar_min) * (scroll_bar->width[2] - scroll_bar->width[3] * 2);
					}

					if(scroll_bar->scroll_bar_mode == SCROLL_BAR_MODE_VERTICAL)
					{
						scroll_bar->y[3]	= scroll_bar->y[0] -scroll_bar->height[3] * 1.5 - scroll_bar->scroll_bar_current / (scroll_bar->scroll_bar_max - scroll_bar->scroll_bar_min) * (scroll_bar->height[2] - scroll_bar->height[3] * 2);
					}
				}
									//	***	[	TEX_ID_00	]

				glColor4f(	scroll_bar->color_current[loop1][0].r,
							scroll_bar->color_current[loop1][0].g,
							scroll_bar->color_current[loop1][0].b,
							scroll_bar->color_current[loop1][0].a);

				glBindTexture(GL_TEXTURE_2D, tex[scroll_bar->tex_id[loop1][0]].texID);

				glBegin(GL_QUADS);
					if(scroll_bar->scroll_bar_mode == SCROLL_BAR_MODE_HORIZONTAL)
					{
						glTexCoord2f(0.0, 0.0);
						glVertex2i(scroll_bar->x[loop1],							scroll_bar->y[loop1]);
						glTexCoord2f(1.0, 0.0);
						glVertex2i(scroll_bar->x[loop1] + scroll_bar->width[loop1],	scroll_bar->y[loop1]);
						glTexCoord2f(1.0, 1.0);
						glVertex2i(scroll_bar->x[loop1] + scroll_bar->width[loop1],	scroll_bar->y[loop1] + scroll_bar->height[loop1]);
						glTexCoord2f(0.0, 1.0);
						glVertex2i(scroll_bar->x[loop1],							scroll_bar->y[loop1] + scroll_bar->height[loop1]);
					}
					else
					{
						glTexCoord2f(1.0, 0.0);
						glVertex2i(scroll_bar->x[loop1],							scroll_bar->y[loop1]);
						glTexCoord2f(1.0, 1.0);
						glVertex2i(scroll_bar->x[loop1] + scroll_bar->width[loop1],	scroll_bar->y[loop1]);
						glTexCoord2f(0.0, 1.0);
						glVertex2i(scroll_bar->x[loop1] + scroll_bar->width[loop1],	scroll_bar->y[loop1] + scroll_bar->height[loop1]);
						glTexCoord2f(0.0, 0.0);
						glVertex2i(scroll_bar->x[loop1],							scroll_bar->y[loop1] + scroll_bar->height[loop1]);
					}
				glEnd();

									//	***	[	TEX_ID_01	]

				glColor4f(	scroll_bar->color_current[loop1][1].r,
							scroll_bar->color_current[loop1][1].g,
							scroll_bar->color_current[loop1][1].b,
							scroll_bar->color_current[loop1][1].a);

				glBindTexture(GL_TEXTURE_2D, tex[scroll_bar->tex_id[loop1][1]].texID);

				glBegin(GL_QUADS);
					if(scroll_bar->scroll_bar_mode == SCROLL_BAR_MODE_HORIZONTAL)
					{
						glTexCoord2f(0.0, 0.0);
						glVertex2i(scroll_bar->x[loop1],							scroll_bar->y[loop1]);
						glTexCoord2f(1.0, 0.0);
						glVertex2i(scroll_bar->x[loop1] + scroll_bar->width[loop1],	scroll_bar->y[loop1]);
						glTexCoord2f(1.0, 1.0);
						glVertex2i(scroll_bar->x[loop1] + scroll_bar->width[loop1],	scroll_bar->y[loop1] + scroll_bar->height[loop1]);
						glTexCoord2f(0.0, 1.0);
						glVertex2i(scroll_bar->x[loop1],							scroll_bar->y[loop1] + scroll_bar->height[loop1]);
					}
					else
					{
						glTexCoord2f(1.0, 0.0);
						glVertex2i(scroll_bar->x[loop1],							scroll_bar->y[loop1]);
						glTexCoord2f(1.0, 1.0);
						glVertex2i(scroll_bar->x[loop1] + scroll_bar->width[loop1],	scroll_bar->y[loop1]);
						glTexCoord2f(0.0, 1.0);
						glVertex2i(scroll_bar->x[loop1] + scroll_bar->width[loop1],	scroll_bar->y[loop1] + scroll_bar->height[loop1]);
						glTexCoord2f(0.0, 0.0);
						glVertex2i(scroll_bar->x[loop1],							scroll_bar->y[loop1] + scroll_bar->height[loop1]);
					}
				glEnd();
			}
		}

		scroll_bar	= scroll_bar->next;
	}

	glDisable(GL_TEXTURE_2D);
}

void	interface_scroll_bar_color_normal_create(interface_scroll_bar_instance *scroll_bar, unsigned short element_id, unsigned short tex_id, float r, float g, float b, float a) 
{
	scroll_bar->color_normal[element_id][tex_id].r	=	r;
	scroll_bar->color_normal[element_id][tex_id].b	=	b;
	scroll_bar->color_normal[element_id][tex_id].g	=	g;
	scroll_bar->color_normal[element_id][tex_id].a	=	a;
}

void	interface_scroll_bar_color_active_create(interface_scroll_bar_instance *scroll_bar, unsigned short element_id, unsigned short tex_id, float r, float g, float b, float a) 
{
	scroll_bar->color_active[element_id][tex_id].r	=	r;
	scroll_bar->color_active[element_id][tex_id].b	=	b;
	scroll_bar->color_active[element_id][tex_id].g	=	g;
	scroll_bar->color_active[element_id][tex_id].a	=	a;
}

void	interface_scroll_bar_select_process(interface_window_instance *window)
{
	interface_scroll_bar_instance	*scroll_bar	=	window->scroll_bar_first;
	unsigned short					loop;
	unsigned short					loop1;

	if(!g_interface.cursor.cursor_on)	return;


	for(loop = 0; loop < window->scroll_bar_num; loop++)
	{
		if(scroll_bar->scroll_bar_on)
		{
			for(loop1 = 0; loop1 < 4; loop1++)
			{
				scroll_bar->scroll_bar_select[loop1]	=	false;

				if(	(mouse.x > scroll_bar->x[loop1]) && (mouse.x < scroll_bar->x[loop1] + scroll_bar->width[loop1]) &&
					(mouse.y > scroll_bar->y[loop1]) && (mouse.y < scroll_bar->y[loop1] + scroll_bar->height[loop1]))
				{
					scroll_bar->scroll_bar_select[loop1]	=	true;
				}
			}

			if(scroll_bar->scroll_bar_select[3])	scroll_bar->scroll_bar_select[2]	= false;
		}

		scroll_bar	=	scroll_bar->next;
	}
}

void	interface_scroll_bar_highlight_process(interface_window_instance *window)
{
	interface_scroll_bar_instance	*scroll_bar	=	window->scroll_bar_first;
	unsigned short					loop;
	unsigned short					loop1;
	unsigned short					loop2;

	for(loop = 0; loop < window->scroll_bar_num; loop++)
	{
		if((scroll_bar->scroll_bar_on) && (scroll_bar->fade_mode == FADE_MODE_NONE))
		{
			for(loop2 = 0; loop2 < 4; loop2++)
			{
				if(scroll_bar->scroll_bar_select[loop2])
				{
					if(scroll_bar->highlight_mode[loop2] == HIGHLIGHT_MODE_NONE)
					{
						scroll_bar->highlight_start[loop2]		=	timerCurrent;
						scroll_bar->highlight_current[loop2]	=	timerCurrent;
						scroll_bar->highlight_length[loop2]		=	g_interface.highlight_length_default;
						scroll_bar->highlight_mode[loop2]		=	HIGHLIGHT_MODE_MIDDLE;
						scroll_bar->highlight_way[loop2]		=	HIGHLIGHT_WAY_UP;
					}
					else
					if(scroll_bar->highlight_mode[loop2] == HIGHLIGHT_MODE_MIDDLE)
					{
						if(scroll_bar->highlight_way[loop2] == HIGHLIGHT_WAY_DOWN)
						{
							scroll_bar->highlight_start[loop2]		=	scroll_bar->highlight_current[loop2] - (scroll_bar->highlight_start[loop2] + scroll_bar->highlight_length[loop2] - scroll_bar->highlight_current[loop2]);
							scroll_bar->highlight_way[loop2]		=	HIGHLIGHT_WAY_UP;
						}

						if(scroll_bar->highlight_current[loop2] - scroll_bar->highlight_start[loop2] > scroll_bar->highlight_length[loop2])
						{
							scroll_bar->highlight_start[loop2]		=	0.0;
							scroll_bar->highlight_current[loop2]	=	0.0;
							scroll_bar->highlight_length[loop2]		=	0.0;
							scroll_bar->highlight_mode[loop2]		=	HIGHLIGHT_MODE_END;
						}
						else
						{
							scroll_bar->highlight_current[loop2]	=	timerCurrent;
							scroll_bar->highlight_way[loop2]		=	HIGHLIGHT_WAY_UP;
						}
					}
				}
				else
				if(!scroll_bar->scroll_bar_select[loop2])
				{
					if(scroll_bar->highlight_way[loop2] == HIGHLIGHT_WAY_UP)
					{
						scroll_bar->highlight_start[loop2]		=	scroll_bar->highlight_current[loop2] - (scroll_bar->highlight_start[loop2] + scroll_bar->highlight_length[loop2] - scroll_bar->highlight_current[loop2]);
						scroll_bar->highlight_way[loop2]		=	HIGHLIGHT_WAY_DOWN;
					}

					if(scroll_bar->highlight_mode[loop2] == HIGHLIGHT_MODE_END)
					{
						scroll_bar->highlight_start[loop2]		=	timerCurrent;
						scroll_bar->highlight_current[loop2]	=	timerCurrent;
						scroll_bar->highlight_length[loop2]		=	g_interface.highlight_length_default;
						scroll_bar->highlight_mode[loop2]		=	HIGHLIGHT_MODE_MIDDLE;
						scroll_bar->highlight_way[loop2]		=	HIGHLIGHT_WAY_DOWN;
					}
					else
					if(scroll_bar->highlight_mode[loop2] == HIGHLIGHT_MODE_MIDDLE)
					{
						if(scroll_bar->highlight_current[loop2] - scroll_bar->highlight_start[loop2] > scroll_bar->highlight_length[loop2])
						{
							scroll_bar->highlight_start[loop2]		=	0.0;
							scroll_bar->highlight_current[loop2]	=	0.0;
							scroll_bar->highlight_length[loop2]		=	0.0;
							scroll_bar->highlight_mode[loop2]		=	HIGHLIGHT_MODE_NONE;
						}
						else
						{
							scroll_bar->highlight_current[loop2]	=	timerCurrent;
							scroll_bar->highlight_way[loop2]		=	HIGHLIGHT_WAY_DOWN;
						}
					}
				}
			}

			//	***	[	HIGHTLIGHT_PROCESS		]

			float	r,	g,	b,	a;

			for(loop2 = 0; loop2 < 4; loop2++)
			{
				if(scroll_bar->highlight_mode[loop2] == HIGHLIGHT_MODE_MIDDLE)
				{
					for(loop1 = 0; loop1 < 2; loop1++)
					{
						r	=	scroll_bar->color_active[loop2][loop1].r - scroll_bar->color_normal[loop2][loop1].r;
						g	=	scroll_bar->color_active[loop2][loop1].g - scroll_bar->color_normal[loop2][loop1].g;
						b	=	scroll_bar->color_active[loop2][loop1].b - scroll_bar->color_normal[loop2][loop1].b;
						a	=	scroll_bar->color_active[loop2][loop1].a - scroll_bar->color_normal[loop2][loop1].a;
	
						if(scroll_bar->highlight_way[loop2] == HIGHLIGHT_WAY_UP)
						{
							scroll_bar->color_current[loop2][loop1].r	=	scroll_bar->color_normal[loop2][loop1].r + r * ((scroll_bar->highlight_current[loop2] - scroll_bar->highlight_start[loop2]) / (float)scroll_bar->highlight_length[loop2]);
							scroll_bar->color_current[loop2][loop1].g	=	scroll_bar->color_normal[loop2][loop1].g + g * ((scroll_bar->highlight_current[loop2] - scroll_bar->highlight_start[loop2]) / (float)scroll_bar->highlight_length[loop2]);
							scroll_bar->color_current[loop2][loop1].b	=	scroll_bar->color_normal[loop2][loop1].b + b * ((scroll_bar->highlight_current[loop2] - scroll_bar->highlight_start[loop2]) / (float)scroll_bar->highlight_length[loop2]);
							scroll_bar->color_current[loop2][loop1].a	=	scroll_bar->color_normal[loop2][loop1].a + a * ((scroll_bar->highlight_current[loop2] - scroll_bar->highlight_start[loop2]) / (float)scroll_bar->highlight_length[loop2]);
						}
						else
						{
							scroll_bar->color_current[loop2][loop1].r	=	scroll_bar->color_active[loop2][loop1].r - r * ((scroll_bar->highlight_current[loop2] - scroll_bar->highlight_start[loop2]) / (float)scroll_bar->highlight_length[loop2]);
							scroll_bar->color_current[loop2][loop1].g	=	scroll_bar->color_active[loop2][loop1].g - g * ((scroll_bar->highlight_current[loop2] - scroll_bar->highlight_start[loop2]) / (float)scroll_bar->highlight_length[loop2]);
							scroll_bar->color_current[loop2][loop1].b	=	scroll_bar->color_active[loop2][loop1].b - b * ((scroll_bar->highlight_current[loop2] - scroll_bar->highlight_start[loop2]) / (float)scroll_bar->highlight_length[loop2]);
							scroll_bar->color_current[loop2][loop1].a	=	scroll_bar->color_active[loop2][loop1].a - a * ((scroll_bar->highlight_current[loop2] - scroll_bar->highlight_start[loop2]) / (float)scroll_bar->highlight_length[loop2]);
						}
					}
				}
			}
		}

 		scroll_bar	=	scroll_bar->next;
	}
}

void	interface_scroll_bar_fade_process(interface_window_instance *window)
{
	interface_scroll_bar_instance	*scroll_bar	=	window->scroll_bar_first;
	unsigned short					loop;
	unsigned short					loop1;
	unsigned short					loop2;

	for(loop = 0; loop < window->scroll_bar_num; loop++)
	{
		if(scroll_bar->fade_mode	==	FADE_MODE_START)
		{
			scroll_bar->fade_mode					=	FADE_MODE_MIDDLE;
			scroll_bar->fade_current				=	timerCurrent;
			scroll_bar->fade_start					=	timerCurrent;
			scroll_bar->fade_length					=	g_interface.fade_length_default;
			scroll_bar->scroll_bar_on				=	true;

			for(loop2 = 0; loop2 < 4; loop2++)
			{
				if(scroll_bar->fade_way	==	FADE_WAY_IN)
				{
					for(loop1 = 0; loop1 < 2; loop1++)
					{
						scroll_bar->fade_color_start[loop2][loop1].r		=	scroll_bar->color_normal[loop2][loop1].r;
						scroll_bar->fade_color_start[loop2][loop1].g		=	scroll_bar->color_normal[loop2][loop1].g;
						scroll_bar->fade_color_start[loop2][loop1].b		=	scroll_bar->color_normal[loop2][loop1].b;
						scroll_bar->fade_color_start[loop2][loop1].a		=	0.0;

						scroll_bar->fade_color_end[loop2][loop1].r			=	scroll_bar->color_normal[loop2][loop1].r;
						scroll_bar->fade_color_end[loop2][loop1].g			=	scroll_bar->color_normal[loop2][loop1].g;
						scroll_bar->fade_color_end[loop2][loop1].b			=	scroll_bar->color_normal[loop2][loop1].b;
						scroll_bar->fade_color_end[loop2][loop1].a			=	scroll_bar->color_normal[loop2][loop1].a;
					}
				}
				else	//	***	[	FADE_WAY_OUT	]
				{
					for(loop1 = 0; loop1 < 2; loop1++)
					{
						scroll_bar->fade_color_start[loop2][loop1].r		=	scroll_bar->color_current[loop2][loop1].r;
						scroll_bar->fade_color_start[loop2][loop1].g		=	scroll_bar->color_current[loop2][loop1].g;
						scroll_bar->fade_color_start[loop2][loop1].b		=	scroll_bar->color_current[loop2][loop1].b;
						scroll_bar->fade_color_start[loop2][loop1].a		=	scroll_bar->color_current[loop2][loop1].a;

						scroll_bar->fade_color_end[loop2][loop1].r			=	scroll_bar->color_current[loop2][loop1].r;
						scroll_bar->fade_color_end[loop2][loop1].g			=	scroll_bar->color_current[loop2][loop1].g;
						scroll_bar->fade_color_end[loop2][loop1].b			=	scroll_bar->color_current[loop2][loop1].b;
						scroll_bar->fade_color_end[loop2][loop1].a			=	0.0;
					}
				}
			}
		}
		else
		if(scroll_bar->fade_mode	==	FADE_MODE_MIDDLE)
		{
			scroll_bar->fade_current	=	timerCurrent;
	
			if(scroll_bar->fade_current - scroll_bar->fade_start > scroll_bar->fade_length)
			{
				scroll_bar->fade_mode				=	FADE_MODE_NONE;

				if(scroll_bar->fade_way	==	FADE_WAY_IN)	
				{
					scroll_bar->fade_way	=	FADE_WAY_OUT;
					scroll_bar->scroll_bar_on	=	true;
				}
				else
				{
					scroll_bar->fade_way	=	FADE_WAY_IN;
					scroll_bar->scroll_bar_on	=	false;
				}

				for(loop2 = 0; loop2 < 4; loop2++)
				{
					scroll_bar->highlight_mode[loop2]	=	HIGHLIGHT_MODE_NONE;

					for(loop1 = 0; loop1 < 2; loop1++)
					{
						scroll_bar->color_current[loop2][loop1].r	=	scroll_bar->fade_color_end[loop2][loop1].r;
						scroll_bar->color_current[loop2][loop1].g	=	scroll_bar->fade_color_end[loop2][loop1].g;
						scroll_bar->color_current[loop2][loop1].b	=	scroll_bar->fade_color_end[loop2][loop1].b;
						scroll_bar->color_current[loop2][loop1].a	=	scroll_bar->fade_color_end[loop2][loop1].a;
					}
				}

				return;
			}
		}

		//	***	[	FADE_PROCESS	]

		if((scroll_bar->scroll_bar_on) && (scroll_bar->fade_mode != FADE_MODE_NONE))
		{
			float	r,	g,	b,	a;

			for(loop2 = 0; loop2 < 4; loop2++)
			{
				for(loop1 = 0; loop1 < 2; loop1++)
				{
					r	=	scroll_bar->fade_color_end[loop2][loop1].r - scroll_bar->fade_color_start[loop2][loop1].r;
					g	=	scroll_bar->fade_color_end[loop2][loop1].g - scroll_bar->fade_color_start[loop2][loop1].g;
					b	=	scroll_bar->fade_color_end[loop2][loop1].b - scroll_bar->fade_color_start[loop2][loop1].b;
					a	=	scroll_bar->fade_color_end[loop2][loop1].a - scroll_bar->fade_color_start[loop2][loop1].a;

					scroll_bar->color_current[loop2][loop1].r	=	scroll_bar->fade_color_start[loop2][loop1].r + r * ((scroll_bar->fade_current - scroll_bar->fade_start) / (float)scroll_bar->fade_length);
					scroll_bar->color_current[loop2][loop1].g	=	scroll_bar->fade_color_start[loop2][loop1].g + g * ((scroll_bar->fade_current - scroll_bar->fade_start) / (float)scroll_bar->fade_length);
					scroll_bar->color_current[loop2][loop1].b	=	scroll_bar->fade_color_start[loop2][loop1].b + b * ((scroll_bar->fade_current - scroll_bar->fade_start) / (float)scroll_bar->fade_length);
					scroll_bar->color_current[loop2][loop1].a	=	scroll_bar->fade_color_start[loop2][loop1].a + a * ((scroll_bar->fade_current - scroll_bar->fade_start) / (float)scroll_bar->fade_length);
				}
			}
		}

 		scroll_bar	=	scroll_bar->next;
	}
}

void	interface_scroll_bar_press_process(interface_window_instance *window)
{
	interface_scroll_bar_instance	*scroll_bar	=	window->scroll_bar_first;
	unsigned short					loop;
	unsigned short					loop1;

	for(loop = 0; loop < window->scroll_bar_num; loop++)
	{
		for(loop1 = 0; loop1 < 4; loop1++)
		{
			scroll_bar->scroll_bar_press[0]	= false;

			if(	(scroll_bar->scroll_bar_on) && 
				(scroll_bar->scroll_bar_select[loop1]) && 
				(scroll_bar->fade_mode == FADE_MODE_NONE) &&
				(mouse.statuss[m_LBUTTON] == b_PRESS))
			{
				scroll_bar->scroll_bar_press[loop1]	= true;

				if(loop1 == 0)
				{
					scroll_bar->scroll_bar_current	-= scroll_bar->scroll_bar_step;
				}
				else
				if(loop1 == 1)
				{
					scroll_bar->scroll_bar_current	+= scroll_bar->scroll_bar_step;
				}
				else
				if(((loop1 == 2) || (loop1 == 3)) && (scroll_bar->scroll_bar_mode == SCROLL_BAR_MODE_HORIZONTAL))
				{
					scroll_bar->scroll_bar_current	=	(mouse.x - scroll_bar->x[2] - scroll_bar->width[3] / 2.0) / (float)(scroll_bar->width[2] - scroll_bar->width[3]);
					scroll_bar->scroll_bar_current	*=	(scroll_bar->scroll_bar_max - scroll_bar->scroll_bar_min);
				}
				else
				if(((loop1 == 2) || (loop1 == 3)) && (scroll_bar->scroll_bar_mode == SCROLL_BAR_MODE_VERTICAL))
				{
					scroll_bar->scroll_bar_current	=	(scroll_bar->y[2] + scroll_bar->height[2] - mouse.y - scroll_bar->height[3] / 2.0) / (float)(scroll_bar->height[2] - scroll_bar->height[3]);
					scroll_bar->scroll_bar_current	*=	(scroll_bar->scroll_bar_max - scroll_bar->scroll_bar_min);
				}

				if(scroll_bar->scroll_bar_current < scroll_bar->scroll_bar_min)	scroll_bar->scroll_bar_current = scroll_bar->scroll_bar_min;
				if(scroll_bar->scroll_bar_current > scroll_bar->scroll_bar_max)	scroll_bar->scroll_bar_current = scroll_bar->scroll_bar_max;
			}

			if(	(scroll_bar->scroll_bar_on) && 
				(scroll_bar->scroll_bar_select[loop1]) && 
				(scroll_bar->fade_mode == FADE_MODE_NONE) &&
				(mouse.statuss[m_LBUTTON] == b_HOLD))
			{
				scroll_bar->scroll_bar_press[loop1]	= true;

				if(((loop1 == 2) || (loop1 == 3)) && (scroll_bar->scroll_bar_mode == SCROLL_BAR_MODE_HORIZONTAL))
				{
					scroll_bar->scroll_bar_current	=	(mouse.x - scroll_bar->x[2] - scroll_bar->width[3] / 2.0) / (float)(scroll_bar->width[2] - scroll_bar->width[3]);
					scroll_bar->scroll_bar_current	*=	(scroll_bar->scroll_bar_max - scroll_bar->scroll_bar_min);
				}
				else
				if(((loop1 == 2) || (loop1 == 3)) && (scroll_bar->scroll_bar_mode == SCROLL_BAR_MODE_VERTICAL))
				{
					scroll_bar->scroll_bar_current	=	(scroll_bar->y[2] + scroll_bar->height[2] - mouse.y - scroll_bar->height[3] / 2.0) / (float)(scroll_bar->height[2] - scroll_bar->height[3]);
					scroll_bar->scroll_bar_current	*=	(scroll_bar->scroll_bar_max - scroll_bar->scroll_bar_min);
				}

				if(scroll_bar->scroll_bar_current < scroll_bar->scroll_bar_min)	scroll_bar->scroll_bar_current = scroll_bar->scroll_bar_min;
				if(scroll_bar->scroll_bar_current > scroll_bar->scroll_bar_max)	scroll_bar->scroll_bar_current = scroll_bar->scroll_bar_max;
			}
		}

		scroll_bar	= scroll_bar->next;
	}
}	
