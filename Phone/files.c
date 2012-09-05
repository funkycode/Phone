#include "files.h"

int readContacts(const char* filename, Contacts* phonebook[])
{
	int ContactsNum, ContactsPhones, i, j;
	Contact* contact;
	Contacts contacts;
	Position P;
	
	//ElementType e;
	
	FILE* contactsFP;
	contactsFP = fopen(filename,"r");

	if (contactsFP)
	{
		if(fscanf(contactsFP, "%d",&ContactsNum)==1)
			
		  for (i=0;i<ContactsNum;i++)
			{
				contact = (Contact*)malloc(sizeof(Contact));
				fscanf(contactsFP,"%s\n%s\n%d",&contact->name,&contact->number,&contact->type);
				j = getTheLetter(contact->name[0]);
				
				Insert(contact,phonebook[j],phonebook[j]);

			}
		  fclose(contactsFP);
		  return 0;
	}
	fclose(contactsFP);
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
int writeContacts(const char* filename, Contacts* contacts)
{
	int ContactsNum, ContactsPhones,i;
	Contact* contact;
	//ElementType e;
	FILE* contactsFP;
	contactsFP = fopen(filename,"w");
	if (contactsFP)
	{
		if(fscanf(contactsFP, "%d",&ContactsNum)==1)
		  for (i=0;i<ContactsNum;i++)
			{
				contact = (Contact*)malloc(sizeof(Contact));
				fscanf(contactsFP,"%s\n%s\n%i",&contact->name,&contact->number,&contact->type);
				Insert(contact,contacts,contacts);
				printf("%d\n\n", contact->name[0]);
			}
		  fclose(contactsFP);
		  return 0;
	}
	return 1;
	

}
int writeCallLog()
{

}
int writeMsgLog()
{
}