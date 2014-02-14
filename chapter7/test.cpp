/*
 ============================================================================
 Name        : test.c
 Author      : Shuaizhen Jing
 Version     :
 Copyright   : Your copyright notice
 Description : list in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "ShellSort.h"

using namespace std;

int main()
{
	int a[] = {81, 94, 11, 96, 12, 35, 17, 95, 28, 58, 41, 75, 15};

	Shellsort(a, sizeof(a)/sizeof(int));
	for (unsigned int i = 0; i < sizeof(a)/sizeof(int); i++)
		cout << a[i] << " ";

	return 0;
}
