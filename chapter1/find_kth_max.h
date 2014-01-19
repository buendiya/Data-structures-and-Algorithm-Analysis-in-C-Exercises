#ifndef _FIND_H
#define _FIND_H

//bubble sort
int find_kth_largest_num(int *a, int num, int k)
{
	int exchange = 0;
	for (int i = 0; i<num-1; i++)
	{
		exchange = 0;
		for (int j = 0; j<num-1-i; j++)
		{
			if (a[j]>a[j+1])
			{
				int tmp = a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
				exchange = 1;
			}
		}
		if (0 == exchange)
		{
			break;
		}
	}
	return a[k-1];
}


int find_kth_largest_num_2(int *a, int num, int k)
{
	//sort the first k elements
	int exchange = 0;
	for (int i = 0; i<k-1; i++)
	{
		exchange = 0;
		for (int j = 0; j<k-1-i; j++)
		{
			if (a[j]>a[j+1])
			{
				int tmp = a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
				exchange = 1;
			}
		}
		if (0 == exchange)
		{
			break;
		}
	}

	//As a new element arrives, it is ignored if it is smaller than the kth element in the array.
	//Otherwise, it is placed in its correct spot in the array, bumping one element out of the array.
	for (int i = 0; i<num-k; i++)
	{
		//Get the next (num-k) number in order; Then put the number in the (k+1)th position
		a[k] = a[k+i];
		for (int j = k; j>0; j--)  // sort the (k+1) num
		{
			if (a[j]>a[j-1])
			{
				int tmp = a[j];
				a[j] = a[j-1];
				a[j-1] = tmp;
			}
			else
			{
				break;
			}
		}
	}

	return a[k-1];
}
#endif
