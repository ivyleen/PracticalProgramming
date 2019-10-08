#include <iostream>
#include <stdio.h>
#include <string>
#include <limits>
#include <math.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

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
    int number1, number2;
    CheckIfValid(number1);
    CheckIfValid(number2);

    cout << "First tehniques:" << endl;
    cout << " Before swapping " << endl
         << "  number 1: " << number1 << endl
         << "  number2: " << number2 << "." << endl;

    number1 = number1 + number2;
    number2 = number1 - number2;
    number1 = number1 - number2;

    cout << " After swapping " << endl
         << "  number 1: " << number1 << endl
         << "  number2: " << number2 << "." << endl;

    cout << "Second tehniques:" << endl;
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

    return 0;
}