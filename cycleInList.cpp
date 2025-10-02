#include <iostream>
using namespace std;

// Define the Node structure
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Floyd’s cycle detection
bool findCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) return true;  // cycle detected
    }

    return false;  // no cycle
}

int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Optional: create a cycle for testing
    head->next->next->next->next->next = head->next->next; // 5 -> 3

    int isCycle = findCycle(head);
    if (isCycle) {
        cout << "Yes, there is a cycle" << endl;
    } else {
        cout << "No, there is not a cycle" << endl;
    }

    return 0;
}
