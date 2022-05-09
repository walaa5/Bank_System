#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedList.h"
#include "linkedList.c"


int size;
int value;
	
// intialize a list 
List bank;

void create_account(void);

int main()
{

	// variable 
	int usr_type;
	char admin_name[10] ;
	char admin_password[5];
	int admin_option;

    // intialize a list         
    // List l;

    List_voidInit(&bank);

	// ***********************************************************  //
	system("cls");
	printf("welcome to our bank system :)\n");
	printf("please choose who you are: \n");
	printf("1 - Admin\n");
	printf("2 - Client\n");
	scanf("%d", &usr_type);
	fflush(stdin);

	// **********************************************************  // 
	if(usr_type == 1)
	{
		printf("\n\nplease enter admin username: ");
		scanf("%s", &admin_name);
		fflush(stdin);

		printf("please enter admin password: ");
		scanf("%s", &admin_password);
		fflush(stdin);
		

		if(strcmp(admin_name, "admin") == 0 && strcmp(admin_password, "0000") == 0)
		{
			system("cls");
			printf("welcome to Admin window \n");
			printf("please choose what you want to do: \n");
			printf("1 - Create New Account\n");
			printf("2 - Open Existing Account\n");
			printf("3 - Exit System\n");

			scanf("%d", &admin_option);
			if(admin_option == 1)
			{
				// create new account
				create_account();

				// print elements and size of the list
				size = List_intSize(&bank);
				printf("The size of the list = %d\n", size);

				printf("The elements of the list are : \n");
				List_voidPrint(&bank);
			}

			else if(admin_option == 2)
			{
				// open existing account and provide number of options
				
			}

			else if(admin_option == 3)
			{
				// Exit system
			}
			
		}

		else
		{
			printf("you have entered wrong name or passward!");
		}

	}

    return 0;
}


void create_account()
{
	// create a new account struct
	Account new_acc;
	
	// first take account info from client
	printf("enter your full name: ");
	fflush(stdin);
	gets(new_acc.full_name); 
	
	printf("entre your address: ");
	fflush(stdin);
	gets(new_acc.full_address);
	
	printf("enter your national id: ");
	fflush(stdin);
	gets(new_acc.id);

	printf("enter your age: ");
	fflush(stdin);
	scanf("%d", &new_acc.age);

	printf("enter your if you have a gard 0 -> No, 1 -> Yes :");
	fflush(stdin);
	scanf("%d", &new_acc.gaurd);

	printf("enter your gaurd id: ");
	fflush(stdin);
	gets(new_acc.gaurd_id);

	printf("enter your status: ");
	fflush(stdin);
	gets(new_acc.status);

	printf("your bank_id is: 0000 0000 00\n");
	strcpy(new_acc.bank_id, "0000000000");

	printf("your password is: 00000000\n");
	strcpy(new_acc.password, "00000000");

	new_acc.balance = 0;
	
	// add a new account node to the system
	List_voidAddList(&bank, new_acc);
	
}


