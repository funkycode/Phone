#include "lists.h"

#ifndef  _contacts_H			
#define _contacts_H

#define NAME_LENGTH 26
#define NUM_LENGTH 15
#define LETTERS 26

//For letter arrays sorting
//enum alphabet_list {A=0, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, WRONG_LETTER = -1};


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
//typedef List Phonebook;
//typedef PtrToNode Position;

int getTheLetter(const char firstLetter);


//Contact* Phonebook[32];
#endif 