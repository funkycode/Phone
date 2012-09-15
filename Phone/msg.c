#include "msg.h"
#include <string.h>
#include <stdio.h>
#include <math.h>

void InsertWithName(Msg* msg, Messages* messages)
{
	int found = 0;
    Conversations* conversations;
	Msg* m;
	Position D, N, P = messages;

    P = Advance(P);
	D = messages;
	while(P)
	{
		conversations = (Conversations*)Retrieve(P);
		N = First(conversations);
		m = (Msg*)Retrieve(N);
		if(strcmp(m->number,msg->number)==0) //comparing number so deleted contact would still go in his group
		{
			while(N)
			{
				if(IsLast(N, conversations))
				{
					found = 1;
					break;
				}
                N = Advance(N);
			}
			
		}
		if(found == 1)
			break;
		D = Advance(D);
		P = Advance(P);
	}
	if(found == 1)
		Insert(msg,conversations,N);
	else
	{
	conversations = MakeEmpty(NULL);
	Insert(msg, conversations, conversations);
    Insert(conversations, messages, D);
	}
}

void InsertNoName(Msg* msg, Messages* messages,  Contacts* phonebook[])
{
	int found = 0;
    Conversations* conversations;
	Msg* m;

	Position D, N, P;
    P = First(messages);
	D = messages;
	while(P)
	{
		conversations = (Conversations*)Retrieve(P);
		N = First(conversations);
		m = (Msg*)Retrieve(N);
		if(m->contact == NULL) 
		{
			while(N)
			{
				if(IsLast(N, conversations))
				{
					found = 1;
					break;
				}
                N = Advance(N);
			}
		}
		if(found == 1)
			break;
		D = Advance(D);
		P = Advance(P);
	}
	if(found == 1)
		Insert(msg,conversations,N);
	else
	{
	conversations = MakeEmpty(NULL);
	Insert(msg, conversations, conversations);
    Insert(conversations, messages, D);
	}
}		

void InsertMsg(Messages messages, Msg* msg, Contacts* phonebook[])
{
	msg->contact = findContactByNum(phonebook, msg->number);

	if(msg->contact == NULL)
	{
		InsertNoName(msg, messages, phonebook);
	}
	else
	{
		InsertWithName(msg, messages);
	}
}

void addMsg(Messages messages, Contacts* phonebook[])
{
	Msg* msg = (Msg*)malloc(sizeof(Msg));
	int  type = NULL;
	SYSTEMTIME currentTime;

	printf("\nPlease enter the number:\n");
	fflush(stdin);
	fgets(msg->number, NUM_LENGTH, stdin);
	strtok(msg->number, "\n");
	printf("\nPlease enter the msg:\n");
	fflush(stdin);
    fgets(msg->msg, MSG_LENGTH, stdin);
	strtok(msg->msg, "\n");
	msg->type = msgType();
	GetSystemTime(&currentTime);
	msg->date=currentTime.wMonth*pow(10,6)+currentTime.wDay*pow(10,4)+currentTime.wHour*pow(10,2)+currentTime.wMinute;

	InsertMsg(messages, msg, phonebook);
}

void printRecentMsgs(Messages* messages, Contacts* phonebook[])
{
	int i, total;
	char number[NUM_LENGTH] = "";
	Conversations clist;
    Position P, D;
	Msg* msg = (Msg*)malloc(sizeof(Msg));

	if(TotalNum(messages)>0)
	{
		P = First(messages);
		while(P)
		{
            clist = Retrieve(P);
			D = clist;
            total = TotalNum(clist);
			if(D)
			{
				msg =(Msg*)Retrieve(First(D));
				if(msg->contact != NULL)
				{
				    for(i=0;i<total;i++)
					    D = Advance(D);
				    msg =(Msg*)Retrieve(D);
				    printOneMsg(msg, phonebook);
				}
				else
				{
					printOneMsg(msg, phonebook);
					for(i=0;i<total;i++)
					{
						 D = Advance(D);
						 strcpy(number,msg->number);
						 msg =(Msg*)Retrieve(D);
						 if(strcmp(msg->number,number) !=0)
							 printOneMsg(msg, phonebook);
					}	
				}

			}
			P = Advance(P);
		}
	}
	else
		printf("\nNo recent msgs\n");
}

void printOneMsg(Msg* msg, Contacts* phonebook[])
{
	int month, day, hour, min;
	char*  MsgType[] = { "in" , "out"};


	if(msg->contact != NULL)
	{
		month = msg->date/pow(10,6);
		day = (msg->date - month*pow(10,6))/pow(10,4);
		hour = (msg->date - month*pow(10,6) - day*pow(10,4))/pow(10,2);
		min = msg->date - month*pow(10,6) - day*pow(10,4) - hour*pow(10,2);
		if(findContactByNum(phonebook,msg->number) != NULL)
			        printBasicInfo(msg->contact);
				else
		        	printf("UNKNOWN|   | ");   
		printf("%s | \"%s\" | %d/%d %d:%d\n\n", MsgType[msg->type], msg->msg, day, month, hour, min );
	}
	else
	{
		month = msg->date/pow(10,6);
		day = (msg->date - month*pow(10,6))/pow(10,4);
		hour = (msg->date - month*pow(10,6) - day*pow(10,4))/pow(10,2);
		min = msg->date - month*pow(10,6) - day*pow(10,4) - hour*pow(10,2);
		printf("%s | %s | \"%s\" | %d/%d %d:%d\n", msg->number, MsgType[msg->type], msg->msg, day, month, hour, min );
	}
}

Conversations* getConvo(Messages* messages, Contacts* phonebook[])
{
	char name[NAME_LENGTH] = "";
	int found = 0;
    Conversations* conversations;
	Conversations* clist = MakeEmpty(NULL);
	Msg* m;
	Position N, P;

	strcpy(name, searchQuery(name));
	firstLettersUp(name);
    P = First(messages);
	while(P)
	{
		conversations = (Conversations*)Retrieve(P);
		N = First(conversations);
		m = (Msg*)Retrieve(N);
		if(findContactByNum(phonebook,m->number) != NULL && strcmp(m->contact->name,name)==0)
		{
			found = 1;
			while(N)
			{
				m = (Msg*)Retrieve(N);
				Insert(m,clist,clist);
				N = Advance(N);
			}
			break;
		}
	P = Advance(P);
	}
	if(!found)
		return NULL;
	else
		return clist;
}

void printConvo(Messages* messages, Contacts* phonebook[])
{
	int i, total, toPrint;
	Conversations* clist = MakeEmpty(NULL);
	Msg* msg;
	Position P;

	clist = getConvo(messages, phonebook);
	if(clist)
	{
		total = TotalNum(clist);
		system("cls");
		printf("\n Found %d msgs\n", total);
		toPrint = msgToPrint(total);
		system("cls");
        P = First(clist);
		for(i=0;i<toPrint;i++)
		{
			msg = (Msg*)Retrieve(P);
			printOneMsg(msg, phonebook);
			P = Advance(P);
		}
	    DeleteList(clist);
	}
	else
        printf("\n Not found any msgs\n");
}

