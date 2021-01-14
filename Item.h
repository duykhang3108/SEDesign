#include <iostream>
#include <string>
#include "Enumclass.h"

using namespace std;

class Item
{
public:
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
        if (this->noOfCopies == 0)
        {
            this->setRentalStatus(RentalStatus::NOT_AVAILABLE);
        }
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

    void setRentalStatus(RentalStatus rentalStatus)
    {
        this->rentalStatus = rentalStatus;
    }

    RentalStatus getRentalStatus()
    {
        return this->rentalStatus;
    }

    void setLoanType(LoanType setLoanType)
    {
        this->loanType = loanType;
    }

    string getLoanType()
    {
        if (this->loanType == LoanType::ONE_WEEK)
        {
            return "one-week";
        }
        else if (this->loanType == LoanType::TWO_DAYS)
        {
            return "two-day";
        }
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
               string(", copies: ") + to_string(noOfCopies) + string(", rental fee: ") + to_string(rentalFee) +
               string(", loan type: ") + this->getLoanType() + string("}");
        return item;
    }

private:
    string id;
    string title;
    float rentalFee;
    int noOfCopies;
    RentalStatus rentalStatus = RentalStatus::AVAILABLE;
    LoanType loanType;
};
