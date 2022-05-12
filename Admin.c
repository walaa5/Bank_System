#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include<string.h>

#include "linkedList.h"
#include "linkedList.c"


int size;
int value;

// bank id for new  current account
int current_id = 1;
// intialize a list 
List bank;

void create_account(void);
void make_transaction(Account* acc_node);
void get_cash(Account* acc_node);
void change_status(Account* acc_node);
void depoist(Account* acc_node);

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
	//system("cls");
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
		scanf("%s", admin_name);
		fflush(stdin);

		printf("please enter admin password: ");
		scanf("%s", admin_password);
		fflush(stdin);
		

		if(strcmp(admin_name, "admin") == 0 && strcmp(admin_password, "0000") == 0)
		{
			while (1)
			{
			
				//system("cls");
				printf("\n welcome to Admin window \n");
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
					int search_id = 0 ; 
					printf("Enter Client Bank Account ID: \n");
					scanf("%i", &search_id);
					
					
					Account* acc_node;
					
					int flag = List_searchid(&bank, search_id, &acc_node);
					
					/*node of linked list sanity check
					printf("%s\n", acc_node->full_name);
					printf("address of node: %p\n", acc_node);
					*/


					if (flag == -1){
						printf("No account with given bank ID \n");
					}
					
					else{
						int open_option ;
						
						printf("welcome to Open account window \n");
						printf("please choose what you want to do: \n");
						printf("1 - Make transaction\n");
						printf("2 - Change account status\n");
						printf("3 - Get Cash\n");
						printf("4 - Depoist into Account\n");
						scanf("%i", &open_option);

						if (open_option == 1){
							make_transaction(acc_node);

						}
						else if(open_option == 2){
							change_status(acc_node);
						}
						else if (open_option == 3){
							get_cash(acc_node);
						}
						else if (open_option == 4){
							depoist(acc_node);
							
							
							
						}

					}
					
				}

				else if(admin_option == 3)
				{
					// Exit system
					break;
				}
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
	// not case sensitive
	for (int i = 0; i < strlen(new_acc.status); ++i) {
        new_acc.status[i] =  tolower((unsigned char) new_acc.status[i]);
    }

	printf("your bank_id is: %i\n", current_id);
	new_acc.bank_id = current_id;
	current_id ++ ;

	printf("your password is: 00000000\n");
	strcpy(new_acc.password, "00000000");

	new_acc.balance = 0;
	
	// add a new account node to the system
	List_voidAddList(&bank, new_acc);
	
}


void make_transaction(Account* acc_node){

	Account* trans_node ;

	int req_id = 0 ; 
	printf("Enter Transfer Client Bank Account ID: \n");
	scanf("%i", &req_id);

	int flag = List_searchid(&bank, req_id, &trans_node);
	if (flag == -1){
		printf("No account with given bank ID \n");
		return;
	}
				
	else{
		if (strcmp(acc_node->status, "active") == 0){
			if (strcmp(trans_node->status, "active") == 0){
				double trans_amount ; 
				printf("Enter amount to tranfer: ");
				scanf("%lf", &trans_amount);

				if (trans_amount > acc_node->balance){
					printf("Not enough in balance, couldn't complete\n");
					return;
				}
				else{
					acc_node->balance -= trans_amount ;
					trans_node->balance += trans_amount;
					printf("Transaction completed\n");
					return;
				}

			}
			
			else{
				printf("Tranfer account is not active, couldn't complete");
				return;
			}

		}
		else{
			printf("Your account is not active, couldn't complete");
			return;
		}

	}

}

void change_status(Account* acc_node){
	int opt ; 
	printf("1 for Active, 2 for Restricted, 3 for Closed");
	scanf("%i", &opt);

	if (opt == 1){
		strcpy(acc_node->status, "active");
	}
	else if (opt == 2){
		strcpy(acc_node->status, "restricted");
	}
	else if (opt == 3){
		strcpy(acc_node->status, "closed");
	}

}

void get_cash(Account* acc_node){
	double withdrawal ;
	printf("Enter amount to withdraw: ");
	scanf("%lf", &withdrawal);

	if (withdrawal > acc_node->balance){
		printf("Not enough cash in balance\n");
		return;
	}
	else{
		acc_node->balance -= withdrawal;
		printf("Cash withdrawal completed\n");
		printf("Current Balance: %lf\n", acc_node->balance);
		return;
	}

}

void depoist(Account* acc_node){
	double into ;
	printf("Enter amount to depoist: ");
	scanf("%lf", &into);

	acc_node->balance += into;
	printf("Cash depoisted completed\n");
	printf("Current Balance: %lf\n", acc_node->balance);
	return;


}

