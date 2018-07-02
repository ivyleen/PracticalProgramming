#include "ex1.h"

Ex1::Ex1(int baseCommision, int procentOfCommision)
    : m_iBaseCommision(baseCommision)
    , m_iProcentOfCommision(procentOfCommision)
    , m_dWholeCommission(0)
{
    CalculateTheWholeCommision();
}

void Ex1::CalculateTheWholeCommision()
{
    m_dWholeCommission = m_iBaseCommision +
            (m_iBaseCommision * m_iProcentOfCommision);
}


bool Ex1::IsInRange200To299()
{
    return (m_dWholeCommission > 200 && m_dWholeCommission < 299);
}

bool Ex1::IsInRange300To399()
{
    return (m_dWholeCommission > 300 && m_dWholeCommission < 399);
}

bool Ex1::IsInRange400To499()
{
    return (m_dWholeCommission > 400 && m_dWholeCommission < 499);
}

bool Ex1::IsInRange500To599()
{
    return (m_dWholeCommission > 500 && m_dWholeCommission < 599);
}

bool Ex1::IsInRange600To699()
{
    return (m_dWholeCommission > 600 && m_dWholeCommission < 699);
}

bool Ex1::IsInRange700To799()
{
    return (m_dWholeCommission > 700 && m_dWholeCommission < 799);
}

bool Ex1::IsInRange800To899()
{
    return (m_dWholeCommission > 800 && m_dWholeCommission < 899);
}

bool Ex1::IsInRange900To999()
{
    return (m_dWholeCommission > 900 && m_dWholeCommission < 999);
}

bool Ex1::IsOrAbove1000()
{
    return m_dWholeCommission >= 1000;
}
