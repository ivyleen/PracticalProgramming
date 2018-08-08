#include "ex2.h"

Ex2::Ex2()
{
    /* initialize random seed: */
    srand(time(0));
    m_aCalculatedValues.fill(0);
    m_aCount.fill(0);
    RollTheTwoDice();
}

Ex2::~Ex2()
{

}

int Ex2::RollFirstDie()
{
    /* generate number between 1 and 6 */
    int roll = 1 +( rand() % 6);
    //std::cout << "First die: " <<roll << std::endl;
    return roll;
}

int Ex2::RollSecondDie()
{
    /* generate number between 1 and 6 */
    int roll = 1 + (rand() % 6);
    //std::cout << "Second die: " <<roll << std::endl;
    return roll;
}

void Ex2::RollTheTwoDice()
{
    for (unsigned i = 0; i < NUMBER_OF_ROLLED_TIMES; i++)
    {
        m_aCalculatedValues.at(i) = RollFirstDie() + RollSecondDie();
    }

    PrintCalculatedValues();

    CountTheSums();
}


void Ex2::CountTheSums()
{

    Print();
}

void Ex2::Print()
{
    std::cout << "Counters : " << std::endl;
    for (auto i : m_aCount)
    {
        std::cout << m_aCount.at(i) << " ";
    }
}

void Ex2::CheckTheTotals()
{

}


void Ex2::PrintCalculatedValues()
{
    std::cout << "Calculated values of all rolls:" << std::endl;
    for (int j = 0; j < 201 ; j++)
    {
        std::cout << "-";
    }
    std::cout << std::endl;
    for (unsigned int i = 1; i <= m_aCalculatedValues.size(); i++)
    {
        std::cout << "|" << setw(3) << m_aCalculatedValues.at(i-1);
        if ( i % 50 == 0 )
        {
            std::cout << "|" << std::endl;
            for (int j = 0; j < 201 ; j++)
            {
                std::cout << "-";
            }
            std::cout << std::endl;
        }
    }
}
