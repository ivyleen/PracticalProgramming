#ifndef SEAT_H
#define SEAT_H

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Seat
{
private:

	int m_iNumber;
	string m_sName;
	bool m_bIsItTaken;
	bool m_bIsItOutOfOrder;

public:
	Seat();
	virtual ~Seat();

	void TakeSeat(){m_bIsItTaken = true;}
	void FreeSeat(){m_bIsItTaken = false;}
	bool IsFreeSeat(){return m_bIsItTaken;}

	void OutOfOrder(){m_bIsItOutOfOrder = true;}
	void InOrder(){m_bIsItOutOfOrder = false;}

	void SetNameOfPassanger(string name){m_sName = name;}
	string GetNameOfPassanger(){return m_sName;}

	void SetNumberOfSeat(int seatNumber){m_iNumber = seatNumber;}
	int GetNumberOfSeat(){return m_iNumber;}
};

#endif // SEAT_H
