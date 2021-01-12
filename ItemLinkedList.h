#include <iostream>
#include "Items.h"
#ifndef ITEMLINKEDLIST_HEADER
#define ITEMLINKEDLIST_HEADER

using namespace std;
using namespace N;

namespace N {
    class ItemNode
    {   
    public:
        Item data;
        ItemNode* next;
        ItemNode* previous;

        ItemNode() { ; };
    };

    class ItemLinkedList
    {
    private:
        ItemNode* head, * tail;
        int size;
        ItemNode* dummy1 = new ItemNode;
        ItemNode* dummy2 = new ItemNode;
    public:
        ItemLinkedList()
        {         
            head = dummy1;
            tail = dummy2;
            head->next = tail;
            tail->previous = head;
            this->size = 0;
        }

        void add_front(Item item)
        {
            ItemNode* tmp = new ItemNode;
            
            tmp->data = item;

            ItemNode* nextItemNode = new ItemNode;

            nextItemNode = head->next;
            head->next = tmp;
            tmp->previous = head;
            tmp->next = nextItemNode;
            nextItemNode->previous = tmp;
            this->size++;
        }

        void add_last(Item item)
        {
            ItemNode* tmp = new ItemNode;
            tmp->data = item;
            tmp->next = NULL;

            if (head == NULL)
            {
                head = tmp;
                tail = tmp;
            }
            else
            {
                tail->next = tmp;
                tail = tail->next;
            }
        }

        void display() {
            ItemNode* tmp = new ItemNode;
            tmp = head->next;

            while (tmp != tail) {
                cout << tmp->data.toString() << endl;
                tmp = tmp->next;
            }
        }

        string find(string id) {
            ItemNode* tmp = new ItemNode;
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
            ItemNode* tmp = new ItemNode;
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

            ItemNode* prevItemNode = new ItemNode;
            prevItemNode = tmp->previous;
            
            ItemNode* nextItemNode = new ItemNode;
            nextItemNode = tmp->next;
            prevItemNode->next = nextItemNode;
            nextItemNode->previous = prevItemNode;

            delete tmp;
            this->size--;

            return "Successfully deleted";
        }

        void updateItem() {
            string id;
            cout << "Enter item id: ";
            getline(cin, id);

            ItemNode* tmp = new ItemNode;
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

            cout << "Enter title: ";
            string title;
            getline(cin, title);
            tmp->data.setTitle(title);
            cout << endl;

            cout << "Enter number of copies in stock: ";
            string noOfCopies;
            getline(cin, noOfCopies);
            tmp->data.setNoOfCopies(noOfCopies);
            cout << endl;

            cout << "Enter rental fee: ";
            string rentalFee;
            getline(cin, rentalFee);
            tmp->data.setRentalFee(rentalFee);
            cout << endl;

            cout << "Item updated as follow: " << endl;
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