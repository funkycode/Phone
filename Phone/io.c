#include "io.h"

void printAllContacts(Contacts* phonebook[])
{
	int i;
	Position P;
	Contact* contact;
	ElementType e;
	for (i=0;i<LETTERS;i++)
	{
		P = Header(phonebook[i]);
		while (P != NULL)
		{
			e = Retrieve(P);
			contact = (Contact* )e;
			printf("%s : %s \n",contact->name, contact->number);
			P = Advance(P);
		}
	}

}