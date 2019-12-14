#ifndef STACK_H
#define STACK_H

#include <iostream>


class Stack
{
private:
    int stkCapacity = 0;
    int stkSize = 0;
    int* stkArray;
public:

    // Constructors
    Stack();
    Stack(const Stack&);
    ~Stack();
    Stack& operator =(const Stack&);

    bool empty() const;
    size_t size() const;
    size_t capacity() const;

    void pop();
    const int & top() const;

    // The output operator should be overloaded so that a Stack can be printed on the standard output.
    // As in Assignment 4, this will need to be a standalone friend function rather than a method.

    // The items stored in the stack should be printed starting with the first array element (subscript 0) and ending
    // with the last valid element (subscript stack size - 1). Print a space after each stack element.
    // ostream& operator<<(ostream& lhs, const Stack& rhs)
    friend std::ostream& operator << (std::ostream&, const Stack&);
    void clear();
    void push(int val);
    void reserve(size_t n);
    int operator [](size_t n) const;
    int &operator [](size_t n);
    bool operator ==(const Stack &rhs) const;
};


#endif // STACK_H
