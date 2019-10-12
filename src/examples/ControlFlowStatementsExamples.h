#pragma once
#include "../include/IncludeLibraries.h"
#include "../include/InputOutputChecks.h"

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

void LeastCommonMultiple()
{
    cout << "Least common multiple" << endl;

    int number1, number2, lcm;
    CheckIfValid(number1);
    CheckIfValid(number2);

    lcm = (number1 > number2) ? number1 : number2;

    // using infinite loop
    while (true)
    {
        if ( lcm % number1 == 0 && 
             lcm % number2 == 0 
           )
        {
            cout << "LCM = " << lcm << endl;
            break;
        }

        ++lcm;
    }
}

void CountTheNumberOfDigits()
{
    cout << "CountTheNumberOfDigits" << endl;

    int count = 0;
    long number;
    CheckIfValid(number);

    cout << "First techniques" << endl;
    long temp = number;
    while ( temp != 0)
    {
        temp /= 10;
        ++count;
    }

    cout << "The count is: " << count << endl;

    cout << "Second techniques" << endl;
    number = (number > 0) ? number : -number;
    count = to_string(number).length();

    cout << "The count is: " << count << endl;
}

void ReverseNumber()
{
    cout << "ReverseNumber" << endl;
    int number, reversedNumber = 0, remainder;
    CheckIfValid(number);

    cout << "First techniques" << endl;
    int temp = number;
    while (temp != 0 )
    {
        remainder = temp%10;
        reversedNumber = reversedNumber*10 + remainder;
        temp/=10;
    }
    cout << "The reversed number is: " << reversedNumber << endl;

    cout << "Second techniques" << endl;
    string sNumber = to_string(number);
    reverse(sNumber.begin(), sNumber.end());
    cout << "The reversed number is: " << sNumber << endl;
}

void IsPalindrome()
{
    string original, reversed;
    CheckIfValid(original);

    reversed = original;
    reverse(reversed.begin(), reversed.end());

    if ( original == reversed)
    {
        cout << original << " is a palidrome." << endl;
    }
    else
    {
        cout << original << " is NOT a palidrome." << endl;
    }
}

void IsPrime()
{
    int number;
    CheckIfValid(number);

    // using flag to monitor the result
    bool isPrime = true;

    for ( int i = 2; i <= number / 2 ; ++i)
    {
        if ( number % i == 0)
        {
            isPrime = false;
            break;
        }
    }

    if (isPrime)
    {
        cout << number << " is prime." << endl;
    }
    else 
    {
        cout << number << " is NOT prime." << endl;
    }
}

bool IsPrime(int number)
{
    // using flag to monitor the result
    bool isPrime = true;

    for ( int i = 2; i <= number / 2 ; ++i)
    {
        if ( number % i == 0)
        {
            isPrime = false;
            break;
        }
    }

    return isPrime;
}

void PrintPrimeNumbersInInterval()
{
    cout << "PrintPrimeNumbersInInterval" << endl;

    int low, high;
    bool isPrime = true;
    CheckIfValid(low);
    CheckIfValid(high);

    //check if low is really lower than high
    if (low == high) 
    {   
        cout << "There is no interval." << endl; 
        return;
    } else if ( low > high) 
    {
        int temp = low;
        low = high;
        high = temp;
    }

    cout<< "Prime numbers in the interval are:" << endl;
    while ( low <= high)
    {
        for ( int i = 2; i <= low / 2 ; ++i)
        {
            isPrime = true;
            if ( low % i == 0)
            {
                isPrime = false;
                break;
            }
        }

        if (isPrime) cout << low << ", ";
        ++low;
    }

    cout << endl;
}

void IsArmstrongNumber()
{
    cout << "IsArmstrongNumber" << endl;

    int number, originalNumber, remainder, count = 0, result = 0;
    CheckIfValid(originalNumber);

    number = originalNumber;
    
    // determine the count of digits
    while ( number != 0)
    {
        number /= 10;
        ++count;
    }

    number = originalNumber;
    // multiply the digits by the count of the digits
    while ( number != 0)
    {
        remainder = number % 10;
        result += pow(remainder, count);
        number /= 10;
    }

    if ( result == originalNumber)
    {
        cout << "The number is an Armstrong number." << endl;
    } else
    {
        cout << "The number is NOT an Armstrong number." << endl;
    }
    
}

void PrintArmstrongNumbersInInputInterval()
{
    cout << "PrintArmstrongNumbersInInputInterval" << endl;

    int low, originalNumberLow, high, remainder, count = 0, result = 0;
    CheckIfValid(originalNumberLow);
    CheckIfValid(high);

    //check if low is really lower than high
    if (originalNumberLow == high) 
    {   
        cout << "There is no interval." << endl; 
        return;
    } else if ( originalNumberLow > high) 
    {
        int temp = originalNumberLow;
        originalNumberLow = high;
        high = temp;
    }

    for ( int i = originalNumberLow; i <=high; ++i )
    {
        count = 0;
        result = 0;

        low = i;
        while ( low != 0)
        {
            low /= 10;
            ++count;
        }

        low = i;
        while( low != 0)
        {
            remainder = low % 10;
            result += pow(remainder, count);
            low /= 10;
        }

        if ( result == i) cout << i << ", ";
    }

    cout << endl;
}

void CreateStarPyramid()
{
    cout << "Create star pyramid" << endl;

    int rows;
    do 
    {
        CheckIfValid(rows);
    } while ( rows < 0);

    for (int i = 0; i <= rows; ++i)
    {
        for (int j = 0; j <=i; ++j )
        {
            cout << "* ";
        }
        
        cout << endl;
    }
}

void SimpleCalculator()
{
    char ourOperator;
    double number1, number2;
    do
    {
        cout << "Enter a valid operator." << endl;
        CheckIfValid(ourOperator);
    } while (ourOperator != '+' &&
             ourOperator != '-' &&
             ourOperator != '*' &&
             ourOperator != '/');

    cout << "Now enter the numbers." << endl;
    CheckIfValid(number1);
    CheckIfValid(number2);

    switch (ourOperator)
    {
    case '+':
        cout << number1 << " + " << number2 << " = " << (number1 + number2) << endl;
        break;
    case '-':
        cout << number1 << " - " << number2 << " = " << (number1 - number2) << endl;
        break;
    case '*':
        cout << number1 << " * " << number2 << " = " << (number1 * number2) << endl;
        break;
    case '/':
        cout << number1 << " / " << number2 << " = " << (number1 / number2) << endl;
        break;
    default:
        cout << "Invalid operator." << endl;
        break;
    }
}

void CanANumberBeRepresentedBySumOfTwoPrimeNumber()
{
    int number;
    bool canBeRepresented = false;
    CheckIfValid(number);

    // print every posible representation of the number
    for ( int i = 2; i <= number /2; ++i)
    {
        if (IsPrime(i))
        {
            if (IsPrime(number - i))
            {
                canBeRepresented = true;
                cout << number << " = " << i << " + " << (number - i) << endl;
            }
        }
    }

    if(!canBeRepresented) 
        cout << "The number can NOT be represented by two prime numbers." << endl;
}