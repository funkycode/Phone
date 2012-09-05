#include "contacts.h"
#include <string.h>

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

void  insertSortedContact(Contacts* contacts, Contact* c)
{

	Contact* contact;
	Position P = First(contacts);
	contact = (Contact*)Retrieve(P);

	while (P && strcmp(contact->name, c->name) == 1)
	{
		P = Advance(P);
		contact = (Contact*)Retrieve(P);
		
	}

		while(P && contact->type > c->type && strcmp(contact->name, c->name) == 0)
		{
		   P = Advance(P);
           contact = (Contact*)Retrieve(P);   
			
		}
		Insert (c, contacts, FindPrevious(contact,contacts));

		
}
