#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* child;

    Node(int v) : data(v), next(nullptr), child(nullptr) {}
};

// Function to flatten the list
Node* flatten(Node* head) {
    if (!head) return nullptr;

    Node* curr = head;

    while (curr) {
        if (curr->child) {
            // Save the next pointer
            Node* nextNode = curr->next;

            // Flatten the child list
            Node* childList = flatten(curr->child);

            // Connect curr ? child
            curr->next = childList;

            // Find tail of childList
            Node* tail = childList;
            while (tail->next) {
                tail = tail->next;
            }

            // Connect tail ? nextNode
            tail->next = nextNode;

            // Clear child pointer
            curr->child = nullptr;
        }
        curr = curr->next;
    }

    return head;
}

// Utility function to print list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create nodes
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);

    // Main list: 1 ? 2 ? 3
    n1->next = n2;
    n2->next = n3;

    // Child list: 4 ? 5 (attached to 2)
    n2->child = n4;
    n4->next = n5;

    cout << "Original (multilevel) list:" << endl;
    cout << "1 ? 2 ? 3" << endl;
    cout << "    |" << endl;
    cout << "    4 ? 5" << endl;

    // Flatten the list
    Node* flat = flatten(n1);

    cout << "\nFlattened list:" << endl;
    printList(flat);

    return 0;
}
