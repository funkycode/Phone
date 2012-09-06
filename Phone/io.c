#include "io.h"




void pressToContinue(){
	int anykey;
	printf("\n\n\n\nTo Continue, please, press any key\n");
	anykey = getch();
}

void printMenu(const Contacts* phonebook[])
{
	int choice = NULL;

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
			printMenu3();
			break;
		case '3':
			system("cls");
			printMenu4();
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
			contacts = getContactsbyName(phonebook);
			system("cls");
			printContactByName(contacts);
			DeleteList(contacts);
			pressToContinue();
			system("cls");
			printMenu2(phonebook);
			break;
		case '2':
			system("cls");
			findContactByNum(phonebook );
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
			deleteContact(phonebook);
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

void printMenu3()
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
			printf("1");
			break;
		case '2':
			printf("2");
			break;
		case '3':
			printf("3");
			break;
		case '4':
			system("cls");
			//	printMenu(phonebook);
			break;
		default:
			system("cls");
			printMenu3();
	}
}

void printMenu4()
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
			printf("1");
			break;
		case '2':
			printf("2");
			break;
		case '3':
			printf("3");
			break;
		case '4':
			system("cls");
			//		printMenu(phonebook);
			break;
		default:
			system("cls");
			printMenu4();
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






