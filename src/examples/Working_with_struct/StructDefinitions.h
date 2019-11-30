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

    // overloading operator +
    ComplexNumbers<T> operator+(const ComplexNumbers<T> & num)
    {
        ComplexNumbers<T> sum;
        sum.real = real + num.real;
        sum.imag = imag + num.imag;
        return sum;
    }

    // overloading operator -
    ComplexNumbers<T> operator-(const ComplexNumbers<T>& num)
    {
        ComplexNumbers<T> result;
        result.real = real - num.real;
        result.imag = imag - num.imag;
        return result;
    }

    // overloading operator << to print ComplexNumbers
    friend std::ostream& operator<<(std::ostream& os, const ComplexNumbers<T>& returnObject)
    {
        os << returnObject.real << '+' << returnObject.imag << 'i';
        return os;
    }
};
