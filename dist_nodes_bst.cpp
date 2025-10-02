#include <iostream>
using namespace std;

// Node structure for BST
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Global root
Node* root = nullptr;

// Create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Insert into BST
Node* createBST(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = createBST(root->left, value);
    } else if (value > root->data) {
        root->right = createBST(root->right, value);
    }
    // if value == root->data, do nothing (no duplicates)
    return root;
}

// Inorder Traversal (to check tree)
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// find lca
Node* findLCA(Node* root, int n1, int n2) {
    // same as root
    if (n1 == root->data || n2 == root->data) {
        return root;
    }

    // one big, one small
    if (n1 < root->data && n2 > root->data) {
        return root;
    }

    if (n1 > root->data && n2 < root->data) {
        return root;
    }

    // if both are less
    if (n1 < root->data && n2 < root->data) {
        return findLCA(root->left, n1, n2);
    }

    // if both are greater
     if (n1 > root->data && n2 > root->data) {
        return findLCA(root->right, n1, n2);
    }

    return NULL;
}

// dist from lca
int distFromLCA(Node* lca, int node, int dist) {
    if (node == lca->data) {
        return dist;
    }

    if (node < lca->data) {
        return distFromLCA(lca->left, node, ++dist);
    } else {
        return distFromLCA(lca->right, node, ++dist);
    }
}


// dist btw nodes
int distBtwNodesBST(int n1, int n2) {
    Node* lca = findLCA(root, n1, n2);
    cout << "lca is : " << lca->data << endl;

    int n1Dist = distFromLCA(lca, n1, 0);
    cout << "n1 dist is: " << n1Dist << endl;

    int n2Dist = distFromLCA(lca, n2, 0);
    cout << "n2 dist is: " << n2Dist << endl;

    
    int dist = n1Dist + n2Dist;

    return dist;
}

int main() {
    // Adding nodes one by one
    root = createBST(root, 50);
    root = createBST(root, 30);
    root = createBST(root, 70);
    root = createBST(root, 20);
    root = createBST(root, 40);
    root = createBST(root, 60);
    root = createBST(root, 80);

   int dist = distBtwNodesBST(20, 50);

   cout << "distance btw nodes is: " << dist << endl;

    return 0;
}
