#include <iostream>
#include "Customer.h"
#ifndef CUSTOMERLINKEDLIST_HEADER
#define CUSTOMERLINKEDLIST_HEADER

using namespace std;
using namespace N;

namespace N {
    class CustomerNode
    {
    public:
        Customer data;
        CustomerNode* next;
        CustomerNode* previous;

        CustomerNode() { ; };
    };

    class CustomerLinkedList
    {
    private:
        CustomerNode* head, * tail;
        int size;
        CustomerNode* dummy1 = new CustomerNode;
        CustomerNode* dummy2 = new CustomerNode;
    public:
        CustomerLinkedList()
        {
            /*head = new CustomerNode;
            tail = new CustomerNode;*/
            head = dummy1;
            tail = dummy2;
            head->next = tail;
            tail->previous = head;
            this->size = 0;
        }

        void add_front(Customer customer)
        {
            CustomerNode* tmp = new CustomerNode;

            tmp->data = customer;

            CustomerNode* nextCustomerNode = new CustomerNode;

            nextCustomerNode = head->next;
            head->next = tmp;
            tmp->previous = head;
            tmp->next = nextCustomerNode;
            nextCustomerNode->previous = tmp;


            /*tmp->next = head;
            head = tmp;*/
            this->size++;
        }

        void display() {
            CustomerNode* tmp = new CustomerNode;
            tmp = head->next;

            while (tmp != tail) {
                cout << tmp->data.toString() << endl;
                tmp = tmp->next;
            }
        }

        string find(string id) {
            CustomerNode* tmp = new CustomerNode;
            tmp = head->next;

            while ((tmp->data.getID() != id) && (tmp != NULL))
            {
                tmp = tmp->next;
                if (tmp == NULL) {
                    return "Cannot find matching item";
                }
            }
            cout << "Found matching item" << endl;
            return tmp->data.toString();
        }

        string deleteItem(string id) {
            CustomerNode* tmp = new CustomerNode;
            tmp = head;

            if (head->data.getID() == id)
            {
                head = tmp->next;
                delete tmp;
                return "Successfully deleted";
            }

            while ((tmp->data.getID() != id) && (tmp != NULL))
            {
                tmp = tmp->next;
                if (tmp == NULL) {
                    return "Cannot find matching item";
                }
            }

            CustomerNode* prevCustomerNode = new CustomerNode;
            prevCustomerNode = tmp->previous;

            CustomerNode* nextCustomerNode = new CustomerNode;
            nextCustomerNode = tmp->next;
            prevCustomerNode->next = nextCustomerNode;
            nextCustomerNode->previous = prevCustomerNode;

            delete tmp;
            this->size--;

            return "Successfully deleted";
        }

        void updateCustomer() {
            string id;
            cout << "Enter customer id: ";
            getline(cin, id);
            cout << endl;

            CustomerNode* tmp = new CustomerNode;
            tmp = head->next;

            while ((tmp->data.getID() != id) && (tmp != NULL))
            {
                tmp = tmp->next;
                if (tmp == NULL) {
                    cout << "Cannot find matching item" << endl;
                    return;
                }
            }
            cout << "Found matching item" << endl;
            cout << "Begin updating" << endl;

            cout << "Enter name: ";
            string name;
            getline(cin, name);
            tmp->data.setName(name);
            cout << endl;

            cout << "Enter address: ";
            string address;
            getline(cin, address);           
            tmp->data.setAddress(address);
            cout << endl;

            cout << "Enter phone: ";
            string phone;
            getline(cin, phone);           
            tmp->data.setPhone(phone);
            cout << endl;

            cout << "Customer updated as follow: " << endl;
            cout << tmp->data.toString() << endl;
        }

        bool isEmpty() {
            return this->size == 0;
        }

        int getSize() {
            return this->size;
        }
    };
}

#endif
