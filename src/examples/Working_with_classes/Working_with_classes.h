#pragma once
#include "GenericStack.h"
#include "Linked_List.h"

void WorkWithGenericStack()
{
    GenericStack arr[4] = {1,2,3,4};

    for ( int i = 0; i < SIZE; ++i)
    {
        arr[1].Push('z');
    }

    for (int i = 0; i < 4; ++i)
    {
        arr[i].Print();
    }
}

void WorkingWithLinkedList()
{
    // TODO:
    // 1 ) fix the corelations between the classes with a thought of making the doubly 
    // linked list and circular linked list, make documentation
    // 2 ) make a singlylinkedlist with constructor
    // 3 ) destroy the list so you can debug it

    cout << "Working with classes" << endl;

    SinglyLinkedList sLL;
    sLL.Push(342);
    sLL.Append(2);
    sLL.Append(3);
    sLL.Append(4);
    sLL.Print();
    // // TODO make InsertAfterANode to work with previous data not Node
    // //sLL.InsertAfterANode(342, 45);
    cout << "is 4 exist : " << boolalpha << sLL.SearchFor(4) << endl;
    sLL.DeleteNode(342);
    sLL.Print();
    sLL.DeleteNodeByPosition(0);
    sLL.Print();
}