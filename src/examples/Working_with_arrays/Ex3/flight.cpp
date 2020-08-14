#include "flight.h"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

Flight::Flight()
    : m_iCurrentFlight()
    , m_sNameOfPlane()
    , m_iTakenSeats()
    , m_iFreeSeats()
    , m_iOutOfOrderSeats()
{
	for (unsigned int i = 0; i < m_aSeats.size(); i++)
	{
		m_aSeats.at(i).SetNumberOfSeat(i);
	}
}

Flight::~Flight()
{

}

bool Flight::CheckIfFullCapacity()
{
	bool isItFull = true;
	for (unsigned int i = 0; i < m_aSeats.size(); i++)
	{
		if(m_aSeats.at(i).IsFreeSeat())
		{
			isItFull = false;
			break;
		}
	}

	return isItFull;
}

bool Flight::CheckIfPlaneIsEmpty()
{
	bool isItEmpty = true;
	for (unsigned int i = 0; i < m_aSeats.size(); i++)
	{
		if(!m_aSeats.at(i).IsFreeSeat())
		{
			isItEmpty = false;
			break;
		}
	}

	return isItEmpty;
}

void Flight::ChangeSeat(int seat, int wantedSeat)
{
	cout << "Changing you're seat." << endl;

	RemoveSeat(seat);

	if (!error)
	{
		TakeSeat(wantedSeat);
		if (error)
		{
			do
			{
				cout << "Please choose another seat." << endl;
				cin >> wantedSeat;
				TakeSeat(wantedSeat);
			} while (!error && (wantedSeat > 0 && wantedSeat < 11));
		}
	}
}

void Flight::TakeSeat(int seat)
{
	if (!m_aSeats.at(seat).IsFreeSeat())
	{
		cout << "This seat is taken" << endl;
		error = true;
		return;
	}
	else
	{
		m_aSeats.at(seat).TakeSeat();
		cout << "You have successfully taken seat " << seat << "." << endl;
	}

	m_iTakenSeats++;
	m_iFreeSeats--;

	//PrintSeats();
}

void Flight::RemoveSeat(int seat)
{
	cout << "First we remove you're seat from the taken." << endl;
	if (m_aSeats.at(seat).IsFreeSeat())
	{
		cout << "The seat wasn't taken." << endl;
		error = true;
	}
	else
	{
		m_aSeats.at(seat).FreeSeat();
		cout << "Success." << endl;
	}

	m_iTakenSeats--;
	m_iFreeSeats++;

	//PrintSeats();
}

void Flight::PrintFlight()
{
	for (unsigned int i =0; i < m_aSeats.size(); i++)
	{
		if (i == 6)
		{
			cout << endl;
		}

		if (m_aSeats.at(i).IsFreeSeat())
		{
			cout << "[" << m_aSeats.at(i).GetNameOfPassanger() << "] ";
		}
		else
		{
			cout << "[Free]";
		}
	}
}
