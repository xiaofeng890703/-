#include <stdio.h>
#include <string.h>

void straight_insert_sort(int array[],int n)
{
	int i,j,temp;
	if(sizeof(array)/sizeof(int) == 0)
	{
		printf("error! array can't 0\n");
	}
	for(i = 0;i < n;i++)
	{
		if(sizeof(array[i]) != 4)
			printf("error! sort must type of int\n");
	}
	for(i = 1;i <= n-1; i++)
	{
		temp = array[i];
		for(j = i - 1;j >= 0 && temp < array[j];j--)
			{
				array[j+1] = array[j];//交换两个数  
				array[j] = temp;
			}		
	}
}
void print_array(int array[],int n)
{
	int i;
	for(i = 0;i <= n-1;i++)
	{
		printf("%d ",array[i]);
	}
}
int main()
{
	int n;
	int array[] = {49,38,65,97,76,13,27,49};
	n = sizeof(array)/sizeof(int); 
	straight_insert_sort(array,n);
	print_array(array,n);
} 
