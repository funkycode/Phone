#include "files.h"

int readContacts(const char* filename, Contacts* contacts)
{
	int ContactsNum, ContactsPhones,i;
	Contacts* contact;
	//ElementType e;
	FILE* contactsFP;
	contactsFP = fopen(filename,"r");
	if (contactsFP)
	{
		if(fscanf(contactsFP, "%d",&ContactsNum)==1)
		  for (i=0;i<ContactsNum;i++)
			{
				//contact = (Contact)malloc(sizeof(Contact));
				fscanf(contactsFP,"%s/n%s/n%i/n",&contact->name,&contact->number,&contact->type);
				//contact = (void*)malloc(sizeof(Contact));
				Insert(contact,contacts,contacts);
			}
		  fclose(contactsFP);
		  return 0;
	}
	return 1;
}


int readCallLog()
{
	int CallsNum;
}
int readMsgLog()
{
	int MsgNum;
}
int writeContacts()
{
	
}
int writeCallLog()
{
}
int writeMsgLog()
{
}