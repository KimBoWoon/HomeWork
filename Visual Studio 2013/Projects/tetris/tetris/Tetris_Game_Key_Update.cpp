/****************************
*							*
*	학번 : 20113259			*
*	이름 : 김보운			*
*							*
****************************/
#include "Tetris_Game.h"
#include "Tetris_Key.h"
#include "Tetris_Block.h"
#include "Tetris_Interface.h"

int KeySet::input_key()
{
	key = getch();

	if (key == 260)
		return 'l';
	else if (key == 258)
		return 'g';
	else if (key == 261)
		return 'r';
	else if (key == 259)
		return 't';
	else if (key == 32)
		return 'd';
	else if (key == 113)
		return 'q';
}