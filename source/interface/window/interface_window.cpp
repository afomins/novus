


#include	"main\main.h"
#include	"interface\interface.h"
#include	"texture\texture.h"
#include	"dinput\dinput.h"
#include	"timer\timer.h"


void	interface_window_create(interface_window_instance *window)
{
	if(g_interface.window_num == 0)
	{
		window->next		= NULL;
		window->prev		= NULL;

		g_interface.window_first	= window;
		g_interface.window_last		= window;
	}
	else
	{
		window->next		= NULL;
		window->prev		= g_interface.window_last;

		g_interface.window_last->next	= window;
		g_interface.window_last			= window;
	}

	window->window_on					= false;
	
	window->fade_mode					= FADE_MODE_START;
	window->fade_way					= FADE_WAY_IN;

	window->button_first				= NULL;
	window->button_last					= NULL;

	window->rectangle_first				= NULL;
	window->rectangle_last				= NULL;

	window->scroll_bar_first			= NULL;
	window->scroll_bar_last				= NULL;


	window->button_num					= 0;
	window->rectangle_num				= 0;
	window->scroll_bar_num				= 0;

	g_interface.window_num++;
}

void	interface_window_delete(interface_window_instance *window)
{
	if(g_interface.window_num	==	0)		return;

	if(g_interface.window_num	==	1)
	{
		g_interface.window_first	=	NULL;
		g_interface.window_last		=	NULL;
	}
	else
	if(g_interface.window_first == window)
	{
		g_interface.window_first		=	window->next;
		g_interface.window_first->prev	=	NULL;
	}
	else
	if(g_interface.window_last	==	window)
	{
		g_interface.window_last			=	window->prev;
		g_interface.window_last->next	=	NULL;
	}
	else
	{
		window->next->prev	=	window->prev;
		window->prev->next	=	window->next;
	}

	interface_button_delete_all(window);
	interface_rectangle_delete_all(window);
	interface_scroll_bar_delete_all(window);

	g_interface.window_num--;

	delete	window;
}

void	interface_window_delete_all()
{
	interface_window_instance	*window;

	while(g_interface.window_num	!=	0)
	{
		window	=	g_interface.window_first;
		interface_window_delete(window);
	}
}

void	interface_window_draw()
{
	interface_window_instance		*w	= g_interface.window_first;
	unsigned short					loop;

	for(loop = 0; loop < g_interface.window_num; loop++)
	{
		if(w->window_on)
		{
			if(w->rectangle_num != 0)	interface_rectangle_draw(w);
			if(w->button_num != 0)		interface_button_draw(w);
			if(w->scroll_bar_num != 0)	interface_scroll_bar_draw(w);
		}

		w	= w->next;
	}
}

void	interface_window_process()
{
	interface_window_instance		*w	= g_interface.window_first;
	interface_rectangle_instance	*r;
	interface_button_instance		*b;
	interface_scroll_bar_instance	*s;
	unsigned short					loop;
	unsigned short					loop_w;
	bool							fade_end;


	for(loop_w = 0; loop_w < g_interface.window_num; loop_w++)
	{
		if((w->window_on) && (w->fade_mode == FADE_MODE_NONE))
		{
			interface_button_press_process(w);
			interface_button_select_process(w);
			interface_button_highlight_process(w);
			interface_button_fade_process(w);

			interface_scroll_bar_press_process(w);
			interface_scroll_bar_select_process(w);
			interface_scroll_bar_highlight_process(w);
			interface_scroll_bar_fade_process(w);

			interface_rectangle_fade_process(w);
		}
		else
		if(w->fade_mode == FADE_MODE_START)
		{
			w->fade_mode	= FADE_MODE_MIDDLE;
			w->window_on	= true;
			b				= w->button_first;
			r				= w->rectangle_first;
			s				= w->scroll_bar_first;

			for(loop = 0; loop < w->button_num; loop++)
			{
				if((w->fade_way == FADE_WAY_OUT) && (b->button_on))	
				{
					b->fade_mode	= FADE_MODE_START;
				}
				else
				if((w->fade_way == FADE_WAY_IN) && (!b->button_on))	
				{
					b->fade_mode	= FADE_MODE_START;
				}

				b	= b->next;
			}

			for(loop = 0; loop < w->scroll_bar_num; loop++)
			{
				if((w->fade_way == FADE_WAY_OUT) && (s->scroll_bar_on))	
				{
					s->fade_mode	= FADE_MODE_START;
				}
				else
				if((w->fade_way == FADE_WAY_IN) && (!s->scroll_bar_on))	
				{
					s->fade_mode	= FADE_MODE_START;
				}

				s	= s->next;
			}

			for(loop = 0; loop < w->rectangle_num; loop++)
			{
				if((w->fade_way == FADE_WAY_OUT) && (r->rectangle_on))	
				{
					r->fade_mode	= FADE_MODE_START;
				}
				else
				if((w->fade_way == FADE_WAY_IN) && (!r->rectangle_on))	
				{
					r->fade_mode	= FADE_MODE_START;
				}

				r	= r->next;
			}

			interface_button_fade_process(w);
			interface_scroll_bar_fade_process(w);
			interface_rectangle_fade_process(w);
		}
		else
		if(w->fade_mode == FADE_MODE_MIDDLE)
		{
			b				= w->button_first;
			r				= w->rectangle_first;
			s				= w->scroll_bar_first;
			fade_end		= true;

			for(loop = 0; loop < w->button_num; loop++)
			{
				if(b->fade_mode == FADE_MODE_MIDDLE)
				{
					fade_end	= false;
					break;
				}

				b	= b->next;
			}

			for(loop = 0; loop < w->scroll_bar_num; loop++)
			{
				if(s->fade_mode == FADE_MODE_MIDDLE)
				{
					fade_end	= false;
					break;
				}

				s	= s->next;
			}

			for(loop = 0; loop < w->rectangle_num; loop++)
			{
				if(r->fade_mode == FADE_MODE_MIDDLE)
				{
					fade_end	= false;
					break;
				}

				r	= r->next;
			}

			if(fade_end)
			{
				if(w->fade_way == FADE_WAY_IN)	
				{
					w->window_on	= true;
					w->fade_way		= FADE_WAY_OUT;
				}
				else
				{
					w->window_on	= false;
					w->fade_way		= FADE_WAY_IN;
				}
				
				w->fade_mode	= FADE_MODE_NONE;
			}

			interface_button_fade_process(w);
			interface_rectangle_fade_process(w);
			interface_scroll_bar_fade_process(w);
		}

		w	= w->next;
	}
}