#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        this->next = NULL;
    }
};

void traverseIt(Node *head)
{
    // O(N) N is no of node in LL
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->next != NULL)
            cout << temp->data << " -> ";
        else
            cout << temp->data << endl;
        temp = temp->next;
    }
}

void traverse(Node *head)
{
    if (head == NULL)
        return;
    if (head->next != NULL)
        cout << head->data << " -> ";
    else
        cout << head->data << endl;
    traverse(head->next);
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    cout<< "Trough iteration"<<endl;
    traverseIt(head);
    cout<< "Through Recursion"<< endl;
    traverse(head);

    return 0;
}
