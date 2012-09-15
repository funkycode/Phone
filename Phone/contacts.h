/********************************************************************
Module Name: Messages
Process:   It contains all operation related to contacts
*******************************************************************/

#include "lists.h"


#ifndef _contacts_H			
#define _contacts_H

#define NAME_LENGTH 30
#define NUM_LENGTH 15
#define LETTERS 26
#define TYPES 3


typedef struct
{
	char name[NAME_LENGTH];
	char number[NUM_LENGTH];
	int type;
}Contact;

typedef List Contacts;

/********************************************************************
Function name: getTheLetter
Process:   Gets the number of  the letter
Arguments: firstLetter is char
Return:    returns the order number of given letter
*******************************************************************/
int getTheLetter(const char firstLetter);
/********************************************************************
Function name: insertSortedContact
Process:   Inserts the contact in given list of contacts ordered by name and type
Arguments: contacts - pointer to the list of contacts, c - pointer to contact to insert
*******************************************************************/
void insertSortedContact(Contacts* contacts, Contact* c);
/********************************************************************
Function name: addContact
Process:   checks which list in array of list to insert the contact and insert to the list
Arguments: phonebook is the pointer to array of lists of contacts
Output:    Asks the user for contacts data
*******************************************************************/
void addContact(Contacts* phonebook[]);
/********************************************************************
Function name: deleteContact
Process:   searches for contacts by name and gives option to chose wich number to delete
Arguments: phonebook is pointer to array of lists of contacts, name - is pointer to name to search by
Output:    gives option to choose the contact to delete or "not found"
*******************************************************************/
void deleteContact(Contacts* phonebook[], char* name);
/********************************************************************
Function name: findContactByNum
Process:   searches the array of contacts to find the contact with given number
Arguments: phonebook is pointer to array of lists of contacts, number is pointer to number to search by
Return:    pointer to contact with given number or NULL
*******************************************************************/
Contact* findContactByNum(Contacts* phonebook[], char* number);
/********************************************************************
Function name: printContactByName
Process:   prints the list of contacts sorted by name
Arguments: clist is pointer to contacts list, order in flag is to print order number
Output:    contacts with data and if order flag is on than serial numbers of each one of them
*******************************************************************/
void printContactByName(Contacts* clist, int order); 
/********************************************************************
Function name: getContactsbyName
Process:   search for all contacts by given name
Arguments: phonebook is pointer to array of lists of contacts, name is pointer to name to search by
Return:   the list of contacts with given name or NULL
*******************************************************************/
Contacts* getContactsbyName(const Contacts* phonebook[], char* name);
/********************************************************************
Function name: getContactsbyPartial
Process:   search for all contacts that contains the string in name
Arguments: phonebook is pointer to array of lists of contacts, name is pointer to string(part of the name) to search by
Return:   the list of contacts with given part of name or NULL
*******************************************************************/
Contacts getContactsbyPartial(const Contacts* phonebook[], char* name);
/********************************************************************
Function name: printAllContacts
Process: prints the data of all contacts
Arguments: phonebook is pointer to array of lists of contacts
Output:    all contacts with all data
*******************************************************************/
void printAllContacts(const Contacts* phonebook[]);
/********************************************************************
Function name: printBasicInfo
Process:   prints basic info of contact or deleted type info
Arguments: c is pointer to the contact
Output:  info of contact or "unknown" if was 
*******************************************************************/
void printBasicInfo(Contact* c);

#endif 