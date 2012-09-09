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
				fscanf(contactsFP, "%s", &contact->name); 
				fscanf(contactsFP,"%s\n%d", &contact->number,&contact->type);
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


int readCallLog(const char* filename, Contacts* phonebook[], Calls* calls)
{
	int i, CallsNum;
	FILE* callsFP;
	Position P = calls;
	//char number[NUM_LENGTH];
	Call* call;

	callsFP = fopen(filename,"r");
	if (callsFP)
	{
		fscanf(callsFP, "%d",&CallsNum);
		if(CallsNum == 0)
			return 0;
        for(i=0;i<CallsNum;i++)
		{
			call = (Call*)malloc(sizeof(Call));
			fscanf(callsFP, "%s\n%d\n%d\n",&call->number ,&call->type, &call->timeDur);
			call->contact = findContactByNum(phonebook, call->number);
			Insert(call,calls,P);
			P = Advance(P);
		}
		fclose(callsFP);
        return 0;
	}
	return 1;
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
int writeCallLog(const char* filename, Calls* calls)
{
	int  i, CallNum = 0;
	Call* call;
	FILE* callsFP;
	Position P = Header(calls);

	callsFP = fopen(filename,"w");
	if (callsFP)
	{
		CallNum = TotalNum(calls);
		fprintf(callsFP, "%d\n",CallNum);		
		for (i=0;i<CallNum;i++)
		{
			P = Advance(P);
			call = (Call*)Retrieve(P);
			fprintf(callsFP, "%s\n%d\n%d\n", call->number, call->type, call->timeDur);
		}
		fclose(callsFP);
		return 0;
	}
	return 1;


}
int writeMsgLog()
{
}