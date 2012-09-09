#include "calls.h"
#include <string.h>
#include <stdio.h>

void printAllCalls(const Calls* calls)
{
	int i, total;
	Position P;
	Call* call;
	char*  CallType[] = { "(in)" , "(out)", "(missed)" };

	total = TotalNum(calls);
	if (total == 0)
		printf("\nNo call logs yet\n");
	else
	{
        P = First(calls);
		while(P)
		{
			call = (Call*)Retrieve(P);
			if(call->contact)
			    printBasicInfo(call->contact);
			else
				printf("%s",call->number); 
			printf(" | %s | ", CallType[call->type]);
			printTime(call->timeDur);
			printf("\n");
			P = Advance (P);	
		}
    }


}
void AddNewCall(Calls* calls, Contacts* phonebook[])
{
	int duration, type = NULL;
    SYSTEMTIME currentTime;
	Call* call;
	char number[NUM_LENGTH];
    
	call = (Call*)malloc(sizeof(Call));
	printf("\nPlease Enter the number:\n");
	fflush(stdin);
	scanf("%s",&number);
	strcpy(call->number,number);
	call->contact = findContactByNum(phonebook, number);
	call->type = callType();
	GetSystemTime(&currentTime);
	printf("\nPlease choose a duration:\n");
	fflush(stdin);
	scanf("%ld",&duration);
	call->timeDur = dateAndDur(currentTime.wDay, currentTime.wMonth, currentTime.wHour, currentTime.wMinute , duration);
    InsertLimitSize(call,calls, MAX_CALL_LOG);

    
}

void DeleteCall(Calls* calls)
{
	int i ,j = -1, count = 0;
	Call* call;
    char name[NAME_LENGTH] = "";
	Calls clist = MakeEmpty(NULL);
	Position N = clist, P = NULL;
	char*  CallType[] = { "(in)" , "(out)", "(missed)" };

	strcpy(name, searchQuery(name));
	name[0] = toupper(name[0]);
	if(TotalNum(calls))
	   P = First(calls);
    system("cls");
	while(P)
	{
		call = (Call*)Retrieve(P);
		if(call->contact->name != NULL && strcmp(call->contact->name, name) == 0)
		{
			count++;
			printf("%d) %s | %s | ", count,  call->contact->name, CallType[call->type]); 
			printTime(call->timeDur);
			printf("\n");
			Insert(call, clist, N);
			N = Advance(N);
		}
		P = Advance(P);
	}
	if( count > 0 )
	{
		printf("\n Select the number to delete:\n  ");
		while(j <1 || j>count)
		{
			j = getch();
			j = atoi(&j);
		}
		N = clist;
		for(i=0;i<j;i++)
			N = Advance(N);
		call = (Call*)Retrieve(N);
		Delete(call, calls);
	}
	else
		printf("\nNot calls found\n");
	DeleteList(clist);


	    
}
