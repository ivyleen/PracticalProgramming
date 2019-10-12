#include <iostream>
#include <stdio.h>
#include <string>
#include <limits>
#include <cmath>
#include <iomanip>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::to_string;
using std::reverse;

template <typename type>
void CheckIfValid(type& number)
{
    // according to the type we check if the input is valid 
    while (cout << "Enter an input: " && !(cin >> number) || cin.peek() != '\n')
    {
        cout << "That's not valid input. Try again." << endl;
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
    //GreatestCommonDivisor();
    //LeastCommonMultiple();
    //CountTheNumberOfDigits();
    //ReverseNumber();
    //IsPalindrome();
    //IsPrime();
    //PrintPrimeNumbersInInterval();
    //IsArmstrongNumber();
    //PrintArmstrongNumbersInInputInterval();
    //CreateStarPyramid();
    //CanANumberBeRepresentedBySumOfTwoPrimeNumber();

    // function that can be made as a whole projects
    //SimpleCalculator();

    // recursive examples
    //PrintSumOfNRealNumbers();
    //CalculateFactorial();
    //CalculateGCD();
    //ReverseSentence();

    // number systems
    //BinaryToDecimal();
    //DecimalToBinary();
    //OctalToDecimal();
    //DecimalToOctal();
    //BinaryToOctal();
    //OctalToBinary();

    return 0;
};