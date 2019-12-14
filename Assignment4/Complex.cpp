/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 4
   PROGRAMMER: Aleksandar Kljaic + Philip Boffa
   LOGON ID:   z1815736 & z1831680
   DUE DATE:   Thursday October 19, 2017

   FUNCTION:   This program tests the functionality of the Complex
               class.
*********************************************************************/

#include "Complex.h"

// Constructors
Complex::Complex(double realNum, double imagNum)
{
    realComplexNumber = realNum;
    imaginaryComplexNumber = imagNum;
}

// This method takes two double variables as arguments, representing the real and imaginary parts of a complex number.
void Complex::setComplex(double realNum, double imagNum)
{
    realComplexNumber = realNum;
    imaginaryComplexNumber = imagNum;
}


// This method takes two references to double variables as arguments, representing the real and imaginary parts of a complex number.
void Complex::getComplex(double& realNum, double& imagNum) const
{
    realNum = realComplexNumber;
    imagNum = imaginaryComplexNumber;
}


// Assign the method parameter to the real part data member of the object that called the method.
void Complex::setRealPart(double value) // A double, representing the real part of a complex number.
{
    realComplexNumber = value;
}

// Return the data member representing the real part of the complex number.
// This method does not alter any data members of the object that called the method, so it should be declared const.
double Complex::getRealPart() const
{
    return realComplexNumber;
}

// Assign the method parameter to the imaginary part data member of the object that called the method.
void Complex::setImaginaryPart(double value) // A double, representing the imaginary part of a complex number.
{
    imaginaryComplexNumber = value;
}

// This method does not alter any data members of the object that called the method, so it should be declared const.
double Complex::getImaginaryPart() const
{
    return imaginaryComplexNumber; // Return the data member representing the imaginary part of the complex number.
}

// Declare a Complex object to hold the result of the arithmetic. You will need to set the real part and the imaginary
// part of this result object to the correct values, as outlined in the ordered pair version of the addition rule shown
// at the beginning of the assignment sheet. For example, the real part of the result object should be set to the sum of
// the real part of the left operand (which corresponds to the variable a in the rule) and the real part of the right
// operand (which corresponds to the variable c in the rule). Once you've done the arithmetic, return the result object.
Complex Complex::operator+(const Complex & rhs) const
{
    Complex result;

    result.realComplexNumber = realComplexNumber + rhs.realComplexNumber;
    result.imaginaryComplexNumber = imaginaryComplexNumber + rhs.imaginaryComplexNumber;

    return result; // Returns: A Complex object that holds the result of the arithmetic.
}

// Declare a Complex object to hold the result of the arithmetic. You will need to set the real part and the imaginary
// part of this result object to the correct values, as outlined in the ordered pair version of the multiplication rule
// shown at the beginning of the assignment sheet. Once you've done the arithmetic, return the result object.
Complex Complex::operator*(const Complex & rhs) const
{

    Complex result;

    result.realComplexNumber = (realComplexNumber * rhs.realComplexNumber) - (imaginaryComplexNumber * rhs.imaginaryComplexNumber);
    result.imaginaryComplexNumber = (realComplexNumber * rhs.imaginaryComplexNumber) + (imaginaryComplexNumber * rhs.realComplexNumber);

    return result;
}

// The method should return true if the real part of the left operand equals the real part of the right operand AND the
// imaginary part of the left operand equals the imaginary part of the right operand. Otherwise, the method should return false.
bool Complex::operator==(const Complex & rhs) const
{
    return realComplexNumber == rhs.realComplexNumber &&
            imaginaryComplexNumber == rhs.imaginaryComplexNumber; // Returns: A boolean value.
}

// Declares the overloaded operator function operator<<() to be a friend of class Complex
std::ostream& operator<<(std::ostream& stream, const Complex& value)
{
    stream << '(' << value.realComplexNumber << ", " << value.imaginaryComplexNumber << ")"; // lhs is the reference to an ostream object
    // passed into the method as the 1st parameter
    return stream; //unsure
}

std::istream& operator>>(std::istream& stream, Complex& value)
{
    // lhs the reference to an istream object
    // passed into the method as the 1st parameter

    char ch;
    stream >> ch; // (
    stream >> value.realComplexNumber; // realComplexNumber
    stream >> ch; // ,
    stream >> value.imaginaryComplexNumber; // imaginaryComplexNumber
   // stream >> ch; // )

    return stream;

}

