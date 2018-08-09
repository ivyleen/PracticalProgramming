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

#ifdef DEBUG
    std::cout << "First die: " <<roll << std::endl;
#endif

    return roll;
}

int Ex2::RollSecondDie()
{
    /* generate number between 1 and 6 */
    int roll = 1 + (rand() % 6);

#ifdef DEBUG
    std::cout << "Second die: " <<roll << std::endl;
#endif

    return roll;
}

void Ex2::RollTheTwoDice()
{
    for (unsigned i = 0; i < m_aCalculatedValues.size(); i++)
    {
        m_aCalculatedValues.at(i) = RollFirstDie()
                + RollSecondDie();
    }

#ifdef DEBUG
    PrintCalculatedValues();
#endif

    CountTheSums();
}


void Ex2::CountTheSums()
{
    for (unsigned i = 0; i < m_aCalculatedValues.size(); ++i)
    {
        // for every calculated value
        // make a counter in m_aCount
        ++m_aCount[m_aCalculatedValues.at(i)];
    }

    Print();
}

void Ex2::Print()
{
    std::cout <<std::endl << "Counters : " << std::endl;
    for (unsigned int j = 0; j < NUMBER_OF_FREQUENCY ; j++)
    {
        std::cout << "-";
    }

    std::cout <<std::endl;

    for (unsigned i = 2; i < m_aCount.size(); i++)
    {
        std::cout << "|" << std::setw(set - 1)<< i << std::setw(set)<< "| - |" << std::setw(set)<< m_aCount.at(i) << "|" << std::endl;
        for (unsigned int j = 0; j < NUMBER_OF_FREQUENCY ; j++)
        {
            std::cout<< "-";
        }
        std::cout << std::endl;
    }

    std::cout <<std::endl;

}

void Ex2::CheckTheTotals()
{

}


void Ex2::PrintCalculatedValues()
{
    std::cout << "Calculated values of all rolls:"
              << std::endl;
    for (unsigned int j = 0; j < line ; j++)
    {
        std::cout << "-";
    }

    std::cout << std::endl;

    for (unsigned int i = 1; i <= m_aCalculatedValues.size(); i++)
    {
        std::cout << "|" << setw(set)
                  << m_aCalculatedValues.at(i-1);

        if ( i % number == 0 )
        {
            std::cout << "|" << std::endl;
            for (unsigned  int j = 0; j < line ; j++)
            {
                std::cout << "-";
            }
            std::cout << std::endl;
        }

    }
}
