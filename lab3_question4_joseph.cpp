#include<iostream>
using namespace std;
class Node{
	public:
		
	int data;
	Node*next;
	public:
		    Node(int v):data(v),next(nullptr){
			}
};
class List{
	Node*head;
	Node*tail;
	public:
	List()
	{
		head=tail=nullptr;
	}
	void push_back(int val)
	{
	   Node*newnode=new Node(val);
	   if(head==nullptr)
	   {
	   	 head=tail=newnode;
	   }
	   else{
	   	tail->next=newnode;
	   	tail=newnode;
	   	tail->next=head;
	   }	
	
	}
	Node*joseph(Node*head,int n,int k)
	{
		int l=1,i=1;
		Node*temp=head;
		Node*slow;
		Node*fast=head;
		while(temp->next!=head)
		{
			temp=temp->next;
			l++;
		}
		while(l!=1)
		{
			while(i<k)
			{
				slow=fast;
				fast=fast->next;
				i++;
			}
			slow->next=fast->next;
			delete fast;
			fast=slow->next;
			l--;
			i=1;
		}
		return slow;
	}
	Node*gethead(){
		return head;
	}
	
};
int main(){
	List l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	l.push_back(6);
	l.push_back(7);
	Node*temp=l.joseph(l.gethead(),7,3);
	cout<<temp->data;
}
