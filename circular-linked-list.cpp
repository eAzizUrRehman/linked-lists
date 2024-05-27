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
void insertAtStart(Node *&head, int data)
{
    Node *newNode = createNode(data);

    // if list is empty
    if (head == nullptr)
    {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    newNode->next = head;

    Node *oldHead = head;
    head = newNode;

    Node *temp = head;

    // using do-while loop because for the first time, temp is always equal to head, and temp won't move if used while loop
    do
    {
        temp = temp->next;
    } while (temp->next != oldHead);

    temp->next = head;
}

// Function to insert a node at the end of the list
// End node will always point to first node
void insertAtEnd(Node *&head, int data)
{
    Node *newNode = createNode(data);

    if (head == nullptr)
    {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    newNode->next = head;
    Node *temp = head;
    do
    {
        temp = temp->next;
    } while (temp->next != head);
    temp->next = newNode;
}

// Function to insert a node at a specific position in the list
void insertAtPosition(Node *&head, int data, int position)
{
    if (position == 0 || head == nullptr)
    {
        insertAtStart(head, data);
        return;
    }

    // any position other than first position
    Node *temp = head;

    for (int i = 0; i < position - 1; i++)
    {
        temp = temp->next;
    }

    Node *newNode = createNode(data);
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

    // if the deleting node is the only node in the list
    if (head->next == head)
    {
        delete head;
        head = nullptr;
        return;
    }

    Node *oldHead = head;

    Node *temp = head;

    head = head->next;

    do
    {
        temp = temp->next;
    } while (temp->next != oldHead);

    temp->next = head;

    delete oldHead;
}

// Function to delete the last node of the list
void deleteAtEnd(Node *&head)
{
    if (head == nullptr)
    {
        cerr << "List is empty\n";
        return;
    }

    if (head->next == head)
    {
        delete head;
        head = nullptr;
        return;
    }

    Node *temp = head;
    Node *secondLast = nullptr;

    while (temp->next->next != head)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = head;
}

// Function to delete a node at a specific position in the list
void deleteAtPosition(Node *&head, int position)
{
    if (head == nullptr)
    {
        cerr << "List is empty\n";
        return;
    }

    // if the deleting node is the first node in the list
    if (position == 0)
    {
        deleteAtStart(head);
        return;
    }

    // if the deleting node is the only node in the list
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }

    Node *temp = head;
    Node *prev = nullptr;

    for (int i = 0; i < position; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cerr << "Invalid position\n";
        return;
    }

    if (temp->next == head)
    {
        deleteAtEnd(head);
        return;
    }

    prev->next = temp->next;

    delete temp;
}

// Function to delete the entire linked list to free memory
void deleteList(Node *&head)
{
    if (head == nullptr)
        return;

    Node *current = head;
    Node *nextNode = nullptr;

    do
    {
        nextNode = current->next;
        delete current;
        current = nextNode;
    } while (current != head);

    head = nullptr;
}

// Function to print the linked list
void printList(Node *&head)
{
    Node *temp = head;

    cout << "Circular Linked List: ";
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl
         << endl;
}

int main()
{
    Node *head = nullptr;
    // insertAtEnd(head, 0);
    // insertAtEnd(head, 1);
    // insertAtEnd(head, 2);
    // insertAtEnd(head, 3);

    // insertAtPosition(head, 2, 2);
    // insertAtPosition(head, 3, 3);
    // insertAtPosition(head, 5, 5);
    // insertAtPosition(head, 7, 7);

    // printList(head);

    // deleteAtStart(head);
    // deleteAtStart(head);
    // deleteAtStart(head);
    // deleteAtStart(head);
    // deleteAtStart(head);
    // deleteAtStart(head);
    // deleteAtStart(head);

    // insertAtEnd(head, 0);
    // insertAtEnd(head, 1);
    // insertAtEnd(head, 2);
    // insertAtEnd(head, 3);

    // printList(head);

    // deleteAtEnd(head);
    // deleteAtEnd(head);
    // deleteAtEnd(head);
    // deleteAtEnd(head);

    insertAtEnd(head, 0);
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);
    printList(head);

    deleteAtStart(head);
    deleteAtPosition(head, 0);
    deleteAtPosition(head, 1);
    deleteAtPosition(head, 2);
    printList(head);

    deleteList(head);
    printList(head);

    return 0;
}
