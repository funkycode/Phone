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
ElementType Retrieve(Position P); 	
int IsEmpty(List L);	
int IsLast(Position P, List L);		
Position Find(ElementType X, List L);	
void Delete(ElementType X, List L);	
Position FindPrevious(ElementType X, List L); 
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);	


#endif  /* _List_H */

