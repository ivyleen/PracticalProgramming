#include "ex1.h"
#include "ex2.h"
#include "Ex3/ex3.h"

void CalculateAvarageValueOfArray()
{
    int size;
    float sum = 0.0, avarage;

    CheckIfValidSizeOfArray(size);

    // using vector 
    // we know the exact size the vector needs to be
    // so we specify it in the constructor
    // in that way there is no need of relocation 
    vector<int> v_Array(size);

    cout << "Enter the elements of the array:" << endl; 
    for (int i = 0; i < size; ++i)
    {
        cout << i+1 << "#: " ;
        cin >> v_Array.at(i);
        sum += v_Array.at(i);
    }

    PrintVector(v_Array);

    avarage = sum / size;
    cout << "Avarage value of the array is: " << avarage << endl;
}

void LargestNumberInArray()
{
    int size;
    float sum = 0.0, avarage, largest = std::numeric_limits<float>::min();

    CheckIfValidSizeOfArray(size);

    // we specify the size in the constructor
    vector<int> v_Array(size);

    cout << "Enter the elements of the array:" << endl; 
    for (int i = 0; i < v_Array.size(); ++i)
    {
        cout << i+1 << "#: " ;
        cin >> v_Array.at(i);

        if(largest < v_Array.at(i))
        {
            largest = v_Array.at(i);
        }
    }

    PrintVector(v_Array);
    cout << "Max number is: " << largest << endl;
}

void AddTwoMultiDimensionalArrays()
{
    int sizeFirstI, sizeFirstJ, sizeSecondI, sizeSecondJ;
    CheckIfValidSizeOfArray(sizeFirstI);
    CheckIfValidSizeOfArray(sizeFirstJ);
    CheckIfValidSizeOfArray(sizeSecondI);
    CheckIfValidSizeOfArray(sizeSecondJ);

    cout << "Enter the elements of the first array:" << endl;
    for ( int i = 0; i < sizeFirstI; ++i)
    {
        for ( int j = 0; j < sizeFirstJ; ++i)
        {
            // TODO
        }
    }
}

void ChooseExampleWithArrays(int number)
{

    switch (number)
    {
    case 1:
        {
            std::cout << std::endl << "Ex1 begins here." << std::endl;
            std::cout << "Fist try" << std::endl;
            vector<int> gross = {1234,4363,1493, 654, 24523};
            Ex1 paytable;
            paytable.SetBaseCommission(200);
            paytable.SetPercentOfGross(9);
            paytable.SetGrosses(gross);
            std::cout << "We set the correct values." << std::endl;
            paytable.CountHowManyPeople();
            std::cout << std::endl << "Second try" << std::endl;
            Ex1 paytable2(300, 10, gross);
            std::cout << "Ex1 ends here."<< std::endl;
        }
        break;
    case 2:
        {
            std::cout << std::endl << "Ex2 begins here." << std::endl;
            Ex2 SecondEx;
            std::cout << "Ex2 ends here."<< std::endl;
        }
        break;
    case 3:
        {
            std::cout << std::endl << "Ex3 begins here." << std::endl;
            std::cout << "Ex3 ends here."<< std::endl;
        }
        break;
    default:
        cout << "There isn't such example." << endl;
        break;
    }
}