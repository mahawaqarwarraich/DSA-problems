#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

// Example: Build two lists with intersection
// l1: 10 -> 20 -> 30 -> 40 -> 50
// l2:            99 -> 40 -> 50
// Intersection starts at node with value 40
Node* createLists(Node*& l1, Node*& l2) {
    // Shared nodes
    Node* intersect1 = new Node(40);
    Node* intersect2 = new Node(50);
    intersect1->next = intersect2;

    // First list: 10 -> 20 -> 30 -> 40 -> 50
    l1 = new Node(10);
    l1->next = new Node(20);
    l1->next->next = new Node(30);
    l1->next->next->next = intersect1; // join to intersection

    // Second list: 99 -> 40 -> 50
    l2 = new Node(99);
    l2->next = intersect1; // join to intersection

    return intersect1; // return the actual intersection node
}

int compare(Node* l1, Node* l2) {
    Node* ptr1 = l1;
    Node* ptr2 = l2;
    while (ptr1 != NULL) {
        if (ptr1 == ptr2) {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}

// Dummy function signature (to be implemented by you)
int findIntersection(Node* l1, Node* l2) {
    // calculate lenghts of both lists
    // lenght 1
    int len1 = 0;
    Node* ptr = l1;
    while (ptr != NULL) {
        len1++;
        ptr = ptr->next;
    }
   

    // length 2
    int len2 = 0;
    ptr = l2;
    while (ptr != NULL) {
        len2++;
        ptr = ptr->next;
    }
   
    // calculte diff
    int diff = abs(len1 - len2);
   

    // if there is a difference, make both the same length in order to compare...
    if (diff > 0) {
        if (len1 > len2) {
            // mov l1 diff steps ahead
            while (diff != 0) {
                l1 = l1->next;
                diff--;
            } 
        } else {
            // move l2 diff steps ahead
             while (diff != 0) {
                l2 = l2->next;
                diff--;
            } 
        }
    }

    
    // now compare them
    int val = compare(l1, l2);
    
    return val;
}

int main() {
    Node* l1 = NULL;
    Node* l2 = NULL;

    Node* realIntersection = createLists(l1, l2);
   ;
    int val = findIntersection(l1, l2);
   
    cout << "Intersection is : " << val << endl;

    // For validation
    cout << "Expected intersection: " << realIntersection->data << endl;

    return 0;
}
