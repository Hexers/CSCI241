#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex
{

private:
    double realComplexNumber;
    double imaginaryComplexNumber;

public:


    // Constructors
    Complex(double realNum = 0.0, double imagNum = 0.0);

    // This method takes two double variables as arguments, representing the real and imaginary parts of a complex number.
    void setComplex(double realComplexNumber, double imaginaryComplexNumber);

    // This method takes two references to double variables as arguments, representing the real and imaginary parts of a complex number.
    void getComplex(double& realComplexNumber, double& imaginaryComplexNumber) const;

    // Assign the method parameter to the real part data member of the object that called the method.
    void setRealPart(double value); // A double, representing the real part of a complex number.

    // Return the data member representing the real part of the complex number.
    // This method does not alter any data members of the object that called the method, so it should be declared const.
    double getRealPart() const;

    // Assign the method parameter to the imaginary part data member of the object that called the method.
    void setImaginaryPart(double setImaginaryComplex); // A double, representing the imaginary part of a complex number.

    // This method does not alter any data members of the object that called the method, so it should be declared const.
    double getImaginaryPart() const;


    // Declare a Complex object to hold the result of the arithmetic. You will need to set the real part and the imaginary
    // part of this result object to the correct values, as outlined in the ordered pair version of the addition rule shown
    // at the beginning of the assignment sheet. For example, the real part of the result object should be set to the sum of
    // the real part of the left operand (which corresponds to the variable a in the rule) and the real part of the right
    // operand (which corresponds to the variable c in the rule). Once you've done the arithmetic, return the result object.
    Complex operator+(const Complex & rhs) const;


    // Declare a Complex object to hold the result of the arithmetic. You will need to set the real part and the imaginary
    // part of this result object to the correct values, as outlined in the ordered pair version of the multiplication rule
    // shown at the beginning of the assignment sheet. Once you've done the arithmetic, return the result object.
    Complex operator*(const Complex & rhs) const;


    // The method should return true if the real part of the left operand equals the real part of the right operand AND the
    // imaginary part of the left operand equals the imaginary part of the right operand. Otherwise, the method should return false.


    bool operator==(const Complex & rhs) const;

    friend std::ostream& operator<<(std::ostream& stream, const Complex& value);

    friend std::istream& operator>>(std::istream& stream, Complex& value);
};




#endif // COMPLEX_H
