#include "Linked_List.h"


// add a Node at the front of the list
void SinglyLinkedList::Push(Node** head, int data)
{
    // allocate new Node
    Node* new_node = new Node();

    // put the data into the new Node
    new_node->data = data;

    // make next of new_node as head
    new_node->next = (*head);

    // make new_node the head
    (*head) = new_node;
}

// add a Node after a given Node
void SinglyLinkedList::InsertAfterANode(Node* previous, int data)
{
    if ( !previous)
    {
        cout << "The previous Node can't be nullptr" << endl;
        return;
    }

    // allocate new Node
    Node* new_node = new Node();

    // put the data in it
    new_node->data = data;

    // make next of new_node as next of previous
    new_node->next = previous->next;

    // move the next of previous as new_node
    previous->next = new_node;
}

// add a Node at the end
void SinglyLinkedList::Append(Node** head, int data)
{
    // allocate new Node
    Node* new_node = new Node();

    // put the data in it
    new_node->data = data;

    // the new node is going to be the last
    new_node->next = nullptr;

    // if the list is empty make a new node
    if (!(*head))
    {
        *head = new_node;
        return;
    }

    // if it's not empty traverse to the last existing Node
    Node* last = *head;

    while (last->next)
    {
        last = last->next;
    }

    // change the next of last 
    last->next = new_node;
}

// delete a Node by passing the data which needs to be deleted
void SinglyLinkedList::DeleteNode( Node** head, int data)
{
    Node* storedHead = *head , *previous;

    // if head stores the data to be deleted
    if ( storedHead && storedHead->data == data)
    {
        // change head
        *head = storedHead->next;

        // free memory
        storedHead = nullptr;
        delete storedHead;
        return;
    }

    // search for the data to be deleted 
    // keep track of previous as we need to change the next of it
    while (storedHead && storedHead->data != data)
    {
        previous = storedHead;
        storedHead = storedHead->next;        
    }

    if (!storedHead)
    {
        cout << "The key is not present in the list" << endl;
        return;
    }

    // unlink the node from the linked list
    previous->next = storedHead->next;

    // free memory
    storedHead = nullptr;
    delete storedHead;
}

// deleting a Node by given position
void SinglyLinkedList::DeleteNodeByPosition( Node** head, int position)
{
    // if linked list is empty
    if (!head)
    {
        cout << "The linked list is empty" << endl;
        return;
    }

    // store head Node
    Node* storedHead = *head;

    // if head needs to be deleted
    if ( position == 0 )
    {
        // change head
        *head = storedHead->next;

        // free memory
        storedHead = nullptr;
        delete storedHead;
        return;
    }

    // find previous Node of the Node to be deleted
    for ( int i = 0; storedHead && i < position - 1; ++i)
    {
        storedHead = storedHead->next;
    }

    if (!storedHead || !storedHead->next)
    {
        cout << "the position is more of the number of nodes" << endl;
        return;
    }

    // Node storedHead->next is the node to be deleted
    // store point to the next of node to be deleted
    Node* next = storedHead->next->next;

    // unlink the Node from the list
    storedHead->next = nullptr;
    delete storedHead->next;

    // unlink the deleted Node from list
    storedHead->next = next;
}