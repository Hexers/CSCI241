//*************************************************************
// CSCI 241 - Assignment 3
//
// PROGRAM: Provider.cpp
// PROGRAMMERS: Aleksandar Kljaic + Philip Boffa
// LOGON ID: z1815736 + z1831680
// DATE DUE: Tuesday October 10, 2017
//
// PURPOSE: This program reads a series of records from
// a file into an array. The objects are
// printed, sorted by name, and then printed again.
//*************************************************************

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <string>
#include "ProviderDB.h"
#include "Provider.h"

using std::cerr;
using std::cout;
using std::endl;
using std::fixed;
using std::ifstream;
using std::setprecision;
using std::string;
using std::getline;

    // Constructors
    Provider::Provider(const char* newProviderNumber,
                       const char* newProviderSpecialty,
                       const char* newProviderFullName,
                       const char* newProviderAddressOne,
                       const char* newProviderAddressTwo,
                       const char* newProviderCity,
                       const char* newProviderState,
                       const char* newProviderZipCode,
                       const char* newProviderPhoneNumber)


    {
        setProviderNumber(newProviderNumber);
        setProviderSpecialty(newProviderSpecialty);
        setProviderFullName(newProviderFullName);
        setProviderAddressOne(newProviderAddressOne);
        setProviderAddressTwo(newProviderAddressTwo);
        setProviderCity(newProviderCity);
        setProviderState(newProviderState);
        setProviderZipCode(newProviderZipCode);
        setProviderPhoneNumber(newProviderPhoneNumber);
    }


// Function Prototypes

int buildProviderArray(Provider[]);
void printProviderArray(Provider[], int);
void sortProviderArray(Provider[], int);

int buildProviderArray(Provider providerArray[])
{
        // Strings being called
    ifstream inFile;
    string providerNumber;
    string providerSpecialty;
    string providerLastName;
    string providerFirstName;
    string providerMiddleName;
    string providerTitle;
    string providerAddressOne;
    string providerAddressTwo;
    string providerCity;
    string providerState;
    string providerZipCode;
    string providerPhoneNumber;

    int count = 0; // count being set to 0 (ZERO)

    // Open the input file and test for failure
    inFile.open("providers.csv");
    if (!inFile)
    {
        cerr << "Error - unable to open input file\n";
        exit(1);
    }

    // Attempting to getline from CSV
        // Reading the providers.csv file with a delimitor comma.
    while (inFile)
    {
        getline(inFile, providerNumber, ',');
        getline(inFile, providerSpecialty, ',');
        getline(inFile, providerLastName, ',');
        getline(inFile, providerFirstName, ',');
        getline(inFile, providerMiddleName, ',');
        getline(inFile, providerTitle, ',');
        getline(inFile, providerAddressOne, ',');
        getline(inFile, providerAddressTwo, ',');
        getline(inFile, providerCity, ',');
        getline(inFile, providerState, ',');
        getline(inFile, providerZipCode, ',');
        getline(inFile, providerPhoneNumber);

        providerArray[count].setProviderNumber(providerNumber.c_str());
        providerArray[count].setProviderSpecialty(providerSpecialty.c_str());

                // Sets fullname to be providerLastName, providerFirstName, and providerTitle
        std::string fullName = providerLastName + ' ' + providerFirstName + ' ' + providerTitle;
        providerArray[count].setProviderFullName(fullName.c_str());
        providerArray[count].setProviderAddressOne(providerAddressOne.c_str());
        providerArray[count].setProviderAddressTwo(providerAddressTwo.c_str());
        providerArray[count].setProviderCity(providerCity.c_str());
        providerArray[count].setProviderState(providerState.c_str());
        providerArray[count].setProviderZipCode(providerZipCode.c_str());
        providerArray[count].setProviderPhoneNumber(providerPhoneNumber.c_str());

        count++;
    }


    inFile.close();
    // Returns count array
    return count - 1;
}

// Setting up the providerArray
void printProviderArray(Provider providerArray[], int size)
{
    int i;
    cout << fixed << setprecision(2);

    for (i = 0; i < size; i++)
    {
        providerArray[i].print();
        cout << endl;
    }
}

// Provider accessor methods

/*
setProviderSpecialty accessor method within the Provider
*/
void Provider::setProviderSpecialty(const char* newProviderSpecialty)
{
    strcpy(providerSpecialty, newProviderSpecialty);
}
/*
setProviderFullName accessor method within the Provider
*/
void Provider::setProviderFullName(const char* newProviderFullName)
{
    strcpy(providerFullName, newProviderFullName);
}

/*
setProviderAddressOne accessor method within the Provider
*/
void Provider::setProviderAddressOne(const char* newProviderAddressOne)
{
    strcpy(providerAddressOne, newProviderAddressOne);
}

/*
setProviderAddressTwo accessor method within the Provider
*/
void Provider::setProviderAddressTwo(const char* newProviderAddessTwo)
{
    strcpy(providerAddressTwo, newProviderAddessTwo);
}

/*
setProviderCity accessor method within the Provider
*/
void Provider::setProviderCity(const char* newProviderCity)
{
    strcpy(providerCity, newProviderCity);
}

/*
setProviderState accessor method within the Provider
*/
void Provider::setProviderState(const char* newProviderState)
{
    strcpy(providerState, newProviderState);
}

/*
setProviderPhoneNumber accessor method within the Provider
*/
void Provider::setProviderPhoneNumber(const char* newProviderPhoneNumber)
{
    strcpy(providerPhoneNumber, newProviderPhoneNumber);
}

// Get Name - Return Name

// Pointer to getProviderSpecialty which returns providerSpecialty
const char* Provider::getProviderSpecialty()
{
    return providerSpecialty;
}

// Pointer to getProviderFullName which returns providerFullName
const char* Provider::getProviderFullName() // Function calling getName
{
    return providerFullName;
}

// Pointer to getProviderAddressOne which returns providerAddressOne
const char* Provider::getProviderAddressOne()
{
    return providerAddressOne;
}

// Pointer to getProviderAddressTwo which returns providerAddressTwo
const char* Provider::getProviderAddressTwo()
{
    return providerAddressTwo;
}

// Pointer to getProviderCity which returns providerCity
const char* Provider::getProviderCity()
{
    return providerCity;
}

// Pointer to getProviderState which returns providerState
const char* Provider::getProviderState()
{
    return providerState;
}

// Pointer to getProviderPhoneNumber which returns providerPhoneNumber
const char* Provider::getProviderPhoneNumber()
{
    return providerPhoneNumber;
}

// Method for setting the providerNumber with a newProviderNumber and copying it to newProviderNumber
void Provider::setProviderNumber(const char *newProviderNumber)
{
    strcpy(providerNumber, newProviderNumber);
}

// Method for setting the providerZipCode with a newProviderZipCode and copying it to newProviderZipCode
void Provider::setProviderZipCode(const char * newProviderZipCode)
{
    strcpy(providerZipCode, newProviderZipCode);
}

// Pointer to getProviderNumber which returns providerNumber
const char* Provider::getProviderNumber()
{
    return providerNumber;
}

// Pointer to getProviderZipCode which returns providerZipCode
const char* Provider::getProviderZipCode()
{
    return providerZipCode;
}

/*
Output layout for the print function within the Provider Method
*/
void Provider::print() const
{
    cout << "#" << providerNumber << endl
         << providerSpecialty << endl
         << providerFullName << endl
         << providerAddressOne << endl
         << providerAddressTwo << endl
         << providerCity << ", "
         << providerState << endl
         << providerZipCode << endl
         << providerPhoneNumber << endl << endl;

}

