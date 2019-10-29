#pragma once

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

// A linked list is represented by a pointer to the first node. 
// Each node in a list consists of at least two parts:
template <typename N>
struct Node 
{
    N data;
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
