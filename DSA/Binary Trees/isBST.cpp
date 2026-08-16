#include <iostream>
#include <vector>

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

std::vector<int> inorderTraversal(Node *p)
{
    std::vector<int> tree;

    if (p != nullptr)
    {
        inorderTraversal(p->left);
        tree.push_back(p->data);
        inorderTraversal(p->right);
    }

    return tree;
}

int isBST(Node *p)
{
    Node *prev = nullptr;
    if (p != nullptr)
    {
        if (!isBST(p->left))
        {
            return 0;
        }
        if (prev != nullptr && p->data >= prev->data)
        {
            return 0;
        }
        prev = p;
        return isBST(p->right);
    }
    else
    {
        return 1;
    }
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

    if (isBST(root)) {
        std::cout << "it is BST" << "\n";
    }

    return 0;
}