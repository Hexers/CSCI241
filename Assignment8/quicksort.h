/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 8
   PROGRAMMER: Aleksandar Kljaic + Philip Boffa
   LOGON ID:   z1815736 & z1831680
   DUE DATE:   Wednesday November 29, 2017


   FUNCTION:   This program builds and sorts lists using the quick
               sort algorithm.
*********************************************************************/
#ifndef QUICKSORTS_H
#define QUICKSORTS_H
#include <fstream>
#include <vector>
using namespace std;
// This function selects a pivot element and then partitions the vector around the pivot.
template <class T>
int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
    {
    int pivotIndex;
    int mid;
    T pivotValue;

    mid = (start + end) / 2;

    swap (set[start], set[mid]);

    pivotIndex = start;
    pivotValue = set[start];

    for (int scan = start + 1; scan <= end; scan++)
        {
        if (compare(set[scan], pivotValue))
            {
            pivotIndex++;
            swap (set[pivotIndex], set[scan]);
            }
        }

    swap(set[start], set[pivotIndex]);

    return pivotIndex;
    }
// This function performs the recursive calls to implement the quick sort algorithm.
template <class T>
void quickSorts(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
    {
    int pivotPoint;

    if (start < end)
        {
        pivotPoint = partition(set, start, end, compare);     // Get the pivot point
        quickSorts(set, start, pivotPoint - 1, compare);       // Sort first sublist
        quickSorts(set, pivotPoint + 1, end, compare);         // Sort second sublist
        }
    }
// This function should sort the items in the vector set using the quick sort algorithm. The first argument to
// this function is a reference to a vector object containing the list of items to sort. The second argument is
// a pointer to a comparison function that can be used to compare two items of the template type.
//
// This function should call the recursive quick sort function, passing it the vector, the subscript of the first
// vector element (which is 0), the subscript of the last vector element (which is set.size() - 1), and the pointer
// to the comparison function
template <class T>
void quickSort(vector<T>& set, bool (*compare)(const T&, const T&))
    {
    quickSorts(set, 0, set.size()-1, compare);
    }

#endif
