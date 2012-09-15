/********************************************************************
Module Name: Calls
Process:   It contains all operation related to calls
*******************************************************************/
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

/********************************************************************
Function name: printAllCalls
Process:   prints all calls with data
Arguments: calls - pointer to calls list, phonebook - array of lists of contacts
Output:    Prints all data of all calls
*******************************************************************/
void printAllCalls(const Calls* calls, Contacts* phonebook[]);
/********************************************************************
Function name: AddNewCall
Process:   Adds new Call to the list due name
Arguments:  calls - pointer to calls list, phonebook - array of lists of contacts
*******************************************************************/
void AddNewCall(Calls* calls, Contacts* phonebook[]);
/********************************************************************
Function name: DeleteCall
Process:   Gives output of calls due name and give option to choose wich one to delete
Arguments:  calls - pointer to calls list
Output:    Prints all found calls due name and numbers to chose to delete
*******************************************************************/
void DeleteCall(Calls* calls);

#endif
