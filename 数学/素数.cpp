#include<iostream>
#include<cmath>
#include<time.h>
#include<vector>
#include<memory.h>

#define OUT(b)  ((b)==1?" is prime":" not prime")
using namespace std;

bool isPrime1(int n){
	if(n < 2){
		return false;
	} 
	for(int i=2;i<n;i++){
		if(n%i==0){
			return false;
		}	
	}
	return true;
}


//因数成对出现 优化 
bool isPrime2(int n){
	if(n < 2){
		return false;
	} 
	double sqrtn = sqrt(n*1.0);
	for(int i=2;i<=sqrtn;i++){
		if(n%i==0){
			return false;
		}	
	}
	return true;
} 


//素数跟6的关系 优化 
bool isPrime3(int n){
	if(n < 2){
		return false;
	} 
	//两个较小的数另外做处理 
    if (n == 2 || n == 3)
        return true;
    //不在6的倍数的两侧一定不是质数 
    if (n % 6 != 1 && n % 6 != 5) {
        return false;
    }

    double sqrtn = sqrt(n*1.0);
    //在6的倍数的两侧不一定是质数 
    for (int i = 5; i <= sqrtn; i += 6)
        if (n %i == 0 || n % (i + 2) == 0)
    		return false;
	return true;
}


int ans[100000] ;

bool checkAns(vector<int> &res){
	for(int i=0;i<res.size();i++){
		if(res[i]!=ans[i]){
			return false;
		}
	}
	return true;
}

int main(){
	//十万数据规模 
	int n=100000;
	memset(ans,0,sizeof(ans));
	for(int i=2;i<n;i++){
		ans[i]=isPrime1(i);
	}
	
	//test isPrime1
	vector<int> res1(n,0);
	clock_t startTime=clock();
	for(int i=2;i<n;i++){
		res1[i]=isPrime1(i);
	}
	clock_t endTime=clock();
	if(checkAns(res1))
		cout<<"isPrime1"<<":"<<double(endTime-startTime)/CLOCKS_PER_SEC<<"s"<<endl;
	else
		cout<<"isPrime1 error"<<endl;
	
	
	//test isPrime2
	vector<int> res2(n,0);
	startTime=clock();
	for(int i=2;i<n;i++){
		res2[i]=isPrime2(i);
	}
	endTime=clock();
	if(checkAns(res2))
		cout<<"isPrime2"<<":"<<double(endTime-startTime)/CLOCKS_PER_SEC<<"s"<<endl;
	else
		cout<<"isPrime2 error"<<endl;
	
	
	//test isPrime3
	vector<int> res3(n,0);
	startTime=clock();
	for(int i=2;i<n;i++){
		res3[i]=isPrime3(i);
	}
	endTime=clock();
	if(checkAns(res3))
		cout<<"isPrime3"<<":"<<double(endTime-startTime)/CLOCKS_PER_SEC<<"s"<<endl;
	else
		cout<<"isPrime3"<<endl;
		
	return 0;
}

//测试结果  方法3效果最好   方法1最废，不能用来实战，到时候写不出来方法3可以用方法2 
/*
isPrime1:0.853s
isPrime2:0.007s
isPrime3:0.003s
*/ 
