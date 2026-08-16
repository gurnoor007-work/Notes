#include <iostream>

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void insert(Node *p, int val) {
    Node *prev = nullptr;
    if (p == nullptr) {
        p = new Node(val);
        std::cout << "Value added." << "\n";
        return;
    }

    if (val > p->data) {
        insert(p->right, val);
    } else if (val < p->data) {
        insert(p->left, val);
    } else {
        std::cout << "Value already exists!!" << "\n";
    }
}

int main() {
    Node *root = new Node(8);
    root->left = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right = new Node(10);
    root->right->right = new Node(14);
    root->right->right->left = new Node(12);

    insert(root, 13);
    return 0;
}