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
        CheckIfValidInputForArrayElement( v_Array.at(i) );
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
        CheckIfValidInputForArrayElement(v_Array.at(i));

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
    int rows, colums;
    cout << " Rows :" << endl;
    CheckIfValidSizeOfArray(rows);
    cout << " Colums :" << endl;
    CheckIfValidSizeOfArray(colums);

    // initialize three vectors with that many rows and colums
    vector< vector<int> > v_array1(rows, vector<int> (colums, 0) );
    vector< vector<int> > v_array2(rows, vector<int> (colums, 0) );
    vector< vector<int> > v_Sum(rows, vector<int> (colums, 0) );

    cout << "Enter the elements of the first array:" << endl;
    for ( int i = 0; i < v_array1.size(); ++i)
    {
        for ( int j = 0; j < v_array1.at(i).size(); ++j)
        {
            cout << i+1 << " - " << j+1 << "#: " << endl;
            CheckIfValidInputForArrayElement(v_array1.at(i).at(j));
        }
    }

    cout << "Enter the elements of the second array:" << endl;
    for ( int i = 0; i < v_array2.size(); ++i)
    {
        for ( int j = 0; j < v_array2.at(i).size(); ++j)
        {
            cout << i+1 << " - " << j+1 << "#: " << endl;
            CheckIfValidInputForArrayElement(v_array2.at(i).at(j));
        }
    }

    PrintMultidimensionalVector(v_array1);
    PrintMultidimensionalVector(v_array2);

        for ( int i = 0; i < v_array2.size(); ++i)
    {
        for ( int j = 0; j < v_array2.at(i).size(); ++j)
        {
            v_Sum.at(i).at(j) = v_array1.at(i).at(j) + v_array2.at(i).at(j);
        }
    }

    cout << "The sum of the elements of the two multidimensional arrays:" << endl;
    PrintMultidimensionalVector(v_Sum);
}

void Multiply2DimensionalArrays()
{
    //To multiply two matrices, the number of columns of first 
    //matrix should be equal to the number of rows to second matrix
    int rowCountFirst, columCountFirst, rowCountSecond, columCountSecond;

    do
    {
        cout << "REMINDER!: the colum count of the first matrix \n"
                " must be equal to the row count of the second matrix.\n"
                "Please, enter a number between 1 and 10." << endl;
        cout << "Enter row and colum count [matrix 1]: " << endl;
        CheckIfValidSizeOfArray(rowCountFirst);
        CheckIfValidSizeOfArray(columCountFirst);
        cout << "Enter row and colum count [matrix 2]: " << endl;
        CheckIfValidSizeOfArray(rowCountSecond);
        CheckIfValidSizeOfArray(columCountSecond);
    } while (columCountFirst != rowCountSecond ||
            ( rowCountFirst > 10 &&
            columCountFirst > 10 &&
            rowCountSecond > 10 &&
            columCountSecond >10) );

    // this example will be with static array
    int firstArray[10][10], secondArray[10][10], resultArray[10][10];

    cout << "Enter the elements of the first Array." << endl;
    for ( int i = 0; i < rowCountFirst; ++i)
    {
        for ( int j = 0; j < columCountFirst; ++j)
        {
            cout << i+1 << " - " << j+1 << "#: ";
            CheckIfValidInputForArrayElement(firstArray[i][j]);
        }
    }

    cout << "Enter the elements of the second Array." << endl;
    for ( int i = 0; i < rowCountFirst; ++i)
    {
        for ( int j = 0; j < columCountFirst; ++j)
        {
            cout << i+1 << " - " << j+1 << "#: ";
            CheckIfValidInputForArrayElement(secondArray[i][j]);
        }
    }

    // set default value for the elements of the result array
    for ( int i = 0; i < rowCountFirst; ++i)
    {
        for ( int j = 0; j < columCountSecond; ++j)
        {
                resultArray[i][j] = 0;
        }
    }

    // multiply the two arrays
    // we multiply every posible combination of 
    // the rows of first array * colums of the second array
    for ( int i = 0; i < rowCountFirst; ++i)
    {
        for ( int j = 0; j < columCountSecond; ++j)
        {
            for ( int k = 0; k < columCountFirst; ++k)
            {
                resultArray[i][j] += firstArray[i][k] * secondArray[k][j];
#ifdef DEBUG
                cout << i << "/" << j << "=" << resultArray[i][j] << 
                    "   (k = " << k << ")" << endl;
#endif
            }
        }
    }

    cout << "The result matrix is:" << endl;
    for ( int i = 0; i < rowCountFirst; ++i)
    {
        for ( int j = 0; j < columCountSecond; ++j)
        {
            cout << resultArray[i][j] << " ";
        }
        cout << endl;
    }
}

void MakeTransposeArray()
{
    // transpose array is array with swaped rows and colums
    int rowCount, columCount;
    do 
    {
        cout << "Enter row and colum count: " << endl;
        CheckIfValidSizeOfArray(rowCount);
        CheckIfValidSizeOfArray(columCount);
    } while ( rowCount > 10 && columCount > 10);

    //we use the STD array 
    // and make every element zero
    array< array <int, 10>, 10 > arr {};
    array< array <int, 10>, 10 > tranposeArr{};

    cout << "Enter elements of the array:" << endl;
    for (int i = 0 ; i < rowCount; ++i)
    {
        for ( int j = 0 ; j < columCount; ++j)
        {
            cout << i+1 << "/" << j+1 << "#: ";
            CheckIfValidInputForArrayElement(arr.at(i).at(j));
        }
    }

    cout << "Before : " << endl;
    for (int i = 0; i < rowCount; ++i)
    {
        cout << arr.at(i);
        cout << endl;
    }

    for ( int i = 0 ; i < rowCount; ++i)
    {
        for ( int j = 0; j < columCount; ++j)
        {
            tranposeArr.at(i).at(j) = arr.at(j).at(i);
        }
    }

    cout << "After :" << endl;
    for (int i = 0; i < rowCount; ++i)
    {
        cout << tranposeArr.at(i);
        cout << endl;
    }

    // TODO : make printing to what we need not the whole array
}

void AccessingValueOfArrayWithPointers()
{
    //working with static arrays
    int data[5] = {0};
    printf("Enter 5 items: ");
    
    for(int i = 0; i < 5; ++i)
    {
        scanf("%d", data + i );
    }

    printf("Array: ");
    for(int i = 0 ; i < 5; ++i)
    {
        printf("%d ", *(data + i));
    }
}

void FindBiggestNumberInDynamicMemory()
{
    int size;
    CheckIfValidSizeOfArray(size);

    // making unique_ptr to array with size 'size'
    unique_ptr<float []> data =  make_unique<float[]> (size);

    cout << "Enter elements:" << endl;
    for ( int i = 0; i < size ; ++i)
    {
        cout << i + 1 << "#: " ;
        CheckIfValidInputForArrayElement(data[i]);
    }

    float max = data[0];

    for ( int i = 0; i < size; ++i)
    {
        if (max < data[i])
        {
            max = data[i];
        }
    }

    cout << "The biggest number is: " << max << endl;
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