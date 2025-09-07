#include<iostream>
#include<List>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		Node(int d):data(d),next(nullptr){}
		
};
class List{
	Node* head;
	Node* tail;
	public:
	List(){
		head=tail=nullptr;
	}
	void pushback(int d){
	Node* newnode=new Node(d);
	if(!head){
		head=tail=newnode;
	}
	else{
		tail->next=newnode;
		tail=newnode;
		
	}	
	}
	Node* gettail() {
    return tail;
    }
    Node* getHead() {
    return head;
    }
    Node* convert(Node* head,Node* tail){
    	tail->next=head;
    	return head;
	}
	void display(Node* head,int x){
		Node* temp=head;
		int i=0;
		while(i!=x){
			cout<<temp->data<<" ";
			temp=temp->next;
			i++;
		}
		
	}
};
int main(){
	List l;
	l.pushback(1);
	l.pushback(2);
	l.pushback(3);
	l.pushback(4);
	l.pushback(5);
	l.pushback(6);
	l.pushback(7);
	Node* temp=l.convert(l.getHead(),l.gettail());
	l.display(temp,14);

}
	