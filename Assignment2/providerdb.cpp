//*****************************************************************
// FILE:      ProviderDB.cpp
// AUTHOR:    Aleksandar Kljaic + Philip Boffa
// LOGON ID:  z1815736 + z1831680
// DUE DATE:  Wednesday September 27, 2017
//
// PURPOSE:   Declaration for the Provider class, which represents
//            information about a health care provider.
//*****************************************************************

#include <iostream>
#include <fstream>
#include <string.h>
#include "ProviderDB.h"
using std::ifstream;
using namespace std;


/******************************************************************************

ProviderDB method to the ProviderDB class
which sets providerCount to 0 (ZERO)

******************************************************************************/
ProviderDB::ProviderDB()
{
        providerCount = 0;
}

/******************************************************************************

ProviderDB method to the ProviderDB class
passing a pointer to fileName and error checking
the file to see if it can be opened.

******************************************************************************/
ProviderDB::ProviderDB(const char* fileName)
{
        ifstream inFile;

        inFile.open(fileName);
        if (!inFile)
        {
                std::cerr << "Error - unable to open input file\n";
                exit(1);
        }

        inFile.read((char*) this, sizeof(ProviderDB));

        inFile.close();
}

/******************************************************************************

print method to the ProviderDB class
This method outputs Healtth Care Provider Listing
and then proceeds to go into a for loop to print out the
arrays listing the providers.

******************************************************************************/
void ProviderDB::print() const
{

        cout << "Health Care Provider Listing " << endl;

        for (int i = 0; i < providerCount; i++)
        {
                providers[i].print();
                cout << endl;
        }

}

/******************************************************************************

sortByProviderNumber method to the ProviderDB class
This method takes no parameters and returns nothing!
This method sorts the array of Provider objects in ASCENDING order
by provider number using the insertion sort algorithm below
The sort code sorts an array of integers called providers of size providerCount.

******************************************************************************/
void ProviderDB::sortByProviderNumber()
{
        int i, j;
        Provider bucket;

        for (i = 1; i < providerCount; i++)
        {
                bucket = providers[i];

                for (j = i; (j > 0) && (strcmp(providers[j-1].getProviderNumber(), bucket.getProviderNumber()) > 0); j--) // String Copy
                        providers[j] = providers[j-1];

                providers[j] = bucket;
        }
}

/******************************************************************************

sortByProviderSpecialty method to the ProviderDB class
This method takes no parameters and returns nothing!
This method sorts the array of Provider objects in DECENDING order
by provider number using the insertion sort algorithm below
The sort code sorts an array of integers called providers of size providerCount.

******************************************************************************/
void ProviderDB::sortBySpecialty()
{
        int i, j;
        Provider bucket;

        for (i = 1; i < providerCount; i++)
        {
                bucket = providers[i];

                for (j = i; (j > 0) && (strcmp(providers[j-1].getProviderSpecialty(), bucket.getProviderSpecialty()) < 0); j--) // String Copy
                        providers[j] = providers[j-1];

                providers[j] = bucket;
        }
}

/******************************************************************************

sortByProviderName method to the ProviderDB class
This method takes no parameters and returns nothing!
This method sorts the array of Provider objects in ASCENDING order
by provider number using the insertion sort algorithm below
The sort code sorts an array of integers called providers of size providerCount.

******************************************************************************/
void ProviderDB::sortByName()
{
           int i, j;
   Provider bucket;

   for (i = 1; i < providerCount; i++)
      {
      bucket = providers[i];

      for (j = i; (j > 0) && (strcmp(providers[j-1].getProviderFullName(), bucket.getProviderFullName()) > 0); j--) // String Copy
         providers[j] = providers[j-1];

      providers[j] = bucket;
      }
}
