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

	for (i=0;i<26;i++)
               phonebook[i] = MakeEmpty(NULL);

	
	
	//debug: Creating dummy file

	/*FILE* contactsFP;
	contactsFP = fopen(contactsFile, "w");
	fprintf(contactsFP,"1\nMisha\n0555\n0");
	fclose(contactsFP);*/

    //end debug
	
	if(readContacts(contactsFile, phonebook))
		printf("There was error reading the contacts from file");
	
	 //printAllContacts(phonebook);
	//contacts->Element = (Contact*)malloc(sizeof(Contact);



    
	printMenu();



}