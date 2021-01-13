#include <string>
#include "ArrayList.h"
#include "Item.h"
#ifndef CUSTOMER_HEADER
#define CUSTOMER_HEADER

using namespace std;
using namespace N;

namespace N
{
	class Customer
	{
	private:
		string id;
		string name;
		string address;
		string phone;
		// string customerType;
		// int currentLevel;
		// int maxItemRent;
		// int minItemToPromote = 3;
		// int minLevelToRentUnlimitedItems = 2;
		int history;

		// void changeMaxItemRent()
		// {
		// 	if (this->currentLevel >= this->minLevelToRentUnlimitedItems)
		// 	{
		// 		this->maxItemRent = 3;
		// 	}
		// }

	public:
		Customer() { ; };

		Customer(string id, string name, string address, string phone)
		{
			this->id = id;
			this->name = name;
			this->address = address;
			this->phone = phone;
			// this->maxItemRent = 2;
			// this->customerType = customerType;
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
			item = string("Customer{ ") + string("id: ") + id + string(", name: ") + name +
				   string(", address: ") + address + string(", phone: ") + phone + string(", customer type: ");
			return item;
		}

		// void promote()
		// {
		// 	if (checkValidPromotion(this->currentLevel, this->history))
		// 	{
		// 		this->currentLevel += 1;
		// 	}
		// }

		// bool checkValidPromotion(int currentLevel, int currentItemRent)
		// {
		// 	if (currentItemRent <= minItemToPromote)
		// 	{
		// 		cout << "Customer has not reached the minimum item rent number. Required: %d, current %d /n", minItemToPromote, currentItemRent;
		// 		return false;
		// 	}
		// 	else if (currentLevel == 3)
		// 	{
		// 		cout << "Customer has reached the highest customer level: VIP" << endl;
		// 		return false;
		// 	}
		// 	else
		// 		return true;
		// }

		virtual bool rentItem(Item *item);
		virtual bool returnItem(Item *item);
	};
} // namespace N

#endif