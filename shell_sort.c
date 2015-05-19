#include <stdio.h>
#include <string.h>

void shell_sort(int array[],int n)
{
	int i,j,gap;
	int temp;
	if(sizeof(array)/sizeof(int) == 0)
	{
		printf("error! array can't 0\n");
	}
	for(i = 0;i < n;i++)
	{
		if(sizeof(array[i]) != 4)
			printf("error! sort must type of int\n");
	}
	for(gap = n/2;gap > 0;gap/=2)
	{
		for(i = gap;i < n;i++)
		{
			temp = array[i];
			for(j = i - gap;j >= 0 && temp < array[j];j-=gap)
			{
				array[j+gap] = array[j];//交换两个数 
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
	int array[] = {49,38,65,97,13,27,49,55,4};
	int n;
	n = sizeof(array)/sizeof(int);
	shell_sort(array,n);
	print_array(array,n);
}
