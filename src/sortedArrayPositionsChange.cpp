/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	if (Arr == NULL || len < 0)
		return NULL;
	int index, swap1 = 0, swap2 = (len - 1), temp;
	if (Arr[0]>Arr[1] && Arr[len - 1] < Arr[len - 2])
	{
		temp = Arr[0];
		Arr[0] = Arr[len - 1];
		Arr[len - 1] = temp;
		return Arr;
	}
		
	for (index = 1; index < len-1; index++)
	{
		if (Arr[index]>Arr[index + 1] && Arr[index] > Arr[index - 1])
			swap1 = index;
		else if (Arr[index] < Arr[index + 1] && Arr[index] < Arr[index - 1])
			swap2 = index;
	}			
	temp = Arr[swap1];
	Arr[swap1] = Arr[swap2];
	Arr[swap2] = temp;
	return NULL;
}