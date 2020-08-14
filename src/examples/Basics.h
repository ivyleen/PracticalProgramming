#pragma once
#include <iostream>
#include "../include/InputOutputChecks.h"

using std::cout;
using std::endl;


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

    cout << "First techniques: without additional variable" << endl;
    cout << " Before swapping " << endl
         << "  number 1: " << number1 << endl
         << "  number2: " << number2 << "." << endl;

    number1 = number1 + number2;
    number2 = number1 - number2;
    number1 = number1 - number2;

    cout << " After swapping " << endl
         << "  number 1: " << number1 << endl
         << "  number2: " << number2 << "." << endl;

    cout << "Second techniques: with additional variable" << endl;
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

    cout << "Third techniques: with STL" << endl;
    cout << " Before swapping " << endl 
         << "  number 1: " << number1 << endl
         << "  number2: " << number2 << "." << endl;

    std::swap(number1,number2);

    cout << " After swapping" << endl
         << "  number 1: " << number1 << endl
         << "  number2: " << number2 << "." << endl;
}


void SwapNumbersInCycleOrder()
{
    int a, b, c, temp, a1, b1, c1;
    CheckIfValid(a);
    CheckIfValid(b);
    CheckIfValid(c);

    cout << "Before: " << a << ", " << b << ", " << c << "." << endl;

    cout << "First techniques: last becomes first:" << endl;
    a1=a; b1=b; c1=c;

    temp = b1;
    b1 = a1;
    a1 = c1;
    c1 = temp;
    cout << "After: " << a1 << ", " << b1 << ", " << c1 << "." << endl;    

    cout << "Second techniques: first becomes last:" << endl;
    temp = a;
    a = b;
    b = c;
    c = temp;

    cout << "After: " << a << ", " << b << ", " << c << "." << endl;    
}
