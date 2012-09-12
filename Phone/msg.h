#include "contacts.h"

#define MSG_LENGTH 130

typedef List Messages;
typedef List Conversations;

typedef struct
{
	char msg[MSG_LENGTH];
	char number[NUM_LENGTH];
	int date;
	Contact* contact;

}Msg;
//
//typedef struct
//{
//	char number[NUM_LENGTH];
//	Conversations ;
//}Convo;

//void InsertMsg(Conversations* conversations, Msg* msg);
void insertWithName(Msg* msg, Messages* messages);
//Conversation* findConversationNoName(Msg* msg, Messages* messages);



