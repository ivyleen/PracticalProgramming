#pragma once
#include <iostream>
#include <vector>
#include <array>
#include <iterator>
#include "../examples/Working_with_struct/StructDefinitions.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;


template <typename type>
void CheckIfValid(type& input)
{
    // according to the type we check if the input is valid 
    while (cout << "Enter an input: " && !(cin >> input) || cin.peek() != '\n')
    {
        cout << "That's not valid input. Try again." << endl;
        // clear and ignore the unvalid input
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void CheckIfValidSizeOfArray(int &size)
{
    while (cout << "Enter correct array size: " && !(cin >> size) 
            || cin.peek() != '\n' || size <= 0)
    {
        cout << "That's not valid input. Try again." << endl;
        // clear and ignore the unvalid input
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

template <typename type>
void CheckIfValidInputForArrayElement(type &input)
{
    while (!(cin >> input) || cin.peek() != '\n')
    {
        cout << "That's not valid input. Try again." << endl;
        // clear and ignore the unvalid input
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

// overloading operator << to print std::arrays
template <typename T, std::size_t N>
std::ostream& operator <<(std::ostream& o, const std::array<T, N>& arr)
{
    copy(arr.cbegin(), arr.cend(), std::ostream_iterator<T>(o, ", "));
    return o;
}

// overloading operator << to print std::vector
template <typename T>
std::ostream& operator <<(std::ostream& o, const vector<T>& vec)
{
    copy(vec.cbegin(), vec.cend(), std::ostream_iterator<T>(o, ", "));
    return o;
}

void CheckIfValidStringLine(std::string& line)
{
    while (cout << "Enter string line: " && !getline(cin, line))
    {
        cout << "That's not valid input. Try again." << endl;
        // clear and ignore the unvalid input
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

template < typename T>
void CheckIfValidComplexNumber( ComplexNumbers<T>& complex)
{
    // according to the type we check if the input is valid 
    cout << "Real part" << endl;
    CheckIfValid(complex.real);
    cout << "Imag part" << endl;
    CheckIfValid(complex.imag);
}