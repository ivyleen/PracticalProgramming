#ifndef EX2_H
#define EX2_H

//#define DEBUG

// includes
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include <array>
#include <iomanip>

using std::vector;
using std::cout;
using std::endl;
using std::array;
using std::rand;
using std::srand;
using std::setw;

class Ex2
{
private:

    static const unsigned int NUMBER_OF_ROLLED_TIMES = 36000;
    static const unsigned int NUMBER_OF_FREQUENCY    = 13;
    // for setw
    static const unsigned int set                   = 3;
    // DEBUG :: number which will be used to make the table
    // must be divided by 10 (% = 0)
    static const unsigned int number                 = 50;
    // DEBUG :: number of - for the line above below and between the numbers
    static const unsigned int line                   = number + (set * number) +1;

    // the two dice
    int m_iFirstDie;
    int m_iSecondDie;

    // array with all the calculated values of the rolls
    std::array<int, NUMBER_OF_ROLLED_TIMES> m_aCalculatedValues;

    // array which contains the frequency of the calculated values
    std::array<int, NUMBER_OF_FREQUENCY> m_aCount;

    // roll the two different dice and return the result
    int RollFirstDie( );
    int RollSecondDie( );

    void PrintCalculatedValues();

public:
    Ex2();
    virtual~Ex2();

    std::array<int, NUMBER_OF_ROLLED_TIMES> GetTheCalculatedValues(){return m_aCalculatedValues;}

    // roll the dice 36 000 times and save the calculated values
    void RollTheTwoDice();
    // count how many times each possible sum appears
    void CountTheSums();
    // print in a tabular format
    void Print();
    // check if totals are reasonable
    void CheckTheTotals();

};

#endif // EX2_H
