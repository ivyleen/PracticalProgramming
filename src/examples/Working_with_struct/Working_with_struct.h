#pragma once

#include "StructDefinitions.h"


void InputStudentInfo()
{
    Student student;

    cout << "Enter info:" << endl;
    cout << "Name: " << endl;
    CheckIfValid(student.name);

    cout << "Group: " << endl;
    CheckIfValid(student.group);

    cout << "Ticket: " << endl;
    CheckIfValid(student.ticket);

    cout << "Displaying info" << endl
         << "Name: " << student.name << endl
         << "Ticket: " << student.ticket << endl
         << "Group: " << student.group << endl;
}

void AddTwoComplexNumbers()
{
    ComplexNumbers<float> first, second, result;

    cout << "Enter first complex number:" << endl;
    CheckIfValidComplexNumber(first);

    cout << "Enter second complex number:" << endl;
    CheckIfValidComplexNumber(second);

    result = first + second;

    cout << result << endl;
}