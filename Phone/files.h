#include <stdio.h>
#include <stdlib.h>
#include "contacts.h"

int readContacts(const char* filename, Contacts* phonebook[]);
int readCallLog();
int readMsgLog();
int writeContacts(const char* filename, Contacts* phonebook[]);
int writeCallLog();
int writeMsgLog();