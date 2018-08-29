
#include "ex3.h"

void Ex3::FlightSchedule()
{

}

void Ex3::TakeSeat()
{

}

void Ex3::TakeChosenSeat(int seat)
{

}

void Ex3::RemoveTakenSeat(int seat)
{

}

void Ex3::ChangeSeat(int takenSeat, int chosenNewSeat)
{

}

bool Ex3::CheckIfFullCapacity()
{

}

bool Ex3::CheckIfEmpty()
{

}

//return number of the free seats
int Ex3::CheckForFreeSeats()
{

}

// return if the seat is free
bool Ex3::CheckIfSeatIsFree(int seat)
{

}

vector<int> Ex3::CheckWhatsAvaliable()
{

}

void Ex3::Menu()
{
    int flight, numberOfMenu;
    string answear;
    cout << "Hello. Please enter the flight number:" << endl;
    cin >> flight;
    cout << "Please confirm that your flight is: " << flight << "." << endl
         << "To answear enter yes or no." << endl;
    cin >> answear;

    cout << "Flight " << flight << endl
         << "Please chose with number from the menu below :" << endl;
    cout << "1. Check if there are available seats." << endl <<
            "2. Take Seat." << endl <<
            "3. Remove reservation." << endl <<
            "4. Change seat" << endl <<
            "5. Enter the name of passanger."<< endl;
    cin >> numberOfMenu;

    cout << "Your choice is " << numberOfMenu << "." << endl
         << "Do you want to change it? "<< endl
         << "Please answear with yes or no." << endl;
    cin >> answear;

    switch (numberOfMenu) {
    case 1:
        if (!CheckIfFullCapacity())
        {
            int freeSeats = CheckForFreeSeats();
            cout << "There are " << freeSeats << "free seats." <<endl;
        }
        else
        {
            cout << "I'm sorry. Everything on this flight is taken." << endl;
        }
        break;
    case 2:
        if (!CheckIfFullCapacity())
        {
            int freeSeats = CheckForFreeSeats();
            cout << "There are " << freeSeats << "free seats." << endl
                 << "Do u want any specific seat?"<< endl
                 << " Answear with yes or no."<< endl;
            cin >> answear;
            if (answear == "yes")
            {
                cout << "Available seats are:" << endl;
                vector<int> availableSeats = CheckWhatsAvaliable();
                for (int i =0; i < availableSeats.size(); i++)
                {
                    cout << i << ", ";
                }
                int seat;
                cout << "." << endl;
                cout << "Which seat do u want to take?" << endl;
                cin >> seat;
                TakeChosenSeat(seat);
            }
            else if(answear == "no")
            {
                TakeSeat();
            }
        }
        else
        {
            cout << "I'm sorry. Everything on this flight is taken." << endl;
        }
        break;
    case 3:
        if (!CheckIfEmpty())
        {
            int seat;
            cout << "Which taken seat do you want to remove?" << endl;
            cin >> seat;
            RemoveTakenSeat(seat);
        }
        else
        {
            cout << "I'm sorry. There are no taken seats." << endl;
        }
        break;
    case 4:
        if (!CheckIfEmpty())
        {
            int takenSeat, chosenSeat;
            cout << "Which is the taken seat?" << endl;
            cin >> takenSeat;
            cout << "Where do you want to change?" << endl;
            cin >> chosenSeat;
            if (CheckIfSeatIsFree(chosenSeat))
            {
                RemoveTakenSeat(takenSeat);
                TakeChosenSeat(chosenSeat);
                cout << "You have succesfully changed your seat." << endl;
            }
            else
            {
                cout << "This seat is already taken." << endl;
            }
        }
        else
        {
            cout << "I'm sorry. There are no taken seats." << endl;
        }
        break;
    default:
        break;
    }


}
