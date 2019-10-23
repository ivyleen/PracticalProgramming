#pragma once
#include "../../include/IncludeLibraries.h"

const short SIZE = 26;

class GenericStack
{
    
private:
    // elements of the stack
    char m_stack[SIZE];
    // tos of the stack
    int m_iTos;
    // stack ID
    int m_iStackID;

public:
    // constructor
    GenericStack(int id);
    // destructor
    ~GenericStack();

    // init the stack
    void Init();
    // adding symbol in the stack
    void Push( char ch);
    // remove a symbol from the stack
    char Pop();
    // print 
    void Print();
};