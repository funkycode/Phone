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
		if(fscanf(contactsFP, "%d\n",&ContactsNum)==1)
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
				fscanf(contactsFP, "%[^\n]", &contact->name); 
				fscanf(contactsFP,"%s\n%d\n", &contact->number,&contact->type);
				firstLettersUp(contact->name); // In case file was modified manually
				
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
	Call* call;

	callsFP = fopen(filename,"r");
	if (callsFP)
	{
		fscanf(callsFP, "%d\n",&CallsNum);
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
int readMsgLog(const char* filename, Contacts* phonebook[], Messages* messages)
{
	int i, MsgNum;
	FILE* msgsFP;
	Msg* msg;

	msgsFP = fopen(filename, "r");
	if(msgsFP)
	{
		fscanf(msgsFP, "%d",&MsgNum);
		for(i=0;i<MsgNum;i++)
		{
			msg = (Msg*)malloc(sizeof(Msg));
			fscanf(msgsFP, "%s\n%d\n%d\n",&msg->number, &msg->date, &msg->type);
			fscanf(msgsFP, "%[^\n]s",&msg->msg);
			InsertMsg(messages,msg,phonebook);
		}
		fclose(msgsFP);
		return 0;
	}
	return 1;
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
int writeMsgLog(const char* filename, Messages* messages)
{
	int i, j, ConvoNum, MsgNum, TotalMsg = 0;
	FILE* msgsFP;
	Msg* msg;
	Conversations* conversations;
	Position P, D;

	msgsFP = fopen(filename, "w");
	if(msgsFP)
	{
		ConvoNum = TotalNum(messages);
		if(ConvoNum>0)
			P = First(messages);
        for(i=0;i<ConvoNum;i++)
		{
			conversations = (Conversations*)Retrieve(P);
			TotalMsg = TotalMsg + TotalNum(conversations);
			P = Advance(P);
		}
		fprintf(msgsFP, "%d\n",TotalMsg);
		P = messages;
		for(i=0;i<ConvoNum;i++)
		{
			P = Advance(P);
            conversations = (Conversations*)Retrieve(P);
			MsgNum = TotalNum(conversations);
			D = conversations;
            for(j=0;j<MsgNum;j++)
			{
				D = Advance(D);
				msg = (Msg*)Retrieve(D);
			    fprintf(msgsFP, "%s\n%d\n%d\n", msg->number, msg->date, msg->type);
			    fprintf(msgsFP, "%s\n", msg->msg);
			}
		}
		fclose(msgsFP);
		return 0;
	}
	return 1;


}