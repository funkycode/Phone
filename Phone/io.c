#include "io.h"




void pressToContinue(){
	int anykey;
	printf("\n\n\n\nTo Continue, please, press any key\n");
	anykey = getch();
}

void printMenu(const Contacts* phonebook[])
{
	int choice = NULL;
	Calls* calls = MakeEmpty(NULL);

	if(readCallLog(callsFile, phonebook, calls))
	{
		 system("cls");
		 printf("WARNING!!!! There was error reading the calls log file!\n");
		 pressToContinue();
		 system("cls");
	}

	printf("========== Main Menu =============== \n\n");
	printf("1.Contacts\n");
	printf("2.Call log \n");
	printf("3.Message Log \n");
	printf("4.Close\n\n");
	choice = getch();
	switch(choice) {
		case '1':
			system("cls");			
			printMenu2(phonebook);
			break;
		case '2':
			system("cls");
			printMenu3(phonebook, calls);
			break;
		case '3':
			system("cls");
			printMenu4(phonebook);
			break;
		case '4':
			break;
		default:
			system("cls");
			printMenu(phonebook);
	}
}

void printMenu2(Contacts* phonebook[])
{
	int choice = NULL;
	Contacts* contacts = MakeEmpty(NULL);
	char name[NAME_LENGTH] = "";


	printf("========== Contacts =============== \n\n");
	printf("1.Find contact by name \n");
	printf("2.Find a contact by partial \n");
	printf("3.Show all contacts \n");
	printf("4.Add new contact \n");
	printf("5.Delete contact \n");
	printf("6.Return to main menu\n\n");
	choice = getch();
	switch(choice) {
		case '1':
			system("cls");
			strcpy(name, searchQuery(name));
			contacts = getContactsbyName(phonebook, name);
			system("cls");
			printContactByName(contacts, 0);
			DeleteList(contacts);
			pressToContinue();
			system("cls");
			printMenu2(phonebook);
			break;
		case '2':
			system("cls");
			strcpy(name, searchQuery(name));
			contacts = getContactsbyPartial(phonebook, name);
			system("cls");
			printContactByName(contacts, 0);
			DeleteList(contacts);
			pressToContinue();
			system("cls");
			printMenu2(phonebook);
			break;
		case '3':
			system("cls");
			printAllContacts(phonebook);
			pressToContinue();
			system("cls");
			printMenu2(phonebook);
			break;
		case '4':
			system("cls");
			addContact(phonebook);
			pressToContinue();
			system("cls");
			printMenu2(phonebook);
			break;
		case '5':
			system("cls");
			strcpy(name, searchQuery(name));
			deleteContact(phonebook, name);
			pressToContinue();
			system("cls");
			printMenu2(phonebook);
			break;
		case '6':
			system("cls");
			printMenu(phonebook);
			break;
		default:
			system("cls");
			printMenu2(phonebook);
	}
}

void printMenu3(Contacts* phonebook[], Calls* calls)
{
	int choice = NULL;
	
	
	printf("========== Call Logs =============== \n\n");
	printf("1.Show all calls\n");
	printf("2.Add new call \n");
	printf("3.Delete call \n");
	printf("4.Return to main menu\n\n");
	choice = getch();
	switch(choice) {
		case '1':
            system("cls");
			printAllCalls(calls);
			pressToContinue();
			system("cls");
			printMenu3(phonebook, calls);
			break;
		case '2':
			system("cls");
			AddNewCall(calls, phonebook);
			pressToContinue();
			system("cls");
			printMenu3(phonebook, calls);			
			break;
		case '3':
			system("cls");
			DeleteCall(calls);
			pressToContinue();
			system("cls");
			printMenu3(phonebook, calls);				
			break;
		case '4':
			system("cls");
			if(writeCallLog(callsFile, calls))
			{
				printf("There was error writing the call logs to the file");
				pressToContinue();
				system("cls");
			}
			printMenu(phonebook);
			break;
		default:
			system("cls");
			printMenu3(phonebook, calls);
	}
}

void printMenu4(Contacts* phonebook[])
{
	int choice = NULL;

	printf("========== Message Log =============== \n\n");
	printf("1.Show recent messages\n");
	printf("2.Add new message\n");
	printf("3.Show conversation \n");
	printf("4.Return to main menu\n\n");
	choice = getch();
	switch(choice) {
		case '1':
			
			break;
		case '2':
			
			break;
		case '3':
			
			break;
		case '4':
			system("cls");
			printMenu(phonebook);
			break;
		default:
			system("cls");
			printMenu4(phonebook);
	}
}




int phoneType()
{
	int type = NULL;

	printf("\nSelect the type:\n");
	printf("1.Mobile\n");
	printf("2.Home\n");
	printf("3.Work\n");
	fflush(stdin);
	type = getch();
	switch(type) {
		case '1':
			return 0;
			break;
		case '2':
			return 1;
			break;
		case '3':
			return 2;
			break;
		default:
			return phoneType();
			break;
	}
}

int callType()
{
	int type = NULL;

	printf("\nSelect the type:\n");
	printf("1.Incoming\n");
	printf("2.Outgoing\n");
	printf("3.Missed\n");
	fflush(stdin);
	type = getch();
	switch(type) {
		case '1':
			return 0;
			break;
		case '2':
			return 1;
			break;
		case '3':
			return 2;
			break;
		default:
			return callType();
			break;
	}
}


char* searchQuery(char* query)
{
	printf("\nEnter the value to search:\n");
	fflush(stdin);
    scanf("%s",query);
	return query;
}




int partialCompare(char first[], char second[])
{
	
	int i;

	for(i=0; i<NAME_LENGTH; i++)
    {
     first[i] = tolower(first[i]);
	 second[i] = tolower(second[i]);
    }
	if(strstr(first,second) != NULL)
		return 1;
	first[0] = toupper(first[0]); //We want to get to upper case first letter
	return 0;
}

int dateAndDur(int day, int month, int minute, int hour, int duration)
{
	int result = 0;
	result = day;
	month = month << 5;
	result = result | month;
	minute = minute << 9;
	result = result | minute;
	hour = hour << 15;
	result = result | hour;
	duration = duration << 20;
	result = result |  duration;

	return result;
}
void printTime(const int bits) {
	int duration = (bits >> 20) &  4095;
	int minutes = duration / 60;
	int seconds = (duration % 60); 
	
	printf(" %d/%d %d:%d | ", bits & 31,(bits >> 5) & 15, (bits >> 15) & 31	,(bits >> 9) & 63); 
	printf("%dm %ds\n", minutes, seconds);
}
