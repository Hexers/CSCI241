#ifndef PROVIDERDB_H
#define PROVIDERDB_H
#include <fstream>
#include "Provider.h"

//*****************************************************************
// FILE:      ProviderDB.h
// AUTHOR:    Aleksandar Kljaic + Philip Boffa
// LOGON ID:  z1815736 + z1831680
// DUE DATE:  Tuesday October 10, 2017
//
// PURPOSE:   Declaration for the Provider class, which represents
//            information about a health care provider.
//*****************************************************************

class ProviderDB
{

public:
    // Constructors
    ProviderDB();
    ProviderDB(const char* fileName);
    void print() const;

    void sortByProviderNumber();
    void sortBySpecialty();
    void sortByName();
    void processTransactions(const char* fileName); // This goes into public


private:

    // Data members and method prototypes for the Provider class go here
    Provider providers[40];
    int providerCount;

    void processTransactionAll();
    void processTransactionSpecialty(std::ifstream &tranFile);
    void processTransactionNumber(std::ifstream &tranFile);
    int searchForProviderNumber(const char* searchNumber);


};


#endif
