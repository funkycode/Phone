#include "msg.h"
#include <string.h>
#include <stdio.h>

void InsertWithName(Msg* msg, Messages* messages)
{
    Conversations* conversations;
	Msg* m;
	Position D, N, P = messages;

    P = Advance(P);
	while(P)
	{
		conversations = (Conversations*)Retrieve(P);
		N = First(conversations);
		m = (Msg*)Retrieve(N);
		if(strcmp(m->number,msg->number)==0)
		{
			//Isert to be first (due date)
			Insert(msg, conversations, conversations);
			exit;

		}
		D = P;
		P = Advance(P);
	}
	//Create new convo list and insert into msgs list
	conversations = MakeEmpty(NULL);
	Insert(msg, conversations, conversations);
    Insert(conversations, messages, D);
}

void InsertNoName(Msg* msg, Messages* messages)
{
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
		if(!m->contact)
		{
			//Isert to be first (due date)
			Insert(msg, conversations, conversations);
			exit;
		}
		D = Advance(D);
		P = Advance(P);
	}
	conversations = MakeEmpty(NULL);
	Insert(msg, conversations, conversations);
    Insert(conversations, messages, D);	
}		

void InsertMsg(Messages messages, Msg* msg, Contacts* phonebook[])
{
	if(!findContactByNum(phonebook, msg->number))
	{
		msg->contact = findContactByNum(phonebook, msg->number);
		InsertNoName(msg, messages);
	}
	else
		InsertWithName(msg, messages);
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
	msg->date=currentTime.wMonth*(10^6)+currentTime.wDay*(10^4)+currentTime.wHour*(10^2)+currentTime.wMinute;

	InsertMsg(messages, msg, phonebook);
}
