#include "files.h"

int readContacts(const char* filename, Contacts* phonebook[])
{
	int ContactsNum, i, corrupt = 0;
	Contact* contact;
	Position P[LETTERS];
    FILE* contactsFP;

	contactsFP = fopen(filename,"r");

	if (contactsFP)
	{
		if(fscanf(contactsFP, "%d",&ContactsNum)==1)
			for(i=0;i<LETTERS;i++)
				P[i]=phonebook[i];
		else
		{

			fclose(contactsFP);
			return 0;
		}
		  for (i=0;i<ContactsNum;i++)
			{
				contact = (Contact*)malloc(sizeof(Contact));
				fscanf(contactsFP,"%s\n%s\n%d",&contact->name,&contact->number,&contact->type);
				contact->name[0] = toupper(contact->name[0]); // In case file was modified manually
				
				if(getTheLetter(contact->name[0])!= -1) //Checking if first Letter is actualy a letter at all
				{
					Insert(contact,phonebook[getTheLetter(contact->name[0])],P[getTheLetter(contact->name[0])]);
					P[getTheLetter(contact->name[0])]=Advance(P[getTheLetter(contact->name[0])]);
				}
				else
					corrupt++;
				
				

			}
		  if(corrupt)
			  printf("\nWARNING!!! %d contacts were corrupted, skipped them\n\n", corrupt);
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
int writeContacts(const char* filename, Contacts* phonebook[])
{
	int  i, j, ContactsNum=0;
	Contact* contact;
	FILE* contactsFP;
	Position P;
	contactsFP = fopen(filename,"w");
	if (contactsFP)
	{
		for (i=0;i<LETTERS;i++)
			ContactsNum+=TotalNum(phonebook[i]);
		if(fprintf(contactsFP, "%d\n",ContactsNum))
		{
		  for (i=0;i<LETTERS;i++)
			{
				P = phonebook[i];
				if(P = Advance(P))
				{
					for(j=0;j<TotalNum(phonebook[i]);j++)
					{
						contact = (Contact*)Retrieve(P);
						fprintf(contactsFP, "%s\n%s\n%d\n", contact->name, contact->number, contact->type);
						P = Advance(P);
					}
				}

            
			}
		  fclose(contactsFP);
			return 0;
		  
		}

	}
	return 1;
	

}
int writeCallLog()
{

}
int writeMsgLog()
{
}