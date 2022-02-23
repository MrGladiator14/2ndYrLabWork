#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{
    Node *head;

public:
    LinkedList() { head = NULL; }

    void insertNode(int); // Function to insert a node at the front of the linked list1.

    void printList();

    void deleteNode();
};

void LinkedList::deleteNode()
{
    Node *temp = head;
    int List1Len = 0;

    if (head == NULL)
    {
        cout << "List1 empty." << endl;
        return;
    }
    head = head->next;
    cout << temp->data << " deleted\n";
    delete temp;
    return;
}

void LinkedList::insertNode(int data)
{
    Node *newNode = new Node(data);

    if (head == NULL)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

void LinkedList::printList()
{
    Node *temp = head;

    if (head == NULL)
    {
        cout << "EMPTY" << endl;
        return;
    }

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    LinkedList list1;

    list1.insertNode(1);
    list1.insertNode(2);
    list1.insertNode(3);
    list1.insertNode(4);

    cout << "Elements of the list1 are: ";

    list1.printList();
    cout << endl;

    list1.deleteNode();

    cout << "Elements of the list 1 are: ";
    list1.printList();
    cout << endl;
    LinkedList list;

    list.insertNode(10);
    list.insertNode(11);
    list.insertNode(12);
    list.insertNode(13);

    cout << "Elements of the list 2 are: ";

    list.printList();
    cout << endl;

    list.deleteNode();

    cout << "Elements of the list are: ";
    list.printList();
    cout << endl;
    return 0;
}
