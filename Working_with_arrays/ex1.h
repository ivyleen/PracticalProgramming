#ifndef EX1_H
#define EX1_H

#include <iostream>

class Ex1
{
private:
    double m_dWholeCommission;
    int m_iProcentOfCommision;
    int m_iBaseCommision;

    void CalculateTheWholeCommision();

public:
    Ex1(int baseCommision ,int procentOfCommision);
    ~Ex1();

    bool IsInRange200To299();
    bool IsInRange300To399();
    bool IsInRange400To499();
    bool IsInRange500To599();
    bool IsInRange600To699();
    bool IsInRange700To799();
    bool IsInRange800To899();
    bool IsInRange900To999();
    bool IsOrAbove1000();

};

#endif // EX1_H
