#include "io.h"




void main()
{
	int i;
	Contacts contacts = MakeEmpty(NULL);
	Contacts* phonebook[LETTERS];
	
	for (i=0;i<LETTERS;i++)
               phonebook[i] = MakeEmpty(NULL);

	if(readContacts(contactsFile, phonebook))
	{
		printf("\n\nThere was error reading the contacts from the file\n\n");
		pressToContinue();
		system("cls");
	    
	}
	    
	printMenu(phonebook);

	if(writeContacts(contactsFile, phonebook))
	{
		system("cls");
		printf("There was error writing the contacts to the file");
		pressToContinue();
	}
}