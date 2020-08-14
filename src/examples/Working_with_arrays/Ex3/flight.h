#ifndef FLIGHT_H
#define FLIGHT_H

#define DEBUG

#include "seat.h"

#include <string>
#include <array>

static const unsigned char NUMBER_OF_SEATS = 10;

class Flight
{
private:

#ifdef DEBUG
	bool error = false;
#endif
	// current flight number
	int m_iCurrentFlight;
	// name of the plane;
	std::string m_sNameOfPlane;
	// number of taken seats
	int m_iTakenSeats;
	// number of free seats
	int m_iFreeSeats;
	// number of out of order seats
	int m_iOutOfOrderSeats;
	// all names of passangers
	std::array<std::string, NUMBER_OF_SEATS> m_aNamesOfPassangers;
	// array with all the seats and their information
	std::array<Seat, NUMBER_OF_SEATS> m_aSeats;

public:
    Flight();
	~Flight();

	// setters and getter
	void SetNameOfPassanger(std::string name, int seat){m_aNamesOfPassangers.at(seat) = name;}
	std::string GetNameOfPassanger(int seat){return m_aNamesOfPassangers.at(seat);}

	void SetCurrentFlightNumber(int flight){m_iCurrentFlight = flight;}
	int GetCurrentFlightNumber(){return m_iCurrentFlight;}

	void SetNameOfThePlane(std::string name){m_sNameOfPlane = name;}
	std::string GetNameOfPlane(){return m_sNameOfPlane;}

	inline std::array<Seat,NUMBER_OF_SEATS> GetAllSeats() {return m_aSeats;}

	// checks for seats
	inline int HowManySeatsAreTaken() {return m_iTakenSeats;}
	inline int HowManySeatsAreFree() {return m_iFreeSeats;}
	inline int HowManySeatsAreOutOfOrder() {return m_iOutOfOrderSeats;}

	bool CheckIfFullCapacity();
	bool CheckIfPlaneIsEmpty();

	inline bool IsSeatFree(int seat){return m_aSeats.at(seat).IsFreeSeat();}

	// main functions
	void TakeSeat(int seat);
	void ChangeSeat(int seat, int wantedSeat);
	void RemoveSeat(int seat);

	// print functions
	void PrintFlight();
};

#endif // FLIGHT_H
