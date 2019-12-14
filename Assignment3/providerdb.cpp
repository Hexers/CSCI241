//*****************************************************************
// FILE:      ProviderDB.cpp
// AUTHOR:    Aleksandar Kljaic + Philip Boffa
// LOGON ID:  z1815736 + z1831680
// DUE DATE:  Tuesday October 10, 2017
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

/******************************************************************************

This method should take one parameter: a pointer to a constant character
(that points to an array of characters contaaining the name of a file of
transaction data). The method should return nothing.

This method will read a series of transaction records until end of file.
Each record contains a transaction type, possibly followed by some additional data.

******************************************************************************/
void ProviderDB::processTransactions(const char* fileName)
{

    ifstream tranFile;

    tranFile.open(fileName);
    if (!tranFile)
    {
        std::cerr << "Error - unable to open input file\n";
        exit(1);
    }


    while (tranFile)
    {

        string tranType; // declares tranType

        tranFile >> tranType; // Reads a string from tranFile to tranType
        if (tranType == "all")
            processTransactionAll();
        else if  (tranType == "specialty")
            processTransactionSpecialty(tranFile);
        else if (tranType == "number")
            processTransactionNumber(tranFile);
        else cout << "Error, unexpected transaction type.";

    }

}


/******************************************************************************
Transaction Type "all"

This transaction type is not followed by any additional fields.
******************************************************************************/
void ProviderDB::processTransactionAll()
{
    sortByName();
    print();
}

/******************************************************************************
Transaction Type "specialty"

This transaction type is followed by a specialty. Since the specialty may contain
whitespace, reading it will be a little tricky. If you try to immediately read the
specialty using getline() (like in Assignment 1), you'll end up reading in the
whitespace that separates the transaction type and the specialty as part of the
specialty string.
******************************************************************************/
void ProviderDB::processTransactionSpecialty(ifstream& tranFile)
{
    tranFile >> ws;
    string specialty;


    getline(tranFile, specialty);
    sortBySpecialty();
    int count = 0;

    for (int i = 0; i < providerCount; i++)
    {
        if (providers[i].getProviderSpecialty() == specialty)
        {
            providers[i].print();
            count++;

        }

    }
    cout << "Number of providers with specialty " << specialty << ": " << count << endl;
}

/******************************************************************************
Transaction Type "number"

This transaction type is followed by a provider number.
******************************************************************************/
void ProviderDB::processTransactionNumber(ifstream& tranFile)
{
    string number;
    tranFile >> number;

    sortByProviderNumber();
    int index = searchForProviderNumber(number.c_str());
    if (index == -1)
        cout << "Error, provider number not found." << endl;
    else
        providers[index].print();
}

/******************************************************************************
searchForProviderNumber()

This method should take one parameter: a character array containing the provider
number of the Provider to search for (searchNumber. The method should return an integer.
******************************************************************************/
int ProviderDB::searchForProviderNumber(const char* searchNumber)
{


    int low = 0;
    int high = providerCount - 1;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (strcmp(searchNumber, providers[mid].getProviderNumber()) == 0)
            return mid;

        if (strcmp(searchNumber, providers[mid].getProviderNumber()) == 1)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
