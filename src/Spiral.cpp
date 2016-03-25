/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>
int* spiral1(int, int, int, int,int**);
int *spiral(int rows, int columns, int **input_array)
{
	int *arr,*res;
	int x1 = 0, y1 = 0, x2 = rows - 1, y2 = columns - 1;
	arr = (int*)malloc((rows*columns)*sizeof(int));
	res=spiral1(x1, x2, y1, y2,input_array);
	return res;
}
int* spiral1(int x1, int x2, int y1, int y2, int **input_array)
{
	int i = 0, *res;
	res = (int*)malloc(100 * sizeof(int));
	if (x2 < x1 || y2 < y1)
		return res;
	for (i = 0; i <= x2 - x1; i++)
	{
		*res = input_array[y1][x1 + i];
		res++;
	}
	for (i = 1; i <= y2 - y1; i++)
	{
		*res = input_array[y1 + i][x2];
		res++;
	}
	for (i = 1; i <= x2 - x1; i++)
	{
		*res = input_array[y2][x2 - i];
		res++;
	}
	for (i = 1; i <= y2 - y1; i++)
	{
		*res = input_array[y2 - i][x1];
		res++;
	}
	spiral1(x1 + 1, x2 - 1, y1 + 1, y2 - 1,input_array);
}