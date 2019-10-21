#pragma once
#include <iostream>

struct Student // structure named Student
{
    std::string name;
    int ticket;
    int group;

}; // variable student

template < typename T>
struct ComplexNumbers // structure name
{
    T real;
    T imag;

    ComplexNumbers()
    {
        real = 0;
        imag = 0;
    }
};

// overloading operator << to print ComplexNumbers
template <typename T>
std::ostream& operator <<(std::ostream& os, const ComplexNumbers<T>& returnObject)
{
    os << returnObject.real << '+' << returnObject.imag << 'i';
    return os;
}
