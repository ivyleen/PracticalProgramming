#ifndef EX3_H
#define EX3_H

#include <vector>
#include <iostream>
#include <array>
#include <string>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::array;
using std::string;

class Ex3
{
private:

    static const unsigned int NUMBER_OF_SEATS = 10;

    string nameOfPassanger;
    vector<int> flightList;

    void FlightSchedule();
    void TakeSeat();
    void TakeChosenSeat(int seat);
    void RemoveTakenSeat(int seat);
    void ChangeSeat(int takenSeat, int chosenNewSeat);

    void SetNameOfPassanger(string name);
    string GetNameOfPassanger();

    bool CheckIfFullCapacity();
    bool CheckIfEmpty();
    //return number of the free seats
    int CheckForFreeSeats();
    // return if the seat is free
    bool CheckIfSeatIsFree(int seat);
    vector<int> CheckWhatsAvaliable();

public:
    void Menu();
};

#endif // EX3_H
