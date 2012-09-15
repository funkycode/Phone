/********************************************************************
Module Name: Messages
Process:   It contains all operation related to messages
*******************************************************************/

#include "contacts.h"
#include <Windows.h>

#define MSG_LENGTH 130
#define MAX_RECENT 10

typedef List Messages;
typedef List Conversations;
typedef List RecentMsgs;

typedef struct
{
	char msg[MSG_LENGTH];
	char number[NUM_LENGTH];
	int date;
	Contact* contact;
	int type;

}Msg;

/********************************************************************
Function name: InsertWithName
Process:   Inserts to the List Msg of existing contact
Arguments: msg - pointer to message itself, messages - pointer to list of conversations(list of messages)
*******************************************************************/
void InsertWithName(Msg* msg, Messages* messages);
/********************************************************************
Function name: InsertNoName
Process:   Inserts to the List Msg of unknown contacts
Arguments: msg - pointer to the message itself, messages  - pointer to list of conversations(list of messages),
pointer to phonebook - array of list of contacts 
*******************************************************************/
void InsertNoName(Msg* msg, Messages* messages,  Contacts* phonebook[]);
/********************************************************************
Function name: InsertMsg
Process:   Checkes what type of message to decide how to insert it to the list
Arguments:  msg - pointer to the message itself, messages  - pointer to list of conversations(list of messages),
pointer to phonebook - array of list of contacts 
*******************************************************************/
void InsertMsg(Messages* messages, Msg* msg, Contacts* phonebook[]);
/********************************************************************
Function name: addMsg
Process:   Adds the New message
Arguments: messages  - pointer to list of conversations(list of messages), pointer to phonebook - array of list of contacts 
*******************************************************************/
void addMsg(Messages* messages, Contacts* phonebook[]);
/********************************************************************
Function name: printOneMsg
Process:   prints single message after checking if contact is in contacts or was deleted, unknown
Arguments: msg - pointer to the message to print, pointer to phonebook - array of list of contacts  
Output:    Prints the message data
*******************************************************************/
void printOneMsg(Msg* msg, Contacts* phonebook[]);
/********************************************************************
Function name: printRecentMsgs
Process:   prints the last messages of each list for contact and the whole list of unknown
Arguments: messages  - pointer to list of conversations(list of messages), phonebook - pointer to array of list of contacts
Output:    The recent messages with data or "nothing found"
*******************************************************************/
void printRecentMsgs(Messages* messages, Contacts* phonebook[]);
/********************************************************************
Function name: printConvo
Process:   gets the list of all messages of giving name and prints due the number of messages user asked for to print due date
Arguments: messages  - pointer to list of conversations(list of messages), phonebook - pointer to array of list of contacts
*******************************************************************/
void printConvo(Messages* messages, Contacts* phonebook[]);
/********************************************************************
Function name: getConvo
Process:   returns pointer to list of messages by name search or NULL if not found
Arguments: messages  - pointer to list of conversations(list of messages), phonebook - pointer to array of list of contacts
Return:    pointer to list of messages
*******************************************************************/
Conversations* getConvo(Messages* messages, Contacts* phonebook[]);