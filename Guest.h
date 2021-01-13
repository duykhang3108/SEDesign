#include <iostream>
#include <string>
#include "Item.h"
#include "Customer.h"
#include "Enumclass.h"

#ifndef GUEST_HEADER
#define GUEST_HEADER

using namespace std;

#define MAX_RENT 2

class Guest : public Customer
{
private:
    int numRented = 0;
    Item *rentalList[MAX_RENT];

public:
    Guest(string id, string name, string address, string phone);

    bool rentItem(Item *item)
    {
        if (item->getNoOfCopies() == 0)
        {
            cout << "No copy of item available for rent." << endl;
            return false;
        }
        if (numRented >= MAX_RENT)
        {
            cout << "A guest can only rent a maximum of " << MAX_RENT << " items at a time." << endl;
            return false;
        }
        if (item->rentalStatus == RentalStatus::AVAILABLE)
        {
            cout << "Customer no. " << this->getID() << " has borrowed " << item->getTitle() << endl;
            cout << "Rental fee: " << item->getRentalFee() << "USD" << endl;
            this->rentalList[numRented] = item;
            numRented++;
            item->setNoOfCopies(item->getNoOfCopies() - 1);
            return true;
        }
    }
    bool returnItem(Item *item)
    {
        bool found = false;
        for (int i = 0; i < MAX_RENT; i++)
        {
            if (this->rentalList[i] != NULL)
            {
                if (item->getID().compare(this->rentalList[i]->getID()) == 0)
                {
                    found = true;
                    break;
                }
            }
        }
        if (!found)
        {
            cout << "Item not found." << endl;
            return false;
        }
        else
        {
            cout << "Customer no. " << this->getID() << " has returned " << item->getTitle() << endl;
            this->rentalList[numRented--] = NULL;
            this->setHistory(this->getHistory() + 1);
            item->setNoOfCopies(item->getNoOfCopies() + 1);
            return true;
        }
    }
};

#endif
