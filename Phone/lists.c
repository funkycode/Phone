#include "lists.h"

struct Node
{
	ElementType Element;
	Position Next;
};

List MakeEmpty(List L)
//Initialization of the List 
{
	L = (Position) malloc(sizeof(struct Node)); // casting
	if (L == NULL) { perror("Out of Space!"); exit(1);}
	L->Next = NULL;
	return(L); 
}

Position Header(List L)
//Return address of the Header  Node
{ 
	return L;
}


Position First(List L)
//Return address of the first Node
{ 
	return L->Next;
}

Position Advance(Position P)
//Return address of the next Node 
{ 
	return P->Next;
} 

ElementType  Retrieve (Position P)
//Return Node Content 
{ 
	return P->Element;
} 

/* function to test whether a linked list is empty */
/* return true if L is empty. The header is pointed by L  */
int IsEmpty (List L)
{
	return L->Next==NULL;
}

/* function to test whether current position is the last in the linked list */
/* return true if P is the last Position in list L */
/* parameter L is unused in this in this implementation */
int IsLast(Position P, List L)
{
	return P->Next==NULL;
}

/* find routine */
/* return position of X in L; NULL if not found; assume use of header  
node*/
Position Find(ElementType X, List L)
{ 
	Position P;
	P=L->Next;
	while (P != NULL && P->Element  != X ) 
		/* if ElementType is string strcmp(P->Element ,X) replaces P->Element != X*/
		P=P->Next;
	return P;
}

/* deletion routine for linked lists */ 
/* delete first occurrence of X from a list */
/* assume use of header node */
void Delete(ElementType X, List L)
{ 
	Position P, TmpCell;
	P = FindPrevious(X, L);
	if (!IsLast(P, L))		/* assumption of header use; X is found; delete it */
	{
		TmpCell=P->Next; // pointed to item to be deleted 
		P->Next=TmpCell->Next; /* bypass deleted cell */
		free(TmpCell);
	}
}

/* FindPrevious – the Find function for use with Delete */

/* if X is not found, then the address of the last item is returned – 
/* assume use of header node*/ 
/* analyze the case of empty list – only header,
why it is not wrong for the delete function */
Position FindPrevious(ElementType X, List L)
{ 
	Position P;
	P=L;
	while (P->Next != NULL && P->Next->Element  != X )
		P=P->Next; 
	/* if ElementType is string  strcmp(P->Next->Element,X) replaces P->Next->Element != X */
	return P;
} 
/* insertion routine for linked lists */
/* insert after legal position P: P is not NULL and pointed
to one of the list items.               
Header implementation assumed */
/* parameter L is unused in this implementation */
void Insert(ElementType X, List L, Position P)
{
	Position TmpCell;
	TmpCell = (Position) malloc(sizeof(struct Node)); // casting
	if (TmpCell == NULL) { perror("Out of Space!"); exit(1);}
	TmpCell->Element = X; 
	/* if ElementType is string strcpy(TmpCell->Element,X); replaces (TmpCell->Element = X); */
	TmpCell->Next = P-> Next;
	P->Next = TmpCell;
}

/* correct algorithm to delete a list */

void DeleteList(List L)
{
	Position P, Tmp; 
	P = L->Next;  /* header assumed */
	L->Next = NULL;
	while (P != NULL)
	{
		Tmp = P->Next;
		free(P);
		P = Tmp; 
	}
}

int TotalNum(List L)
{
 int count =0;
 Position P = First(L);
 while (P)
 {
	 count++;
	 P = Advance(P);
 }
 return count;
}

void InsertLimitSize(ElementType X, List L, int size)
{
	int i, total;
	Position P;

	Insert(X,L,Header(L));
	P = First(L);
    total = TotalNum(L);
	for(i=0;i>total;i++)
	{
		if(i > size)
			Delete(P->Element,L);
		P = Advance(P);
	}
}