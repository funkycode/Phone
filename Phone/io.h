/********************************************************************
Module Name: Input/Output
Process:   It contains all operation related to input/output from user
and as well few help operatons
*******************************************************************/

#include "calls.h"
#include "files.h"


#ifndef _io_H			
#define _io_H

#define contactsFile "contacs.txt"
#define msgFile "msgs.txt"
#define callsFile "calls.txt"


/********************************************************************
Function name: printMenu
Process:   prints main menu
Arguments: phonebook is pointer to array of lists of contacts, calls is pointer to list of calls,
messages is pointer to list of lists of messages
Output:  main menu with options
*******************************************************************/
void printMenu(Contacts* phonebook[], Calls* calls, Messages* messages);
/********************************************************************
Function name: printMenu2
Process:   prints contacts menu
Arguments: phonebook is pointer to array of lists of contacts, calls is pointer to list of calls,
messages is pointer to list of lists of messages
Output:  contacts menu with options
*******************************************************************/
void printMenu2(Contacts* phonebook[], Calls* calls, Messages* messages);
/********************************************************************
Function name: printMenu3
Process:   prints calls menu
Arguments: phonebook is pointer to array of lists of contacts, calls is pointer to list of calls,
messages is pointer to list of lists of messages
Output:  calls menu with options
*******************************************************************/
void printMenu3(Contacts* phonebook[], Calls* calls, Messages* messages);
/********************************************************************
Function name: printMenu4
Process:   prints messages menu
Arguments: phonebook is pointer to array of lists of contacts, calls is pointer to list of calls,
messages is pointer to list of lists of messages
Output:  messages menu with options
*******************************************************************/
void printMenu4(Contacts* phonebook[], Calls* calls, Messages* messages);
/********************************************************************
Function name: pressToContinue
Process:   waits for user to press any key to continue
Output:  Asks to press any key to continue
*******************************************************************/
void pressToContinue();
/********************************************************************
Function name: searchQuery
Process:   asks the user to enter value to search
Arguments: query is pointer to value to search
Output:   Asks to input the value
Return:    returns the value of input
*******************************************************************/
char* searchQuery(char* query);
/********************************************************************
Function name: partialCompare
Process:   searches if first string contains second one
Arguments: (the name of each argument and validity description)
Output:    (passed by reference arguments output values)
Return:    returns 1 on success, 0 on fail
*******************************************************************/
int partialCompare(char first[], char second[]);
/********************************************************************
Function name: phoneType
Process:  prints the types of phone to chose untill right one is chosen
Output:   types of phone to chose
Return:   the choise
*******************************************************************/
int phoneType();
/********************************************************************
Function name: callType
Process:  prints the types of cals to chose untill right one is chosen
Output:   types of calls to chose
Return:   the choise
*******************************************************************/
int callType();
/********************************************************************
Function name: msgType
Process:  prints the types of msg to chose untill right one is chosen
Output:   types of msgs to chose
Return:   the choise
*******************************************************************/
int msgType();
/********************************************************************
Function name: msgToPrint
Process:  ask the user to chose the number from 1 to max(variable)
Arguments: max is maximum number to chose
Output:    asks to chose the number
Return:    choise of user
*******************************************************************/
int msgToPrint(int max);
/********************************************************************
Function name: dateAndDur
Process:  stack operation with date
Arguments: all arguments are integers and named by meaning of value
Return:   date and duration as one integer(bits)
*******************************************************************/
int dateAndDur(int day, int month, int minute, int hour, int duration);
/********************************************************************
Function name: printTime
Process:   takes integer and gets values from in(date and duration)
Arguments: bits is integer that contains date and duration in bits
Output:    prints the date and duration
*******************************************************************/
void printTime(const int bits);
/********************************************************************
Function name: firstLettersUp
Process:   Capitilize first letter of each word
Arguments: name is pointer to the name
*******************************************************************/
void firstLettersUp(char* name);

#endif