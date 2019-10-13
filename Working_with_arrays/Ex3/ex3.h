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
	// number of flights of the airport
	vector<int> m_vNumberOfFlights;
	// vector that contains information for
	// every flight
	vector<Flight> m_vFlights;

private:
	int m_iCurrentFlight;

	void TakeFreeSeat();
    void TakeChosenSeat(int seat);
    void RemoveTakenSeat(int seat);
    void ChangeSeat(int takenSeat, int chosenNewSeat);

	// checks if the plane is at full capacity
    bool CheckIfFullCapacity();
	// check if the plane is empty
    bool CheckIfEmpty();

    //return number of the free seats
    int CheckForFreeSeats();
	// return number of the taken seats
	int CheckForTakenSeats();

    // return if the seat is free
    bool CheckIfSeatIsFree(int seat);

    vector<int> CheckWhatsAvaliable();

	void PrintMenu();

public:
	Ex3();
	virtual ~Ex3();

    void Menu();
};

#endif // EX3_H
