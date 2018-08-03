#ifndef EX1_H
#define EX1_H

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class Ex1
{
private:
    int m_iBaseCommission;
    int m_iPercentOfGross;
    vector<int> m_vGrosses;

    vector<double> m_vWholeSallaries;

    vector<int> m_vCount;

    static const unsigned char COUNT_SIZE = 9;

    // check if we start with empty constructor
    bool m_bEmptyConstructor;

    void CalculateWholeSallaries();

    void PrintWholeSallaries();

public:
    //blank constructor
    Ex1();

    // constructor
    Ex1(int baseCommision ,int procentOfGross, vector<int>& gross);

    // destructor
    ~Ex1();

    void SetBaseCommission(int baseCommission){m_iBaseCommission = baseCommission;}
    void SetPercentOfGross(int percent){m_iPercentOfGross = percent;}
    void SetGrosses(vector<int> grosses){m_vGrosses = grosses;}

    // check how many people earn chosen sallary
    void CountHowManyPeople();

private:

    // prints the distribution of all salaries
    void PrintDistributionOfSallaries();

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
