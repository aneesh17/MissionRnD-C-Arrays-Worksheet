/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

INPUTS: Integer array and length of the array.

OUTPUT: Update input array by removing duplicate values.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>
#include<malloc.h>
void Merge(int*, int, int);
void sort(int*, int, int, int);
void * removeArrayDuplicates(int *Arr, int len)
{
	if (Arr == NULL || len < 0)
		return NULL;	
	Merge(Arr, 0, (len-1));
	return Arr;
}

void Merge(int *Arr, int lo, int hi)
{
	int mid;
	if (lo < hi)
	{
		mid = (lo + hi) / 2;
		Merge(Arr, lo, mid);
		Merge(Arr, (mid + 1), hi);
		sort(Arr, lo, mid, hi);
	}
}

void sort(int *Arr, int lo, int mid, int hi)
{
	int size1, size2;
	int i = 0, j = 0, k = 0;
	size1 = mid - lo + 1;
	size2 = hi - mid;
	int *arr1 = (int*)malloc(size1*sizeof(int));
	int *arr2 = (int*)malloc(size2*sizeof(int));
	for (i = 0; i < size1; i++)
	{
		arr1[i] = Arr[lo + i];
	}
	arr1[i] = 99999;
	for (i = 0; i < size2; i++)
	{
		arr2[i] = Arr[mid + 1 + i];
	}
	arr2[i] = 99999;
	i = 0;
	j = 0;
	for (k = lo; k <= hi; k++)
	{
		if (arr1[i] < arr2[j])
			Arr[k] = arr1[i++];
		else if (arr1[i] > arr2[j])
			Arr[k] = arr2[j++];
		else
		{
			Arr[k] = arr1[i++];		
			j++;
		}
	}
	
}