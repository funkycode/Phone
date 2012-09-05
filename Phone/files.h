#include <stdio.h>
#include <stdlib.h>
#include "contacts.h"

int readContacts(const char* filename, Contacts* contacts);
int readCallLog();
int readMsgLog();
int writeContacts();
int writeCallLog();
int writeMsgLog();