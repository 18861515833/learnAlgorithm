#include "sortTest.h"

void bubbleSort(int *arr,int n)
{
	int i,j;
	//优化  避免已经排序的数组重复进行遍历 
	bool isSort=true; 
	for(i=n-1;i>=0;i--)
	{
		isSort=true;
		for(int j=0;j<i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(arr[j],arr[j+1]);
				isSort=false;
			}
		}
		if(isSort)
			break;
	}
} 

int main()
{
	int n=10000;//数据大小 
	int *arr=generateRandomArray<int>(n,1,n);
	testSort<int>("bubbleSort",bubbleSort,arr,n);
	//回收空间
	delete[] arr; 
	return 0;
}
