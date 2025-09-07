#include<iostream>
#include<list>
using namespace std;
class Node{
		public:
	int data;
	Node* next;

		Node(int d){
			data=d;
			next=nullptr;
		}
};
class LL{
Node*head;
Node*tail;
	public:
		LL()
		{
			head=tail=nullptr;
		}
	
		void pushback(int val)
		{
			Node*newnode=new Node(val);
			if(head==nullptr)
			{
				head=tail=newnode;
			}
			else{
				tail->next=newnode;
				tail=newnode;
			}
		}
		
		bool palindrome(){
			Node*fast=head;
			Node*slow=head;
			while(fast!=nullptr&&fast->next!=nullptr){
				fast=fast->next->next;
				slow=slow->next;
			}
			Node*prev=nullptr;
			Node*current=slow->next;
			Node*Next;
			while(current!=nullptr){
				Next=current->next;
				current->next=prev;
				prev=current;
				current=Next;
			}
			Node*temp=head;
			Node*temp1=prev;
			while (temp1 != nullptr) {
				if(temp->data!=temp1->data){
						return false;}
					temp=temp->next;
					temp1=temp1->next;
			}
			return true;
		}
};
int main()
{
	LL z;
	z.pushback(1);
	z.pushback(2);
	z.pushback(3);
	z.pushback(2);
	z.pushback(1);
	bool find=z.palindrome();
	if(find)cout<<"true";
	else cout<<"false";
	
}