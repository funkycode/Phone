#include "io.h"




void main()
{
	int i;
	Contacts contacts = MakeEmpty(NULL);
	Contacts* phonebook[LETTERS];
	Messages* msgs = MakeEmpty(NULL);
	
	for (i=0;i<LETTERS;i++)
               phonebook[i] = MakeEmpty(NULL);

	if(readContacts(contactsFile, phonebook))
	{
		printf("\n\nThere was error reading the contacts from the file\n\n");
		pressToContinue();
		system("cls");
	    
	}
	
	if(readMsgLog(msgFile,phonebook,msgs))
	{
		printf("\n\nThere was error reading the msgs from the file\n\n");
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