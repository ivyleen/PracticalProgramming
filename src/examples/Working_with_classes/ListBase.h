#pragma once

#include "Node.h"

// abstract class as a base for every linked list
template <typename B>
class ListBase
{
public:
    ListBase() {};
    ~ListBase() {};

    // add a Node at the front of the list
    virtual void Push( B data) = 0;

    // add a Node after a given Node
    virtual void InsertAfterANode(Node<B>* previous, B data) = 0;

    // add a Node at the end
    virtual void Append( B data) = 0;

    // delete a Node by passing the data which needs to be deleted
    virtual void DeleteNode( B data) = 0;

    // deleting a Node by given position
    virtual void DeleteNodeByPosition( int position) = 0;

    // check if the list is empty
    virtual bool IsEmpty() = 0;

    // return the size of the list
    virtual int GetSize() = 0;

    // search for an element : returns true if data is found
    virtual bool SearchFor( B data) = 0;

    // function that returns the data at position
    virtual B GetDataAt ( int position) = 0;

    virtual void Print() = 0 ;
};
