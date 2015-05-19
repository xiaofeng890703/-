#include <stdio.h>
#include <string.h>

void quick_sort(int array[],int low,int high)
{
	if(low >= high)
	{
		return;
	}
	int first = low;
	int last = high;
 	int key = array[low];
 	while(low < high)
 	{
	 	while(low < high && array[high] >= key)
	 	{
	 		--high;
	 		//high--;都一样 
	 	}
	 	array[low] = array[high];
	 	while(low < high && array[low] <= key)
	 	{
	 		++low;
	 		//low++;
	 	}
	 	array[high] = array[low];
	}//while end 
	array[low] = key;
	quick_sort(array,first,low-1);
	quick_sort(array,low+1,last);	
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
	quick_sort(array,0,n-1);
	print_array(array,n);
}
