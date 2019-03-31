//空有单链表的型 没有用上，要在删除节点的时候体现与单链表的不同 
#include<bits/stdc++.h>
using namespace std;

class MyLinkedList{
	private:
		int val;
		MyLinkedList *prev;
		MyLinkedList *next;
	public:
		MyLinkedList()
		{
			val=-1;
			prev=NULL;
			next=NULL;
			
		};
		int get(int index)
		{
			if(index<0)
				return -1;
			int i=0;
			MyLinkedList *p=this->next;
			while(i!=index&&p)
			{
				p=p->next;
				i++;
			}
			if(p)
				return p->val;
			return -1;
		};
		void addAtHead(int val)
		{
			MyLinkedList *t=new MyLinkedList();
			
			t->val=val;
			t->next=this->next;
			t->prev=this;
			
			if(this->next) 
				this->next->prev=t;
			this->next=t;
	
		};
		void addAtTail(int val)
		{
			MyLinkedList *p=this;
			while(p->next)
			{
				p=p->next;
			}
			
			MyLinkedList *t=new MyLinkedList();
			t->val=val;
			t->prev=p;
			t->next=NULL;
			
			p->next=t;
		};
		
		void addAtIndex(int index,int val)
		{
			if(index<0)
				return;
			MyLinkedList *p=this;
			int i=0;
			while(i!=index&&p->next)
			{
				i++;
				p=p->next;
			}
			if(i==index)
			{
				MyLinkedList *t=new MyLinkedList();
				t->val=val;
				t->prev=p;
				t->next=p->next;
				
				if(p->next)
					p->next->prev=t;
				p->next=t;
			}
			return ;
		}
		/* 
		void deleteAtIndex(int index)
		{
			if(index<0)
				return ;
			MyLinkedList *p=this;
			int i=0;
			while(i!=index&&p->next)
			{
				i++;
				p=p->next;
			}
			if(i==index)
			{
				if(p->next)
					p->next=p->next->next;
				
				if(p->next)
					p->next->prev=p;

			}
			return ;
		}
		*/ 
		//改进版的删除 
		void deleteAtIndex(int index)
		{
			if(index<0)
				return ;
			MyLinkedList *p=this->next;
			int i=0;
			while(i!=index&&p)
			{
				i++;
				p=p->next;
			}
			if(i==index)
			{
				if(p)
				{
					p->prev->next=p->next;
					if(p->next)
						p->next->prev=p->prev;
				}
			}
		} 
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
};


int main()
{
	MyLinkedList *p=new MyLinkedList();
	p->addAtHead(1);
	p->addAtHead(2);
	p->addAtTail(3);
	p->addAtTail(4);
	p->addAtIndex(0,5);
	p->deleteAtIndex(5);
	p->printList();
	//cout<<p->get(-1)<<endl;
	return 0;
}
