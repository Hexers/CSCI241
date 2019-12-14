/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 9
   PROGRAMMER: Aleksandar Kljaic + Philip Boffa
   LOGON ID:   z1815736 & z1831680
   DUE DATE:   Tuesday December 5, 2017

*********************************************************************/
#include "Triangle.h"
#include <iostream>
#include <string>

// Rectangle()
// This is the default constructor for the Rectangle class. It takes the color,
// height, and width of a rectangle.
Triangle::Triangle(std::string triColor, int triHeight,
                   int triBase) : Shape(triColor)
   {
   height = triHeight;
   base = triBase;
   }

// get_area()
// This function calculates the area of the triangle based on the values that are
// stored in the 'height' and 'base' variables. It returns a double which is the
// calculated area.
double Triangle::get_area()
   {
   double area = 0.0;
   area = (0.5 * base * height);

   return area;
   }

// print()
// This function first calls the base class 'Shape' for the color to be printed, and
// then it prints out the triangle height, base, and area.
void Triangle::print()
   {
   Shape::print();
   std::cout << " triangle, height " << height
             << ", base " << base << ", area "
             << get_area() << std::endl;
   }
