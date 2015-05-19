#include <stdio.h>
#include <string.h>

void Msort(int src[],int tar[],int start,int mid,int end)
{
	int i = start,j = mid+1,k = start;
	int m = mid, n = end;
	while(i <= mid && j <= n)
	{
		if(src[i] < src[j])
			tar[k++] = src[i++];
		else
			tar[k++] = src[j++];
		
	}
	while(i <= m) //若第1个子文件非空，则复制剩余记录到tar中
		tar[k++] = src[i++];
	while(j <= n)  //若第2个子文件非空，则复制剩余记录到tar中  
		tar[k++] = src[j++];
	for(i = start;i <= end;i++)
		src[i]= tar[i];
} //两个有序数组的合并 

void merge_sort(int array[],int temp[],int start,int end)
{
	int mid;
	if(start < end)
	{
		mid = (start + end)/2;
		merge_sort(array,temp,start,mid);//左边有序 
		merge_sort(array,temp,mid+1,end);//右边有序 
		Msort(array,temp,start,mid,end);//再将两个数组合并 
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
	int array[8] = {49,38,65,97,76,13,27,49};
	int temp[8];
	int n = sizeof(array)/sizeof(int);
	merge_sort(array,temp,0,n-1);
	print_array(array,n);
}
