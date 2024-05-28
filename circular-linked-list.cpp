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
    newNode->next = nullptr; // initially next is null for each node
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtStart(Node *&head, int data)
{
    Node *newNode = createNode(data);

    // if list has no node at all
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
void insertAtEnd(Node *&head, int data)
{
    Node *newNode = createNode(data);

    // if list has no node at all
    if (head == nullptr)
    {
        // points to itself if only one node
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
    // if the insertion is required at the begining of the list
    if (position == 0 || head == nullptr)
    {
        insertAtStart(head, data);
        return;
    }

    Node *temp = head;

    // traversing upto the specified position
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
    // if list is already empty
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
    // if the deleting node is the only node in the list
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

    Node *temp = head;
    Node *secondLast = nullptr;

    // finding the last node
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

    // traversing upto the specified position
    Node *temp = head;
    Node *prev = nullptr;
    for (int i = 0; i < position; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    // if temp goes out of the list
    if (temp == nullptr)
    {
        cerr << "Invalid position\n";
        return;
    }

    // if the deleting node is the last node of the list
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
    // if list is already empty
    if (head == nullptr)
        return;

    Node *current = head;
    Node *nextNode = nullptr;

    // freeing memory of each node one by one
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

    // traversing the list upto end node
    do
    {
        cout << temp->data << "  ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

int main()
{
    Node *head = nullptr;

    /* ***************** NOTE: THIS PROGRAM USE 0-BASED INDEXING/POSITIONING ***************** */

    /********************************** FIRST TEST - INSERTION **********************************/
    insertAtStart(head, 2);
    insertAtStart(head, 1);
    insertAtStart(head, 0);

    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);

    cout << "\nInserting At Start & End ---------> Circular Linked List: \t";
    printList(head); // Should Print ------------> 0  1  2  3  4  5

    insertAtPosition(head, 999, 0);
    insertAtPosition(head, 888, 3);
    insertAtPosition(head, 777, 6);

    cout << "\nInserting At Random Positions ----> Circular Linked List: \t";
    printList(head); // Should Print ------------> 999  0  1  888  2  3  777  4  5

    /********************************** SECOND TEST - DELETION **********************************/
    deleteAtStart(head);

    deleteAtEnd(head);

    cout << "\nDeleting At Start & End ----------> Circular Linked List: \t";
    printList(head); // Should Print ------------> 0  1  888  2  3  777  4

    deleteAtPosition(head, 2);
    deleteAtPosition(head, 4);

    cout << "\nDeleting At Random Positions -----> Circular Linked List: \t";
    printList(head); // Should Print ------------> 0  1  2  3  4

    /***************************** THIRD TEST - DELETING WHOLE LIST *****************************/
    deleteList(head);

    cout << "\nDeleting Whole List --------------> Circular Linked List: \t";
    printList(head); // Should Print ------------>
    cout << endl;

    return 0;
}