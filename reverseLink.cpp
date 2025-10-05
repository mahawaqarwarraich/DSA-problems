#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// ITERATIVE
Node* reverseLink(Node* head) {
    Node* temp = head;
    Node* prev = nullptr;

    while (temp) {
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    return prev;
    
}

// RECURSIVE

Node* reverseLinkRec(Node* head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }

  Node* newHead = reverseLinkRec(head->next);
  Node* front = head->next;
  front->next = head;
  head->next = nullptr;
  return newHead;
    
}


// Display function
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Create a sample list
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    cout << "Original List: ";
    display(head);

    head = reverseLinkRec(head); // reverse

    cout << "Reversed List: ";
    display(head);

    return 0;
}
