#include <string>
#include <iostream>
#include "Enumclass.h"
#include "HashTable.h"

using namespace std;

namespace N{
	//Singleton design pattern
	class CustomerLevelMapping {
		static CustomerLevelMapping* instance;
		CustomerLevelMapping(){}
	public:
		static CustomerLevelMapping* getInstance() {
			if (!instance) {
				instance = new CustomerLevelMapping;
			}
			return instance;
		}

		HashTable CUSTOMER_LEVEL;

	private:
		CustomerLevelMapping() {
			Customer customer1("001", "khang", "address", "123456", "REGULAR");
			CUSTOMER_LEVEL.addCustomer(&customer1);
			CUSTOMER_LEVEL.retrieveCustomer(001);
		}
	};
}
