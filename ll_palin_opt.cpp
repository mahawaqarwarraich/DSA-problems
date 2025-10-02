#include<iostream>
using namespace std;

// Node definition
struct Node {
    int data;
    Node* next;
};

// make head global
Node* head = NULL;

// helper to add new nodes at end
void insert(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void findMid(Node* head, Node* &slow, Node* &fast) {
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Slow will be at mid
}

Node* reverse(Node* head) {
    if (!head) return NULL;

    Node* ptr1 = head;
    Node* ptr2 = NULL;
    cout << "hehe";

    while (ptr1 != NULL) {
        cout << "okbye";
        Node* temp = ptr1->next;
        cout << "duo";
        ptr1->next = ptr2;
        cout << "troi";
        ptr2 = ptr1;
        cout << "gillo";
        ptr1 = temp;
        cout << "chalty jayein";

    }

    return ptr2;
}

bool isPalindrome(Node* head) {
    Node* slow;
    Node* fast;

    // Find the mid;
    findMid(head, slow, fast);
    cout << "a";

    // Reverse the second part
    Node* head2 = reverse(slow->next);
    cout << "b";

    // comparison
    Node* ptr1 = head;
    Node* ptr2 = head2;

    while (ptr2 != NULL) {
        if (ptr1 != ptr2) {
            return false;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
cout << "c";
    // again reverse back the list
    reverse(head2);
    cout << "d";

    return true;

}

int main() {
    // create linked list
    insert(1);
    insert(2);
    insert(3);
    insert(2);
    insert(1);

    bool ans = isPalindrome(head);

    if (ans) {
        cout << "yes it is a palindrome linked list";
    } else {
        cout << "not its not palindrome in a linked list";
    }
    return 0;
}