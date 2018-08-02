#include "ex1.h"

Ex1::Ex1()
    : m_iBaseCommission(0)
    , m_iPercentOfGross(0)
    , m_vGrosses{}
    , m_vWholeSallaries{}
{
    m_bEmptyConstructor = true;
    std::cout << "You are starting with empty constructor." << std::endl <<
                 "Please enter the correct values for: "
                 "base commission,"
                 "percent of gross,"
                 "and vector of grosses." << std::endl;
}

Ex1::Ex1(int baseCommision , int procentOfGross, vector<int> &gross)
    : m_iBaseCommission(baseCommision)
    , m_iPercentOfGross(procentOfGross)
    , m_vGrosses(gross)
{
    m_bEmptyConstructor = false;
    m_vWholeSallaries.resize(gross.size());
    CalculateWholeSallaries();
}

Ex1::~Ex1()
{
    Clean();
}

void Ex1::CalculateWholeSallaries()
{
    m_vWholeSallaries.resize(m_vGrosses.size());
    for (unsigned int i = 0; i < m_vGrosses.size(); i++)
    {
        m_vWholeSallaries[i] = m_iBaseCommission +
                static_cast<double>((m_iPercentOfGross * m_vGrosses[i])/100);
    }

    PrintWholeSallaries();

    if (m_bEmptyConstructor)
    {
        m_bEmptyConstructor = ! m_bEmptyConstructor;
    }

    CountHowManyPeople();
}

void Ex1::Clean()
{
    m_iBaseCommission = 0;
    m_iPercentOfGross = 0;
    m_vGrosses.clear();
    m_vWholeSallaries.clear();
    m_vCount.clear();
}

void Ex1::CountHowManyPeople()
{
    if (m_bEmptyConstructor){
        std::cout << "First we need to calculate the whole sallaries." << std::endl;
        CalculateWholeSallaries();
    }
    else
    {
        std:: cout << "Now we count." << std::endl;
    }

    for (unsigned int i = 0 ; i < m_vWholeSallaries.size(); i++)
    {
        if(IsInRange200To299(i)) {  }
        if(IsInRange300To399(i)) {  }
        if(IsInRange400To499(i)) {  }
        if(IsInRange500To599(i)) {  }
        if(IsInRange600To699(i)) {  }
        if(IsInRange700To799(i)) {  }
        if(IsInRange800To899(i)) {  }
        if(IsInRange900To999(i)) {  }
        if(IsOrAbove1000(i)) {  }
    }

        PrintDistributionOfSallaries();

    //return m_vCount;
}

bool Ex1::IsInRange200To299(int i)
{
    return (m_vWholeSallaries[i] >= 200 && m_vWholeSallaries[i] <= 299);
}

bool Ex1::IsInRange300To399(int i)
{
    return (m_vWholeSallaries[i] >= 300 && m_vWholeSallaries[i] <= 399);
}

bool Ex1::IsInRange400To499(int i)
{
    return (m_vWholeSallaries[i] >= 400 && m_vWholeSallaries[i] <= 499);
}

bool Ex1::IsInRange500To599(int i)
{
    return (m_vWholeSallaries[i] >= 500 && m_vWholeSallaries[i] <= 599);
}

bool Ex1::IsInRange600To699(int i)
{
    return (m_vWholeSallaries[i] >= 600 && m_vWholeSallaries[i] <= 699);
}

bool Ex1::IsInRange700To799(int i)
{
    return (m_vWholeSallaries[i] >= 700 && m_vWholeSallaries[i] <= 799);
}

bool Ex1::IsInRange800To899(int i)
{
    return (m_vWholeSallaries[i] >= 800 && m_vWholeSallaries[i] <= 899);
}

bool Ex1::IsInRange900To999(int i)
{
    return (m_vWholeSallaries[i] >= 900 && m_vWholeSallaries[i] <= 999);
}

bool Ex1::IsOrAbove1000(int i)
{
    return m_vWholeSallaries[i] >= 1000;
}

void Ex1::PrintDistributionOfSallaries()
{
    std::cout << "Range : " << std::endl;
    for (unsigned int i=0; i < m_vCount.size(); i++)
    {
        if (i != 9){
            std::cout << ( ( (i+1)*100) +100) << " - " <<
                         ( ( (i+1)*100) +199) << setw(13) << m_vCount[i];
        }
        else if (i>9)
        {
            std::cout << "1000"<< setw(13)<< m_vCount[i];
        }

        std::cout << std::endl;
    }
}

void Ex1::PrintWholeSallaries()
{
    std::cout << "Whole sallaries : " << std::endl;
    for (unsigned int i=0; i < m_vWholeSallaries.size(); i++)
    {
            std::cout << i+1 << setw(13) <<std::setprecision (5) << m_vWholeSallaries[i] << std::endl;
    }
}
