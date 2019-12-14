/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 5
   PROGRAMMER: Aleksandar Kljaic + Philip Boffa
   LOGON ID:   z1815736 & z1831680
   DUE DATE:   Tuesday October 31, 2017

   FUNCTION:   This program tests the functionality of the Stack
               class.
*********************************************************************/

#include <iostream>
#include <stdexcept>
#include "Stack.h"


// Constructors

// The class should have a default constructor that takes no arguments.
// The constructor should set the stack size and stack capacity to 0 and the stack array pointer to nullptr.
Stack::Stack()
{
    stkCapacity = 0;
    stkSize = 0;
    stkArray = nullptr;
}


// The class should have a destructor that deletes the dynamic memory for the stack array. The destructor
// should NOT call the clear() method.
Stack::~Stack()
{
    delete[] stkArray;
}

// The class should also have a proper copy constructor. Your code should account for the possibility that
// you might be copying an empty Stack object.
Stack::Stack(const Stack& other)
{
    // Similar to Stack& Stack::operator=(const Stack& other)
    stkCapacity = other.stkCapacity;
    stkSize = other.stkSize;

    if (stkCapacity == 0)
        stkArray = nullptr;
    else
        stkArray = new int[stkCapacity];

    for (int i = 0; i < stkSize; ++i)
        stkArray[i] = other.stkArray[i];
}

// The assignment operator should be properly overloaded to allow one Stack object to be assigned to another.
// Your code should account for the possibility that you might be copying an empty Stack object
Stack& Stack::operator=(const Stack& other)
{
    stkCapacity = other.stkCapacity;
    stkSize = other.stkSize;

    delete[] stkArray;

    if (stkCapacity == 0)
        stkArray = nullptr;
    else
        stkArray = new int[stkCapacity];

    for (int i = 0; i < stkSize; ++i)
        stkArray[i] = other.stkArray[i];

        return *this;
}


// This method should set the stack size to 0. It should not change the stack capacity or the stack array.
void Stack::clear()
{
    stkSize = 0;
}

// This method should return the stack size.
size_t Stack::size() const
{
    return stkSize;
}

// This method should return the stack capacity.
size_t Stack::capacity() const
{
    return stkCapacity;
}

// This method should return true if the stack size is equal to 0; otherwise it should return false.
bool Stack::empty() const
{
    return stkSize == 0;
}

// This method should return the top element of the stack array (the one at the subscript stack size - 1).
// You may assume this method will not be called if the stack is empty.
const int& Stack::top() const
{
    // Optional
    if (empty())
        throw std::underflow_error("Stack underflow on call to top()");

    return stkArray[stkSize - 1];
}

// The output operator should be overloaded so that a Stack can be printed on the standard output.
// As in Assignment 4, this will need to be a standalone friend function rather than a method.

// The items stored in the stack should be printed starting with the first array element (subscript 0)
// and ending with the last valid element (subscript stack size - 1). Print a space after each stack element.
std::ostream &operator <<(std::ostream &  stream, const Stack & stk)
{
for (size_t i = 0; i < stk.stkSize; ++i)
    stream << stk.stkArray[i] << " ";
    return stream;
}

// This method takes an integer argument, the value to insert into the stack. If the stack is full (the stack size
// is equal to the stack capacity), this method will need to call the reserve() method to increase the capacity of
// the stack array and make room for the value to insert. If the stack capacity is currently 0, pass a new capacity
// of 1 to the reserve() method. Otherwise, pass a new capacity of twice the current stack capacity to the reserve()
// method.

// Using the stack size as the subscript, copy the value to be inserted into the stack array. The stack size should
// then be incremented by 1.
void Stack::push(int val)
{
    //Insert new item at top of stack.
    // If stack is full, allocate additional storage
    if (stkSize == stkCapacity)
    {
        if (stkCapacity == 0)
            reserve(1);
        else
            reserve(stkCapacity * 2);
    }

    stkArray[stkSize] = val;
    ++stkSize;
}

// This method should decrement the stack size by 1, which effectively removes the top (last) value from the stack array.
// No changes need be made to the stack array contents. You may assume this method will not be called if the stack is empty.
void Stack::pop()
{
    //Remove top item from stack.

    // Optional
    if (empty())
        throw std::underflow_error("Stack underflow on call to top()");

    --stkSize;
}

// This method increases the capacity of the stack array. It takes a single integer argument, the new capacity.
// The logic for this method should look something like this:
void Stack::reserve(size_t n)
{
    if (n < stkCapacity)
        return;

    int* tempArray = new int[n];

    for (size_t i = 0; i < stkSize; ++i)
    {
        tempArray[i] = stkArray[i];
    }

    stkCapacity = n;
    delete[] stkArray;
    stkArray = tempArray;
}

// This method should return the element of the stack array at subscript n. You may assume this method will not be called
// with an argument n that is out of range.
int Stack::operator[](size_t n) const
{
    return stkArray[n];
}

// This method should return the element of the stack array at subscript n. You may assume this method will not be called
// with an argument n that is out of range.
int& Stack::operator[](size_t n)
{
    return stkArray[n];
}

// This method should return true if the values stored in the stack array of the object that called the method are identical
// to the values stored in the stack array of the Stack object passed in as rhs.

// The logic for this method is less difficult that it might initially appear to be. The first step is to compare the stack
// sizes of the two stacks. If they are different, return false (two stacks of different lengths can not be equal).

// Otherwise, loop through the elements of both stack arrays, starting at 0 and stopping when you reach the stack size.
// (The size of which stack doesn't matter, since you know they're the same by this point.) Compare the current element
// from each stack array. If elements are different, return false. If the elements are the same, don't return true; do
// nothing and let the loop continue.
// Once the loop ends and you've reached the end of both stacks, return true.
bool Stack::operator==(const Stack& rhs) const
{
    if ( stkSize != rhs.stkSize)
        return false;
    for (size_t i = 0; i < rhs.stkSize; ++i)
        if (stkArray[i] != rhs.stkArray[i])
            return false;

    return true;
}

