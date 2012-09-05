#include "io.h"
#include "files.h"

#define contactsFile "contacs.txt"
#define msgFile "msgs.txt"
#define callsFile "calls.txt"


void main()
{
	int i;
	char name[20] , name2[20] ;
	Contacts contacts = MakeEmpty(NULL);
	Contacts* phonebook[LETTERS];

	for (i=0;i<LETTERS;i++)
               phonebook[i] = MakeEmpty(NULL);

	
	if(readContacts(contactsFile, phonebook))
		printf("There was error reading the contacts from file");
	
	 printAllContacts(phonebook);
	 printMenu();



}