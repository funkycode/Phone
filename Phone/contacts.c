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

void deleteContact(Contacts* phonebook[], char* name)
{
	int i;
	Position P=
	name = searchQuery();
	





}

void printContactByName(Contacts* phonebook[])
{
	int i, type[TYPES], chk, total;
	Contact* contact;
	Position P;
    char name[NAME_LENGTH];
    char * PhoneType[] = { "mobile" , "work", "home" };




	for(i=0;i<TYPES;i++)
		type[i]=0;

	printf("\nEnter the value to search:\n");
	scanf("%s",&name);
	name[0] = toupper(name[0]);

	if(getTheLetter(name[0])!= -1)
	{
		Position P = First(phonebook[getTheLetter(name[0])]);
        total = TotalNum(phonebook[getTheLetter(name[0])]);
		if(total>0)
		{
		    
			for(i=0;i<total;i++)
			{
				contact = (Contact*)Retrieve(P);
				if (strcmp(contact->name,name)==0)
				{
					printf("%s\n",name);
					break;
				}
				P = Advance(P);
			}
			
			while (P && strcmp(contact->name,name)==0)
			{
				
				
                contact = (Contact*)Retrieve(P);
                type[contact->type]++;
				
				if ( type[contact->type] > 1 )
				   printf("\n %s%d %s\n", PhoneType[contact->type], type[contact->type], contact->number);
				else
				   printf("\n %s %s\n", PhoneType[contact->type], contact->number);
				P = Advance(P);


				
			}
		}
		chk = 0; 
		for(i=0;i<3;i++)
		      if(type[i]>0)
				  chk++;
		if(!chk)
			printf("\n\n No Entery found for \"%s\"\n\n",name);


	}

}
