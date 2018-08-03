#ifndef EX2_H
#define EX2_H

#define DEBUG

// includes
#include <vector>

using std::vector;

class Ex2
{
private:
    // the two dice
    int m_iFirstDice;
    int m_iSecondDice;

    vector<int> m_vCalculatedValue;

public:
    Ex2();
    ~Ex2();

    vector<int> GetTheCalculatedValues(){return m_vCalculatedValue;}

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
