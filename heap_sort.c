#include <stdio.h>
void heap_adjust(int array[],int start,int n) 
{
	int Min = start;
	int lchild = 2*start;
	int rchild = 2*start+1;
	int temp;
	if(start <= n/2)//如果i是叶节点就不用进行调整 
	{			
		if(lchild < n && array[lchild] < array[Min])
		{
			Min = lchild;
		}
		if(rchild < n && array[rchild] < array[Min])
		{
			Min = rchild;
		}
		if(Min != start)
		{
			temp = array[start];
			array[start] = array[Min];
			array[Min] = temp;
			heap_adjust(array,Min,n); //避免调整之后以max为父节点的子树不是堆 
		}
	}
	//array[start] = temp;	
}
void heap_sort(int array[],int n)
{
	int i,start;
	for(start = (n-1)/2;start >= 0;start--)
	{
		heap_adjust(array,start,n);
	} 
	for(i = n-1;i > 0;i--)
	{
		array[i]=array[0]^array[i];
        array[0]=array[0]^array[i];
        array[i]=array[0]^array[i];
        //不断缩小调整heap的范围，每一次调整完毕保证第一个元素是当前序列的最大值
        heap_adjust(array,0,i);
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
	heap_sort(array,n);
	print_array(array,n);
}
