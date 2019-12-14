/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 8
   PROGRAMMER: Aleksandar Kljaic + Philip Boffa
   LOGON ID:   z1815736 & z1831680
   DUE DATE:   Wednesday November 29, 2017


   FUNCTION:   This program builds and sorts lists using the quick
               sort algorithm.
*********************************************************************/
#ifndef SORTS_H
#define SORTS_H
#include <fstream>
#include <vector>
using namespace std;

// This function should read items from an input file and put them into a vector. The first argument to this
// function is a reference to a vector object that will be used to store the items. The second argument is a
// C-style string containing the full pathname of the input file.
//
// The function should first open the file for input, then read items from the file using the >> operator one
// at a time until end of file, inserting them into the vector. Finally, it should close the input file.
template <class T>
void buildList(vector<T>& set, const char* fileName){


    T item;
    ifstream inFile(fileName);

    if(inFile.fail()){
        cout<<"Error in opening file"<<endl;
        return;
    }

    // reading file
    inFile>>item;
    while(!inFile.eof()){
        set.push_back(item);
        inFile>>item;
    }

    inFile.close();
}

// This function should print a list of items stored in a vector. The first argument to this function is a reference
// to a constant vector object that will contain the items to print. The second argument is an integer specifying the
// width an individual item should occupy when printed. The third argument is an integer specifying the maximum number
// of items that should be printed in a single line of output.
template <class T>
void printList(const vector<T>& set, int itemWidth, int numPerLine){

    int count = 0;

    for(int i=0; i<set.size(); i++){

        cout<<setw(itemWidth)<<set[i];

        count++;

        if(count == numPerLine){
            cout<<endl;
            count = 0;
        }
    }
}
// This function should return true if item1 is less than item2 and false if not. You may assume that the data type
// T can be compared using the standard relational operators.
template <class T>
bool lessThan(const T& item1, const T& item2)
{
    return item1 < item2;
}
// This function should return true if item1 is greater than item2 and false if not. You may assume that the data
// type T can be compared using the standard relational operators.
template <class T>
bool greaterThan(const T& item1, const T& item2)
{
    return item1 > item2;

}

#endif // SORTS_H
