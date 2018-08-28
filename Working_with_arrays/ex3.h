#ifndef EX3_H
#define EX3_H

#include <vector>
#include <iostream>
#include <array>

using std::vector;
using std::cout;
using std::endl;
using std::array;

class Ex3
{
private:

    static const unsigned int NUMBER_OF_SEATS = 10;

    void FlightSchedule();
    void TakeSeat();
    void TakeChosenSeat(int seat);
    void RemoveTakenSeat(int seat);
    void ChangeSeat(int takenSeat, int chosenNewSeat);

    bool CheckIfFullCapacity();
    bool CheckIfEmpty();
    //return number of the free seats
    int CheckForFreeSeats();
    // return if the seat is free
    bool CheckIfSeatIsFree(int seat);
    std::vector CheckWhatsAvaliable();

public:
    void Menu();
}

#endif // EX3_H
