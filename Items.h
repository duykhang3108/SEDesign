#include <iostream>
#include <string>
#include "Enumclass.h"

#ifndef ITEM_HEADER
#define ITEM_HEADER
using namespace std;
using namespace N;

namespace N
{
    class Item {
    public:
        string getID() {
            return this->id;
        }

        void setID(string id) {
            this->id = id;
        }

        void setTitle(string title) {
            this->title = title;
        }

        void setNoOfCopies(string noOfCopies) {
            this->noOfCopies = noOfCopies;
        }

        void setRentalFee(string rentalFee) {
            this->rentalFee = rentalFee;
        }

        Item(string id, string title, string noOfCopies, string rentalFee)
        {
            this->id = id;
            this->title = title;
            this->noOfCopies = noOfCopies;
            this->rentalFee = rentalFee;
        }

        Item() { ; };

        string toString() { 
            /*string item = "Item{ ";
            string item2 = item + "id= " + id + ", ";
            string item3 = item2 + "title= " + title + ", ";
            string item4 = item3 + "Copies: " + noOfCopies + ", " ;
            string item5 = item4 + "Rental Fee: " + rentalFee + "}";*/
            string item = "";
            item.reserve(1000);
            item = string("Item{ ") + string("id= ") + id + string(", title= ") + title +
                string(", copies: ") + noOfCopies + string(", rental fee: ") + rentalFee + string("}");          
            return item;
        }
    private:
        string id;
        string title;
        string noOfCopies;
        string rentalFee;
        RentalStatus rentalStatus;    
    };

    class DVD : public Item {
    private:
        RentalType rentalType;
    protected:
        using Item::Item;
    };

    class MovieRecords : public Item {
    private:
        RentalType rentalType;
    protected:
        using Item::Item;
    };

    class VideoGames : public Item {
    private:
        RentalType rentalType;
    protected:
        using Item::Item;
    };
}

#endif