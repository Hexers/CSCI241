/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 9
   PROGRAMMER: Aleksandar Kljaic + Philip Boffa
   LOGON ID:   z1815736 & z1831680
   DUE DATE:   Tuesday December 5, 2017

*********************************************************************/
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include <string>

class Rectangle : public Shape
   {
   protected:

      int height;
      int width;

   public:

      Rectangle(std::string, int, int);
      virtual double get_area();
      virtual void print();

   };

#endif //RECTANGLE_H

