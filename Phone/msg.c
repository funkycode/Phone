#include "msg.h"

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
			while(N)
			{
				if(IsLast(N,conversations))
				{
					Insert(msg, conversations, N);
					exit;
				}
				N = Advance(N);
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
			while(N)
			{
				if(IsLast(N,conversations))
				{
					Insert(msg, conversations, N);
					exit;
				}
				N = Advance(N);
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
		InsertNoName(msg, messages);
	else
		InsertWithName(msg, messages);
}