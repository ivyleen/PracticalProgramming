#pragma once
#include "IncludeLibraries.h"

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