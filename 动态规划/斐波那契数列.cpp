#include<bits/stdc++.h>
using namespace std；

//通过记忆化搜索来优化斐波拉契数列的求解 
long long fib[1000];
long long dfs(int x)
{
	if(fib[x]!=0)
	{
		return fib[x];	
	}
	if(x==1||x==2)
		return fib[x]=1;
	return fib[x]=dfs(x-1)+dfs(x-2);
}

int main()
{
	int n;
	cin>>n; 
	cout<<dfs(n)<<endl;
	return 0;
}
