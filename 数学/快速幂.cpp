#include<iostream>

#define M 1000000007
using namespace std;

//������  a^n
long long qpow(long long a, long long n)
{
    long long re = 1;
    while(n)
    {
        if(n & 1)//�ж�n�����һλ�ǲ���1 
            re = (re * a) % M;
        n >>= 1;//��ȥ���һλ 
        a = (a * a) % M;//��aƽ�� 
    }
    return re % M;
}

//��չ�������� 

int main(){
	//Ч��������һ����o��n������ һ����o��logn������
	cout<<qpow(2,10)<<endl; 
	
	return 0;
} 
