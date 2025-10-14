#include<iostream>
using namespace std;

struct Node {
    int val;
    Node* next;

    Node(int v) {
        val = v;
        next = nullptr;
    }
};

class LinkList {
    public:
    Node* head;
    Node* last;

    LinkList() {
        head = nullptr;
        last = nullptr;
    }

    void insert(int val) {
        Node* node = new Node(val);
        if (last == nullptr) {
           head = node;

        } else {
            last->next = node;
        }
        last = node;
    }

    void display() {
        Node* ptr = head;
        while (ptr) {
            cout << ptr->val << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }

    // without counter
    void dltNode(int n) {
        Node* slow = head;
        Node* fast = head->next;

        // Place fast after n nodes
        while (n > 0) {
            fast = fast->next;
            n--;
        }

        // move slow and fast unti fast becomes null
        while (fast) {
            slow = slow->next;
            fast = fast->next;
        }

        // delete
        Node* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;


    }

    void showMedian(Node* head) {
        
    }


};

int main() {
    // before deletion
    LinkList linkList;

    linkList.insert(1);
    linkList.insert(2);
    linkList.insert(3);
    linkList.insert(4);
    linkList.insert(5);


    linkList.display();

    linkList.dltNode(4);
    
    linkList.display();
    return 0;
}