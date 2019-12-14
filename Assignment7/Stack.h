/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 7
   PROGRAMMER: Aleksandar Kljaic + Philip Boffa
   LOGON ID:   z1815736 & z1831680
   DUE DATE:   Thursday November 16, 2017

   FUNCTION:   This program tests the functionality of the Stack
               template class.
*********************************************************************/
#ifndef STACK_H
#define STACK_H

#endif // STACK_H

#include <iostream>
#include <stdexcept>

// Forward declaration of the Stack template class
template <class T>
class Stack;

// Forward declaration of the operator<< template function
template <class T>
std::ostream& operator<<(std::ostream&, const Stack<T>&);


// Class to represent a Stack node
template <class T>
struct Node
{
    T data;
    Node<T>* next;

    Node(const T& = T(), Node<T>* next = NULL);
};

template <class T>
Node<T>::Node(const T& newData, Node<T>* newNext)
{
    data = newData;
    next = newNext;
}



// Class to represent a Stack
template <class T>
class Stack
{
    friend std::ostream& operator<< <>(std::ostream&, const Stack<T>&);


private:

    Node<T>* stkTop;
    size_t stkSize;
    // size_t qFront;
    // size_t qBack;

public:

    // Constructor
    // The class should have a default constructor that takes no arguments.
    // The constructor should set stkTop to nullptr and set the stack size to 0.
    Stack()
    {
        //stkTop = nullptr;
        stkTop = NULL;
        stkSize = 0;
    }

    // Destructor
    // The class should have a destructor. The destructor can simply call the clear() method described below.
    ~Stack()
    {
        empty();
    }

    // Copy Constructor
    // The class should also have a proper copy constructor.

    Stack(const Stack<T>& other)
    {
        stkTop = NULL;
        copyList(other);
        stkSize = other.stkSize;
    }

    // operator=
    // The assignment operator should be properly overloaded.

    Stack<T>& operator=(const Stack<T>& other)
    {
        if (this != &other)
        {
            clear();
            copyList(other);
            stkSize = other.stkSize;
        }

        return *this;
    }



    // clear()
    // This method takes no arguments and returns nothing. It should properly set the stack back to the empty state.
    // That means deleting all of the nodes in the stack, setting the top pointer back to nullptr, and setting the
    // stack size back to 0. One easy way to accomplish this is to repeatedly pop until the stack is empty.
    // While the stack is not empty, call pop().
    void clear()
    {

        while (!empty())
        {
            pop();
        }

    }

    // size()
    // This method takes no arguments and returns an unsigned integer or size_t. It should return the stack size; i.e.,
    // the number of data items currently stored in the stack.
    size_t size() const
    {
        return stkSize;
    }

    // empty()
    // Returns true if there are no data items currently stored in the stack; otherwise returns false.
    bool empty() const
    {
        return stkSize == 0;
    }

    // top()
    // This method takes no arguments and returns a reference to a constant item of the template parameter type. It should
    // return the data stored in the top node of the stack (i.e., the first node in the linked list). You may assume this
    // method will not be called if the stack is empty.
    const T& top() const
    {
        if (empty())
            throw std::underflow_error("Stack underflow on call to top()");

        return stkTop->data;
    }

    // push()
    // This method takes a reference to a constant item of the template parameter type as its argument (the item to insert
    // into the stack). It returns nothing. The method should insert the item at the top of the stack (at the front of the linked list).
    // void push(const T& val)
    void push(const T& item)
    {
        Node<T>* newNode = new Node<T>(item, stkTop);
        stkTop = newNode;
        stkSize++;
    }

    // pop()
    // This method takes no arguments and returns nothing. It should remove the node at the top of the stack. You may assume this method
    // will not be called if the stack is empty.
    void pop()
    {
        if (empty())
            throw std::underflow_error("Stack underflow on call to pop()");

        Node<T>* delNode = stkTop;
        stkTop = stkTop->next;       // or stkTop = delNode->next;
        delete delNode;
        stkSize--;
    }

    // copylist()
    // copyList() method that can be called by both the copy constructor
    // and overloaded assignment operator to make a copy of the linked list.

    void copyList(const Stack<T>& other)
    {
        Node<T>* ptr, * newNode, * last = NULL;
        for (ptr = other.stkTop; ptr != NULL; ptr = ptr->next)
        {
            newNode = new Node<T>(ptr->data);
            if (last == NULL)
                stkTop = newNode;
            else
                last->next = newNode;

            last = newNode;
        }
    }




};


// operator<<
// The output operator should be overloaded so that an entire Stack can be sent to the standard output.
// As usual, this function will need to be a friend rather than a method. Declaring a template function
// to be a friend of a template class requires some special syntax - see the Implementation Hints below.

template <class T>
std::ostream &operator << (std::ostream& lhs, const Stack<T>& rhs)
{
    for (Node<T>* ptr = rhs.stkTop; ptr != NULL; ptr = ptr->next)
        lhs << ptr->data << ' ';

    return lhs;
}


