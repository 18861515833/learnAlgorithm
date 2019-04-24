#include "sortTest.h"

template<typename T>
int _partition(T *arr,int l,int r)
{
	//优化点 随机选择标定点，防止数据本身有序而照成的快排退化 
	swap(arr[l],arr[rand()%(r-l+1)+l]); 
	T mid=arr[l];
	int i,j;
	i=j=l+1;
	for(j=l+1;j<=r;j++)
	{
		if(arr[j]<=mid)
		{
			swap(arr[i],arr[j]);
			i++;
		}
	}
	swap(arr[i-1],arr[l]);
	//swap(arr[i-1],mid); //这里如果使用swap(arr[i-1],mid); 为什么速度会变慢（排序结果也是错误的  --改变了数组），重复元素变多造成了速度变慢 
	return i-1;
}
template<typename T>
int _partition2(T arr,int l,int r)
{
	
} 

template<typename T>
void _quickSort(T *arr,int l,int r)
{
	if(l>=r)
		return ;
	int m=_partition(arr,l,r);
	_quickSort(arr,l,m-1);
	_quickSort(arr,m+1,r);
}


template<typename T>
void quickSort(T *arr,int n)
{
	_quickSort(arr,0,n-1);
}

int main()
{
	int n=100000;
	int *arr=generateRandomArray<int>(n,1,1000);
	//printArray(arr,n);
	testSort<int>("quickSort",quickSort,arr,n);
	//printArray(arr,n); 
	//回收空间
	delete[] arr; 
	return 0;
}
