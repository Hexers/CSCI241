//*************************************************************
// CSCI 241 - Assignment 3
//
// PROGRAM: assign3.cpp
// PROGRAMMERS: Aleksandar Kljaic + Philip Boffa
// LOGON ID: z1815736 + z1831680
// DATE DUE: Tuesday October 10, 2017
//
// PURPOSE: This program reads a series of records from
// a file into an array. The objects are
// printed, sorted by name, and then printed again.
//*************************************************************

#include "ProviderDB.h"

int main() // Main
{
    // Method calls to the main program

    /* ProviderDB object using the alternate constructor you wrote. Pass the filename string "providerdb" as an argument to the constructor. */
    ProviderDB db ("providerdb");
    /* Call the print() method for the ProviderDB object. */
    db.print();

    /* Call the sortByProviderNumber() method for the ProviderDB object. */
    db.sortByProviderNumber();
    /* Call the print() method for the ProviderDB object. */
    db.print();

    /* Call the sortBySpecialty() method for the ProviderDB object. */
    db.sortBySpecialty();
    /* Call the print() method for the ProviderDB object. */
    db.print();

    /* Call the sortByName() method for the ProviderDB object. */
    db.sortByName();
    /* Call the print() method for the ProviderDB object. */
    db.print();

    /* Call the processTransactions() method for the ProviderDB object. */
    /* Pass the filename string "transactions.txt" as an argument to the method.*/
    db.processTransactions("transactions.txt");

    return 0;
}
