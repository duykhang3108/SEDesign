// assignment2.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>
#include <sstream>
#include "Item.h"
#include "Customer.h"
#include "Guest.h"
#include "RegularCustomer.h"
#include "VIPCustomer.h"
#include "ItemLinkedList.h"
#include "CustomerLinkedList.h"

using namespace std;
using namespace N;

Item readItemFile(ifstream&,string);

int main()
{

    ItemLinkedList itemDatabase;

    Item item3("003", "Book", 4, 10, 1);
    Item item1("001", "Book", 4, 11, 2);
    Item item2("002", "Book", 5, 9.99, 2);
    Item item4("004", "Book", 5, 5.99, 1);
    Item item5("005", "Book", 5, 6, 1);

    itemDatabase.add_front(item3);
    itemDatabase.add_front(item1);
    itemDatabase.add_front(item2);
    itemDatabase.add_front(item4);

    itemDatabase.display();
    cout << itemDatabase.find("003") << endl;
    cout << itemDatabase.deleteItem("004") << endl;
    itemDatabase.add_front(item5);

    CustomerLinkedList customerDatabase;
    RegularCustomer customer1("001", "Khang", "address1", "123456");
    Guest customer2("002", "Long", "address2", "123456");
    RegularCustomer customer3("003", "Nguyen", "address3", "123456");
    RegularCustomer customer4("004", "Nhi", "address4", "123456");
    VIPCustomer customer5("005", "Kiet", "address5", "123456");

    customerDatabase.add_front(customer1);
    customerDatabase.add_front(customer2);
    customerDatabase.add_front(customer3);
    customerDatabase.add_front(customer4);

    customer2.rentItem(&item3);
    customer2.returnItem(&item3, customerDatabase);

    customer2.rentItem(&item4);
    customer2.returnItem(&item4, customerDatabase);

    customer2.rentItem(&item4);
    customer2.returnItem(&item4, customerDatabase);


	//load the database

		// Create ifstreams
	ifstream itemFile("items.txt");
	

	//check if file is opened
	if (!itemFile.is_open())
	{
		cerr << "Error opening file" << endl;
		return 0;
	}

	string line;
	Item tempItem;

	//read file
	while (getline(itemFile, line))
	{
		tempItem = readItemFile(itemFile, line);
		if (line[0] != '#')
		{
			itemDatabase.add_front(tempItem);
		}
	}

	string line2;
	Customer temCus;

	//display
	itemDatabase.display();


	


	//close file
	itemFile.close();

    return 0;
}


Item readItemFile(ifstream &file, string line)
{
	Item temp;
	float rentalFee = 0;
	int noOfCopies = 0;
	string id, title, loanType, rentType, genre, tempString;
	stringstream ss(line);
	if (line[0] != '#')
	{
		getline(ss, id, ',');
		getline(ss, title, ',');
		getline(ss, rentType, ',');
		getline(ss, loanType, ',');
		getline(ss, tempString, ',');
		noOfCopies = stoi(tempString);
		getline(ss, tempString);
		rentalFee = stof(tempString);

		temp.setID(id);
		temp.setTitle(title);
		temp.setNoOfCopies(noOfCopies);
		temp.setRentalFee(rentalFee);
	}
	return temp;
}
