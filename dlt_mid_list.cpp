#include<iostream>
using namespace std;

struct Node {
    int val;
    Node* next;

    Node(int vl) {
        val = vl;  
        next = nullptr;  
    }
};

Node* head = nullptr;





void  dlt_mid_list(Node* mid) {
    

    if (mid && mid->next) {
        mid->val = mid->next->val; // replace the val
        Node* temp = mid->next; // node to be deleted
        mid->next = mid->next->next; // link
        delete temp;
    }
   


}

void insertList(int el) {
  
    static Node* curr;
    Node* node = new Node(el);
  
   

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
   
    // insertList(4);
    // insertList(5);
    // insertList(6);
    // insertList(7);

    Node* first = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);

    first->next = second;
    second->next = third;
    third->next = NULL;

    head = first;
   

    printList();

    dlt_mid_list(second);
    cout << endl;

    printList();
   
    return 0;
}