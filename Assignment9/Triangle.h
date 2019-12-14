/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 9
   PROGRAMMER: Aleksandar Kljaic + Philip Boffa
   LOGON ID:   z1815736 & z1831680
   DUE DATE:   Tuesday December 5, 2017

*********************************************************************/
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include <string>

class Triangle : public Shape
  {
  protected:

     int height;
     int base;

  public:

     Triangle(std::string, int, int);
     virtual double get_area();
     virtual void print();

  };

#endif //TRIANGLE_H
