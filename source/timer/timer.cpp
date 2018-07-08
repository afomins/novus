  


#include "main\main.h"

#include <time.h>


int				timerFrameCount		=	0;
int				timerFps			=	0;

float			timerCurrent		=	0;
float			timerPrior			=	0;

float			timerCurrentSec		=	0;
float			timerPriorSec		=	0;

float			timerFrameLength	=	0;

int				timerFirst			=	GetTickCount();

void	timerProcess()
{
	timerFrameCount++;

	timerPrior			=	timerCurrent;
	timerCurrent		=	GetTickCount() - timerFirst;//clock();

	timerFrameLength	=	timerCurrent - timerPrior;

	timerCurrentSec		=	timerCurrent / CLOCKS_PER_SEC;
	
	if(timerCurrentSec - 1 > timerPriorSec)
	{
		timerPriorSec	= timerPrior / CLOCKS_PER_SEC;

		timerFps		= timerFrameCount;
		timerFrameCount	= 0;
	}
}
