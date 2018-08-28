#include "ex2.h"


const unsigned int Ex2::m_aProbabilities[NUMBER_OF_FREQUENCY]
                                = {0,0,1,2,3,4,5,6,5,4,3,2,1};

Ex2::Ex2()
{
    /* initialize random seed: */
    srand(time(0));
    m_aCalculatedValues.fill(0);
    m_aCount.fill(0);
    m_aIdealResultPercentage.fill(0);
    m_aRealResultPercentage.fill(0);
    m_aRealVsIdealProbabilities.fill(0);
    RollTheTwoDice();
}

Ex2::~Ex2()
{
    m_aCalculatedValues.fill(0);
    m_aCount.fill(0);
    m_aIdealResultPercentage.fill(0);
    m_aRealResultPercentage.fill(0);
    m_aRealVsIdealProbabilities.fill(0);
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

    CheckTheTotals();
}

void Ex2::Print()
{
    // print the titles
    std::cout <<std::endl << "Counter : "<<setw(set*set)
              << "Frequency : " <<setw(set*set)
              << "    Probabilities      :"
              << "  Ideal % : " <<setw(set*set)
              << "   Real % : " <<setw(set*set)
              << "Reasonable:"
              <<std::endl;

    // print the first horizontal line
    for (unsigned int j = 0; j < line ; j++)
    {
        std::cout << "-";
    }
    std::cout <<std::endl;

    // print the line with values
    for (unsigned i = 2; i < m_aCount.size(); i++)
    {
        std::cout << "|" << std::setw(set*2)<< i <<  " | "
                  << std::setw(set*set) << m_aCount.at(i)
                  << " | " << PrintTheProbabilities(i)
                  << std::setw(set*set) << m_aIdealResultPercentage.at(i)
                  << " | " << std::setw(set*set) << m_aRealResultPercentage.at(i)
                  << " | " << std::setw(set*set) << std::boolalpha
                  << m_aRealVsIdealProbabilities[i] << " | "
                  << std::endl;
    }

    // print the last horizontal line
    for (unsigned int j = 0; j < line ; j++)
    {
        std::cout << "-";
    }
    std::cout <<std::endl;

}

string Ex2::PrintTheProbabilities(int i)
{
    switch (i) {
    case 2:
        return "1+1                    |" ;
        break;
    case 3:
        return "2+1 1+2                |" ;
        break;
    case 4:
        return "2+2 1+3 3+1            |" ;
        break;
    case 5:
        return "3+2 2+3 4+1 1+4        |" ;
        break;
    case 6:
        return "3+3 2+4 4+2 1+5 5+1    |" ;
        break;
    case 7:
        return "4+3 3+4 5+2 2+5 1+6 6+1|" ;
        break;
    case 8:
        return "4+4 3+5 5+3 2+6 6+2    |" ;
        break;
    case 9:
        return "4+5 5+4 3+6 6+3        |" ;
        break;
    case 10:
        return "5+5 4+6 6+4            |" ;
        break;
    case 11:
        return "6+5 5+6                |" ;
        break;
    case 12:
        return "6+6                    |" ;
        break;
    default:
        break;
    }

    return "";
}

void Ex2::CheckTheTotals()
{
    // calculate the ideal percentage of probabilities
    for (unsigned i = 2; i < NUMBER_OF_FREQUENCY; i++)
    {
        int scale = 100;
        if (NUMBER_OF_ROLLED_TIMES >= 1000){
            scale = 10000;
        }
        if (NUMBER_OF_ROLLED_TIMES >= 10000)
        {
            scale = 100000;
        }
        if (NUMBER_OF_ROLLED_TIMES >= 100000)
        {
            scale = 1000000;
        }

#ifdef DEBUG
        std::cout << "ideal : " << i << ((static_cast<double>(m_aProbabilities[i])/NUMBER_OF_ROLLED_TIMES)*scale) <<std::endl;
#endif
        m_aIdealResultPercentage.at(i) = ((static_cast<double>(m_aProbabilities[i])/NUMBER_OF_ROLLED_TIMES)*scale);
    }

    // calculate the real percentage of probabilities
    for (unsigned i = 2; i < NUMBER_OF_FREQUENCY; i++)
    {
#ifdef DEBUG
        std::cout << "real : " << i << ((static_cast<double>(m_aCount[i])/11)*100)<<std::endl;
#endif
        m_aRealResultPercentage.at(i) = ((static_cast<double>(m_aCount.at(i))/NUMBER_OF_ROLLED_TIMES)*100);
    }

    // compare ideal to real result
    for (unsigned i = 2; i < NUMBER_OF_FREQUENCY; i++)
    {
        if (m_aRealResultPercentage.at(i) > m_aIdealResultPercentage.at(i)
            || m_aRealResultPercentage.at(i) < m_aIdealResultPercentage.at(i))
        {
            m_aRealVsIdealProbabilities[i] = false;
        }
        else if (m_aRealResultPercentage.at(i) == m_aIdealResultPercentage.at(i))
        {
            m_aRealVsIdealProbabilities[i] = true;
        }
    }

    Print();
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
