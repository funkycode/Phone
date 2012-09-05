#include "contacts.h"


int getTheLetter(const char firstLetter)
{
	int value;
	value = (int)firstLetter;
    if ( 65 <= value <= 90 || 97 <= value <= 112)
	{
		if (65 <= value <= 90)
			return (value-65);
		return (value-97);
	}
	return -1;
}