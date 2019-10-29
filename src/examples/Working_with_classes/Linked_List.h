#pragma once

#include "../../include/IncludeLibraries.h"
#include "ListBase.h"

// child of ListBase
template <typename S>
class SinglyLinkedList /*: public ListBase<T>*/
{
private:
    // the first node is called head
    // if head == nullptr the list is empty
    Node<S>* head;
    Node<S>* itterator;

public:
    SinglyLinkedList<S>();
    virtual ~SinglyLinkedList<S>();

    // add a Node at the front of the list
    void Push( S data) ;

    // add a Node after a given Node
    void InsertAfterANode(Node<S>* previous, S data) ;

    // add a Node at the end
    void Append( S data) ;

    // delete a Node by passing the data which needs to be deleted
    void DeleteNode( S data) ;

    // deleting a Node by given position
    void DeleteNodeByPosition( int position) ;

    bool IsEmpty()  { return (head == nullptr); }

    // return the size of the list
    int GetSize() ;

    // search for an element : returns true if data is found
    bool SearchFor( S data) ;

    // recursive function that returns the data at position
    S GetDataAt ( int position) ;

    void Print() ;
};

template <typename S>
SinglyLinkedList<S>::SinglyLinkedList()
:   head(nullptr), itterator(nullptr)
{
}

template <typename S>
SinglyLinkedList<S>::~SinglyLinkedList()
{
    cout << "Deconstructor of singly linked list working..." << endl;
 
    itterator = nullptr;
    while ( head)
    {
        Node<S>* temp = head;
        cout << " Data " << head->data << endl;
        head = head->next;
        delete temp;
    }

    delete head;
    delete itterator;
}

// add a Node at the front of the list
template <typename S>
void SinglyLinkedList<S>::Push( S data)
{
    // allocate new Node
    Node<S>* new_node = new  Node<S>();

    // put the data into the new Node
    new_node->data = data;

    // make next of new_node as head
    new_node->next = head;

    // make new_node the head
    head = new_node;
}

// add a Node after a given Node
template <typename S>
void SinglyLinkedList<S>::InsertAfterANode( Node<S>* previous, S data)
{
    if ( !previous)
    {
        cout << "The previous Node can't be nullptr" << endl;
        return;
    }

    // allocate new Node
    Node<S>* new_node = new  Node<S>();

    // put the data in it
    new_node->data = data;

    // make next of new_node as next of previous
    new_node->next = previous->next;

    // move the next of previous as new_node
    previous->next = new_node;
}

// add a Node at the end
template <typename S>
void SinglyLinkedList<S>::Append( S data)
{
    // allocate new Node
    Node<S>* new_node = new  Node<S>();

    // put the data in it
    new_node->data = data;

    // the new node is going to be the last
    new_node->next = nullptr;

    // if the list is empty make a new node
    if (!head)
    {
        head = new_node;
        return;
    }

    // if it's not empty traverse to the last existing Node
    itterator = head;

    while (itterator->next)
    {
        itterator = itterator->next;
    }

    // change the next of last 
    itterator->next = new_node;
}

// delete a Node by passing the data which needs to be deleted
template <typename S>
void SinglyLinkedList<S>::DeleteNode(  S data)
{
    // if linked list is empty
    if (!head)
    {
        cout << "The linked list is empty" << endl;
        return;
    }
    
     Node<S>* storedHead = head , *previous;

    // if head stores the data to be deleted
    if ( storedHead && storedHead->data == data)
    {
        // change head
        head = storedHead->next;

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
        cout << "The data is not present in the list" << endl;
        return;
    }

    // unlink the node from the linked list
    previous->next = storedHead->next;

    // free memory
    storedHead = nullptr;
    delete storedHead;
}

// deleting a Node by given position
template <typename S>
void SinglyLinkedList<S>::DeleteNodeByPosition( int position)
{
    // if linked list is empty
    if (!head)
    {
        cout << "The linked list is empty" << endl;
        return;
    }

    // store head Node
     Node<S>* storedHead = head;

    // if head needs to be deleted
    if ( position == 0 )
    {
        // change head
        head = storedHead->next;

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
    itterator = storedHead->next->next;

    // unlink the Node from the list
    storedHead->next = nullptr;
    delete storedHead->next;

    // unlink the deleted Node from list
    storedHead->next = itterator;
}

template <typename S>
int SinglyLinkedList<S>::GetSize()
{
    int count = 0;
    itterator = head;

    while (itterator)
    {
        ++count;
        itterator = itterator->next;
    }

    return count;
}

template < typename S>
bool SinglyLinkedList<S>::SearchFor( S data)
{
    // if linked list is empty
    if (!head)
    {
        cout << "The linked list is empty" << endl;
        return false;
    }

    itterator = head;

    while (itterator)
    {
        if (itterator->data == data)
        {
            return true;
        }

        itterator = itterator->next;
    }

    return false;
}

template < typename S>
// TODO : recursive here will break the class
S SinglyLinkedList<S>::GetDataAt( int position)
{
    int count = 1;

    if(count == position)
    {
        return head->data;
    }

    // make head next pointer
    head = head->next;

    // recursively call GetDataAt with decreased position
    return GetDataAt(position - 1);
}

template < typename S>
void SinglyLinkedList<S>::Print()
{
    itterator = head;
    while (itterator)
    {
        cout << itterator->data << " ";
        itterator = itterator->next;
    }
    cout << endl;
}