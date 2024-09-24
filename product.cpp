#include <string>
#include <iostream>
#include <cstdio>
#include "product.h"

using std::string;

string product::product_info()
{
	char buffer [50];

	//format balance string for printing
	sprintf(buffer, "%.2f", price);
	string price_str(buffer);
		
		
	return "Name: " + name + "\n" 
		 + "Description: " + description + "\n"
		 + "Price: $" + price_str;
}
