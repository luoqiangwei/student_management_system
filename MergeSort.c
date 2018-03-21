#include <stdlib.h>

#include "InsertSort.h"
#include "MergeSort.h"

void Merge(DataType a[], int n, DataType swap[], int k)
{
	int m = 0;
	int u1, u2;
	int i, j;
	int l2;
	int l1 = 0;

	while (l1 + k < n - 1)
	{
		l2 = l1 + k;
		u1 = l2 - 1;
		u2 = (l2 + k - 1 <= n - 1) ? l2 + k - 1 : n - 1;

		for (i = l1, j = l2; i <= u1 && j <= u2; m++)
		{
			if (a[i]._num <= a[j]._num)
			{
				swap[m] = a[i];
				i++;
			}
			else
			{
				swap[m] = a[j];
				j++;
			}
		}

		while (i < u1)
		{
			swap[m] = a[i];
			m++;
			i++;
		}
		while (j <= u2)
		{
			swap[m] = a[j];
			m++;
			j++;
		}
		l1 = u2 + 1;
	}
	for (i = l1; i < n; i++, m++) swap[m] = a[i];
}
void MergeSort(DataType a[], int n)
{
	int i, k = 1;
	DataType *swap;

	swap = (DataType*)malloc(sizeof(DataType)*n);
	/*for (int q = 0; q < n; q++)
		swap[q]._name = (char*)malloc(sizeof(char) * 15);*/ //²»ÐèÒª
	while (k < n)
	{
		Merge(a, n, swap, k);
		for (i = 0; i < n; i++)
			a[i] = swap[i];
		k = 2 * k;
	}
	/*for (int q = 0; q < n; q++)
		free(swap[q]._name);*/
	InsertSort(a, n);
	free(swap);
}