#include <iostream>
#include <format>
using namespace std;

struct Node
{
    int data;
    struct Node *next; // A pointer of struct Node type which points to the next node

    // Constructors
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next_node) : data(x), next(next_node) {}
};

// TRAVERSAL
void linkedListTraversal(struct Node *ptr)
{
    while (true)
    {
        cout << format("data: {}\n", ptr->data);
        if (ptr->next == nullptr)
        {
            break;
        }
        ptr = ptr->next;
    }
}

// INSERTION
void insertNode(int data, struct Node *prev, struct Node *after)
{
    struct Node *ins;
    prev->next = ins;
    ins->data = data;
    ins->next = after;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *end;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    end = (struct Node *)malloc(sizeof(struct Node));

    head->data = 8;
    head->next = second;
    second->data = 10;
    second->next = third;
    third->data = 120;
    third->next = end;
    end->data = 34451;
    end->next = nullptr;

    Node head(8, second); // Create with constructor

    linkedListTraversal(head);

    return 0;
}