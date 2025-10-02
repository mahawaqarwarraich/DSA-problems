#include<iostream>
using namespace std;

struct Node {
    int val;
    Node* next = nullptr;
};

Node* head = nullptr;





void  dlt_nth_last_list(int pos) {
    if (!head) return;

    
    Node* slow = head;
    Node* fast = head;

    // Initialze fast at nth position from slow
    for (int i = 0; i < pos; i++) {
        fast = fast->next;
    }

    // Move both by one step until fast reaches end, at end slow will automatically be at prev
     while (fast && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

    // head
    if (fast == NULL) {
        cout << "i am here";
        head = head->next;
        delete slow;
    } else {
        // middle and last
        Node* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
    }

   

    
}

void insertList(int el) {
  
    static Node* curr;
    Node* node = new Node();
    node->val = el;
   

    if (head == nullptr) {
        head = node;
        curr = head;
        
    } else {
        curr->next = node;
        curr = node;
       
    }

    

   
}

void printList() {
   
    Node* ptr = head;
    while (ptr != NULL) {
        cout << ptr->val << " ";
        ptr = ptr->next;
    }
}



int main() {
   
    insertList(4);
    insertList(5);
    insertList(6);
    insertList(7);
   

    printList();

    dlt_nth_last_list(4);
    cout << endl;

    printList();
   
    return 0;
}