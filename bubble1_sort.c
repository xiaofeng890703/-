#include <stdio.h>
void bubble_sort(int array[],int n)
{
	int i,j,temp;
	if(sizeof(array)/sizeof(int) == 0)
	{
		printf("error! array can't 0\n");
	}
	for(i = 0;i < n-1;i++)
	{
		if(sizeof(array[i]) != 4)
			printf("error! sort must type of int\n");
	}
	for(i = 0;i < n;i++)
	{
		for(j = i+1;j < n;j++)//????ó???С??????? 
		{
			if(array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}

void print_array(int array[],int n)
{
	int i; 
	for(i = 0;i < n;i++)
	{
		printf("%d ",array[i]);
	}
}

int main()
{
	int array[] = {49,38,65,97,76,13,27,49};
	int n = sizeof(array)/sizeof(int);
	bubble_sort(array,n);
	print_array(array,n);

} 
