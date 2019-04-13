#include "sortTest.h"


template<typename T>
void quickSort(T *arr,int n)
{
	
}

int main()
{
	int n=100000;
	int *arr=generateRandomArray<int>(n,1,n);
	testSort<int>("quickSort",quickSort,arr,n);
	//ªÿ ’ø’º‰
	delete[] arr; 
	return 0;
}
