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

void preorder(Node *root){
    if (root != nullptr) {
        std::cout << root->data << "\n";
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    Node *p = new Node(1);
    p->left = new Node(10);
    p->right = new Node(16);
    p->left->left = new Node(18);
    p->right->left = new Node(122);

    preorder(p);
    return 0;
}