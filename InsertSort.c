#include "InsertSort.h"

void InsertSort(DataType a[], int n)
{
	int i, j;
	DataType temp;
	for (i = 0; i < n - 1; i++)
	{
		temp = a[i + 1];
		j = i;
		while (j > -1 && temp._num < a[j]._num)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}
}