#pragma once
#include <cmath>
#include "../include/InputOutputChecks.h"


bool CheckIfBinary( long number)
{
    while (number > 0)
    {
        int reminder = number % 10;
        if ( reminder != 0 &&
             reminder != 1)
        {
            return false;
        }

        number /=10;
        if(number == 0)
        {
            return true;
        }
    }
}

bool CheckIfOctal( long number)
{
    while (number > 0)
    {
        int reminder = number % 10;
        if ( !(reminder >= 0 &&
             reminder <= 7))
        {
            return false;
        }

        number /=10;
        if(number == 0)
        {
            return true;
        }
    }
}

void BinaryToDecimal()
{
    cout << "BinaryToDecimal" << endl;

    long number = 0;
    do
    { 
        cout << "Enter number" << endl;
        CheckIfValid(number);
        
    } while (!CheckIfBinary(number));

    int decimal = 0, remainder, i = 0;

    while (number != 0 )
    {
        remainder = number % 10;
        number /= 10;
        decimal += remainder * pow(2,i);
        ++i;
    }

    cout << "Converted decimal number is: " << decimal << endl;
    
}

void DecimalToBinary()
{
    cout << "DecimalToBinary" << endl;
    long binary = 0;
    int decimal, remainder, base = 1;
    CheckIfValid(decimal);

    while ( decimal != 0)
    {
        remainder = decimal % 2;
        decimal /= 2;
        binary += remainder * base;
        base*=10;
    }
    
    if ( CheckIfBinary (binary ))
        cout << "Converted binary number is: " << binary << endl;
}

void OctalToDecimal()
{
    cout << "OctalToDecimal" << endl;

    int octal = 0, decimal = 0, base = 0;
    do
    { 
        cout << "Enter number" << endl;
        CheckIfValid(octal);
        
    } while (!CheckIfOctal(octal));

    while (octal != 0)
    {
        decimal += (octal % 10 ) * pow(8, base);
        ++base;
        octal /= 10;
    }
    
    cout << "Converted decimal number is: " << decimal << endl;
}

void DecimalToOctal()
{
    cout << "DecimalToOctal" << endl;
    
    int decimal;
    CheckIfValid(decimal);

    int octal = 0, base = 1;

    while( decimal != 0)
    {
        octal += (decimal % 8) * base;
        decimal /= 8;
        base *= 10;
    }

    if ( CheckIfOctal(octal) )
        cout << "Converted octal number is: " << octal << endl;
}

void BinaryToOctal()
{
    cout << "BinaryToOctal" << endl;

    long binary;
    do
    {
        CheckIfValid(binary);
    } while (!CheckIfBinary(binary));
    
    int octal = 0, decimal = 0, base = 0;

    while ( binary != 0)
    {
        decimal += (binary % 10) * pow(2, base);
        ++base;
        binary /= 10;
    }

    base = 1;
    while ( decimal != 0)
    {
        octal += (decimal % 8) * base;
        decimal /= 8;
        base *= 10;
    }

    cout << "The converted octal number is: " << octal << endl;
}

void OctalToBinary()
{
    cout << "OctalToBinary" << endl;

    int octal, decimal = 0, base = 0; 
    long binary;
    do
    {
        CheckIfValid(octal);
    } while (!CheckIfOctal(octal));

    while ( octal != 0)
    {
        decimal += (octal % 10) * pow(8, base);
        ++base;
        octal /= 10;
    }

    base = 1;

    while ( decimal != 0 )
    {
        binary += (decimal % 2) * base;
        decimal /= 2;
        base *= 10;
    }

    cout << "The converted binary number is: " << binary << endl;
}
