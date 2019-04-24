//完全二叉树
 
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

template<typename T>
class MaxHeap{
	public:
		MaxHeap(int capacity)
		{
			data=new T[capacity+1];
			count=0;
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

int main()
{
	//MaxHeap<int> mh(100);
	MaxHeap<int> mh=MaxHeap<int>(100);
	mh.push(100);
	mh.push(102);
	mh.push(99);
	mh.push(105);
	mh.push(9);
	cout<<mh.front()<<endl;
	cout<<mh.front()<<endl;
	cout<<mh.front()<<endl;
	return 0;
}

