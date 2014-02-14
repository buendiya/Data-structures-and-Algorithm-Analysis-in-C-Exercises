/*
 ============================================================================
 Name        : list.c
 Author      : Shuaizhen Jing
 Version     :
 Copyright   : Your copyright notice
 Description : list in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* Return true if L is empty */
/* Why the return result type is integer, not boolean ? */
int IsEmpty(List L)
{
	return L->Next == NULL;
}

/* Return true if P is the last position in List L */
/* Parameter L is not used, why not delete it ? */
int IsLast(Position P, List L)
{
	return P->Next == NULL;
}

/* return position of x in L, NULL if not found */
Position Find(ElementType X, List L)
{
	Position P;
	P = L->Next;
	while (NULL != P && X != P->Element)
		P = P->Next;
	return P;
}

/* Delete first occurrence of X from List */
/* Assume use of a header node */
void Delete(ElementType X, List L)
{
	Position P, TmpCell;

	P = FindPrevious(X, L);
	if (!IsLast(P, L))
	{
		TmpCell = P->Next;
		P->Next = P->Next->Next; /* Bypass deleted cell */
		free(TmpCell);
	}
}

/* If X is not found, then Next field of returned Position is NULL */
/* Assume use of a header node */
Position FindPrevious(ElementType X, List L)
{
	Position P;
	P = L;
	while (NULL != P->Next && X != P->Next->Element)
		P = P->Next;
	return P;
}


/* Insert (after legal position P) */
/* Assume use of a header node */
/* Parameter L is unused in this implementation */
void Insert(ElementType X, List L, Position P)
{
	Position TmpCell;

	TmpCell = malloc(sizeof(struct Node));
	if (NULL == TmpCell)
		perror("Out of space");

	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
}
