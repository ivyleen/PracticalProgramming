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

    SinglyLinkedList<int> sList;
    sList.Push(342);
    sList.Append(2);
    sList.Append(3);
    sList.Append(4);
    sList.Print();
    // // TODO make InsertAfterANode to work with previous data not Node
    // //sList.InsertAfterANode(342, 45);
    cout << "is 4 exist : " << boolalpha << sList.SearchFor(4) << endl;
    sList.DeleteNode(342);
    sList.Print();
    sList.DeleteNodeByPosition(0);
    sList.Print();
}