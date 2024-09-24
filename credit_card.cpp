#include <string>
#include <iostream>
#include <cstdio>
#include "credit_card.h"

using std::string;

bool credit_card::make_purchase(double purchase_amount)
{
	if ( (purchase_amount + current_balance) > limit ) return false;
	else 
	{
		current_balance += purchase_amount; 
		return true;
	}	
}

bool credit_card::make_payment(double payment_amount)
{
	if( (current_balance - payment_amount) < 0 ) return false;
	else
	{
		current_balance -= payment_amount;
		return true;
	}
}

string credit_card::credit_card_info()
{
	char buffer [50];

	//format credit card number for printing
	sprintf(buffer, "%i", cc_number);
	string card_number_string(buffer);	
 
	//format limit string for printing
	sprintf(buffer, "%.2f", limit);
	string limit_str(buffer);

	//format balance string for printing
	sprintf(buffer, "%.2f", current_balance);
	string balance_str(buffer);
		
		
	return "Credit card number: " + card_number_string + "\n" 
		 + "Credit Card Limit: $" + limit_str + "\n"
		 + "Current Balance: $" + balance_str;
}
