#pragma once
#include "../../include/IncludeLibraries.h"

// making of linked list without stl
// Advantages over arrays : 
// 1) Dynamic size ; 
// 2) Ease of insertion/deletion.
// 3) Size is allocated during runtime
// 4) Memory utilization is efficient


// Drawbacks over arrays : 
// 1) Random access is not allowed (=> no efficient binary search) ; 
// 2) Extra memory space for a pointer for every element ;
// 3) Not cache friendly. 

// base class
// A linked list is represented by a pointer to the first node. 
// Each node in a list consists of at least two parts:
class Node 
{
public:
    int data;
    // the first node is called head
    // if head == nullptr that the list is empty
    struct Node* next;

    Node()
    : data(), next(nullptr)
    {}

    virtual ~Node()
    {

    }

    virtual void PrintList(Node* node)
    {
        while (node)
        {
            cout << node->data << " ";
            node = node->next;
        }
    }
};

// child of Node
class SinglyLinkedList : Node
{

public:
    // add a Node at the front of the list
    void Push(Node** head, int data);

    // add a Node after a given Node
    void InsertAfterANode(Node* previous, int data);

    // add a Node at the end
    void Append(Node** head, int data);

    // delete a Node by passing the data which needs to be deleted
    void DeleteNode( Node** head, int data);

    // deleting a Node by given position
    void DeleteNodeByPosition( Node** head, int position);
};