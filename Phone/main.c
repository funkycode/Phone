#include "menus.h"
#include "files.h"
//#include "lists.h"

#define contactsFile "contacs.txt"
#define msgFile "msgs.txt"
#define callsFile "calls.txt"


void main()
{
	//debug
	FILE* contactsFP;
	contactsFP = fopen(contactsFile, "w");
	fprintf(contactsFP,"1/nMisha/n0555/n0");
	fclose(contactsFP);

    //end debug
	Contacts* contacts = MakeEmpty(NULL);
	readContacts(contactsFile, contacts);
	//contacts->Element = (Contact*)malloc(sizeof(Contact);



    
	printMenu();



}