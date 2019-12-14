//*************************************************************
// CSCI 241 - Assignment 1
//
// PROGRAM: assign1
// PROGRAMMERS: Aleksandar Kljaic + Philip Boffa
// LOGON ID: z1815736 + z1831680
// DATE DUE: Thursday September 14, 2017
//
// PURPOSE: This program reads a series of records from
// a file into an array. The objects are
// printed, sorted by name, and then printed again.
//*************************************************************

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::fixed;
using std::ifstream;
using std::setprecision;
using std::string;
using std::getline;

class Provider
{
private:

    char providerNumber[7] = {};
    char providerSpecialty[41] = {};
    char providerFullName[41] = {}; // Concatenated version of the providers last name, first name, middle initial, and title
    char providerAddressOne[41] = {};
    char providerAddressTwo[31] = {}; // Concatenated version of the providers city, state, and zip code
    char providerCity[21] = {};
    char providerState[3] = {};
    char providerZipCode[6] = {};
    char providerPhoneNumber[15] = {};


public:
    // Constructors
    Provider() {}
    Provider(const char* newProviderNumber,
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

    // Accessor methods
    void setProviderFullName(const char*);
    const char* getProviderFullName();

    void setProviderSpecialty(const char*);
    const char* getProviderSpecialty();

    void setProviderAddressOne(const char*);
    const char* getProviderAddressOne();

    void setProviderAddressTwo(const char*);
    const char* getProviderAddressTwo();

    void setProviderCity(const char*);
    const char* getProviderCity();

    void setProviderState(const char*);
    const char* getProviderState();

    void setProviderPhoneNumber(const char*);
    const char* getProviderPhoneNumber();

    void setProviderZipCode(const char*);
    const char* getProviderZipCode();

    void setProviderNumber(const char*);
    const char* getProviderNumber();
    void print();

};

// Function Prototypes

int buildProviderArray(Provider[]);
void printProviderArray(Provider[], int);
void sortProviderArray(Provider[], int);

int buildProviderArray(Provider providerArray[])
{
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

    int count = 0;

    // Open the input file and test for failure
    inFile.open("providers.csv");
    if (!inFile)
    {
        cerr << "Error - unable to open input file\n";
        exit(1);
    }

    // Attempting to getline from CSV
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

void Provider::setProviderSpecialty(const char* newProviderSpecialty)
{
    strcpy(providerSpecialty, newProviderSpecialty);
}

void Provider::setProviderFullName(const char* newProviderFullName)
{
    strcpy(providerFullName, newProviderFullName);
}

void Provider::setProviderAddressOne(const char* newProviderAddressOne)
{
    strcpy(providerAddressOne, newProviderAddressOne);
}

void Provider::setProviderAddressTwo(const char* newProviderAddessTwo)
{
    strcpy(providerAddressTwo, newProviderAddessTwo);
}

void Provider::setProviderCity(const char* newProviderCity)
{
    strcpy(providerCity, newProviderCity);
}

void Provider::setProviderState(const char* newProviderState)
{
    strcpy(providerState, newProviderState);
}

void Provider::setProviderPhoneNumber(const char* newProviderPhoneNumber)
{
    strcpy(providerPhoneNumber, newProviderPhoneNumber);
}

// Get Name - Return Name

const char* Provider::getProviderSpecialty()
{
    return providerSpecialty;
}

const char* Provider::getProviderFullName() // Function calling getName
{
    return providerFullName;
}

const char* Provider::getProviderAddressOne()
{
    return providerAddressOne;
}

const char* Provider::getProviderAddressTwo()
{
    return providerAddressTwo;
}

const char* Provider::getProviderCity()
{
    return providerCity;
}

const char* Provider::getProviderState()
{
    return providerState;
}

const char* Provider::getProviderPhoneNumber()
{
    return providerPhoneNumber;
}

void Provider::setProviderNumber(const char *newProviderNumber)
{
    strcpy(providerNumber, newProviderNumber);
}

void Provider::setProviderZipCode(const char * newProviderZipCode)
{
    strcpy(providerZipCode, newProviderZipCode);
}

const char* Provider::getProviderNumber()
{
    return providerNumber;
}

const char* Provider::getProviderZipCode()
{
    return providerZipCode;
}


void Provider::print()
{
    cout << "#" << providerNumber << endl
         << providerSpecialty << endl
         << providerFullName << endl
         << providerAddressOne << endl
         << providerAddressTwo << endl
         << providerCity << ", "
         << providerState << endl
         << providerZipCode << endl
         << providerPhoneNumber << endl;

}

int main() // Main
{
    // Whatever stuff
    Provider providerArray[100]; // Change this number ASAP
    int count;

    count = buildProviderArray(providerArray);

    cout << "Assignment #1\n\n";

    printProviderArray(providerArray, count);
    return 0;
}
