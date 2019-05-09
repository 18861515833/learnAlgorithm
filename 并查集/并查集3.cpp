//针对并查集2进行优化 
#include<iostream>

using namespace std;

class UnionFind{
private:
	int *parent;
	int *sz;//sz[i] 以i为根的集合中元素的个数 
	int count;
public:
	UnionFind(int n){
		count=n;
		parent=new int[n];
		sz=new int[n];
		for(int i=0;i<n;i++)
		{
			parent[i]=i;
			sz[i]=1;
		}
	}	
	~UnionFind()
	{
		delete[] sz;
		delete[] parent;
	}
	int find(int p)//找到父亲节点 
	{
		while(p!=parent[p])
		{
			p=parent[p];
		}
		return p;
	}
	bool isConnected(int p,int q)
	{
		return find(p)==find(q);
	}
	void unionElements(int p,int q)
	{
		int pRoot=find(p);
		int qRoot=find(q);
		if(pRoot==qRoot)
			return ;
		
		if(sz[pRoot]<sz[qRoot])
		{
			parent[pRoot]=qRoot;	
			sz[qRoot]+=sz[pRoot];
		}
		else
		{
			parent[qRoot]=pRoot;
			sz[pRoot]+=sz[qRoot];
		}		
	}
};

int main()
{
	UnionFind test(10);
	cout<<test.isConnected(1,2)<<endl;
	test.unionElements(1,2);
	cout<<test.isConnected(1,2)<<endl;
	return 0;
}
