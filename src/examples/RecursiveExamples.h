#pragma once
#include "../include/InputOutputChecks.h"


int AddNumbersResursively(int n)
{
    if( n != 0)
    {
        return n + AddNumbersResursively(n -1);
    }
    else 
    {
        return n;
    }
}

void PrintSumOfNRealNumbers()
{
    cout << "PrintSumOfNRealNumbers()" << endl;

    int n;
    do
    {
        CheckIfValid(n);
    } while ( n < 0);

    cout << "The sum is: " << AddNumbersResursively(n) << endl;
}

long int factorial( int number)
{
    if ( number >=1)
    {
        return number*factorial(number - 1);
    }
    else 
    {
        return 1;
    }
}

void CalculateFactorial()
{
    cout << "CalculateFactorial" << endl;

    int number;
    do{
        CheckIfValid(number);
    } while ( number < 0);

    cout << "The factorial of " << number << " is: " << factorial(number) << endl;
}

int gcd( int number1, int number2)
{
    if ( number2 != 0)
    {
        return gcd( number2, number1%number2);
    }
    else 
    {
        return number1;
    }
}

void CalculateGCD()
{
    cout << "CalculateGCD" << endl;

    int number1, number2;
    do {
        cout << "Please enter only positive numbers " << endl;
        CheckIfValid(number1);
        CheckIfValid(number2);
    } while ( number1 < 0 || number2 < 0);
 
    cout << "GCD of " << number1 << " and " << number2 << " is: " 
         << gcd( number1, number2) << endl;
}

void ReverseSentence()
{
    char c;
    scanf("%c", &c);

    if(c != '\n')
    {
        ReverseSentence();
        cout << c ;
    }
}