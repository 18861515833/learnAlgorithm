#include<iostream>
#include<time.h>
using namespace std;

//���
int gcd1(int a,int b){
	int min=a>b?b:a;
	for(int i=min;i>=1;i--){
		if(a%i==0&&b%i==0){
			return i;
		}
	}
	return -1;
} 


//շת���
int gcd2(int a,int b){
	int c;
	while(b){
		c=a%b;
		a=b;
		b=c;
	}	
	return a;
} 

//�������
int gcd3(int a,int b){
	while(a!=b){
		if(a>b)
			a=a-b;
		else
			b=b-a;
	}
	return a;
}

int main(){
	cout<<gcd1(26,39)<<endl;
	cout<<gcd2(26,39)<<endl;
	cout<<gcd3(26,39)<<endl;
	
	return 0; 
} 
