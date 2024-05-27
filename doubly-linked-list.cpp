#include <iostream>
using namespace std;

// Define the structure for a node
struct Node
{
    int data;   // Data stored in the node
    Node *next; // Pointer to the next node in the list
    Node *prev; // Pointer to the prev node in the list
};

// Function to create a new node
Node *createNode(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtStart(Node *&head, int data)
{
    Node *newNode = createNode(data);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(Node *&head, int data)
{
    Node *newNode = createNode(data);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node *temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Function to insert a node at a specific position in the list
void insertAtPosition(Node *&head, int data, int position)
{
    if (position == 0)
    {
        insertAtStart(head, data);
        return;
    }

    Node *newNode = createNode(data);
    Node *temp = head;

    for (int i = 0; i < position - 1; i++)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to delete the first node of the list
void deleteAtStart(Node *&head)
{
    if (head == nullptr)
    {
        cerr << "List is empty\n";
        return;
    }
    if (head->next == nullptr)
    {
        head = nullptr;
        delete head;
        return;
    }

    Node *temp = head;
    head = head->next;
    head->prev = nullptr;

    delete temp;
}

// Function to delete the last node of the list
void deleteAtEnd(Node *&head)
{
    if (head == nullptr)
    {
        cerr << "List is empty\n";
        return;
    }

    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }

    Node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

// Function to delete a node at a specific position in the list
void deleteAtPosition(Node *&head, int position)
{
    if (head == nullptr)
    {
        cerr << "List is empty\n";
        return;
    }

    if (position == 0)
    {
        deleteAtStart(head);
        return;
    }

    Node *temp = head;

    for (int i = 0; i < position; i++)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cerr << "\nInvalid position\n";
        return;
    }

    if (temp->next == nullptr)
    {
        deleteAtEnd(head);
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;
}

// Function to delete the entire linked list to free memory
void deleteList(Node *&head)
{
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

// Function to print the linked list
void printList(Node *&head)
{
    Node *temp = head;

    cout << "Doubly Linked List: ";

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl
         << endl;
}

int main()
{
    Node *head = nullptr;
    // insertAtEnd(head, 0);
    // insertAtEnd(head, 1);
    // insertAtEnd(head, 2);
    // printList(head);

    // insertAtStart(head, 2);
    // insertAtStart(head, 1);
    // insertAtStart(head, 0);
    // printList(head);

    insertAtPosition(head, 0, 0);
    insertAtPosition(head, 1, 1);
    insertAtPosition(head, 2, 2);
    printList(head);

    // deleteAtStart(head);
    // deleteAtStart(head);
    // deleteAtStart(head);
    // printList(head);

    // insertAtPosition(head, 0, 0);
    // insertAtPosition(head, 1, 1);
    // insertAtPosition(head, 2, 2);
    // printList(head);

    // deleteAtEnd(head);
    // deleteAtEnd(head);
    // deleteAtEnd(head);
    // printList(head);

    // insertAtPosition(head, 0, 0);
    // insertAtPosition(head, 1, 1);
    // insertAtPosition(head, 2, 2);
    // printList(head);

    // deleteAtPosition(head, 5);

    insertAtPosition(head, 0, 0);
    insertAtPosition(head, 1, 1);
    insertAtPosition(head, 2, 2);
    printList(head);

    deleteAtEnd(head);
    deleteAtEnd(head);
    printList(head);

    deleteList(head);
    printList(head);

    return 0;
}