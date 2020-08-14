#include "GenericStack.h"
#include <iostream>

using std::cout;
using std::endl;

GenericStack::GenericStack(int id)
    : m_stack{},
    m_iTos(),
    m_iStackID(id)

{
    cout << "Initializing stack #" << m_iStackID << endl;
}

GenericStack::~GenericStack()
{
    cout << "Destrutor of stack #" << m_iStackID << " is working ..." << endl;
}

void GenericStack::Init()
{
    m_iTos = 0;
}

void GenericStack::Push(char ch)
{
    if (m_iTos == SIZE)
    {
        cout << "Stack if full." << endl;
        return;
    }

    m_stack[m_iTos] = ch;
    m_iTos++;
}

char GenericStack::Pop()
{
    if (m_iTos == 0)
    {
        cout << "The stack is empty." << endl;
        return 0;
    }

    m_iTos--;
    return m_stack[m_iTos];
}

void GenericStack::Print()
{
    cout << "Stack #" << m_iStackID << endl;
    cout << "Elements of the stack:" << endl;
    if ( m_iTos == 0)
    {
        cout << "There aren't any elements in the stack." << endl;
        return;
    }

    for ( int i = 0; i < m_iTos; ++i)
    {
        cout << m_stack[i] << " ";
    }
    
    cout << endl;
}