#include "io.h"
#include "files.h"

#define contactsFile "contacs.txt"
#define msgFile "msgs.txt"
#define callsFile "calls.txt"


void main()
{
	int i;
	Contacts contacts = MakeEmpty(NULL);
	Contacts* phonebook[LETTERS];
    
	printf("\n\nInitializing data...\n\n");
	for (i=0;i<LETTERS;i++)
               phonebook[i] = MakeEmpty(NULL);

	if(readContacts(contactsFile, phonebook))
		printf("\n\nThere was error reading the contacts from the file\n\n");
     
	printf("Finished initialization");
	pressToContinue();
	system("cls");	
	printMenu(phonebook);

	if(writeContacts(contactsFile, phonebook))
		printf("There was error writing the contacts to the file");


}