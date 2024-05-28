// Submitted by: AZIZ UR REHMAN - 866-FOC/BSIT/F22(A)

#include <iostream>
using namespace std;

// Define the structure for a node
struct Node
{
    int data;   // Data stored in the node
    Node *next; // Pointer to the next node in the list
};

// Function to create a new node
Node *createNode(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert a node at the beginning of the list
// When inserting a new node at the beginning of a linked list, the next pointer of the new node should point to the current head of the list.
// This allows the new node to become the new head while maintaining the connection to the rest of the list.
// setting the next pointer of the new node to point to the current head,
// assuming that the head pointer is pointing to the first node of the linked list(or nullptr if the list is empty).

void insertAtStart(Node *&head, int data)
{
    Node *newNode = createNode(data);
    newNode->next = head;
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
    for (int i = 0; i < position - 1 && temp != nullptr; i++)
    {
        temp = temp->next;
    }
    if (temp == nullptr)
    {
        cerr << "Invalid position\n";
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete the first node of the list
void deleteAtStart(Node *&head)
{
    if (head == nullptr)
    {
        cerr << "List is empty\n";
        return;
    }
    Node *temp = head;
    head = head->next;
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
    Node *prev = nullptr;
    for (int i = 0; i < position && temp != nullptr; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr)
    {
        cerr << "Invalid position\n";
        return;
    }
    prev->next = temp->next;
    delete temp;
}

// Function to print the linked list
void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
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

int main()
{
    Node *head = nullptr;

    // Inserting elements into the linked list
    insertAtEnd(head, 1);
    insertAtEnd(head, 3);
    insertAtEnd(head, 5);
    insertAtStart(head, 0);
    insertAtPosition(head, 2, 2);
    insertAtPosition(head, 4, 4);
    insertAtEnd(head, 6);

    // Printing the linked list
    cout << "\nLinked List: ";
    printList(head);

    // Deleting elements from the linked list
    deleteAtStart(head);
    deleteAtEnd(head);
    deleteAtPosition(head, 2);

    // Printing the modified linked list
    cout << "\nModified Linked List: ";
    printList(head);

    // Deleting the linked list
    deleteList(head);
    cout << "\nDeleted Linked List: ";
    printList(head);

    return 0;
}