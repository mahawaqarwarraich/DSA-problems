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
Node* head = NULL;

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

void inorderBST(Node* root) {
    if (!root) return;

    inorderBST(root->left);
    cout << root->val << " ";
    inorderBST(root->right);
}


int main() {
    Node* root = new Node(5, NULL, NULL);
    
    insertBST(root, new Node(6, NULL, NULL));
    insertBST(root, new Node(2, NULL, NULL));
    insertBST(root, new Node(3, NULL, NULL));
    insertBST(root, new Node(8, NULL, NULL));
    insertBST(root, new Node(7, NULL, NULL));
    insertBST(root, new Node(9, NULL, NULL));

    inorderBST(root);
    return 0;
}