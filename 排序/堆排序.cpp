#include "sortTest.h"

template<typename T>
class MaxHeap{
	public:
		MaxHeap(int capacity)
		{
			data=new T[capacity+1];
			count=0;
		}
		MaxHeap(T arr[],int n)
		{
			data=new T[n+1];
			for(int i=0;i<n;i++)
				data[i+1]=arr[i];
			count=n;
			for(int i=n/2;i>0;i--)
			 ShiftDown(i);
		}
		~MaxHeap()
		{
			delete[] data;
		}
		int size()
		{
			return count;
		}
		bool isEmpty()
		{
			return count==0;
		}
		void push(T val)
		{
			data[count+1]=val;
			ShiftUp(count+1);
			count++;
		}
		T front()
		{
			T res=data[1];
			swap(data[1],data[count]);
			count--;
			ShiftDown(1);
			
			return res;
		}
	private:
		T* data;
		int count;
		void ShiftUp(int p)
		{
			if(p>1&&data[p/2]<data[p]) 
			{
				swap(data[p],data[p/2]);
				ShiftUp(p/2);//递归实现 
			}
		}
		void ShiftDown(int p)
		{
			if(p*2<=count)
			{
				int j=p*2;
				if(j+1<=count&&data[j+1]>data[j])
					j+=1;
				if(data[p]<data[j])
				{
					swap(data[p],data[j]);
					ShiftDown(j);
				}
			}	
		}
};

template<typename T>
void _shiftDown(T arr,int n,int p)
{
	if(p*2+1<n)
	{
		int j=p*2+1;
		if(j+1<n&&arr[j+1]>arr[j])
			j+=1;
		if(arr[p]<arr[j])
		{
			swap(arr[p],arr[j]);
			_shiftDown(arr,n,j);
		}
	}	
}

template<typename T>
void heapSort1 (T arr[], int n)
{
	MaxHeap<T> mh(n);
	for(int i=0;i<n;i++)
		mh.push(arr[i]);
	for(int i=n-1;i>=0;i--)
		arr[i]=mh.front();
}

template<typename T>
void heapSort2 (T arr[], int n)
{
	MaxHeap<T> mh(arr,n);
	for(int i=n-1;i>=0;i--)
		arr[i]=mh.front();
}


template<typename T>
void heapSort3 (T arr[], int n)
{
	for(int i=(n-1)/2;i>=0;i--)
		_shiftDown(arr,n,i);
	for(int i=n-1;i>0;i--)
	{
		swap(arr[0],arr[i]);
		_shiftDown(arr,i,0);
	}	
}



int main()
{
	int n=1000000;
	int *arr=generateRandomArray<int>(n,1,n);
	//printArray(arr,n);
	testSort<int>("heapSort1",heapSort1,arr,n);
	testSort<int>("heapSort2",heapSort2,arr,n);
	testSort<int>("heapSort3",heapSort3,arr,n);
	//printArray(arr,n);
	//回收空间
	delete[] arr; 
	return 0;
}


