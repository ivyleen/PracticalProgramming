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