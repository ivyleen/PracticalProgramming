#include "ex1.h"

Ex1::Ex1(int baseCommision, int procentOfGross, vector<int> gross)
    : m_iBaseCommission(baseCommision)
    , m_iPercentOfGross(procentOfGross)
    , m_iGross(gross)
    , m_vWholeSallaries{0}
{
    CalculateWholeSallaries();
}

Ex1::~Ex1()
{
    Clean();
}

void Ex1::CalculateWholeSallaries()
{
    for (int i = 0; i < m_vGrosses.size(); i++)
    {
        m_vWholeSallaries[i] = m_iBaseCommission +
                (m_iPercentOfGross * m_vGrosses[i]);
    }
}

void Ex1::Clean()
{
    m_iBaseCommission = 0;
    m_iPercentOfGross = 0;
    m_iGross.clean();
    m_vWholeSallaries.clean();
}

vector<int> Ex1::CountHowManyPeople()
{
    for (int i = 0 ; i < m_vWholeSallaries.size(); i++)
    {
        if(IsInRange200To299(i)) {m_vCount[0]++;}
        if(IsInRange300To399(i)) {m_vCount[1]++;}
        if(IsInRange400To499(i)) {m_vCount[2]++;}
        if(IsInRange500To599(i)) {m_vCount[3]++;}
        if(IsInRange600To699(i)) {m_vCount[4]++;}
        if(IsInRange700To799(i)) {m_vCount[5]++;}
        if(IsInRange800To899(i)) {m_vCount[6]++;}
        if(IsInRange900To999(i)) {m_vCount[7]++;}
        if(IsOrAbove1000(i)) {m_vCount[8]++;}
    }

    return m_vCount;
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
    for (int i=0; i < m_vCount.size(); i++)
    {
        if (i != 9){
            std::cout << ( ( (i+1)*100) +100) << " - " <<
                         ( ( (i+1)*100) +199) << setw(13);
        }
        else if ()
        {
            std::cout << "1000"<< setw(13);
        }
    }

}
