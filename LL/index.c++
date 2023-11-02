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

int lenghtOfLL(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void traverseIt(Node *head)
{
    // O(N) N is no of node in LL
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->next != NULL)
            cout << temp->data << " -> ";
        else
            cout << temp->data << " Length " << lenghtOfLL(head) << endl;
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

void insertATBegin(Node *&head, int x)
{
    Node *temp = new Node(x);
    temp->next = head;
    head = temp;
}

void insertAtPos(Node *&head, int x, int pos)
{
    Node *temp = head;
    Node *newNode = new Node(x);
    if (pos == 1)
    {
        insertATBegin(head, x);
        return;
    }
    while (--pos > 1)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void insertionAtEnd(Node *head, int x)
{
    Node *temp = head;
    Node *newNode = new Node(x);
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    cout << "Inserting 10 at begin" << endl;

    insertATBegin(head, 5);
    insertAtPos(head, 50, 4);
    cout << "Last Insertion " << endl;
    insertionAtEnd(head, 60);
    cout << "Trough iteration" << endl;
    traverseIt(head);
    cout << "Through Recursion" << endl;
    traverse(head);

    return 0;
}
