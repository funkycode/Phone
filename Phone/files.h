#include <stdio.h>
#include <stdlib.h>
#include "msg.h"
#include "calls.h"
//
#ifndef  _files_H			
#define _files_H



int readContacts(const char* filename, Contacts* phonebook[]);
int readCallLog(const char* filename, Calls* calls);
int readMsgLog();
int writeContacts(const char* filename, Contacts* phonebook[]);
int writeCallLog();
int writeMsgLog();

#endif