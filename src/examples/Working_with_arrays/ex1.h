#ifndef EX1_H
#define EX1_H

#define DEBUG

// includes
#include "../../include/IncludeLibraries.h"


class Ex1
{
private:
    // we need to have constant count value
    static const unsigned char COUNT_SIZE = 9;

    int m_iBaseCommission;
    int m_iPercentOfGross;

    // we don't have information about how many
    // workers we would be provided with
    // that's why we use vector
    vector<int> m_vGrosses;
    vector<double> m_vWholeSallaries;

    // we have fixed number of ranges
    // that's why we use std::array
    std::array<int, COUNT_SIZE> m_aCount;

    // check if we start with default constructor
    bool m_bEmptyConstructor;

public:
    //default constructor
    Ex1();

    // parameterized constructor
    Ex1(int baseCommision ,int procentOfGross, vector<int>& gross);

    // destructor
    virtual ~Ex1();

    // setter functions
    void SetBaseCommission(int baseCommission);
    void SetPercentOfGross(int percent);
    void SetGrosses(vector<int> grosses);

    // get the results of counts
    std::array<int,COUNT_SIZE> GetTheCountedValues () {return m_aCount;}

    // check how many people earn chosen sallary
    void CountHowManyPeople();

private:

    // helper function that calculates
    // the vector of all sallaries
    void CalculateWholeSallaries();

    // prints all "person - salary"
    void PrintWholeSallaries();

    // prints the distribution of all salaries
    void PrintDistributionOfSallaries();

    // helper functions:
    // check if the sallary is in range 200 To 299 for one salesperson
    bool IsInRange200To299(int i);
    // check if the sallary is in range 300 To 399 for one salesperson
    bool IsInRange300To399(int i);
    // check if the sallary is in range 400 To 499 for one salesperson
    bool IsInRange400To499(int i);
    // check if the sallary is in range 500 To 599 for one salesperson
    bool IsInRange500To599(int i);
    // check if the sallary is in range 600 To 699 for one salesperson
    bool IsInRange600To699(int i);
    // check if the sallary is in range 700 To 799 for one salesperson
    bool IsInRange700To799(int i);
    // check if the sallary is in range 800 To 899 for one salesperson
    bool IsInRange800To899(int i);
    // check if the sallary is in range 900 To 999 for one salesperson
    bool IsInRange900To999(int i);
    // check if the sallary is above 1000 for one salesperson
    bool IsOrAbove1000(int i);

    // sets the members to 0
    void Clean();
};

#endif // EX1_H
