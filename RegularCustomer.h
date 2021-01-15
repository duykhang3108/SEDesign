#include <iostream>
#include <string>
#include "Item.h"
#include "Customer.h"
#include "Enumclass.h"
#include "ItemLinkedList.h"

#ifndef REGULAR_HEADER
#define REGULAR_HEADER

class RegularCustomer : public Customer
{
private:
    int numRented = 0;
    ItemLinkedList rentalList;

public:
    RegularCustomer();
    RegularCustomer(string id, string name, string address, string phone) : Customer(id, name, address, phone){};

    bool rentItem(string id)
    {
        Item item;

        if (item.getNoOfCopies() == 0)
        {
            cout << "No copy of item available for rent." << endl;
            return false;
        }

        else
        {
            cout << "Customer no. " << this->getID() << " has borrowed " << item.getTitle() << endl;
            cout << "Rental fee: " << item.getRentalFee() << "USD" << endl;
            this->rentalList.add_front(item);
            item.setNoOfCopies(item.getNoOfCopies() - 1);
            return true;
        }
    }

    bool returnItem(string id)
    {
        Item item;
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
            cout << "Customer no." << this->getID() << " has returned " << item.getTitle() << endl;
            this->rentalList.deleteItem(item.getID());
            this->setHistory(this->getHistory() + 1);
            item.setNoOfCopies(item.getNoOfCopies() + 1);
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
            VIPCustomer promotedCus(this->getID(), this->getName(), this->getAddress(), this->getPhone());
            list.add_front(promotedCus);
        }
    }
};

#endif
