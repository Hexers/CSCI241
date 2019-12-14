/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 6
   PROGRAMMER: Aleksandar Kljaic + Philip Boffa
   LOGON ID:   z1815736 & z1831680
   DUE DATE:   Thursday November 9, 2017

   FUNCTION:   This program tests the functionality of the Queue
               template class.
*********************************************************************/
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>

// Forward declaration of the Queue template class
template <class T>
class Queue;

// Forward declaration of the operator<< template function
template <class T>
std::ostream& operator<<(std::ostream&, const Queue<T>&);

template <class T>
class Queue
{
    friend std::ostream& operator<< <>(std::ostream&, const Queue<T>&);

private:
    T* qArray;
    size_t qSize;
    size_t qCapacity;
    size_t qFront;
    size_t qBack;

public:
    // Constructors
    // Constructor
    // The class should have a default constructor that takes no arguments. The constructor should set the
    // queue size and queue capacity to 0 and the queue array pointer to nullptr. The queue front subscript
    // should be initialized to 0. The queue back subscript should be initialized to the queue capacity - 1.
    // Alternately, the data members can be initialized in the class declaration, in which case this method's
    // body can be empty.
    Queue()
    {

        qCapacity = 0;
        qSize = 0;
        qArray = NULL;
        qFront = 0;                     // First element of qArray
        qBack = qCapacity - 1;          // Last element of qArray
    }
    // Copy Constructor
    // The class should also have a proper copy constructor. This will be similar to the copy constructor you wrote
    // for the Stack class for Assignment 5. The main difference is that you will need to copy the contents of the
    // entire queue array (elements 0 to queue capacity - 1), not just elements 0 to queue size - 1.
    Queue(const Queue<T>& other)
    {
        qCapacity = other.qCapacity;
        qSize = other.qSize;
        qArray = new int[qCapacity];

        for (size_t i = 0; i < qCapacity; ++i)
            qArray[i] = other.qArray[i];

        qFront = other.qFront;
        qBack = other.qBack;
    }

    // Destructor
    // The class should have a destructor that deletes the dynamic memory for the queue array. The destructor
    // should not call the clear() method.
    ~Queue()
    {
        delete[] qArray;
    }
    // Copy Assignment Operator
    // The copy assignment operator should be properly overloaded to allow one Queue to be assigned to another.
    // Once again, the code here will be similar to what you wrote for Assignment 5. As with the copy constructor,
    // you will need to copy the contents of the entire queue array.
    Queue<T>& operator=(const Queue<T>& other)
    {
        if(&other == this)
            return *this;

        qCapacity = other.qCapacity;
        qSize = other.qSize;

        delete[] qArray;

        if (qCapacity == 0)
            qArray = NULL;
        else
            qArray = new int[qCapacity];

        for (int i = 0; i < qSize; ++i)
            qArray[i] = other.qArray[i];

        return *this;
    }
    // empty()
    // This method takes no arguments and returns a boolean value. It should return true if the
    // queue size is 0; otherwise it should return false.
    bool empty() const
    {
        return qSize == 0;
    }
    // size()
    // This method takes no arguments and returns a size_t. It should return the queue size.
    size_t size() const
    {
        return qSize;
    }
    // capacity()
    // This method takes no arguments and returns a size_t. It should return the queue capacity.
    size_t capacity() const
    {
        return qCapacity;
    }
    // pop()
    // This method takes no arguments and returns nothing. If the queue is empty, this method should throw
    // an underflow_error exception. Otherwise, it should increment the queue front subscript (wrapping
    // around to the front of the queue array if needed) to effectively remove the front item in the queue
    // array. The queue size should be decremented by 1.
    void pop()
    {
        //Remove top item from stack.

        // Optional
        if (empty())
            throw std::underflow_error("Stack underflow on call to pop()");

        qFront = (qFront + 1) % qCapacity;
        --qSize;
    }

