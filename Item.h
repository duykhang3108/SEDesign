#include <iostream>
#include <string>
#include "Enumclass.h"

using namespace std;

class Item
{
public:
    RentalStatus rentalStatus = RentalStatus::AVAILABLE;
    string getID()
    {
        return this->id;
    }

    void setID(string id)
    {
        this->id = id;
    }

    void setTitle(string title)
    {
        this->title = title;
    }

    string getTitle()
    {
        return this->title;
    }

    void setNoOfCopies(int noOfCopies)
    {
        this->noOfCopies = noOfCopies;
    }

    int getNoOfCopies()
    {
        return this->noOfCopies;
    }

    void setRentalFee(float rentalFee)
    {
        this->rentalFee = rentalFee;
    }

    float getRentalFee()
    {
        return this->rentalFee;
    }

    Item(string id, string title, int noOfCopies, float rentalFee)
    {
        this->id = id;
        this->title = title;
        this->noOfCopies = noOfCopies;
        this->rentalFee = rentalFee;
    }

    Item() { ; };

    string toString()
    {
        string item = "";
        item.reserve(1000);
        item = string("Item{ ") + string("id= ") + id + string(", title= ") + title +
               string(", copies: ") + to_string(noOfCopies) + string(", rental fee: ") + to_string(rentalFee) + string("}");
        return item;
    }

private:
    string id;
    string title;
    float rentalFee;
    int noOfCopies;
    LoanType loanType;
};
