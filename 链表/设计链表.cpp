//设计链表  写的有很多不明白的地方 值得深究 关于边界的问题 
#include<bits/stdc++.h>
using namespace std;

class MyLinkedList{
	private:
		int val;
		MyLinkedList *next;
	public:
		MyLinkedList(){
			val=-1;
			next=NULL;	
		};
		void printList()
		{
			MyLinkedList *p=this->next;
			while(p)
			{
				cout<<p->val<<" ";
				p=p->next;
			}
			cout<<endl;
		};
		int get(int index){
			if(index<0)
				return -1;
			int i=0;
			MyLinkedList *p=this->next;
		
			while(i!=index&&p)
			{
				i++;
				p=p->next;
			}
			if(!p)
			{
				return -1;
			}
			return p->val;	
		};
		void addAtHead(int val){
			MyLinkedList *t=new MyLinkedList();
			t->val=val;
			t->next=next;
			next=t;	
		};
		void addAtTail(int val){ 
			MyLinkedList *t=new MyLinkedList();
			t->val=val;
			t->next=NULL;
			
			MyLinkedList *p=this;
			while(p->next)
			{
				p=p->next;
			}
			p->next=t;
		};
		void addAtIndex(int index,int val){//不好写，调试了半天 
			if(index<0)
				return;
			
			MyLinkedList *t=new MyLinkedList();
			t->val=val;
			
			int i=0;
			MyLinkedList *pre,*cur;
			pre=this;
			cur=pre->next;
			while(i!=index&&cur)
			{
				pre=cur;
				cur=cur->next;
				i++;
			}
			//i==index //找到了 
			//t->next=cur;
			//pre->next=t;
			//cur==NULL
			//return ;
			
			//i==index&&cur==NULL
			if(i==index)
			{
				t->next=cur;
				pre->next=t;
			}
		};
		void deleteAtIndex(int index){
			if(index<0)
				return;
			
			int i=0;
			MyLinkedList *pre,*cur=next;
			pre=this;
			while(i!=index&&cur)
			{
				i++;
				pre=cur;
				cur=cur->next;
			}
			if(i==index&&cur)
				pre->next=cur->next;
		};
};

int main()
{
	MyLinkedList list;
	list.addAtHead(1);
	list.addAtHead(2);
	list.addAtTail(3);
	list.addAtIndex(4,9);
	/*
	cout<<list.get(-1)<<endl;
	cout<<list.get(0)<<endl;
	cout<<list.get(1)<<endl;
	cout<<list.get(2)<<endl;
	cout<<list.get(3)<<endl;
	cout<<list.get(4)<<endl;
	*/
	list.printList();
	list.deleteAtIndex(4);
	list.printList();
	return 0;
}
