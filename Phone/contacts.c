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
		if(N = Advance (P)){
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
	scanf("%s",&contact->name);
	contact->name[0] = toupper(contact->name[0]);
	printf("\nPlease Enter the phone number:\n");
	fflush(stdin);
	scanf("%s",&contact->number);
	contact->type = phoneType();

	if(getTheLetter(contact->name[0]) != -1)
		insertSortedContact(phonebook[getTheLetter(contact->name[0])], contact);
	else
		printf("\n\n\nFAILED!!! First letter should be a letter and not just any symbol\n\n");


}

void findContactByNum(Contacts* phonebook[])
{
	int i, j, totalInList;
	Contact* contact;
	Position P;
	char number[NUM_LENGTH];
	char *  PhoneType[] = { "mobile" , "work", "home" };

	printf("\nEnter the value to search:\n");
	scanf("%s",&number);

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
				printf("\n%s %s : %s\n", contact->name, PhoneType[contact->type], contact->number); 

			}

		}
	}


}

void deleteContact(Contacts* phonebook[])
{
	int i, j, total;
	Contacts* clist = MakeEmpty(NULL);
	Contact* c;
	Position P;

	clist = getContactsbyName(phonebook);
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




	}






}

void printContactByName(Contacts* clist, int order)
{
	int i, type[TYPES], total, count = 1;
	Position P;
	char * PhoneType[] = { "mobile" , "work", "home" };
	Contact* contact;

	total = TotalNum(clist);
	if(total)
	{
		for(i=0;i<TYPES;i++)
			type[i]=0;

		P = First(clist);

		contact = (Contact*)Retrieve(P);
		printf("\n\n%s\n", contact->name);


		for(i=0;i<total;i++)
		{
			contact = (Contact*)Retrieve(P);
			type[contact->type]++;
			count++;

			if(order)
			{
				if ( type[contact->type] > 1 )
					printf("\n%d) %s%d %s\n", count, PhoneType[contact->type], type[contact->type], contact->number);
				else
					printf("\n%d) %s %s\n", count, PhoneType[contact->type], contact->number);
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



Contacts getContactsbyName(const Contacts* phonebook[])
{

	int i, total;
	Contact* contact;
	Contacts* clist = MakeEmpty(NULL);
	Position P , N = clist;
	char name[NAME_LENGTH];

	printf("\nEnter the name to search:\n");
	scanf("%s",&name);
	name[0] = toupper(name[0]);

	if(getTheLetter(name[0])!= -1)
	{
		P = First(phonebook[getTheLetter(name[0])]);
		total = TotalNum(phonebook[getTheLetter(name[0])]);
		if(total>0)
		{

			for(i=0;i<total;i++)
			{
				contact = (Contact*)Retrieve(P);
				if (strcmp(contact->name,name)==0)
				{
					break;
				}
				P = Advance(P);
			}



			while (P && strcmp(contact->name,name)==0)
			{


				contact = (Contact*)Retrieve(P);
				Insert(contact,clist,N);
				P = Advance(P);
				N = Advance(N);
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
				printf("-- %s%d: %s\n", PhoneType[contact->type], type[contact->type], contact->number);
			else
				printf("-- %s: %s\n", PhoneType[contact->type], contact->number);
			strcpy(name, contact->name);

			P = Advance(P);
		}
	}

}
