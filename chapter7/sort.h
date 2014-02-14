#ifndef SHELLSORT_H
#define SHELLSORT_H

#include <stdio.h>

typedef int ElementType;

void InsertSort(ElementType A[], int N)
{
	int i, j;
	ElementType tmp;

	for (i = 1; i < N; i++)
	{
		tmp = A[i];
		for (j = i; j > 0 && A[j-1] > tmp; j--)
			A[j] = A[j-1];
		A[j] = tmp;
	}
}

void Shellsort(ElementType A[], int N)
{
	int i, j, Increment;
	ElementType tmp;

	for (Increment = N/2; Increment > 0; Increment /=2)
	{
		for (i = Increment; i < N; i += Increment)
		{
			tmp = A[i];
			for (j = i; j > 0 && A[j-Increment] > tmp; j -= Increment)
				A[j] = A[j - Increment];
			A[j] = tmp;
		}

	}
}

#endif
