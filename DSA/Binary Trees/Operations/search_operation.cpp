#include <iostream>

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Recursive method to search
void search(Node *p, int val)
{
    if (p != nullptr)
    {
        if (val > p->data)
        {
            search(p->right, val);
        }
        else if (val < p->data)
        {
            search(p->left, val);
        }
        else if (val == p->data)
        {
            std::cout << "Value found" << "\n";
        }
    }
    else
    {
        std::cout << "No Value found" << "\n";
    }
}

// Iteration method to search
void searchIter(Node *p, int val)
{
    while (p != nullptr)
    {
        if (val == p->data)
        {
            std::cout << "Value found" << "\n";
            return;
        }
        else if (val > p->data)
        {
            p = p->right;
        }
        else if (val < p->data)
        {
            p = p->left;
        }
    }
    std::cout << "No Value found" << "\n";
}

int main()
{
    Node *root = new Node(9);
    root->left = new Node(6);
    root->left->left = new Node(3);
    root->left->left->right = new Node(4);
    root->left->right = new Node(7);
    root->right = new Node(10);
    root->right->right = new Node(11);
    root->right->right->right = new Node(19);
    root->right->right->right->left = new Node(16);

    searchIter(root, 20);

    return 0;
}