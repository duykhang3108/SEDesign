#pragma once
#include <string>
#include "Items.h"

using namespace std;
using namespace N;

/*namespace N {
	class Node {
	private:
		Item item;
	public:
		Node *next;
		Node *previous;

		Node();

		Node(Item item) {
			this->item = item;
			next = NULL;
			previous = NULL;
		}

		Item getItem() {
			return this->item;
		}

		string toString();
	};

	class Linked_list {
	private:
		Node *headpointer;
		Node *tailpointer;
		int size;

	public:
		Linked_list() {
			this->headpointer = NULL;
			this->tailpointer = NULL;
			this->headpointer->next = tailpointer;
			this->tailpointer->previous = headpointer;
			this->size = 0;
		}

		bool isEmpty() {
			return this->size == 0;
		}

		void insert(Node node) {
			if (this->size == 0) {
				this->headpointer->next = &node;
				node.previous = this->headpointer;
				node.next = tailpointer;
				tailpointer->previous = &node;
			}
			else
			{
				Node *curNode = this->headpointer->next;
				while (curNode != this->tailpointer)
				{
					curNode = curNode->next;
				}
				Node *prevNode = curNode->previous;
				prevNode->next = &node;
				node.previous = prevNode;
				node.next = curNode;
				curNode->previous = &node;
			}
			this->size += 1;
			cout << "Successfully inserted" << endl;
		}

		void printList() {
			Node *curNode = this->headpointer->next;
			while (curNode != this->tailpointer)
			{
				cout << curNode << endl;
				curNode = curNode->next;
			}
		}

		int getSize() {
			return this->size;
		}

		Node search(string id) {
			Node curNode;
			Node* curNode = this->headpointer->next;			
			while ((curNode.getItem().getID() != id) && (*curNode != this->tailpointer)
			{

			}
		}
	};
}*/