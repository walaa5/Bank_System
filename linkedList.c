/*************************************************************************************/ 
/* Author   :   Walaa Ahmed                                                          */
/* Date     :   31 Dec 2021                                                          */
/* Version  :   V01                                                                  */
/* SoftWare :   List implemetation using linked_base                                 */
/*************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"


/**** 
    List Functions prototypes 
***/
/*void List_voidInit(List* pl);
void List_voidInsertList(int Pos, List* pl, Account new_account);
void List_voidReplaceList(int Pos, List* pl, Account new_account);
void List_voidDeleteList(int Pos, List* pl, Account* pd);
void List_voidRetriveList(int Pos, List* pl, Account* pd);
void List_voidAddList(List* pl, Account new_account);

int  List_intIsEmpty(List* pl);
int  List_intIsFull(List* pl);
int  List_intSize(List* pl);
void List_voidPrint(List* pl);
void List_voidDestroyList(List* pl);*/


/*int main()
{
    int size;
    int value;
	
	Account A ;
    A.full_name = "walaa ahmed";

    // intialize a list 
    List L;
    List_voidInit(&L);
    
	List_voidAddList(&L, A);
    List_voidAddList(&L, A);

    // print elements and size of the list
    size= List_intSize(&L);
    printf("The size of the list = %d\n", size);

    printf("The elements of the list are : \n");
    List_voidPrint(&L);

    printf("\n===================================\n");

    // retrive element from list 
    List_voidRetriveList(2, &L, &value);
    printf("the retrived value = %d\n", value);
    printf("\n===================================\n");

    // delete an element from list 
    List_voidDeleteList(1, &L, &value);
    printf("The deleted value = %d\n", value);
    
    size= List_intSize(&L);
    printf("The size of the list = %d\n", size);

    printf("The elements of the list are : \n");
    List_voidPrint(&L);

    printf("\n===================================\n");

    // destroy the list 
    List_voidDestroyList(&L);
    printf("List is desroyed\n");
    
    size= List_intSize(&L);
    printf("The size of the list is = %d\n", size);*/



// *****************************************  Functions ***************************************//
/*** 
 * this function to init the List
***/
void List_voidInit(List* pl)
{
    pl->head = NULL;
    pl->size =0;
}


/***
 * check the List is empty or not
***/
int  List_intIsEmpty(List* pl)
{
    return (pl->head == NULL);
}


/***
 * check the List is full or not
***/
int  List_intIsFull(List* pl)
{
    return 0;
}


/***
 * function return the size of the List
***/
int  List_intSize(List* pl)
{
    return (pl->size);
}


/***
 * function to insert a value at a specific position inside List
***/
void List_voidInsertList(int Pos, List* pl, Account new_account)
{
    ListNode* q;
    int i;

    /* Create a node */
    ListNode* pn = (ListNode*)malloc(sizeof(ListNode));
    pn->new_acc = new_account;
    pn->Next =   NULL;

    if(Pos == 0)        
    {
        /* Insert at first */
        pn->Next = pl->head;
        pl->head = pn;
    }
    else
    {
        for(q = pl->head, i=0; i< Pos-1; i++)
        {
            q = q->Next;
        }
        pn ->Next= q->Next;
        q->Next= pn;
    }

    pl->size++;
}


/***
 * function to replace a value at specific position inside list
***/
void List_voidReplaceList(int Pos, List* pl, Account new_account)
{
    int i;
    ListNode* q;
    for(q= pl->head, i=0; i<Pos; i++)
    {
        q = q->Next;
    }
    q->new_acc= new_account;
}


/***
 * function to delete an element at specific position from the List
***/
void List_voidDeleteList(int Pos, List* pl, Account* pd)
{
    int i;
    ListNode *q, *tmp;

    if(Pos==0)
    {
        *pd = pl->head->new_acc;
        tmp = pl->head->Next;
        free(pl->head);
        pl->head= tmp;
    }
    else
    {
        for(q= pl->head, i=0; i<Pos-1; i++)
        {
            q = q->Next;
        }
       *pd = q->Next->new_acc;
        tmp= q->Next->Next;
        free(q->Next);
        q->Next = tmp;
    }
    pl->size--;
}


/***
 * function to retrive ana element from list at specific position 
***/
void List_voidRetriveList(int Pos, List* pl, Account* pd)
{
    int i;
    ListNode* q;

    for(q= pl->head, i=0; i< Pos; i++)
    {
        q = q->Next;
    }
    *pd= q->new_acc;
}


/***
 * function to print elements of a List
***/
void List_voidPrint(List* pl)
{
    ListNode* q= pl->head;

    while(q != NULL)
    {
        printf("%s\t", q->new_acc.full_name);
        q= q->Next;
    }
}


/***
 * function to destroy a List
***/
void List_voidDestroyList(List* pl)
{
    ListNode* tmp;

    while(pl->head != NULL)         
    {
        tmp = pl->head->Next;
        free(pl->head);
        pl->head= tmp;
    }

    pl->size=0;
}


/***
 * function to insert a value at the end of the List
***/
void List_voidAddList(List* pl, Account new_account)
{
    ListNode* q;
    int i;

    /* Create a node */
    ListNode* pn = (ListNode*)malloc(sizeof(ListNode));
    pn->new_acc =   new_account;
    pn->Next =   NULL;

    if(pl-> head == NULL)        
    {
        /* Insert at first */
        pl->head = pn;
    }
    else
    {
		q = pl -> head;
        while(q ->Next != NULL)
        {
            q = q->Next;
        }
        q->Next= pn;
		pn->Next = NULL;
    }

    pl->size++;
}


/***
 * function to search element of a List by bank account id and return node of account if exists
***/
int List_searchid(List* pl, int search_id, Account** acc_node)
{
    ListNode* q= pl->head;

    while(q != NULL)
    {
        if (q->new_acc.bank_id == search_id){
            *acc_node = &(q->new_acc);
            return 0;
        }
        q= q->Next;
    }
    return -1;
}
