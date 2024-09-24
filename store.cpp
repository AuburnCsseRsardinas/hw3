#include <iostream>
#include <string>
#include "store.h"

using std::cout;
using std::endl;

Store::Store()
{
	num_products_ = 0;
	num_transactions_ = 0;	
	num_customers_ = 0;
}

void Store::num_products(int product_count) { num_products_ = product_count; }
int Store::num_products() { return num_products_; }

void Store::num_customers(int customer_count) { num_customers_ = customer_count; }
int Store::num_customers() { return num_customers_; }

void Store::num_transactions(int transaction_count) 
{ num_transactions_ = transaction_count; }

int Store::num_transactions() { return num_transactions_; }

bool Store::add_customer(Person customer)
{
	if (num_customers_ <100 )
	{
		customers_[num_customers_++] = customer;
		cout << "Adding customer" << endl;
		cout << "Adding customer" << endl;
		cout << customers_[num_customers_ -1].person_info() << endl << endl;
 
	}	
	else return false;
	return true;
}

Person Store::get_customer(int index) { return customers_[index]; }

bool Store::add_product(product item)
{
	if (num_products_ <100 ) products_[num_products_++] = item;	
	else return false;
	return true;
}

product Store::get_product(int index) { return products_[index]; }

bool Store::add_transaction(transaction ntransaction)
{
	if (num_transactions_ <100 ) transactions_[num_transactions_++] = ntransaction;	
	else return false;
	return true;
}

transaction Store::get_transaction(int index) { return transactions_[index]; } 

bool Store::make_purchase(Person cust, product item, int amount)
{
	double total_cost = item.price * amount;
	if( (num_transactions_ < 100)  && cust.person_credit_card().make_purchase(total_cost) ) 
	{
		transaction temp;		
		temp.transaction_number = num_transactions_ + 1;
		temp.customer = cust;
		temp.purchased_item = item;
		temp.quantity = amount;

		add_transaction(temp);
	
		cout << "in make purchase" << endl << endl;
		cout << "cust" << endl;
		cout << cust.person_credit_card().credit_card_info() << endl << endl;

		cout << "transaction array" << endl;
		cout << get_transaction(num_transactions_ - 1).customer.person_credit_card().credit_card_info()
			 << endl << endl;

		return true;
	}
	else return false;
	
}

string Store::customer_info()
{
	int i;
	string customer_str = "";
	for (i=0;i<num_customers_;i++)
		customer_str += customers_[i].person_info() + "\n";

	return customer_str;
}

string Store::product_info()
{
	int i;
	string product_str = "";
	for (i=0;i<num_products_;i++)
		product_str += products_[i].product_info() + "\n";

	return product_str;
}

string Store::transaction_info()
{
	int i;
	string transaction_str = "";
	for(i=0;i<num_transactions_;i++)
		transaction_str += transactions_[i].transaction_info() + "\n";

	return transaction_str;
}

string Store::store_info()
{
	int i;
	string store_str = "";

	store_str += "Customers: \n";
	store_str += customer_info();

	store_str += "\nProducts: \n";
	store_str += product_info();

	store_str += "\nAll Transactions: \n";
	store_str += transaction_info();

	return store_str;
}

string Store::purchase_history(Person cust)
{
	string phistory_str = "";
	int i;
	
	for(i=0;i<num_transactions_;i++)
	{
		if(transactions_[i].customer.name() == cust.name())
			phistory_str += transactions_[i].transaction_info() + "\n";
	}

	return phistory_str;
}
