#include <string>
#include <iostream>
#include <cstdio>
#include "transaction.h"

using std::string;

string transaction::transaction_info()
{
	char buffer [50];

	//format transaction number for printing
	sprintf(buffer, "%i", transaction_number);
	string tnum_str(buffer);	
 
	//format quantity string for printing
	sprintf(buffer, "%i", quantity);
	string quantity_str(buffer);
		
	return "Transaction #: " + tnum_str + "\n" +
		   "Customer: \n" + customer.person_info() + "\n" +
		   "Product: \n" + purchased_item.product_info() + "\n" +
		   "Quantity: " + quantity_str;
}
