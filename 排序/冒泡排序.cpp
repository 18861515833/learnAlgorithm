#include "sortTest.h"

void bubbleSort(int *arr,int n)
{
	int i,j;
	//�Ż�  �����Ѿ�����������ظ����б��� 
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
	int n=10000;//���ݴ�С 
	int *arr=generateRandomArray<int>(n,1,n);
	testSort<int>("bubbleSort",bubbleSort,arr,n);
	//���տռ�
	delete[] arr; 
	return 0;
}
