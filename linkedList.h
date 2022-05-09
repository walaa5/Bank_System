#ifndef LINKEDLIST_H
#define LINKEDLIST_H


// structure for Bank account
typedef struct bank_account
{
	char full_name[40];
	char full_address[200];
	char id[15];
	int age ;
	int bank_id;
	int gaurd;
	char gaurd_id[14];
	char status[11];
	double balance;
	char password[9];
	
}Account;


// structure for List nodes
typedef struct listnode
{
    Account new_acc;
    struct listnode* Next;
}ListNode;

// define struct List
typedef struct list
{
    int size;
    ListNode* head;
}List;


/**** 
    List Functions prototypes 
***/
void List_voidInit(List *pl);
void List_voidInsertList(int Pos, List* pl, Account new_account);
void List_voidReplaceList(int Pos, List* pl, Account new_account);
void List_voidDeleteList(int Pos, List* pl, Account* pd);
void List_voidRetriveList(int Pos, List* pl, Account* pd);
void List_voidAddList(List* pl, Account new_account);

int  List_intIsEmpty(List* pl);
int  List_intIsFull(List* pl);
int  List_intSize(List* pl);
void List_voidPrint(List* pl);
void List_voidDestroyList(List* pl);
int List_searchid(List* pl, int search_id, Account* pd);


#endif