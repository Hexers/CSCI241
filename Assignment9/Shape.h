/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 9
   PROGRAMMER: Aleksandar Kljaic + Philip Boffa
   LOGON ID:   z1815736 & z1831680
   DUE DATE:   Tuesday December 5, 2017

*********************************************************************/
#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape
   {
   protected:

      std::string color;

   public:

      Shape(const std::string&);
      virtual ~Shape() {}
      virtual double get_area() = 0;
      virtual void print();

   };

#endif //SHAPE_H
