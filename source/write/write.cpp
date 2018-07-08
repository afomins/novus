  


#include <string.h>

#include "main\main.h"
#include "draw\draw2d.h"
#include "texture\texture.h"
#include "write\write.h"


int write(int x, int y, char* text, float sizeX, float sizeY, int fontNum)
{
	char	letters[256];
	int		symbolNumber;

	int		textLength		= strlen(text);
	float	textPos			= 0.0;
	int		length			= 0;

	int		backWidth		= writeStringGetLength(text);

glPushMatrix();
	glTranslatef(x, y, 0.0);
	glScalef(sizeX, sizeY, 0.0);

	for(int loop = 0; loop < textLength; loop++)
	{
		letters[loop]	= text[loop];
		symbolNumber	= letters[loop];

		if(symbolNumber > 0)	
			symbolNumber -= 32;
		else
			symbolNumber += 160;

		draw2dSymbol(symbolNumber, fontNum);

		glTranslatef((font[fontNum].symbolWidth[symbolNumber] + 2), 0.0, 0.0);

		length += font[fontNum].symbolWidth[symbolNumber] + 2;
	}
glPopMatrix();

	return length;
}

int power_10[7] = {1, 10, 100, 1000, 10000, 100000, 1000000};
//				   0  1   2    3     4      5       6 
int write(int x, int y, float num, int level, float sizeX, float sizeY, int fontNum)
{
	float	oldNum			= num;
	bool	minus			= FALSE;
	int		dec[7]			= {0, 0, 0, 0, 0, 0, 0};
	int		dec_[7]			= {0, 0, 0, 0, 0, 0, 0};
	int		symbolNum		= 0;
	int		symbolNumber;

	int		backWidth		= 0;

	if(num < 0) 
	{
		minus = TRUE;
		num -= num * 2;
	}

	for(int loop = 6; loop >= 0; loop--)	//	÷ðÿþûý õª DEC üð¸¸øò
	{										//
		while(num - power_10[loop] > 0)		//	0	-	õôøýø¡v
		{									//	1	-	ôõ¸ ªúø
			dec[loop]++;					//	2	-	¸þªýø
			num -= power_10[loop];			//	3	-	ªv¸ ¢ø
		}									//	...
	}										//

		if(num == 1) dec[0]++;				//	õ¸ûø ¢ø¸ûþ ¡õûþõ (NUM ¤ªþ þ¸ªðªþú)
											//	ªþ ºòõûø¢øòðõü úþû-òþ õôøýø¡ ýð 1

	for(loop = 0; loop <= 6; loop++)			//	
	{											//	
		if(dec[loop] == 10)						//
		{										//
			dec[loop] = 0;						//	
			dec[loop + 1] = dec[loop + 1] + 1;	//
		}										//
	}											//

	loop = 6;
	
	int decimal = -1;

	while(decimal == -1)
	{
		if(dec[loop] != 0) decimal = loop;
		loop--;
	}


	if((oldNum < 1) & (oldNum > -1))
		decimal = 0;
	
//	**********************************************************************************************

glPushMatrix();

	glTranslatef(x, y, 0.0);
	glScalef(sizeX, sizeY, 0.0);

	if(minus == TRUE)
	{
		draw2dSymbol(13, fontNum);
		glTranslatef((font[fontNum].symbolWidth[13] + 2), 0.0, 0.0);
	}

	for(loop = 0; loop <= decimal; loop++)
	{
		symbolNumber = dec[decimal - loop] + 16;
		draw2dSymbol(symbolNumber, fontNum);
		glTranslatef((font[fontNum].symbolWidth[symbolNumber] + 2), 0.0, 0.0);

		symbolNum += font[fontNum].symbolWidth[13] + 2;
	}

//	**********************************************************************************************


	if((num != 1) & (level != 0))
	{
		num *= power_10[level];

		for(int loop = 6; loop >= 0; loop--)
		{
			while(num - power_10[loop] > 0)
			{
				dec_[loop]++;
				num -= power_10[loop];
			}
		}

		if(num == 1) dec_[0]++;

		for(loop = 0; loop <= 6; loop++)
		{
			if(dec_[loop] == 10)
			{
				dec_[loop] = 0;
				dec_[loop + 1] = dec_[loop + 1] + 1;
			}
		}

		loop = 0;
	
		int decimal_ = -1;

		while(decimal_ == -1)
		{
			if(dec_[loop] != 0) decimal_ = loop;
			loop++;
		}

//	**********************************************************************************************
	
			draw2dSymbol(14, fontNum);

			glTranslatef((font[fontNum].symbolWidth[14] + 2), 0.0, 0.0);

			symbolNum += font[fontNum].symbolWidth[14] + 2;

		for(loop = 0; loop < level; loop++)
		{
			symbolNumber = dec_[level - 1 - loop] + 16;
			draw2dSymbol(symbolNumber, fontNum);
			glTranslatef((font[fontNum].symbolWidth[symbolNumber] + 2), 0.0, 0.0);

			symbolNum += font[fontNum].symbolWidth[symbolNumber] + 2;
		}
//	**********************************************************************************************
	}
glPopMatrix();

	return symbolNum * sizeX;
}

void write(int x, int y, char* text, float num, int level, float sizeX, float sizeY, int fontNum)
{
	int startWriting = write(x, y, text, sizeX, sizeY, fontNum);

	write(x + startWriting, y, num, level, sizeX, sizeY, fontNum);
}

void write(int x, int y, float num, int level, char* text, float sizeX, float sizeY, int fontNum)
{
	int startWriting = write(x, y, num, level, sizeX, sizeY, fontNum);

	write(x + startWriting, y, text, sizeX, sizeY, fontNum);
}

void write(int x, int y, unsigned short num, float sizeX, float sizeY, int fontNum)
{
	float	numTemp = num;

	write(x, y, numTemp, 0, sizeX, sizeY, fontNum);
}

int	writeStringGetLength(char *text)
{
	int		length			=	0;
	int		textLength		=	strlen(text);
	int		symbolNumber	=	0;
	char	letters[256];
	int		loop;
	int		fontNum			=	0;

	for(loop = 0; loop < textLength; loop++)
	{
		letters[loop]	= text[loop];
		symbolNumber	= letters[loop];

		if(symbolNumber > 0)	
			symbolNumber -= 32;
		else
			symbolNumber += 160;

		length += font[fontNum].symbolWidth[symbolNumber] + 2;
	}
	
	return length;
}