    // front()
    // This method takes no arguments and returns a reference to a constant item of the template parameter
    // type. If the queue is empty, this method should throw an underflow_error exception. Otherwise, it should
    // return the front element of the queue array (the one at the queue front subscript).
    const T& front() const
    {
        // Optional
        if (empty())
            throw std::underflow_error("Stack underflow on call to front()");

        return qArray[qFront];
    }
    // back()
    // This method takes no arguments and returns a reference to a constant item of the template parameter type.
    // If the queue is empty, this method should throw an underflow_error exception. Otherwise, it should return
    // the back element of the queue array (the one at the queue back subscript).
    const T& back() const
    {
        // Optional
        if (empty())
            throw std::underflow_error("Stack underflow on call to back()");

        return qArray[qBack];
    }

    void clear()
    {
        qSize = 0;
        qFront = 0;
        qBack = qCapacity -1; // Not sure if correct
    }
    // push()
    // This method takes a reference to a constant item of the template parameter type as its argument,
    // the value to insert into the queue. If the queue is full (the queue size is equal to the queue
    // capacity), this method will need to call the reserve() method to increase the capacity of the
    // queue array and make room for the item to insert. If the queue capacity is currently 0, pass a
    // new capacity of 1 to the reserve() method. Otherwise, pass a new capacity of twice the current
    // queue capacity to the reserve() method.
    // .
    // To insert an item, the method should increment the queue back subscript (wrapping around to the
    // front of the queue array if needed) and then copy the method argument into the queue array as the
    // new back item in the queue. The queue size should be incremented by 1.
    void push(const T& val)
    {
        // If queue is full, allocate additional storage
        if (qSize == qCapacity)
        {
            if (qCapacity == 0)
                reserve(1);
            else
                reserve(qCapacity * 2);
        }

        qBack = (qBack + 1) % qCapacity;
        qArray[qBack] = val;
        ++qSize;
    }
    // reserve()
    // This method takes a size_t, the new capacity to allocate for the queue array. It returns nothing.
    // .
    // If the new capacity is less than the queue size or is equal to the current queue capacity, simply return.
    // Otherwise, the method should reserve additional capacity for the queue array equal to the new capacity passed in.
    // The logic to do this is similar to that used in Assignment 5.
    // .
    // Note that the "circular" nature of the queue array does complicate copying the items from the queue array to the
    // new temporary array. You will need to modify your code from Assignment 5 accordingly.
    void reserve(size_t n)
    {
        if (n < qSize || n == qCapacity)
            return;

        T* tempArray = new T[n];

        int current = qFront;
        for (size_t i = 0; i < qSize; i++)
        {
            tempArray[i] = qArray[current];
            current = (current + 1) % qCapacity;
        }

        qCapacity = n;
        qFront = 0;
        qBack = qSize - 1;
        delete[] qArray;
        qArray = tempArray;
    }
    /*   bool operator ==(const Queue &rhs) const
    {

    }

*/

};
// operator<<
// The output operator should be overloaded so that a Queue can be printed on the standard output. As in Assignments
// 4 and 5, this will need to be a standalone friend function rather than a method.
// .
// Declaring a template function to be a friend of a template class requires some special syntax - see
// the Implementation Hints below.
// .
// Looping through the queue array to print the elements is complicated by the fact that the queue front subscript
// will not necessarily be less than the queue back subscript. One way to make this work is to have a counter that
// controls how many times the loop is done, and a subscript that starts at the front of the queue and is incremented
// until it reaches the back of the queue:

// clear()
// This method takes no arguments and returns nothing. It should properly set
// the queue back to the empty state (set the queue size to 0, the queue front
// subscript to 0, and the queue back subscript to the queue capacity - 1).
template <class T>
std::ostream &operator << (std::ostream& lhs, const Queue<T>& rhs)
{
    size_t current, i;

    for (current = rhs.qFront, i = 0; i < rhs.qSize; ++i)
    {
        // Print queue element at subscript i
        lhs << rhs.qArray[current] << ' ';

        // Increment i, wrapping around to front of queue array if necessary
        current = (current + 1) % rhs.qCapacity;
    }
    return lhs;
}

#endif
