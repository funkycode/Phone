/********************************************************************
Module Name: Dummy LIST
Process:   It contains all operation related to linked lists with added functions (described below)
*******************************************************************/
#include <stdlib.h>

#ifndef  _list_H			
#define _list_H
struct Node;
typedef void* ElementType;		
typedef struct Node *PtrToNode;	
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty(List L);		
Position Header(List L);		
Position First(List L);	
Position Advance(Position P);
Position Prev(Position P);
ElementType Retrieve(Position P); 	
int IsEmpty(List L);	
int IsLast(Position P, List L);		
Position Find(ElementType X, List L);	
void Delete(ElementType X, List L);	
Position FindPrevious(ElementType X, List L); 
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);
/********************************************************************
Function name: TotalNum
Process:   return the number of values in list
Arguments: L is list
Return:  number of values in list
*******************************************************************/
int TotalNum(List L);
/********************************************************************
Function name: InsertLimitSize
Process:  insert in list and keeps list not bigger than given number
Arguments: X is element to insert, L is list, size is maximum size
*******************************************************************/
void InsertLimitSize(ElementType X, List L, int size);

#endif  /* _List_H */

