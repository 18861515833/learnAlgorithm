//�ϲ�������������--�鲢����������

#include "sortTest.h"

template<typename T>
void merge(T arr[],int l,int r)//��arr[l...r]�ڵ�Ԫ�ؽ��кϲ� 
{
	int m=l+(r-l)/2;
	int i=l,j=m+1;
	T* aux=new T[r-l+1];
	for(int k=l;k<=r;k++)
		aux[k-l]=arr[k];
	for(int k=l;k<=r;k++)
	{
		if(i>m)
		{
			arr[k]=aux[j-l];
			j++;
		}
		else if(j>r)
		{
			arr[k]=aux[i-l];
			i++;
		}
		else if(aux[i-l]<aux[j-l])//���г���� 
		{
			arr[k]=aux[i-l];
			i++;
		}
		else
		{
			arr[k]=aux[j-l];
			j++;
		}
	}
	delete[] aux;
}

template<typename T>
void _mergeSort(T arr[],int l,int r)
{
	if(l>=r)
		return ;
	int t=l+(r-l)/2;
	//�Ż���2 ���ݹ�ģС��ʱ��ʹ�ò�������ȽϿ� 
	_mergeSort(arr,l,t);
	_mergeSort(arr,t+1,r);
	if(arr[t]>arr[t+1])//�Ż���1 
		merge(arr,l,r);
}

template<typename T>
void mergeSort(T arr[],int n)
{
	_mergeSort(arr,0,n-1);	
}  
int main()
{
	int n=100000;
	int *arr=generateRandomArray<int>(n,1,n);
	//printArray(arr,n);
	testSort<int>("mergeSort",mergeSort,arr,n);
	//printArray(arr,n);
	//���տռ�
	delete[] arr; 
	return 0;
}

 
