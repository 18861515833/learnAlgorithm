#include<iostream>

using namespace std;

class UnionFind{
private:
	int *id;
	int count;
public:
	UnionFind(int n){
		count=n;
		id=new int[n];
		for(int i=0;i<n;i++)
			id[i]=i;
	}	
	~UnionFind()
	{
		delete[] id;
	}
	int find(int p)
	{
		return id[p];
	}
	bool isConnected(int p,int q)
	{
		return find(p)==find(q);
	}
	void unionElements(int p,int q)
	{
		int pId=find(p);
		int qId=find(q);
		if(pId==qId)
			return;
		for(int i=0;i<count;i++)
			if(id[i]==pId)
				id[i]=qId;
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
