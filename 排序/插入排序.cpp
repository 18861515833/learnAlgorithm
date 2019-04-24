#include "sortTest.h"

template<typename T>
void insertSort(T *arr,int n)
{
	int i,j;
	for(i=1;i<n;i++)
	{
		T tem=arr[i];
		for(j=i;j>0;j--)
		{
			if(tem<arr[j-1])
			{
				arr[j]=arr[j-1];
			}
			else
				break;
		}
		arr[j]=tem;
	}
} 

int main()
{
	int n=100000;//���ݴ�С 
	int *arr=generateRandomArray<int>(n,1,n);
	testSort<int>("insertSort",insertSort,arr,n);
	//���տռ�
	delete[] arr; 
	return 0;
}
