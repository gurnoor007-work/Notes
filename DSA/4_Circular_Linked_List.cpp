#include <iostream>
#include <format>

struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr)
    {
        std::cout << "Default Node Created\n";
    }
    ListNode(int x) : val(x), next(nullptr)
    {
        std::cout << std::format("Node with value {} Created\n", x);
    }
    ListNode(int x, ListNode *next_node) : val(x), next(next_node)
    {
        std::cout << std::format("Node with value {} Created with next node {}\n", x, next_node->val);
    }
};

void traversal(struct ListNode* head) {
    struct ListNode* ptr = head;
    do {
        std::cout << std::format("Value: {}\n", ptr->val);
        ptr = ptr->next;
    } while(ptr != head);
}

void setVal(struct ListNode* head) {
    struct ListNode* ptr = head;
    int i = 1;
    int input;
    do {
        std::cout << std::format("Enter Value {}: ", i);
        std::cin >> input;
        ptr->val = input;
        ptr = ptr->next;
    } while (ptr!=head);
}

int main()
{
    ListNode* head = new ListNode(10);
    ListNode* first = new ListNode(25);
    ListNode* second = new ListNode(66);
    ListNode* third = new ListNode(1);

    head->next = first;
    first->next = second;
    second->next = third;
    third->next = head;

    traversal(head);


    return 0;
}