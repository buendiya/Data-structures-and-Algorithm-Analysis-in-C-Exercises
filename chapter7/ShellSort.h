#ifndef SHELLSORT_H
#define SHELLSORT_H

#include <stdio.h>

typedef int ElementType;

void Shellsort(ElementType A[], int N)
{
	int i, j, Increment;
	ElementType Tmp;

	for (Increment = N/2; Increment > 0; Increment /=2)
		for (i = Increment; i < N; i++)
		{
			Tmp = A[i];
			for (j = i; j >= Increment; j -= Increment)
			{
				printf("\n j = %d, Increment = %d ", j, Increment);
				if (Tmp < A[j - Increment])
					A[j] = A[j - Increment];
				else
					break;
			}
			A[j] = Tmp;

			printf("\nTmp: %d ", Tmp);
			for (int i = 0; i < N; i++)
				printf("%d ", A[i]);
		}
}

#endif
