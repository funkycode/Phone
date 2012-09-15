/********************************************************************
Module Name: Files
Process:   It contains all operation for reading and writing files
*******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "msg.h"
#include "calls.h"
//
#ifndef  _files_H			
#define _files_H



/********************************************************************
Function name: readContacts
Process:   reads contacts from file and insert in array of list 
Arguments: filename is pointer to file name, phonebook is pointer to array of lists of contacts
Return:  0 on success, 1 on fail
*******************************************************************/
int readContacts(const char* filename, Contacts* phonebook[]);
/********************************************************************
Function name: readCallLog
Process:  reads call log from file to list of calls
Arguments: filename is pointer to file name, calls is pointer to list of calls
Return:    0 on success, 1 on fail
*******************************************************************/
int readCallLog(const char* filename, Calls* calls);
/********************************************************************
Function name: readMsgLog
Process:   reads messages log from file and inserts in list of lists of messages
Arguments: filename is pointer to name of file, phonebook is pointer to array of lists of contacts
calls is pointer to list of calls
Return:    0 on success, 1 on fail
*******************************************************************/
int readMsgLog(const char* filename, Contacts* phonebook[], Calls* calls);
/********************************************************************
Function name: writeContacts
Process:   writes contacts to file from array of lists of contacts 
Arguments: filename is pointer to file name, phonebook is pointer to array of lists of contacts
Return:    0 on success, 1 on fail
*******************************************************************/
int writeContacts(const char* filename, Contacts* phonebook[]);
/********************************************************************
Function name: writeCallLog
Process:   writes call log to file from list of calls
Arguments: filename is pointer to file name, calls is pointer to lists of calls
Return:    0 on success, 1 on fail
*******************************************************************/
int writeCallLog(const char* filename, Calls* calls);
/********************************************************************
Function name: writeMsgLog
Process:   writes log of msgs to file from list of lists of messages
Arguments: filename is pointer to file name, messages is pointer to list of lists of messages
Return:   0 on success, 1 on fail
*******************************************************************/
int writeMsgLog(const char* filename, Messages* messages);

#endif