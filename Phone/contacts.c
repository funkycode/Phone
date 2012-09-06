#include "contacts.h"
#include <string.h>
#include <stdio.h>
//#include <ctype.h>

int getTheLetter(const char firstLetter)
{
	int value;
	value = (int)firstLetter;
    if ( (65 <= value && value <= 90) ) // ||( 97 <= value && value <= 122)) // No need anymore as we convert to Upcase when reaadingfrom file and adding !!!
	{
		//if (65 <= value && value <= 90)  //see comment above 
			return (value-65);
		//return (value-97); //see comment above
	}
	return -1;
}

void  insertSortedContact(Contacts* contacts, Contact* c)
{
    int chk = -1;
	Contact* contact;
	Position P = contacts, N; //check next and keep prev.
	
	if(N = Advance (P))
	{
       contact = (Contact*)Retrieve(N);
	   chk = strcmp(contact->name, c->name);
	}
    
		while (N &&  chk == -1)
		{
			P = Advance(P);
			if(N = Advance (P)){
			contact = (Contact*)Retrieve(N);
			chk = strcmp(contact->name, c->name);
			}
		}

		while(N && contact->type < c->type && strcmp(contact->name, c->name) == 0)
		{
		   P = Advance(P);
		   if(N = Advance (P))
             contact = (Contact*)Retrieve(N);   
			
		}
		Insert (c, contacts, P );

		
}

void addContact(Contacts* phonebook[])
{
	int  type = NULL;
	Contact* contact;
	contact = (Contact*)malloc(sizeof(Contact));
	printf("\nPlease Enter the name:\n");
	fflush(stdin);
	scanf("%s",&contact->name);
	contact->name[0] = toupper(contact->name[0]);
	printf("\nPlease Enter the phone number:\n");
	fflush(stdin);
	scanf("%s",&contact->number);
	contact->type = phoneType();

	if(getTheLetter(contact->name[0]) != -1)
	   insertSortedContact(phonebook[getTheLetter(contact->name[0])], contact);
	else
		printf("\n\n\nFAILED!!! First letter should be a letter and not just a symbol\n\n");
    

}

