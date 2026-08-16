#include <iostream>

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val): data(val), left(nullptr), right(nullptr) {}

        void createChildren(int l, int r) {
            left = new Node(l);
            right = new Node(r);
        }
};
// ====Observing 9====
// ====Observing 6====
// ====Observing 3====
// 3
// ====Observing 4====
// 4
// 6
// ====Observing 7====
// 7
// 9
// ====Observing 10====
// 10
// ====Observing 11====
// 11
// ====Observing 19====
// ====Observing 16====
// 16
// 

// Inorder traversal being an ascending order sorted list
// means that the Binary Tree is a Binary search tree

void inorder(Node *root) {
    if (root != nullptr) {
        std::cout << "====Observing Node " << root->data << "====\n";
        inorder(root->left);
        std::cout << root->data << "\n";
        inorder(root->right);
        
    }
}

int main() {
    Node *root = new Node(9);
    root->left = new Node(6);
    root->left->left = new Node(3);
    root->left->left->right = new Node(4);
    root->left->right = new Node(7);
    root->right = new Node(10);
    root->right->right = new Node(11);
    root->right->right->right = new Node(19);
    root->right->right->right->left = new Node(16);

    inorder(root);
    return 0;
}


