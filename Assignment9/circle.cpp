/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 9
   PROGRAMMER: Aleksandar Kljaic + Philip Boffa
   LOGON ID:   z1815736 & z1831680
   DUE DATE:   Tuesday December 5, 2017

*********************************************************************/
#include "Circle.h"
#include <iostream>
#include <cmath>
#include <string>


// Circle()
// This is the default constructor for the Circle class.
// It takes the color of a circle and the radius.

Circle::Circle(std::string cirColor, int cirRadius) : Shape(cirColor)
   {
   radius = cirRadius;
   }

// get_area()
// This function calculates the area of the circle based on the value stored in 'radius'.
// It returns a double which is the calculated area.

double Circle::get_area()
   {
   double area = 0.0;
   area = (M_PI * pow(radius, 2));

   return area;
   }

// print()
// This function first calls the base class 'Shape' for the color to be printed, and then
// it prints out the circle radius and area.

void Circle::print()
   {
   Shape::print();   //Prints color
   std::cout << " circle, radius " << radius
             << ", area " << get_area() << std::endl;
   }
