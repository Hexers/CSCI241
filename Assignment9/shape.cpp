/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 9
   PROGRAMMER: Aleksandar Kljaic + Philip Boffa
   LOGON ID:   z1815736 & z1831680
   DUE DATE:   Tuesday December 5, 2017

*********************************************************************/
#include "Shape.h"
#include <iostream>
#include <string>

// Shape()
// This is the default constructor which initializes the shapes color.
Shape::Shape(const std::string& shapeColor) : color(shapeColor) {}

// print()
// This function prints the color stored in the 'color' string.
void Shape::print()
   {
   std::cout << color;
   }
