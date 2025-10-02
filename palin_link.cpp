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

bool compare(Node* l1, Node* l2) {
    Node* ptr1 = l1;
    Node* ptr2 = l2;

    while (ptr1 != NULL) {
        if (ptr1->data != ptr2->data) {
            return false;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return true;
}


bool isPalindrome(Node* head) {
    // reverse upto the mid, length/2
    // now we have l1 and l2, if odd l2=>l2->next;
    // compare l1 and l2
    // if compare palindrome else no

    // lets know the length
    int len = 0;
    Node* ptr  = head;
    while (ptr != NULL) {
        len++;
        ptr = ptr->next;
    }
    cout << "a" << endl;

    // calculate the mid
    int mid = len/2;

    // REVERSE UPTO MID
    Node* head2 = NULL;
    Node* ptr1;
    while (mid > 0) {
        ptr1 = head;
        head = ptr1->next;
        ptr1->next = head2;
        head2 = ptr1;
        mid--;
    }
     cout << "b" << endl;

    // if length odd move h1 by one
    if (len % 2 != 0) {
        head = head->next;
    }

    cout << "head 1 is " << head->data << "and head2 is" << head2->data << endl;

    // now compare
    int ans = compare(head, head2);
     cout << "c" << endl;

    return ans;



}

int main() {

     // create linked list
    insert(1);
    insert(3);
    insert(3);
    insert(2);
    insert(1);

    int ans = isPalindrome(head);

    if (ans) {
        cout << "yes it is a palindrome linked list";
    } else {
        cout << "not its not palindrome in a linked list";
    }
    return 0;
}