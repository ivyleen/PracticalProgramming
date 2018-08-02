#ifndef MAIN_CPP
#define MAIN_CPP

#include <iostream>
#include "Working_with_arrays/ex1.h"
#include "Working_with_arrays/ex2.h"


int main() {

    cout << "Hello" << endl;

    vector<int> gross = {1234,4363,1493, 654, 24523};

    Ex1 paytable;

    paytable.SetBaseCommission(200);
    paytable.SetPercentOfGross(9);
    paytable.SetGrosses(gross);
    std::cout << "We set the correct values." << std::endl;
    paytable.CountHowManyPeople();


    Ex1 paytable2(300, 10, gross);


    return 0;
}

#endif // MAIN_CPP
