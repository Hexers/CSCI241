/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 9
   PROGRAMMER: Aleksandar Kljaic + Philip Boffa
   LOGON ID:   z1815736 & z1831680
   DUE DATE:   Tuesday December 5, 2017

*********************************************************************/
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include <iostream>
#include <vector>

int main(void)
   {
   std::vector <Shape *> shape(6);

   shape.push_back(new Circle("green", 10));
   shape.push_back(new Rectangle("red", 8, 6));
   shape.push_back(new Triangle("yellow", 8, 4));
   shape.push_back(new Triangle("black", 4, 10));
   shape.push_back(new Circle("orange", 5));
   shape.push_back(new Rectangle("blue", 3, 7));

std::cout << std::endl << "Printing all shapes..."
                         << std::endl << std::endl;

   for (unsigned int i = 0; i < shape.size(); ++i)
      {
      Shape *shapePtr = dynamic_cast<Shape *> (shape[i]);

      if (shapePtr != 0)
         shapePtr->print();
   }

   std::cout << std::endl << "Printing only circles..."
                          << std::endl << std::endl;

   for (unsigned int i = 0; i < shape.size(); ++i)
      {
      Circle *circlePtr = dynamic_cast<Circle *> (shape[i]);

      if (circlePtr != 0)
         circlePtr->print();
      }

     std::cout << std::endl;

   return 0;
   }
