#pragma once

#include "../../include/IncludeLibraries.h"
#include "../../include/InputOutputChecks.h"

void CharsFrequencyInString()
{
    string str;
    char ch;
    int frequency = 0;
    CheckIfValid(str);
    CheckIfValid(ch);

    for (int i = 0; i < str.size(); ++i)
    {
        if (str.at(i) == ch)
        {
            ++frequency;
        }
    }

    cout << "The frequency of '" << ch << "' is: " << frequency << "."<< endl;
}

void FrequencyOfLettersInString()
{
    string str;
    CheckIfValid(str);
    
    unordered_map<char,int> frequency;

    for (const char & ch : str)
    {
        frequency[ch]++;
    }

    cout << "The frequencies are:" << endl;
    for ( auto& pair : frequency)
    {
        cout << pair.first << " : " << pair.second << " times" << endl;
    }
}

void CountNumbersAndSpacesInStringLine()
{
    string line;
    CheckIfValidStringLine(line);
    int digits = 0, spaces = 0;

    for ( char& ch : line)
    {
        if ( ch >='0' && ch<='9')
        {
            ++digits;
        }
        else if (ch == ' ')
        {
            ++spaces;
        }
    }

    cout << "The count of digits in the line are: " << digits << endl;
    cout << "The count of spaces in the line are: " << spaces << endl;
}

void RemoveAllSymbolsAcceptNumbers()
{
    string line;
    CheckIfValidStringLine(line);
    string newLine;

    for ( char& ch : line)
    {
        if ( ch >= '0' && ch <= '9')
        {
            newLine.push_back(ch);
        }
    }

    if ( newLine. size() != 0)
        cout << "After removing string looks like:" << endl
             <<  newLine << endl;
    else 
        cout << "There not any numbers in the line." << endl;
}

