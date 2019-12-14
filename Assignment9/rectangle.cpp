/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 9
   PROGRAMMER: Aleksandar Kljaic + Philip Boffa
   LOGON ID:   z1815736 & z1831680
   DUE DATE:   Tuesday December 5, 2017

*********************************************************************/
#include "Rectangle.h"
#include <iostream>
#include <string>

// Rectangle()
// This is the default constructor for the Rectangle class. It takes the color,
// height, and width of a rectangle.
Rectangle::Rectangle(std::string recColor, int recHeight,
                     int recWidth) : Shape(recColor)
   {
   height = recHeight;
   width = recWidth;
   }

// get_area()
// This function calculates the area of the rectangle based on the values that
// are stored in the 'height' and 'width' variables. It returns a double which
// is the calculated area.

double Rectangle::get_area()
   {
   double area = 0.0;
   area = height * width;

   return area;
   }

// print()
// This function first calls the base class 'Shape' for the color to be printed,
// and then it prints out the rectangle height, width, and area.

void Rectangle::print()
   {
   Shape::print();
   std::cout << " rectangle, height " << height
             << ", width " << width << ", area "
             << get_area() << std::endl;
   }

