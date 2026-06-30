#include <iostream>

struct Node
{
    int data;
    struct Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, struct Node *next_node) : data(x), next(next_node) {}
};

int main()
{
    Node* top = new Node(10);
    
    return 0;
}