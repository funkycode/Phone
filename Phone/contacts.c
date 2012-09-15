#include "contacts.h"
#include <string.h>
#include <stdio.h>
//#include <ctype.h>

int getTheLetter(const char firstLetter)
{
	int value;
	value = (int)firstLetter;
	if ( (65 <= value && value <= 90) ) // ||( 97 <= value && value <= 122)) // No need anymore as we convert to Upcase when reaadingfrom file and adding !!!
	{
		//if (65 <= value && value <= 90)  //see comment above 
		return (value-65);
		//return (value-97); //see comment above
	}
	return -1;
}

void  insertSortedContact(Contacts* contacts, Contact* c)
{
	int chk = -1;
	Contact* contact;
	Position P = contacts, N; //check next and keep prev.

	if(N = Advance (P))
	{
		contact = (Contact*)Retrieve(N);
		chk = strcmp(contact->name, c->name);
	}
	while (N &&  chk == -1)
	{
		P = Advance(P);
		if(N = Advance (P))
		{
			contact = (Contact*)Retrieve(N);
			chk = strcmp(contact->name, c->name);
		}
	}
	while(N && contact->type < c->type && strcmp(contact->name, c->name) == 0)
	{
		P = Advance(P);
		if(N = Advance (P))
			contact = (Contact*)Retrieve(N);   
	}
	Insert (c, contacts, P );
}

void addContact(Contacts* phonebook[])
{
	int  type = NULL;
	Contact* contact;

	contact = (Contact*)malloc(sizeof(Contact));
	printf("\nPlease Enter the name:\n");
	fflush(stdin);
	fgets(contact->name, NAME_LENGTH, stdin);
	strtok(contact->name, "\n");
	firstLettersUp(&contact->name);
	printf("\nPlease Enter the phone number:\n");
	fflush(stdin);
    fgets(contact->number, NUM_LENGTH, stdin);
	strtok(contact->number, "\n");
	contact->type = phoneType();

	if(getTheLetter(contact->name[0]) != -1)
		insertSortedContact(phonebook[getTheLetter(contact->name[0])], contact);
	else
		printf("\n\n\nFAILED!!! First letter should be a letter and not just any symbol\n\n");
}

Contact* findContactByNum(Contacts* phonebook[], char* number)
{
	int i, j, totalInList;
	Contact* contact = NULL;
	Position P;
	
	for(i=0;i<LETTERS;i++)
	{
		totalInList=TotalNum(phonebook[i]);
		if(totalInList)
			P = phonebook[i];
		for(j=0;j<totalInList;j++)
		{
			P = Advance(P);
			contact = (Contact*)Retrieve(P);
			if(strcmp(contact->number,number) == 0)
			{
				return contact;
			}
		}
	}
    return NULL;
}

void deleteContact(Contacts* phonebook[],char* name)
{
	int i, j, total;
	Contacts* clist = MakeEmpty(NULL);
	Contact* c;
	Position P;

	clist = getContactsbyName(phonebook, name);
	printContactByName(clist, 1);
	total = TotalNum(clist);
	if(total)
	{
		P = clist;
		printf("\n Select the number to delete:\n  ");
		j = -1;
		while(j <1 || j>total)
		{
			j = getch();
			j = atoi(&j);
		}

		for(i=0;i<j;i++)
			P = Advance(P);
		c = (Contact*)Retrieve(P);
		Delete(c,phonebook[getTheLetter(c->name[0])]);
		free(c);
	}
}

void printContactByName(Contacts* clist, int order)
{
	int i, j, type[TYPES], total;
	Position P;
	char * PhoneType[] = { "mobile" , "work", "home" };
	char name[NAME_LENGTH] = "";
	Contact* contact;

	total = TotalNum(clist);
	if(total)
	{
		P = First(clist);
		for(i=0;i<total;i++)
		{
  			contact = (Contact*)Retrieve(P);
			if(strcmp(contact->name,name) != 0)
			{
			    for(j=0;j<TYPES;j++)
			        type[j]=0;
				printf("\n\n%s\n", contact->name);
				strcpy(name,contact->name);
			}
			type[contact->type]++;
			if(order)
			{
				if ( type[contact->type] > 1 )
					printf("\n%d) %s%d %s\n", (i+1), PhoneType[contact->type], type[contact->type], contact->number);
				else
					printf("\n%d) %s %s\n", (i+1), PhoneType[contact->type], contact->number);
			}
			else
			{
				if ( type[contact->type] > 1 )
					printf("\n %s%d %s\n", PhoneType[contact->type], type[contact->type], contact->number);
				else
					printf("\n %s %s\n", PhoneType[contact->type], contact->number);
			}
			P = Advance(P);
		}
	}
	else
		printf("\n\nNo contact found\n\n");
}



Contacts* getContactsbyName(const Contacts* phonebook[], char* name)
{

	int i, total;
	Contact* contact;
	Contacts* clist = MakeEmpty(NULL);
	Position P , N = clist;

	firstLettersUp(name);
	if(getTheLetter(name[0])!= -1)
	{
		P = First(phonebook[getTheLetter(name[0])]);
		total = TotalNum(phonebook[getTheLetter(name[0])]);
		if(total>0)
		{
			for(i=0;i<total;i++)
			{
				contact = (Contact*)Retrieve(P);
				if (strcmp(name,contact->name) == 0)
				{
	                Insert(contact,clist,clist);
				}

				P = Advance(P);
			}
		}
	}
	return clist;
}

void printAllContacts(const Contacts* phonebook[])
{
	int i, j, type[TYPES];
	Position P;
	Contact* contact;
	char name[NAME_LENGTH] = "";
	char *  PhoneType[] = { "mobile" , "work", "home" };


	for (i=0;i<LETTERS;i++)
	{
		P = First(phonebook[i]);
		while (P)
		{
			contact = (Contact*)Retrieve(P);
			if(strcmp(name,contact->name))
			{
				printf("\n%s\n", contact->name);
				for(j=0;j<TYPES;j++)
					type[j]=0;
			}
			type[contact->type]++;
			if ( type[contact->type] > 1 )
				printf("  %s%d: %s\n", PhoneType[contact->type], type[contact->type], contact->number);
			else
				printf("  %s: %s\n", PhoneType[contact->type], contact->number);
			strcpy(name, contact->name);
			P = Advance(P);
		}
	}
}

void printBasicInfo(Contact* c)
{
	char*  PhoneType[] = { "mobile" , "work", "home" };
    
	printf("\n%s | %s | ", c->name, PhoneType[c->type]); 
}

Contacts getContactsbyPartial(const Contacts* phonebook[], char* name)
{

	int i, j, total;
	Contact* contact;
	Contacts* clist = MakeEmpty(NULL);
	Position P , N = clist;

	for(i=0;i<LETTERS;i++)
	{
		P = First(phonebook[i]);
		total = TotalNum(phonebook[i]);
		if(total>0)
		{
			for(j=0;j<total;j++)
			{
				contact = (Contact*)Retrieve(P);
				if (partialCompare(contact->name,name))
				{
					firstLettersUp(contact->name); //we want to get back to upper case
                    Insert(contact,clist,N);
				}
				P = Advance(P);
			}
		}
	}
	return clist;
}