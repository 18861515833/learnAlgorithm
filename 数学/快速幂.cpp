#include<iostream>

#define M 1000000007
using namespace std;

//快速幂  a^n
long long qpow(long long a, long long n)
{
    long long re = 1;
    while(n)
    {
        if(n & 1)//判断n的最后一位是不是1 
            re = (re * a) % M;
        n >>= 1;//舍去最后一位 
        a = (a * a) % M;//将a平方 
    }
    return re % M;
}

//拓展矩阵快递幂 

int main(){
	//效率提升，一个是o（n）级别 一个是o（logn）级别
	cout<<qpow(2,10)<<endl; 
	
	return 0;
} 
