#include<iostream>
#include<list>
using namespace std;
class Single{
	public:
		int data;
		Single* next;
		
		Single(int d){
			data=d;
			next=nullptr;
		}
		
};
class Double{
	public:
		int data;
		Double* next;
		Double* prev;
		Double(int d){
			data=d;
			next=prev=nullptr;
		}
};
Double *convert(Single* head){
	Double*dllhead=new Double(head->data);
	Double*dllcurrent=dllhead;
	Single*sllc=head->next;
	while(sllc!=nullptr){
	Double*newnode=new Double(sllc->data);
	dllcurrent->next=newnode;
	newnode->prev=dllcurrent;
	sllc=sllc->next;
	dllcurrent=newnode;
	}
	return dllhead;
	}
	
	void displayForward(Double* head) {
    while (head) {
        cout << head->data << " ";
        if (head->next == nullptr) break; // save tail for backward later
        head = head->next;
    }
    cout << endl;
    }

    // Display DLL backward
    void displayBackward(Double* tail) {
    while (tail) {
        cout << tail->data << " ";
        tail = tail->prev;
    }
    cout << endl;
    }
	
	
	int main(){
		Single* head = new Single(1);
        Single* temp = head;
        for (int i = 2; i <= 5; i++) {
        temp->next = new Single(i);
        temp = temp->next;
        }
        Double* Head=convert(head);
        Double* tail = Head;
        while (tail->next!=nullptr) 
		tail = tail->next;
        
        displayForward(Head);
        displayBackward(tail);
    }
