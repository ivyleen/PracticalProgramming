#pragma once

#include "../../include/IncludeLibraries.h"
#include "ListBase.h"

// child of ListBase
// template <typename T>
class SinglyLinkedList /*: public ListBase<T>*/
{
private:
    // the first node is called head
    // if head == nullptr the list is empty
    Node<int>* head;

public:
    SinglyLinkedList();
    virtual ~SinglyLinkedList();

    // add a Node at the front of the list
    void Push( int data) ;

    // add a Node after a given Node
    void InsertAfterANode(Node<int>* previous, int data) ;

    // add a Node at the end
    void Append( int data) ;

    // delete a Node by passing the data which needs to be deleted
    void DeleteNode( int data) ;

    // deleting a Node by given position
    void DeleteNodeByPosition( int position) ;

    bool IsEmpty()  { return (head == nullptr); }

    // return the size of the list
    int GetSize() ;

    // search for an element : returns true if data is found
    bool SearchFor( int data) ;

    // recursive function that returns the data at position
    int GetDataAt ( int position) ;

    void Print() ;
};