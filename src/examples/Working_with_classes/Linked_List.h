#pragma once

#include "../../include/IncludeLibraries.h"
#include "ListBase.h"

// this is the declarations of template class SinglyLinkedList
// main purpose : to showcase how singly linked list works internally
// child of base template class ListBase
template <typename S>
class SinglyLinkedList : private ListBase<S>
{
private:
    // the first node is called head
    // if head == nullptr the list is empty
    Node<S>* head;
    // itterator used for itterating through elements of the list
    // for internal usage only
    Node<S>* itterator;

public:
    // default constructor
    SinglyLinkedList<S>();
    // default dectructor 
    // 
    virtual ~SinglyLinkedList<S>();

    // add a Node at the front of the list
    void Push( S data) override;

    // add a Node after a given Node
    void InsertAfterANode(Node<S>* previous, S data) override;

    // add a Node at the end
    void Append( S data) override;

    // delete a Node by passing the data which needs to be deleted
    void DeleteNode( S data) override;

    // deleting a Node by given position
    void DeleteNodeByPosition( int position) override;

    bool IsEmpty() override { return (head == nullptr); }

    // return the size of the list
    int GetSize() override;

    // search for an element : returns true if data is found
    bool SearchFor( S data) override;

    // recursive function that returns the data at position
    S GetDataAt ( int position) override;

    void Print() override;
};


// This is the definition of the class SinglyLinkedList
// NOTE :: Because the class is template class we have a slight problem :
// if we have the implimentations in other Linked_List.cpp file it will be 
// compiled seperatly first from the implicit inistance in 
// Working_with_classes. In that case the implementations of those 
// member functions are not in Working_with_classes.cpp file nor in any 
// header files included in it and therefore the compiler can't include 
// complete versions of those functions in the object file. On the other hand
// compiling Linked_list.cpp the compiler won't compile those instances eihter
// because there are no implicit or explicit intances of the class.
// So we have two options if we want to be able to make objects of it:
// 1) explicitly instantiate all the relevant templates at the end of the cpp
// file (problem : you need to know which are the relevant templates, but 
// in this way you can ensure that the implimentations are placed in one 
// translation unit - .cpp file, and the explicit instances are places 
// after the definitions of all the funtions)
// 2) put the definitions inside the header file where the class is declared
// (problem : it could mean the same funtions are compiled many times so it's 
// slower, but linker will ignore the duplicate implementations)

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
        // if we've found the passed data return true
        if (itterator->data == data)
        {
            return true;
        }

        // otherwise continue itterating
        itterator = itterator->next;
    }

    return false;
}

template < typename S>
// TODO : recursive here will break the class
S SinglyLinkedList<S>::GetDataAt( int position)
{
    itterator = head;
    int count = 0;

    if (GetSize() < position)
    {
        cout << "The position is outside the list." << endl;
        return 0;
    }

    // while itterator != nullptr
    while (itterator)
    {
        // if the count of the positions is the same as wanted
        if (count == position)
        {
            // return the data
            return itterator->data;
        }

        // otherwise continue itterating
        ++count;
        itterator = itterator->next;
    }
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