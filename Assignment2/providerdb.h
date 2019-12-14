#ifndef PROVIDERDB_H
#define PROVIDERDB_H

#include "Provider.h"

//*****************************************************************
// FILE:      ProviderDB.h
// AUTHOR:    Aleksandar Kljaic + Philip Boffa
// LOGON ID:  z1815736 + z1831680
// DUE DATE:  Wednesday September 27, 2017
//
// PURPOSE:   Declaration for the Provider class, which represents
//            information about a health care provider.
//*****************************************************************

class ProviderDB
{
        // Data members and method prototypes for the Provider class go here
private:

        Provider providers[40];
        int providerCount;

public:
        // Constructors
        ProviderDB();
        ProviderDB(const char* fileName);
        void print() const;

        void sortByProviderNumber();
        void sortBySpecialty();
        void sortByName();
};

#endif
