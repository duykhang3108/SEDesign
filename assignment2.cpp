// assignment2.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include "Item.h"
#include "Customer.h"
#include "Guest.h"
#include "RegularCustomer.h"
#include "VIPCustomer.h"
#include "ItemLinkedList.h"
#include "CustomerLinkedList.h"

using namespace std;
using namespace N;

Item readItemFile(ifstream &, string);

ItemLinkedList itemDatabase;
CustomerLinkedList customerDatabase;

// Function to print the group's details
void printGroup()
{
	cout << endl;
	cout << "ASSIGNMENT 1 GROUP 16" << endl;
	cout << "s3754467, s3754467@rmit.edu.vn, Nhi, Vo" << endl;
	cout << "s3759777, s3759777@rmit.edu.vn, Anh, Nguyen" << endl;
	cout << "s3753740, s3753740@rmit.edu.vn, Khang, Tran" << endl;
	cout << "s3754707, s3754707@rmit.edu.vn, Nguyen, Nguyen" << endl;
}

void clearScreen()
{
	cout << string(100, '\n');
}

void greetings()
{
	cout << "=================================" << endl;
	cout << "Welcome to Genie's video store: " << endl;
	cout << "Enter an option below: " << endl;
	cout << "1. Add a new item" << endl;
	cout << "2. Update an item" << endl;
	cout << "3. Delete an item" << endl;
	cout << "4. Add a new customer" << endl;
	cout << "5. Update a customer information" << endl;
	cout << "6. Delete a customer" << endl;
	cout << "7. Promote a customer" << endl;
	cout << "8. Display all customers" << endl;
	cout << "9. Display all items" << endl;
	cout << "10. Display group of customers" << endl;
	cout << "11. Display out-of-stock items" << endl;
	cout << "12. Rent an item" << endl;
	cout << "13. Return an item" << endl;
	cout << "14. Exit" << endl;
	cout << endl;
	cout << "Enter your choice: " << endl;
	return;
}

void addNewItem()
{
	Item newItem;

	cout << "Enter item's id: ";
	string id;
	getline(cin, id);
	newItem.setID(id);

	cout << "Enter item's title: ";
	string title;
	getline(cin, title);
	newItem.setTitle(title);

	cout << "Enter item's rental fee: ";
	float rentalFee;
	cin >> rentalFee;
	newItem.setRentalFee(rentalFee);

	cout << "Enter item's number of copies in stock: ";
	int noOfCopies;
	cin >> noOfCopies;
	newItem.setNoOfCopies(noOfCopies);

	cout << "Set item's loan type: ";
	string loanType;
	cin >> loanType;
	newItem.setLoanType(loanType);

	cout << "Set item's rent type: ";
	string rentType;
	cin >> rentType;
	newItem.setRentType(rentType);

	itemDatabase.add_front(newItem);
	return;
}

void addNewCustomer()
{
	Guest newCustomer;

	cout << "Enter customer's id: ";
	string id;
	getline(cin, id);
	newCustomer.setID(id);

	cout << "Enter customer's name: ";
	string name;
	getline(cin, name);
	newCustomer.setName(name);

	cout << "Enter customer's address: ";
	string address;
	getline(cin, address);
	newCustomer.setAddress(address);

	cout << "Enter customer's phone numbers: ";
	string phone;
	getline(cin, phone);
	newCustomer.setPhone(phone);

	customerDatabase.add_front(newCustomer);
	return;
}

void addDummies()
{
	Item item3("003", "Book", 4, 10, "DVD", "2-day");
	Item item1("001", "Book", 4, 11, "Record", "2-day");
	Item item2("002", "Book", 5, 9.99, "Game", "2-day");
	Item item4("004", "Book", 5, 5.99, "DVD", "1-week");
	Item item5("005", "Book", 5, 6, "Game", "2-day");

	itemDatabase.add_front(item3);
	itemDatabase.add_front(item1);
	itemDatabase.add_front(item2);
	itemDatabase.add_front(item4);

	RegularCustomer customer1("001", "Khang", "address1", "123456");
	Guest customer2("002", "Long", "address2", "123456");
	RegularCustomer customer3("003", "Nguyen", "address3", "123456");
	RegularCustomer customer4("004", "Nhi", "address4", "123456");
	VIPCustomer customer5("005", "Kiet", "address5", "123456");

	customerDatabase.add_front(customer1);
	customerDatabase.add_front(customer2);
	customerDatabase.add_front(customer3);
	customerDatabase.add_front(customer4);
}

void menu()
{
	string choice;

	greetings();
	while (choice != "Exit")
	{

		getline(cin, choice);
		if (choice == "1")
		{
			addNewItem();
			menu();
		}

		if (choice == "2")
		{
			itemDatabase.updateItem();
			menu();
		}

		if (choice == "3")
		{
			string id;
			cout << "Enter item's id: ";
			getline(cin, id);
			itemDatabase.deleteItem(id);
			menu();
		}

		if (choice == "4")
		{
			addNewCustomer();
			menu();
		}

		if (choice == "5")
		{
			customerDatabase.updateCustomer();
			menu();
		}

		if (choice == "6")
		{
			string id;
			cout << "Enter item's id: ";
			getline(cin, id);
			customerDatabase.deleteItem(id);
			menu();
		}

		if (choice == "7")
		{
			menu();
		}

		if (choice == "8")
		{
			customerDatabase.display();
			menu();
		}

		if (choice == "9")
		{
			itemDatabase.display();
			menu();
		}

		if (choice == "10")
		{
			menu();
		}

		if (choice == "11")
		{
			itemDatabase.outOfStockItems();
			menu();
		}

		if (choice == "12")
		{
			menu();
		}

		if (choice == "13")
		{
			menu();
		}

		if (choice == "Exit")
		{
			printGroup();
			break;
		}
		if (choice == "")
		{
			continue;
		}
		else
		{
			cout << "Invalid input. Please try again" << endl;
			continue;
		}
	}
	return;
}

int main()
{
	string itemDB, customerDB;

	cout << "Please input item database file: ";
	cin >> itemDB;
	cout << "Please input customer database file: ";
	cin >> customerDB;

	//ifstream
	ifstream itemFile(itemDB);
	ifstream customerFile(customerDB);

	//check if file is opened
	if (!itemFile.is_open() || !customerFile.is_open())
	{
		cerr << "Error opening database file" << endl;
	}
	else
	{
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
	}
	addDummies();
	menu();

	//save to files
	ofstream outItemFile(itemDB);

	//check if file is opened
	if (!itemFile.is_open() || !customerFile.is_open())
	{
		cerr << "Error opening database file" << endl;
	}
	else
	{
		itemDatabase.saveToItemFile(outItemFile);
	}
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

		if (rentType == "DVD" || rentType == "Record")
		{
			getline(ss, tempString, ',');
			rentalFee = stof(tempString);
			getline(ss, genre);
			temp.setGenre(genre);
		}
		else
		{
			getline(ss, tempString);
			rentalFee = stof(tempString);
		}

		temp.setID(id);
		temp.setTitle(title);
		temp.setNoOfCopies(noOfCopies);
		temp.setRentalFee(rentalFee);
		temp.setLoanType(loanType);
		temp.setRentType(rentType);
	}
	return temp;
}
