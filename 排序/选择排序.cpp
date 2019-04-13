#include "sortTest.h"

void selectionSort(int *arr,int n)
{
	for(int i=0;i<n;i++)
	{
		int min=i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]<arr[min])
				min=j;
		}
		swap(arr[i],arr[min]);
	}
} 

int main()
{
	int n=10000;//数据大小 
	int *arr=generateRandomArray<int>(n,1,n);
	testSort<int>("selectionSort",selectionSort,arr,n);
	//回收空间
	delete[] arr; 
	return 0;
}
