#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d): data(d), next(nullptr) {}
};

class List {
    Node* head;
    Node* tail;
public:
    List() {
        head = tail = nullptr;
    }

    void pushback(int d) {
        Node* newnode = new Node(d);
        if (!head) {
            head = tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }

    Node* getHead() {
        return head;
    }

    // reverse in groups of size k
    Node* rik(Node* head, int k) {
        if (!head) return nullptr;

        Node* current = head;
        Node* prev = nullptr;
        Node* next = nullptr;
        int count = 0;

        // check if we have k nodes
        Node* temp = head;
        for (int i = 0; i < k; i++) {
            if (!temp) return head; // less than k nodes ? no reversal
            temp = temp->next;
        }

        // reverse k nodes
        while (current && count < k) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }

        // head is now the last node of this group
        if (next) {
            head->next = rik(next, k);
        }

        return prev; // new head of this block
    }

    void display(Node* head) {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    List l;
    l.pushback(1);
    l.pushback(2);
    l.pushback(3);
    l.pushback(4);
    l.pushback(5);
    l.pushback(6);
    l.pushback(7);
    l.pushback(8);
    l.pushback(9);
    l.pushback(10);
    l.pushback(11);
    l.pushback(12);
    l.pushback(13);

    cout << "Original list: ";
    l.display(l.getHead());

    Node* newHead = l.rik(l.getHead(), 4);

    cout << "Reversed in groups of 3: ";
    l.display(newHead);

    return 0;
}
