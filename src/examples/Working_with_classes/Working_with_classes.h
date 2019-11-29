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
    cout << "Working with classes" << endl;

    SinglyLinkedList<int> sList;
    sList.Push(342);
    sList.Append(2);
    sList.Append(3);
    sList.Append(4);
    cout << sList << endl;
    // // TODO make InsertAfterANode to work with previous data not Node
    // //sList.InsertAfterANode(342, 45);
    cout << "is 4 exist : " << boolalpha << sList.SearchFor(4) << endl;
    sList.DeleteNode(342);
    cout << sList << endl;
    sList.DeleteNodeByPosition(0);
    cout << sList << endl;
}