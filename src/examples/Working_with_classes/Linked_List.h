#pragma once

#include "../../include/IncludeLibraries.h"
#include "ListBase.h"

// child of ListBase
template <typename T>
class SinglyLinkedList : public ListBase<T>
{
private:
    // the first node is called head
    // if head == nullptr the list is empty
    Node<T>* head;

public:
    SinglyLinkedList(const SinglyLinkedList& sLS);
    virtual ~SinglyLinkedList();

    // add a Node at the front of the list
    void Push( T data) override;

    // add a Node after a given Node
    void InsertAfterANode(Node<T>* previous, T data) override;

    // add a Node at the end
    void Append( T data) override;

    // delete a Node by passing the data which needs to be deleted
    void DeleteNode( T data) override;

    // deleting a Node by given position
    void DeleteNodeByPosition( int position) override;

    inline bool IsEmpty() override { return (head == nullptr); }
};