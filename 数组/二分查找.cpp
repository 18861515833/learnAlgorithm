#include<iostream>
using namespace std;

//递归实现 
template<typename T>
int BinarySearch(int a,int b,T tar,T *data)
{
	//cout<<a<<""<<b<<endl;
	if(a>b)
		return -1;
	int t=a+(b-a)/2;//写成 (a+b)/2会有溢出的风险 
	if(tar==data[t])
	{
		return t;
	}
	else if(tar>data[t])
	{
		return BinarySearch(t+1,b,tar,data);
	}
	else if(tar<data[t])
	{
		return BinarySearch(a,t-1,tar,data);
	}
	return -1;		
} 


template<typename T>
int LowwerBound(int a,int b,T tar,T *data)
{
	if(a>b)
		return -1;
	int t=a+(b-a)/2;//写成 (a+b)/2会有溢出的风险 
	if(tar==data[t])
	{
		while(t>0&&data[--t]==tar)
		{
			
		}
		if(data[t]==tar)
			return t;
		else
			return t+1;
	}
	else if(tar>data[t])
	{
		return BinarySearch(t+1,b,tar,data);
	}
	else if(tar<data[t])
	{
		return BinarySearch(a,t-1,tar,data);
	}
	return -1;		
} 

int main()
{
	int data[5]={2,2,2,2,5};
	
	cout<<BinarySearch<int>(0,5,2,data)<<endl;
	cout<<LowwerBound<int>(0,5,2,data)<<endl;
	return 0;
} 
