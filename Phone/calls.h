#include "lists.h"
#include "contacts.h"
#include <Windows.h>

#ifndef _calls_H			
#define _calls_H

#define MAX_CALL_LOG 200

typedef struct
{
 int type;
 Contact* contact;
 char number[NUM_LENGTH];
 int timeDur;
}Call;

typedef List Calls;

void printAllCalls(const Calls* calls);
void AddNewCall(Calls* calls, Contacts* phonebook[]);

#endif
