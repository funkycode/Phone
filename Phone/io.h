#include <stdio.h>
#include <stdlib.h>

#include "calls.h"
#include "files.h"


#ifndef _io_H			
#define _io_H

#define contactsFile "contacs.txt"
#define msgFile "msgs.txt"
#define callsFile "calls.txt"


void printMenu(const Contacts* phonebook[]);
void printMenu2(Contacts* phonebook[]);
void printMenu3(Contacts* phonebook[], Calls* calls);
void printMenu4(Contacts* phonebook[]);
void pressToContinue();
char* searchQuery(char* query);
int fullCompare(char first[], char second[]);
int partialCompare(char first[], char second[]);
int phoneType();
int callType();
int dateAndDur(int day, int month, int minute, int hour, int duration);
void printTime(const int bits);
#endif