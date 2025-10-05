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

// Linked List class
class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    // Insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Display the list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

// Function to delete second last node
void dltSecLast(Node* &head) {
    // For 1 length list
    if (!head || head->next == nullptr) {
        return;
    }

    // For 2 length list
    if (head->next && head->next->next == nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;// oh 
        
    }

    // For 3 length node
    Node* ptr = head;
    while (ptr->next && ptr->next->next && ptr->next->next->next) {
        ptr = ptr->next;
    }

    Node* temp = ptr->next;
    ptr->next = ptr->next->next;
    delete temp;

}

int main() {
    LinkedList list;

    // Insert some values
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);

    cout << "Original List: ";
    list.display();

    dltSecLast(list.head);

    cout << "After deleting 2nd last node: ";
    list.display();

    return 0;
}
