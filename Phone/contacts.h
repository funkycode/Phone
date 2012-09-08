#include "lists.h"


#ifndef  _contacts_H			
#define _contacts_H

#define NAME_LENGTH 26
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

int getTheLetter(const char firstLetter);
void insertSortedContact(Contacts* contact, Contact* c);
void addContact(Contacts* phonebook[]);
void deleteContact(Contacts* phonebook[]);
void findContactByNum(Contacts* phonebook[]);
void printContactByName(Contacts* clist, int order); 
Contacts getContactsbyName(const Contacts* phonebook[]);
void printAllContacts(const Contacts* phonebook[]);

#endif 