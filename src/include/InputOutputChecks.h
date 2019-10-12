#pragma once
#include "IncludeLibraries.h"

template <typename type>
void CheckIfValid(type& number)
{
    // according to the type we check if the input is valid 
    while (cout << "Enter an input: " && !(cin >> number) || cin.peek() != '\n')
    {
        cout << "That's not valid input. Try again." << endl;
        // clear and ignore the unvalid input
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}