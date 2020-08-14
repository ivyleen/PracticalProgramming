#include <iostream>
#include <vector>
#include <string> 

#define number_of_seat_in_a_row 10 

struct PlaneSeat
{
    int numberOfRow;
    char numberOfSeat;
    bool taken = false;
};

int seats( int n, std::string & str)
{
    // make a vector with the prototype of empty plane
    std::vector < PlaneSeat > seats(n * number_of_seat_in_a_row);

    // initialize the seats and rows with the correct values
    int row = 1;
    char seatLetter = 'A';
    for ( int i = 0 ; i < seats.size(); ++ i)
    {
        if ( i != 0 && i % number_of_seat_in_a_row == 0)
        {
            ++row;
            seatLetter = 'A';
        }
        seats.at(i).numberOfRow = row;
        seats.at(i).numberOfSeat = seatLetter;
        ++seatLetter;
    }

    // find the taken seats from the passed input
    for ( int i = 0, j = 1; i < str.size() -1 && j < str.size(); i+=3, j+=3)
    {
        for ( int k = 0; k < seats.size(); ++k)
        {
            int numOfRow = str.at(i) - '0';

            if ( numOfRow == seats.at(k).numberOfRow
                    && seats.at(k).numberOfSeat == str.at(j) )
            {
                seats.at(k).taken = true;
            }
        }
    }

    // find if we can have a family on the row
    int families = 0;
    int four = 0;

    for ( int j = 0; j < n; ++j)
    {
        for ( int i = 1; i < number_of_seat_in_a_row - 1; ++i)
        {
            if ( four == 4)
            {
                ++families;
            }
            
            if ( !seats.at(i).taken)
            {
                ++four;
            }
            else 
            {
                four = 0;
            }
        }
    }

    return families;
}