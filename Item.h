#pragma once

#include <iostream>
#include <string>
#include "Enumclass.h"

using namespace std;

class Item
{

private:
    string id;
    string title;
    float rentalFee;
    int noOfCopies;
    RentType rentType;
    RentalStatus rentalStatus = RentalStatus::AVAILABLE;
    LoanType loanType;
    Genres genre;

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

    void setRentType(string type)
    {
        if (type == "DVD")
        {
            this->rentType = RentType::DVD;
        }
        else if (type == "Game")
        {
            this->rentType = RentType::VIDEOGAMES;
        }
        else if (type == "Record")
        {
            this->rentType = RentType::MOVIERECORDS;
        }
        return;
    }

    string getRentType()
    {
        if (this->rentType == RentType::DVD)
        {
            return "DVD";
        }
        else if (this->rentType == RentType::VIDEOGAMES)
        {
            return "Games";
        }
        else if (this->rentType == RentType::MOVIERECORDS)
        {
            return "Record";
        }
        else
        {
            return "Null";
        }
    }

    void setLoanType(string type)
    {
        if (type == "1-week")
        {
            this->loanType = LoanType::ONE_WEEK;
        }
        else if (type == "2-day")
        {
            this->loanType = LoanType::TWO_DAYS;
        }
        return;
    }

    string getGenre()
    {
        if (this->genre == Genres::ACTION)
        {
            return ",Action";
        }
        else if (this->genre == Genres::HORROR)
        {
            return ",Horror";
        }
        else if (this->genre == Genres::DRAMA)
        {
            return ",Drama";
        }
        else if (this->genre == Genres::COMEDY)
        {
            return ",Comedy";
        }
        else
        {
            return "";
        }
    }

    void setGenre(string type)
    {
        if (type == "Horror")
        {
            this->genre = Genres::HORROR;
        }
        else if (type == "Comedy")
        {
            this->genre = Genres::COMEDY;
        }
        else if (type == "Dram")
        {
            this->genre = Genres::DRAMA;
        }
        else if (type == "Action")
        {
            this->genre = Genres::ACTION;
        }
        else{
            return;
        }
        return;
    }

    string getLoanType()
    {
        if (this->loanType == LoanType::ONE_WEEK)
        {
            return "1-week";
        }
        else if (this->loanType == LoanType::TWO_DAYS)
        {
            return "2-day";
        }
        else
        {
            return "Null";
        }
    }

    Item(string id, string title, int noOfCopies, float rentalFee, string rentT, string loanT, string genre = "")
    {
        this->id = id;
        this->title = title;
        this->noOfCopies = noOfCopies;
        this->rentalFee = rentalFee;
        this->setRentType(rentT);
        this->setLoanType(loanT);
        if (rentT=="Record" || rentT == "DVD"){
            this->setGenre(genre);
        }
    }

    Item() { ; };

    string toString()
    {
        string item = "";
        item.reserve(1000);
        item = string("Item{") + string("id= ") + id + string(", title= ") + title +
               string(", copies: ") + to_string(noOfCopies) + string(", rental fee: ") + to_string(rentalFee) +
               string(", rent type: ") + this->getRentType() + string("}");
        return item;
    }
};
