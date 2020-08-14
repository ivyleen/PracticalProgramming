#ifndef EX2_H
#define EX2_H

// includes
#include <iostream>
#include <array>
#include <string>
#include "../../include/Debug.h"


class Ex2
{
private:

    static const unsigned int NUMBER_OF_ROLLED_TIMES  = 36000;
    static const unsigned int NUMBER_OF_FREQUENCY     = 13;

    // array that shows how many ways there are
    // to get a number
    static const unsigned int m_aProbabilities[NUMBER_OF_FREQUENCY];

    // for setw
    static const unsigned int set               = 3;
    // DEBUG :: number which will be used to make the table
    // must be divided by 10 (% == 0)
    static const unsigned int number            = 20;
    // DEBUG :: number of - for the line above below and between the numbers
    static const unsigned int line              = number + (set * number) +1;

    // the two dice
    int m_iFirstDie;
    int m_iSecondDie;

    // array with all the calculated values of the rolls
    std::array<int, NUMBER_OF_ROLLED_TIMES> m_aCalculatedValues;

    // array which contains the frequency of the calculated values
    std::array<int, NUMBER_OF_FREQUENCY> m_aCount;

    // result array with the ideal percentage of probabilities
    std::array<int, NUMBER_OF_FREQUENCY> m_aIdealResultPercentage;
    // result array with the real percentage of probabilities
    std::array<int, NUMBER_OF_FREQUENCY> m_aRealResultPercentage;
    // array that shows if real is like ideal probabilities
    std::array<bool, NUMBER_OF_FREQUENCY> m_aRealVsIdealProbabilities;

    // roll the two different dice and return the result
    int RollFirstDie( );
    int RollSecondDie( );

    void PrintCalculatedValues();
    std::string PrintTheProbabilities(int i);


public:
    Ex2();
    virtual~Ex2();

    std::array<int, NUMBER_OF_ROLLED_TIMES> GetTheCalculatedValues()
                                        {return m_aCalculatedValues;}

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
