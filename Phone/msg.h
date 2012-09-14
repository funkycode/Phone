#include "contacts.h"
#include <Windows.h>

#define MSG_LENGTH 130

typedef List Messages;
typedef List Conversations;

typedef struct
{
	char msg[MSG_LENGTH];
	char number[NUM_LENGTH];
	int date;
	Contact* contact;
	int type;

}Msg;

void InsertWithName(Msg* msg, Messages* messages);
void InsertNoName(Msg* msg, Messages* messages);
void InsertMsg(Messages* messages, Msg* msg, Contacts* phonebook[]);
void addMsg(Messages* messages, Contacts* phonebook[]);
void printOneMsg(Msg* msg);
void printAllMsgs(Messages* messages, Contacts* phonebook[]);
void deleteMsg(Messages* messages, Contacts* phonebook[]);