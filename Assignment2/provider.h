#ifndef PROVIDER_H
#define PROVIDER_H

//*****************************************************************
// FILE:      Provider.h
// AUTHOR:    Aleksandar Kljaic + Philip Boffa
// LOGON ID:  z1815736 + z1831680
// DUE DATE:  Wednesday September 27, 2017
//
// PURPOSE:   Declaration for the Provider class, which represents
//            information about a health care provider.
//*****************************************************************

class Provider
{
        // Data members and method prototypes for the Provider class go here
private:

        char providerNumber[7] = {}; // providerNumber array holding 6 plus a null character
        char providerSpecialty[41] = {}; // providerSpecialty array holding 40 plus a null character
        char providerFullName[41] = {}; // Concatenated version of the providers last name, first name, middle initial, and title
        char providerAddressOne[41] = {}; // providerAddressOne array holding 40 plus a null character
        char providerAddressTwo[31] = {}; // Concatenated version of the providers city, state, and zip code
        char providerCity[21] = {}; // providerCity array holding 20 plus a null character
        char providerState[3] = {}; // providerState array holding 2 plus a null character
        char providerZipCode[6] = {}; // providerZipCode array holding 5 plus a null character
        char providerPhoneNumber[15] = {}; // providerPhoneNumber array holding 14 plus a null character


public:
        // Constructors
        Provider() {}

        /* Constructors for all arrays relating to Provider */
        Provider(const char* newProviderNumber,
                const char* newProviderSpecialty,
                const char* newProviderFullName,
                const char* newProviderAddressOne,
                const char* newProviderAddressTwo,
                const char* newProviderCity,
                const char* newProviderState,
                const char* newProviderZipCode,
                const char* newProviderPhoneNumber);


        // Accessor methods

        /* Accessor Method for setProviderFullname and getProviderFullName */
        void setProviderFullName(const char*);
        const char* getProviderFullName();

        /* Accessor Method for setProviderSpecialty and getProviderSpecailty */
        void setProviderSpecialty(const char*);
        const char* getProviderSpecialty();

        /* Accessor Method for setProviderAddressOne and getProviderAddressOne */
        void setProviderAddressOne(const char*);
        const char* getProviderAddressOne();

        /* Accessor Method for setProviderAddressTwo and getProviderAddessTwo */
        void setProviderAddressTwo(const char*);
        const char* getProviderAddressTwo();

        /* Accessor Method for setProviderCity and getProviderCity */
        void setProviderCity(const char*);
        const char* getProviderCity();

        /* Accessor Method for setProviderState and getProviderState */
        void setProviderState(const char*);
        const char* getProviderState();

        /* Accessor Method for setProviderPhoneNumber and getProviderPhoneNumber */
        void setProviderPhoneNumber(const char*);
        const char* getProviderPhoneNumber();

        /* Accessor Method for setProviderZipCode and getProviderZipCode */
        void setProviderZipCode(const char*);
        const char* getProviderZipCode();

        /* Accessor Method for setProviderNumber and getProviderNumber */
        void setProviderNumber(const char*);
        const char* getProviderNumber();

        /* Accessor Method for print  */
        void print() const;
};

#endif
