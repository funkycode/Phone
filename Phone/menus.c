#include "menus.h"


void printMenu()
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
			printMenu2();
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
			//here we need to save all data
			break;
		default:
			system("cls");
			printMenu();
	}
}

void printMenu2()
{
	int choice = NULL;

	printf("========== Contacts =============== \n\n");
	printf("1.Find contact by name \n");
	printf("2.Find a contact by partial name \n");
	printf("3.Show all contacts \n");
	printf("4.Add new contact \n");
	printf("5.Delete contact \n");
	printf("6.Return to main menu\n\n");
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
			break;
		case '5':
			break;
		case '6':
			system("cls");
			printMenu();
			break;
		default:
			system("cls");
			printMenu2();
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
			printMenu();
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
			printMenu();
			break;
		default:
			system("cls");
			printMenu4();
	}
}

