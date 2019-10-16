#pragma once

#include "IncludeLibraries.h"

#define DEBUG

inline void PrintVector( vector<int>& v)
{
    cout << "The numbers in the vectors are: " << endl;
    copy(v.begin(), v.end(), 
    ostream_iterator<int>(cout, " "));
    cout << endl;
}