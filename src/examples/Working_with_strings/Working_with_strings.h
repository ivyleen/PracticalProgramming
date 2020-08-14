#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include "../../include/InputOutputChecks.h"

using std::cout;
using std::endl;
using std::string;
using std::unordered_map;

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

void SortStringInLecsographicOrder()
{
    vector<string> cities;
    string buffer, data;
    CheckIfValidStringLine(buffer);
    std::istringstream iss(buffer);
    while (iss >> data)
    {
        cities.push_back(data);
    }

    cout << "First technique:" << endl;
    sort ( cities.begin(), cities.end());

    // TODO : sort without a stl function

    cout << cities << endl;
 }

// we are not changing the original string 
// we simply return a new string with the new value 
// that's why we can mark s as a string const and
// we are taking it by reference to avoid copying
string printZigZag(string const& s, int numOfRows)
{
    // check if number of rows is 1
    if ( numOfRows == 1)
    {
        // return the string as it is
        return s;
    }

    // otherwise continue conversion
    // returning string
    string returnString;
    // reduce reallocation by reserving storage
    returnString.reserve(s.size());
    // the step we are taking when putting the correct characters
    // in the return string
    int step = (numOfRows - 1) *2;

    // for all rows
    for (int i = 0; i < numOfRows; ++i)
    {
        // until the size of the original string step by step
        for ( int j = 0; j + i < s.size(); j += step)
        {
            // put the current character of the colum made by the step
            // in the return string
            returnString += s.at(j+i);
            
            // put the character between the colums 
            // in the rows between the first and the last one
            if ( i != 0 && i != numOfRows - 1 && j + step - i < s.size())
            {
                returnString += s.at(j + step - i);
            }
        }
    }

    return returnString;
}

char whichLetterIsUsedTwiceInTheString( const std::string & S)
{
    std::map<char,int> counts;

    // count every single letters in the string
    for ( char ch : S)
    {
        counts[ch]++;
    }

    char letter = '-';

    // find the one with frequency two
    for (const auto& count : counts)
    {
        if ( count.second == 2)
        {
            letter = count.first;
        }
    }

    return letter;
}