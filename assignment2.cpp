// assignment2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Item.h"
#include "Customer.h"
#include "ItemLinkedList.h"
#include "CustomerLinkedList.h"

using namespace std;
using namespace N;

int main()
{

    ItemLinkedList list1;
    cout << "Begin adding list of items" << endl;
    cout << "Below is a new linked list" << endl;

    Item item3("003", "Book", 4, 10);
    Item item1("001", "Book", 4, 11);
    Item item2("002", "Book", 5, 9.99);
    Item item4("004", "Book", 5, 5.99);
    Item item5("005", "Book", 5, 6);

    list1.add_front(item3);
    list1.add_front(item1);
    list1.add_front(item2);
    list1.add_front(item4);

    list1.display();
    cout << list1.find("003") << endl;
    cout << list1.deleteItem("004") << endl;
    list1.add_front(item5);

    cout << "New linked list" << endl;
    list1.display();

    cout << "Begin adding list of customers" << endl;
    CustomerLinkedList list2;
    Customer customer1("001", "Khang", "address1", "123456", "REGULAR");
    Customer customer2("002", "Long", "address2", "123456", "VIP");
    Customer customer3("003", "Nguyen", "address3", "123456", "GUEST");
    Customer customer4("004", "Nhi", "address4", "123456", "REGULAR");
    Customer customer5("005", "Kiet", "address5", "123456", "VIP");

    list2.add_front(customer1);
    list2.add_front(customer2);
    list2.add_front(customer3);
    list2.add_front(customer4);

    list2.display();

    cout << list2.find("002") << endl;
    cout << list2.deleteItem("001") << endl;
    list2.add_front(customer5);

    cout << "New customer list" << endl;
    list2.display();

    list2.updateCustomer();
    cout << "List with updated customer" << endl;
    list2.display();
    return 0;
}
