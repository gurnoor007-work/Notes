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

int main() {
    Node* root = new Node(1);

    root->createChildren(11, 12);
    return 0;
}