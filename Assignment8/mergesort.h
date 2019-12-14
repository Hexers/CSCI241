/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 8
   PROGRAMMER: Aleksandar Kljaic + Philip Boffa
   LOGON ID:   z1815736 & z1831680
   DUE DATE:   Wednesday November 29, 2017


   FUNCTION:   This program builds and sorts lists using the quick
               sort algorithm.
*********************************************************************/
#ifndef MERGESORT_H
#define MERGESORT_H
#include <fstream>
#include <vector>
using namespace std;

template <class T>
void merge(vector<T>& set, int low, int mid, int high, bool (*compare)(const T&, const T&)){

    // Create temporary vector to hold merged subvectors
    vector<T> temp(high - low + 1);

    int i = low; // Subscript for start of left sorted subvector
    int j = mid+1; // Subscript for start of right sorted subvector
    int k = 0; // Subscript for start of merged vector

    // While not at the end of either subvector
    while (i <= mid && j <= high)
    {
        if (compare(set[j], set[i]))
        {
            //Copy element j of set into element k of temp
            temp[k] = set[j];
            //Add one to j
            j = j+1;
            //Add one to k
            k = k + 1;
        }
        else
        {
            //Copy element i of set into element k of temp
            temp[k] = set[i];
            //Add one to i
            i = i + 1;
            //Add one to k
            k = k + 1;
        }
    }

    // Copy over any remaining elements of left subvector
    while (i <= mid)
    {
        //Copy element i of set into element k of temp
        temp[k] = set[i];
        //Add one to i
        i = i + 1;
        //Add one to k
        k = k + 1;
    }

    // Copy over any remaining elements of right subvector
    while (j <= high)
    {
        //Copy element j of set into element k of temp
        temp[k] = set[j];
        //Add one to j
        j = j+1;
        //Add one to k
        k = k + 1;
    }

    // Copy merged elements back into original vector
    for (i = 0, j = low; j <= high; i++, j++){
        //Copy element i of temp into element j of set
        set[j] = temp[i];
    }
}
// This function should sort the items in the vector set using the merge sort algorithm.
// The first argument to this function is a reference to a vector object containing the
// list of items to sort. The second argument is a pointer to a comparison function that
// can be used to compare two items of the template type.
//
// This function should call the recursive merge sort function, passing it the vector,
// the subscript of the first vector element (which is 0), the subscript of the last
// vector element (which is set.size() - 1), and the pointer to the comparison function
template <class T>
void mergeSort(vector<T>& set, int low, int high, bool (*compare)(const T&, const T&)){
    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;

        // Divide and conquer

        mergeSort(set, low, mid, compare);
        mergeSort(set, mid+1, high, compare);

        // Combine
        merge(set, low, mid, high, compare);
    }
}
// This function merges two sorted subvectors.
template <class T>
void mergeSort(vector<T>& set, bool (*compare)(const T&, const T&)){

    mergeSort(set, 0, set.size()-1, compare);
}


#endif // MERGESORT_H
