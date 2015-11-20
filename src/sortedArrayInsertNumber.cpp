/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>
int * insertAtPosition(int*, int, int, int);
int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	if (Arr == NULL || len < 0)		
		return NULL;
	int index;
	int hi = len - 1, lo = 0;
	if (num < Arr[0])
	{
		Arr = insertAtPosition(Arr, len+1, num, 0);
		return Arr;
	}
	if (num > Arr[len - 1])
	{
		Arr = insertAtPosition(Arr, len + 1, num, len);
		return Arr;
	}
	while (1)
	{
		index = (hi + lo) / 2;
		if (Arr[index] > num)		
			hi = index;		
		else if (Arr[index] < num)
			lo = index;
		else
		{
			Arr = insertAtPosition(Arr, len + 1, num, index);	
			break;
		}
		
		if (lo == (hi - 1))
		{
			Arr = insertAtPosition(Arr, (len+1), num, hi);			
			break;
		}
	}//while	
	return Arr;
}

int * insertAtPosition(int *Arr, int len, int num, int index)
{
	int indexForArr;
	Arr = (int *)realloc(Arr, len*sizeof(int));
	for (indexForArr = len - 2; indexForArr >= index; indexForArr--)
	{
		Arr[indexForArr + 1] = Arr[indexForArr];
	}
	Arr[indexForArr + 1] = num;
	return Arr;
}