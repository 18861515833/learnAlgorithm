//��̬����vector��� 
#include<iostream>
#include<string.h>

using namespace std;

template<class T>
class myVector{
	private:
		int length;
		int capacity;
		T* data;
		void reSize(int newCapacity)
		{
			//cout<<"12"<<endl;
			T *newData=new T[newCapacity];
			
			for(int i=0;i<length;i++)
				newData[i]=data[i];
			
			//memcpy(newData,data,sizeof(T)*(length));//ֱ��ʹ��sizeof(data);����� 
			delete[] data;
			data=newData;
			capacity=newCapacity;
		}
	public:
		myVector(int n)
		{
			data=new T[n];
			capacity=n;
			length=0;	
		};
		void push_back(T d)
		{
			if(length>=capacity)
				reSize(capacity*2);
			data[length++]=d;
		}; 
		T pop_back()
		{
			length--;
			T res=data[length];
			//length--;
			if(length<capacity/4)//���������Եĳ��� ����3�δ�һ�� 
				reSize(capacity/2);
			
			return res;
		};
		T get(int index)
		{
			return data[index];
		};
		int size()
		{
			return length;
		}; 
};

int main()
{
	myVector<double> a(2);
	a.push_back(1.1);
	a.push_back(2.2);
	a.push_back(3.3);
	//a.pop();
	
	int len=a.size();
	for(int i=0;i<len;i++)
		cout<<a.pop_back()<<endl;
		//cout<<a.get(i)<<endl;
	return 0;
} 
