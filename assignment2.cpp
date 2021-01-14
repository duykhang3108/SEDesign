// assignment2.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Item.h"
#include "Customer.h"
#include "Guest.h"
#include "RegularCustomer.h"
#include "VIPCustomer.h"
#include "ItemLinkedList.h"
#include "CustomerLinkedList.h"

using namespace std;
using namespace N;

int main()
{

    ItemLinkedList itemDatabase;

    Item item3("003", "Book", 4, 10);
    Item item1("001", "Book", 4, 11);
    Item item2("002", "Book", 5, 9.99);
    Item item4("004", "Book", 5, 5.99);
    Item item5("005", "Book", 5, 6);

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

    return 0;
}
