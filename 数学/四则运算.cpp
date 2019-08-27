#include<iostream>
#include<time.h>
using namespace std;

int main(){
	int n=10000000;
	int a=23;
	int b=31207; 
	
	clock_t startTime=clock();
	for(int i=0;i<n;i++){
		a+b;
		b+a;
	}
	clock_t endTime=clock();
	cout<<"+ "<<":"<<double(endTime-startTime)/CLOCKS_PER_SEC<<"s"<<endl;
	
	startTime=clock();
	for(int i=0;i<n;i++){
		a-b;
		b-a;
	}
	endTime=clock();
	cout<<"- "<<":"<<double(endTime-startTime)/CLOCKS_PER_SEC<<"s"<<endl;
	
	startTime=clock();
	for(int i=0;i<n;i++){
		a*b;
		b*a;
	}
	endTime=clock();
	cout<<"* "<<":"<<double(endTime-startTime)/CLOCKS_PER_SEC<<"s"<<endl;
	
	startTime=clock();
	for(int i=0;i<n;i++){
		a/b;
		b/a;
	}
	endTime=clock();
	cout<<"/ "<<":"<<double(endTime-startTime)/CLOCKS_PER_SEC<<"s"<<endl;
	
	startTime=clock();
	for(int i=0;i<n;i++){
		a%b;
		b%a;
	}
	endTime=clock();
	cout<<"% "<<":"<<double(endTime-startTime)/CLOCKS_PER_SEC<<"s"<<endl;
	
	return 0;
} 

//���Խ��  �Ӽ���Ч�ʸߣ��˳���Ч����΢�͵�  %Ӧ�ø��˳�����һ�������  ����ǰһֱ����������� 
/*
+ :0.017s
- :0.015s
* :0.021s
/ :0.02s
% :0.02s
*/ 
