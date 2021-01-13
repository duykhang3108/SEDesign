#include <iostream>
#include <string>
#include "Item.h"
#include "Customer.h"
#include "Enumclass.h"
#include "ItemLinkedList.h"

#ifndef VIP_HEADER
#define VIP_HEADER

class VIPCustomer : public Customer
{
private:
    int rewardPoints = 0;
    ItemLinkedList rentalList;

public:
    VIPCustomer(string id, string name, string address, string phone) : Customer(id, name, address, phone){};

    bool rentItem(Item item)
    {
        if (item.getNoOfCopies() == 0)
        {
            cout << "No copy of item available for rent." << endl;
            return false;
        }

        else
        {
            cout << "Customer no. " << this->getID() << " has borrowed " << item.getTitle() << endl;
            if (this->rewardPoints >= 100)
            {
                cout << "Rental fee: FREE (reward points applied)" << endl;
            }
            else
            {
                cout << "Rental fee: " << item.getRentalFee() << "USD" << endl;
            }
            this->rentalList.add_front(item);
            item.setNoOfCopies(item.getNoOfCopies() - 1);
            return true;
        }
    }

    bool returnItem(Item item)
    {
        bool found = false;
        for (int i = 0; i < this->rentalList.getSize(); i++)
        {
            if (item.getID().compare(this->rentalList.find(item.getID())) == 0)
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Item not found." << endl;
            return false;
        }
        else
        {
            cout << "Customer no. " << this->getID() << " has returned " << item.getTitle() << endl;
            this->rentalList.deleteItem(item.getID());
            this->setHistory(this->getHistory() + 1);
            this->rewardPoints += 10;
            item.setNoOfCopies(item.getNoOfCopies() + 1);
            return true;
        }
    }
};

#endif
