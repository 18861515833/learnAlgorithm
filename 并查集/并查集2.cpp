#include<iostream>

using namespace std;

class UnionFind{
private:
	int *parent;
	int count;
public:
	UnionFind(int n){
		count=n;
		parent=new int(n);
		for(int i=0;i<n;i++)
			parent[i]=i;
	}	
	~UnionFind()
	{
		delete[] parent;
	}
	int find(int p)//ÕÒµ½¸¸Ç×½Úµã 
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
		else
			parent[pRoot]=qRoot;
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
