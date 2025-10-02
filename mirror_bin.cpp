#include<iostream>
using namespace std;

// Node definition
struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int v, Node* l, Node* r) {
        val = v;
        left = l;
        right = r;
    }
};

// make head global
Node* root = NULL;

bool isMirrorHelp(Node* r1, Node* r2) {
    if (!r1 || !r2) return r1 == r2;

    if (r1->val != r2->val) return false;

    return isMirrorHelp(r1->left, r2->right) && 
    isMirrorHelp(r1->right, r2->left);
   
}

bool isMirror(Node* root) {
    if (!root) return true;

    return isMirrorHelp(root->left, root->right);
}

void insertBST(Node* root, Node* n) {
    if (!root) root = n;

    if (n->val < root->val) {
        if (root->left) {
            insertBST(root->left, n);
        } else {
            root->left = n;
            return;
        }
    } else {
         if (root->right) {
            insertBST(root->right, n);
        } else {
            root->right = n;
            return;
        }
    }
}


int main() {

    Node* root = new Node(5, NULL, NULL);
    
    insertBST(root, new Node(5, NULL, NULL));
    insertBST(root, new Node(2, NULL, NULL));
    insertBST(root, new Node(3, NULL, NULL));
    insertBST(root, new Node(8, NULL, NULL));
    insertBST(root, new Node(7, NULL, NULL));
    insertBST(root, new Node(9, NULL, NULL));


    int ans = isMirror(root);
    if (ans) {
        cout << "yes";
    } else {
        cout << "no";
    }
    return 0;
}