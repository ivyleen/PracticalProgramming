#include <iostream>
#include <stdio.h>
#include <string>
#include <limits>
#include <cmath>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;

template <typename type>
void CheckIfValid(type& number)
{
    // according to the type we check if the input is valid 
    while (cout << "Enter an input: " && !(cin >> number) || cin.peek() != '\n')
    {
        cout << "That's not valid input. Try again" << endl;
        // clear and ignore the unvalid input
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void HelloWorld()
{
    cout << "Hello World!" << endl;
}

void PrintInputNumber()
{ 
    cout << "PrintInputNumber" << endl;

    double number;
    CheckIfValid(number);

    cout << "The number you've entered is : " << number << endl;
}

void PrintSumOfTwoInputNumbers()
{
    cout << "PrintSumOfTwoInputNumbers" << endl;

    double number1, number2;
    CheckIfValid(number1);
    CheckIfValid(number2);

    cout << "The sum of the numbers you've entered is : " << 
            (number1 + number2) << endl;
}

void PrintTwoMultipliedInputNumber()
{
    cout << "PrintTwoMultipliedInputNumber" << endl;

    double number1, number2;
    CheckIfValid(number1);
    CheckIfValid(number2);

    printf("The multiplied result of the numbers you've "
            "entered is : %.2f \n" , (number1 * number2));
}

void PrintASCIINumberOfAnInputSymbol()
{
    cout << "PrintASCIINumberOfAnInputSymbol" << endl;

    char symbol;
    CheckIfValid(symbol);

    cout << " You've entered " << symbol << " as a symbol."
            " This is it's ASCII numeric value: " << (int)symbol 
            << endl;
}

void PrintQuotientAndReminder()
{
    cout << "PrintQuotientAndReminder" << endl;

    double dividend, divisor, reminder;
    int quotient;

    CheckIfValid(dividend);
    CheckIfValid(divisor);

    quotient = dividend / divisor;
    reminder = fmod(dividend, divisor);

    cout << "Quotient: " << quotient << endl;
    cout << "Reminder: " << reminder << endl;
}

void PrintSizesOfDataTypes()
{
    cout << "Size of char: " << sizeof(char) << endl;
    cout << "Size of bool: " << sizeof(bool) << endl;
    cout << "Size of short: " << sizeof(short) << endl;
    cout << "Size of int: " << sizeof(int) << endl;
    cout << "Size of wide char: " << sizeof(wchar_t) << endl;
    cout << "Size of float: " << sizeof(float) << endl;
    cout << "Size of double: " << sizeof(double) << endl;
    cout << "Size of long: " << sizeof(long) << endl;
    cout << "Size of long long: " << sizeof(long long) << endl;
    cout << "Size of long double: " << sizeof(long double) << endl;

}

void SwapTwoNumbers()
{
    cout << "SwapTwoNumbers" << endl;

    int number1, number2;
    CheckIfValid(number1);
    CheckIfValid(number2);

    cout << "First tehniques: without additional variable" << endl;
    cout << " Before swapping " << endl
         << "  number 1: " << number1 << endl
         << "  number2: " << number2 << "." << endl;

    number1 = number1 + number2;
    number2 = number1 - number2;
    number1 = number1 - number2;

    cout << " After swapping " << endl
         << "  number 1: " << number1 << endl
         << "  number2: " << number2 << "." << endl;

    cout << "Second tehniques: with additional variable" << endl;
    cout << " Before swapping " << endl 
         << "  number 1: " << number1 << endl
         << "  number2: " << number2 << "." << endl;

    int temp;
    temp = number1;
    number1 = number2;
    number2 = temp;

    cout << " After swapping" << endl
         << "  number 1: " << number1 << endl
         << "  number2: " << number2 << "." << endl;

    cout << "Third tehniques: with STL" << endl;
    cout << " Before swapping " << endl 
         << "  number 1: " << number1 << endl
         << "  number2: " << number2 << "." << endl;

    std::swap(number1,number2);

    cout << " After swapping" << endl
         << "  number 1: " << number1 << endl
         << "  number2: " << number2 << "." << endl;
}

void IsNumberEven()
{
    cout << "IsNumberEven" << endl;

    double number;
    CheckIfValid(number);

    // check if there is any reminder when we divide the number by 2
    if ( fmod(number,2) == 0)
        cout << "The number you've entered is even. " << endl;
    else 
        cout << "The number you've entered is odd." << endl;
}

void IsCharacterAVowel()
{
    cout << "CheckIfCharacterIsVowel" << endl;

    char character;
    CheckIfValid(character);

    if ( character == 'a' || character == 'A' ||
         character == 'e' || character == 'E' ||
         character == 'u' || character == 'U' ||
         character == 'i' || character == 'I' ||
         character == 'o' || character == 'O'    
        ) 
    {
        cout << "The character is vowel." << endl;
    }
    else
    {
        cout << "The character is not a vowel." << endl;
    }
}

void BiggerOfThreeNumbers()
{
    cout << "CheckBiggerOfThreeNumbers" << endl;

    double number1, number2, number3, max;
    CheckIfValid(number1);
    CheckIfValid(number2);
    CheckIfValid(number3);

    if(number1 >= number2 && number1 >= number3)
    {
        max = number1;
    }

    if(number2 >= number1 && number2 >= number3)
    {
        max = number2;
    }

    if(number3 >= number1 && number3 >= number2)
    {
        max = number3;
    }

    cout << "The bigger number of the three is: " << max << endl;

}

void SolveTheQuadraticEquation()
{
    cout << "SolveTheQuadraticEquation" << endl;

    double a, b, c, determinant, root1, root2, realPart, imaginaryPart;
    CheckIfValid(a);
    CheckIfValid(b);
    CheckIfValid(c);

    determinant = b*b-4*a*c;

    if( determinant > 0)
    {
        root1 = (-b + sqrt(determinant) ) / (2*a);
        root2 = (-b - sqrt(determinant) ) / (2*a);

        cout << "root 1: " << root1 << endl <<
                "root 2: " << root2 << endl;
    }
    else if(determinant == 0)
    {
        root1 = root2 = -b / (2*a);
        cout << "root1 == root2 == " << root1 << endl;
    }
    else
    {
        realPart = -b / (2*a);
        imaginaryPart = sqrt(-determinant) / (2*a);

        cout << "The equation doesn't have real roots." << endl;
        cout << "root 1: " << realPart << "+" << imaginaryPart << "i" << endl <<
                "root 2: " << realPart << "-" << imaginaryPart << "i" << endl ;
    }
    
}

void IsLeapYear()
{
    cout << " IsLeapYear " << endl;

    int year;
    CheckIfValid(year);

    if ( (year % 4) == 0)
    {
        if ( (year % 100) == 0)
        {
            if ( (year % 400) == 0)
            {
                cout << "The year " << year << " is a leap year." << endl;
            }
            else
            {
                cout << "The year " << year << " is not a leap year." << endl;
            }
        }
        else 
        {
            cout << "The year " << year << " is a leap year." << endl;
        }
    }
    else 
    {
        cout << "The year " << year << " is not a leap year." << endl;
    }
}

void IsPositive()
{
    cout << "IsPositive" << endl;

    double number;
    CheckIfValid(number);

    if (number > 0)
    {
        cout << "The number " << number << " is positive." << endl;
    }
    else if (number < 0)
    {
        cout << "The number " << number << " is negative." << endl;
    }
    else 
    {
        cout << "The number " << number << " is zeroE." << endl;   
    }
}

void PrintSumOfInputIterationCount()
{
    cout << "PrintSumOfInputIterationCount" << endl;
    
    int count, sum = 0;
    do
    {
        CheckIfValid(count);
    } while (count <= 0);
    
    for (int i = 1; i <= count; i++)
    {
        sum += i;
    }

    cout << "The sum is: " << sum << endl;
}

void PrintCountOfIterationsUntilRandomNumberIsEqualToInputNumber()
{
    cout << "PrintSumOfInputIterationCount" << endl;
    
    int randomNumber, input, count = 0;
    do
    {
        CheckIfValid(input);
    } while (input <= 0);
    
    while ( randomNumber != input)
    {
        randomNumber = 1 + rand() % RAND_MAX;
        count++;
    }

    cout << "The count is: " << count << endl;
}

void IsInputCharacterInEnglishAlphabet()
{
    cout << "IsInputCharacterInEnglishAlphabet" << endl;

    char character;
    CheckIfValid(character);

    if ( (character >= 'a' && character <= 'z') 
          || (character >= 'A' && character <= 'Z') )

    {
        cout << "The character " << character << " is in alphabet." << endl;
    }
    else
    {
        cout << "The character " << character << " is not in alphabet." << endl;
    }
    
}

void CalculateFactorialOfInputNumber()
{
    cout << "CalculateFactorialOfInputNumber" << endl;
    
    int number;
    do
    {
        CheckIfValid(number);
    } while (number <= 0);

    unsigned long factorial = 1;
    for ( int i = 1; i <= number; ++i)
    {
        factorial *= i;
    }
    
    cout << "Factorial of number " << number << 
            " is " << factorial << endl;
}

void PrintTableOfMultiplicationOfInputNumber()
{
    cout << "PrintTableOfMultiplicationOfInputNumber" << endl;
    
    int number;
    do
    {
        CheckIfValid(number);
    } while (number < 0);

    for (int i = 1; i <= 10; ++i)
    {
        cout <<  number << " * " << setw(2) << i << " = " 
             << setw(2) << (number * i) << endl;
    }
}

void PrintFibonacciNumbers()
{
    cout << "PrintFibonacciNumbers" << endl;

    int term1 = 0, term2 = 1, nextTerm = 0, countOfTerms;
    CheckIfValid(countOfTerms);

    cout << "Fibonacci numbers : " << endl;
    for ( int i = 1; i <= countOfTerms; ++i)
    {
        string commaOrDot = ", ";
        if( i == countOfTerms) commaOrDot = ".";

        if ( i == 1) 
        {   
            cout << term1 << commaOrDot; 
            continue;
        }

        if ( i == 2) 
        {
            cout << term2 << commaOrDot; 
            continue;
        }

        nextTerm = term1 + term2;
        term1 = term2;
        term2 = nextTerm;

        cout << nextTerm << commaOrDot;
    }

    cout << endl;
}

void GreatestCommonDivisor()
{
    cout << "Greatest common divisor" << endl;

    int number1, number2;
    CheckIfValid(number1);
    CheckIfValid(number2);

    number1 = (number1 > 0) ? number1 : -number1;
    number2 = (number2 > 0) ? number2 : -number2;

    while ( number1 != number2)
    {
        if( number1 > number2) number1 -= number2;
        if( number2 > number1) number2 -= number1;
    }

    cout << "GCD = " << number1 << endl;
    
}

int main ()
{
    // basics
    //HelloWorld();
    //PrintInputNumber();
    //PrintSumOfTwoInputNumbers();
    //PrintTwoMultipliedInputNumber();
    //PrintASCIINumberOfAnInputSymbol();
    //PrintQuotientAndReminder();
    //PrintSizesOfDataTypes();
    //SwapTwoNumbers();

    // control flow statements
    //IsNumberEven();
    //IsCharacterAVowel();
    //BiggerOfThreeNumbers();
    //SolveTheQuadraticEquation();
    //IsLeapYear();
    //IsPositive();
    //PrintSumOfInputIterationCount();
    //PrintCountOfIterationsUntilRandomNumberIsEqualToInputNumber();
    //IsInputCharacterInEnglishAlphabet();
    //CalculateFactorialOfInputNumber();
    //PrintTableOfMultiplicationOfInputNumber();
    //PrintFibonacciNumbers();
    GreatestCommonDivisor();

    return 0;
};