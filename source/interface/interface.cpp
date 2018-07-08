


#include	"main\main.h"
#include	"interface\interface.h"


void	interface_delete()
{
	interface_window_delete_all();
}

void	interface_draw()
{
	interface_window_draw();

	if(g_interface.cursor.cursor_on)
	{
		interface_cursor_draw();
	}
}

void	interface_process()
{
	interface_window_process();
}

void	interface_check_resolution(int x_from, int y_from, int x_to, int y_to)
{
	float	x	=	x_to / (float)x_from;
	float	y	=	y_to / (float)y_from;

	unsigned short	loop;
	unsigned short	loop_w;
	unsigned short	loop1;

	interface_window_instance		*w	= g_interface.window_first;
	interface_rectangle_instance	*r;
	interface_button_instance		*b;
	interface_scroll_bar_instance	*s;

	for(loop_w = 0; loop_w < g_interface.window_num; loop_w++)
	{
		r	= w->rectangle_first;
		b	= w->button_first;
		s	= w->scroll_bar_first;

		//	***	[	RECTANGLE	]

		for(loop = 0; loop < w->rectangle_num; loop++)
		{
			r->x	*=	x;
			r->y	*=	y;

			r->width	*=	x;
			r->height	*=	y;

			r = r->next;
		}

		//	***	[	BUTTON	]

		for(loop = 0; loop < w->button_num; loop++)
		{
			b->x	*=	x;
			b->y	*=	y;

			b->width	*=	x;
			b->height	*=	y;

			b = b->next;
		}

		//	***	[	scroll_bar ]

		for(loop = 0; loop < w->scroll_bar_num; loop++)
		{
			for(loop1 = 0; loop1 < 4; loop1++)
			{
				s->x[loop1]			*=	x;
				s->y[loop1]			*=	y;

				s->width[loop1]		*=	x;
				s->height[loop1]	*=	y;
			}

			s = s->next;
		}

		w	= w->next;
	}
}