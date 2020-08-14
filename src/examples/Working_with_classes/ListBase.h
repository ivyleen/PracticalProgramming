#pragma once

#include "Node.h"
#include <iostream>

// abstract class as a base for every linked list
template <typename B>
class ListBase
{
public:
    ListBase() {};
    ~ListBase() {};

    // only member function can be virtualized
    // a friend function is not a member function
    // we can not make operator overloading virtual that's why
    // we use a function to do the overloading
    friend std::ostream& operator<<(std::ostream& out, const ListBase& lB)
	{
		// Delegating responsibility for printing to member function Print()
        // when this is called the complier does an implicit upcast
        // of the derived class to ListBase& and then calls virtual member function
		return lB.Print(out);
	}

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

protected:
    // when comming from overriding the operator <<
    // the function needs to be virutal so every derived class
    // needs to have it's printing function
    // and in this class needs to be with declaration
    // and a body (empty for now) so we don't get an undefined 
    // reference to the function error
    virtual std::ostream& Print( std::ostream&) const {}
};
