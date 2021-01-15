#include <iostream>
#include <string>
#include "Item.h"
#include "Customer.h"
#include "CustomerLinkedList.h"
#include "RegularCustomer.h"
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
    Guest(string id, string name, string address, string phone) : Customer(id, name, address, phone){};
    Guest() : Customer() { ; };

    bool findItemByID(string id, ItemLinkedList list)
    {
        bool found;
        Item *item;

        for (int i = 0; i < list.getSize(); i++)
        {
            if (list.find(id).compare(item->getID()) == 0)
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "There is no item with such ID." << endl;
            return false;
        }

        else
        {
            if (item->getNoOfCopies() == 0)
            {
                cout << "No copy of item available for rent." << endl;
                return false;
            }
            if (this->numRented >= MAX_RENT)
            {
                cout << "A guest can only rent a maximum of " << MAX_RENT << " items at a time." << endl;
                return false;
            }
            if (item->getLoanType() == "2-day")
            {
                cout << "A guest can't rent a 2-day item." << endl;
            }
            if (item->getRentalStatus() == RentalStatus::AVAILABLE)
            {
                cout << "Customer no." << this->getID() << " has borrowed " << item->getTitle() << endl;
                cout << "Rental fee: " << item->getRentalFee() << "USD" << endl;
                this->rentalList[numRented] = item;
                numRented++;
                item->setNoOfCopies(item->getNoOfCopies() - 1);
                return true;
            }
            else
            {
                return false;
            }
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
            cout << "Customer no." << this->getID() << " has returned " << item->getTitle() << endl;
            this->rentalList[numRented--] = NULL;
            this->setHistory(this->getHistory() + 1);
            item->setNoOfCopies(item->getNoOfCopies() + 1);

            return true;
        }
    }
    void promote(CustomerLinkedList list)
    {
        // check for validity
        if (this->getHistory() < 3)
        {
            cout << "This customer hasn't meet the requirement to be promoted." << endl;
        }
        else
        {
            list.deleteItem(this->getID());
            RegularCustomer promotedCus(this->getID(), this->getName(), this->getAddress(), this->getPhone());
            list.add_front(promotedCus);
        }
    }
};

#endif
