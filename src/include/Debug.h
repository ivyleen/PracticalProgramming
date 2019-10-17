#pragma once

#include "IncludeLibraries.h"

#define DEBUG

inline void PrintVector( vector<int>& v)
{
    cout << "The numbers in the vectors are: " << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

inline void PrintMultidimensionalVector( vector < vector<int> >& v)
{
    cout << "The numbers in the vectors are: " << endl;
    for ( int i = 0 ; i < v.size() ; ++i)
    {
        copy(v.at(i).begin(), v.at(i).end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }
}