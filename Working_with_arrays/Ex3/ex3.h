#ifndef EX3_H
#define EX3_H

#include "flight.h"

#include <vector>
#include <array>

using std::vector;
using std::array;

class Ex3
{
private:
	int m_iCurrentFlight;
	void TakeFreeSeat();
    void TakeChosenSeat(int seat);
    void RemoveTakenSeat(int seat);
    void ChangeSeat(int takenSeat, int chosenNewSeat);

    bool CheckIfFullCapacity();
    bool CheckIfEmpty();

    //return number of the free seats
    int CheckForFreeSeats();
    // return if the seat is free
    bool CheckIfSeatIsFree(int seat);

    vector<int> CheckWhatsAvaliable();

public:
	Ex3();
	virtual ~Ex3();

    void Menu();
};

#endif // EX3_H
