#include<iostream>
#include<thread>
#include<future>

using namespace std;


int sum(int *arr,int s,int e){
	int sum=0;
	for (int i = s; i < e; i++)
	{
		for (int j = s; j < e; j++)
			arr[i]*= arr[j];
		sum += arr[i];
	}
		
	return sum;
}	




int asyncSum(int *arr,int s,int e){
	//cout << "×ÓÏß³ÌID£º" << this_thread::get_id() << endl;
	if(e-s<1000)
		return sum(arr,s,e);
	//cout << "aaa" << endl;
	int m=s+(e-s)/2;
	auto res1=async(launch::async,asyncSum,arr,m,e);
	int res2=asyncSum(arr,s,m);
	return res2+res1.get();
}


int main(){
	int *arr=new int[10000000];
	for(int i=0;i<10000000;i++)
		arr[i]=1;
	clock_t startTime = clock();


	cout<<asyncSum(arr,0, 10000)<<endl;
	//cout << sum(arr, 0, 10000) << endl;
	clock_t endTime = clock();
	cout << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	return 0;
}
