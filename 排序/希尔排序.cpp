#include "sortTest.h"
void shellSort(int *arr,int n)
{
	int i,j,tem;
	for(int d=n/2;d>=1;d/=2)
	{
		for(i=d;i<n;i+=d)
		{
			tem=arr[i];
			for(j=i;j>0;j-=d)
			{
				if(tem<arr[j-d])
				{
					arr[j]=arr[j-d];
				}
				else
					break;
			}
			arr[j]=tem;
		}	
	}
} 
int main()
{
	int n=10000;//���ݴ�С 
	int *arr=generateRandomArray<int>(n,1,n);
	testSort<int>("shellSort",shellSort,arr,n);
	//���տռ�
	delete[] arr; 
	return 0;
}
