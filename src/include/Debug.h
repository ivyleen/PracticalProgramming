#pragma once

#include <vector>
#include <iterator>

using std::cout;
using std::endl;

#define DEBUG

inline void PrintVector( std::vector<int>& v)
{
    cout << "The numbers in the vectors are: " << endl;
    copy(v.begin(), v.end(), std::ostream_iterator<int>(cout, " "));
    cout << endl;
}

inline void PrintMultidimensionalVector( std::vector < std::vector<int> >& v)
{
    cout << "The numbers in the vectors are: " << endl;
    for ( int i = 0 ; i < v.size() ; ++i)
    {
        copy(v.at(i).begin(), v.at(i).end(), std::ostream_iterator<int>(cout, " "));
        cout << endl;
    }
}