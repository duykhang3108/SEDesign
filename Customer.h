#include <string>
#include "ArrayList.h"
#include "Item.h"


#ifndef CUSTOMER_HEADER
#define CUSTOMER_HEADER

using namespace std;


namespace N
{
	class Customer
	{
	private:
		string id;
		string name;
		string address;
		string phone;
		int history = 0;

	public:
		Customer() { ; };

		Customer(string id, string name, string address, string phone)
		{
			this->id = id;
			this->name = name;
			this->address = address;
			this->phone = phone;
		}

		string getID()
		{
			return this->id;
		}

		string getName()
		{
			return this->name;
		}

		string getAddress()
		{
			return this->address;
		}

		string getPhone()
		{
			return this->phone;
		}

		int getHistory()
		{
			return this->history;
		}

		void setName(string name)
		{
			this->name = name;
		}

		void setID(string id)
		{
			this->id = id;
		}

		void setAddress(string address)
		{
			this->address = address;
		}

		void setPhone(string phone)
		{
			this->phone = phone;
		}

		void setHistory(int history)
		{
			this->history = history;
		}

		string toString()
		{
			string item;
			item.reserve(1000);
			item = string("Customer{") + string("id: ") + id + string(", name: ") + name +
				   string(", address: ") + address + string(", phone: ") + phone + "}";
			return item;
		}

		virtual bool rentItem(Item *item);
		virtual bool returnItem(Item *item);
	};
} // namespace N

#endif