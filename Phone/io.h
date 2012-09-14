#include "calls.h"
#include "files.h"


#ifndef _io_H			
#define _io_H

#define contactsFile "contacs.txt"
#define msgFile "msgs.txt"
#define callsFile "calls.txt"


void printMenu(Contacts* phonebook[], Calls* calls, Messages* messages);
void printMenu2(Contacts* phonebook[], Calls* calls, Messages* messages);
void printMenu3(Contacts* phonebook[], Calls* calls, Messages* messages);
void printMenu4(Contacts* phonebook[], Calls* calls, Messages* messages);
void pressToContinue();
char* searchQuery(char* query);
int fullCompare(char first[], char second[]);
int partialCompare(char first[], char second[]);
int phoneType();
int callType();
int msgType();
int dateAndDur(int day, int month, int minute, int hour, int duration);
void printTime(const int bits);
void firstLettersUp(char* name);
#endif