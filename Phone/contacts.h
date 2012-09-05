#include "lists.h"
#define NAME_LENGTH 26
#define NUM_LENGTH 15
typedef struct
{
	char name[NAME_LENGTH];
	char number[NUM_LENGTH];
	int type;
}Contact;
//struct Node;
//typedef Contact ElementType;		
//typedef struct Node *PtrToNode;	
//typedef PtrToNode List;
typedef List Contacts;
//typedef PtrToNode Position;



Contact* Phonebook[32];
