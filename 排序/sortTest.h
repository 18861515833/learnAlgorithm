#include<bits/stdc++.h>
using namespace std;

//生成数组 
template<typename T>
T* generateRandomArray(int n,T rangeL,T rangeR)
{
	T *arr=new T[n];
	srand(time(NULL));
	for(int i=0;i<n;i++)
		arr[i]=(rand()%(rangeR-rangeL+1)+rangeL);
	return arr;
} 

template<typename T>
void printArray(T *arr,int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

template<typename T>
int isSorted(T *arr,int n)
{
	for(int i=0;i<n-1;i++)
	{
		if(arr[i]>arr[i+1])
			return 0;
	}		
	return 1;
}

template<typename T>
void testSort(string sortName,void(*sort)(T[],int),T *arr,int n)
{
	clock_t startTime=clock();
	sort(arr,n);
	clock_t endTime=clock();
	if(isSorted(arr,n))
	{
		cout<<"排序成功"<<endl;
		cout<<sortName<<":"<<double(endTime-startTime)/CLOCKS_PER_SEC<<"s"<<endl;
	}
	else
		cout<<"排序失败"<<endl; 
	
	
}
