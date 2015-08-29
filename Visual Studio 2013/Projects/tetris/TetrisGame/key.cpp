#include <iostream>
#include "key.h"

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