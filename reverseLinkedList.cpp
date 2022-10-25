
// Reverse a linked list, given a pointer to the head of the linked list.

#include<bits/stdc++.h>
using namespace std;

class Node                                //class definition for node
{
    public:
    int val;
    Node* next;

    Node(int data)
    {
        val = data;
        next = NULL;
    }
};

void insert(Node*& head, int data)        //function to insert nodes at the end of list
{
    if (head == NULL)
    {
        head = new Node(data);
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp -> next = new Node(data);
}

void print(Node*& head)                   //function to print the list
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reverse(Node*& head)                 //function to reverse the list
{
    Node* prev = NULL;
    Node* curr = head;

    while (curr != NULL)
    {
        Node* nextnode = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = nextnode;
    }
    head = prev;
}

int main()
{
    Node* head = NULL;
    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);

    cout << "Before reversing: ";
    print(head);
    cout << "After reversing: ";
    reverse(head);
    print(head);

    return 0;
}

//Contributed by: Palak Jain