#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "address.h"
#include "credit_card.h"
#include "person.h"
#include "product.h"
#include "store.h"
#include "transaction.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::getline;

int main()
{

	srand( (unsigned)time(0) );

	//open all files to import information
	ifstream cc_stream("credit_card.txt");
	ifstream people_stream("people.txt");
	ifstream product_stream("products.txt");

	int num_people, num_ccards, num_products, i, j;
	int transaction_number = 1;

	//make a store
	Store store1;

	//save number of items in each file
	people_stream >> num_people;
	cc_stream >> num_ccards;
	product_stream >> num_products;

	Person people [num_people];
	product items [num_products];

	//skip newline in people stream
	string line;
	getline(people_stream,line);

	//populate people array
	for(i=0;i<num_people;i++)
	{
		getline(people_stream,line);
		people[i].name(line);
		getline(people_stream,line);
		people[i].phone(line);

		address temp_address;
		getline(people_stream, temp_address.address_line1);
		getline(people_stream, temp_address.address_line2);
		getline(people_stream, temp_address.city);
		getline(people_stream, temp_address.state);
		getline(people_stream, temp_address.zip);

		people[i].person_address(temp_address);

		store1.add_customer(people[i]);
	}
	
	//close people file stream
	people_stream.close();

	//skip newline in credit card stream
	getline(cc_stream, line);

	string temp_name;
	credit_card temp_card;

	//populate credit card array and associate credit cards with correct person	
	for(i=0;i<num_ccards;i++)
	{
		getline(cc_stream, temp_name);
		
		cc_stream >> temp_card.cc_number 
				  >> temp_card.limit
				  >> temp_card.current_balance;

		//add credit card to appropriate person
		for(j=0;j<num_people;j++)
			if ( temp_name == store1.get_customer(j).name() )
			{
				store1.get_customer(j).person_credit_card(temp_card);
				break;
			}
	//clear newline	
	getline(cc_stream, line);
		
	}
	
	//close credit card file stream
	cc_stream.close();

	//clear newline	 from products stream
	getline(product_stream, line);
	

	//populate products array and add products to the store	
	for(i=0;i<num_products;i++)
	{	
		getline(product_stream, items[i].name);
		getline(product_stream, items[i].description);
		product_stream >> items[i].price;

		store1.add_product(items[i]);	
		
		//clear newline	 from products stream
		getline(product_stream, line);
	}	

	//close product file stream
	product_stream.close();

	//cout << "People: " << endl << endl;
	//for(i=0;i<num_people;i++)
	//	cout << store1.get_customer(i).person_info() << endl << endl;

	//cout << "Products: " << endl << endl;
	//for(i=0;i<num_people;i++)
//		cout << items[i].product_info() << endl << endl;

	cout << "Store info: " << endl << endl;
	cout << store1.store_info() << endl << endl;


	//perform transactions
	int random_person, random_product, random_quantity;
	random_person = rand() % num_people;
	random_product = rand() % num_products;	
	random_quantity = (rand()%10) + 1;
	
	if(store1.make_purchase(store1.get_customer(random_person), 
							store1.get_product(random_product),
							random_quantity))
	{
		cout << "Successfull transaction!" << endl;
		cout << "Transaction Details: " << endl;
		cout << store1.get_transaction(store1.num_transactions()-1).transaction_info() << endl << endl;
	}
	else 
	{
		cout << "Unsuccessfull transaction!" << endl;
		cout << "Transaction Details: " << endl;
		cout << "Person: " << endl;
		cout << store1.get_customer(random_person).person_info() << endl;
		cout << "Product: " << endl;
		cout << store1.get_product(random_product).product_info() << endl;
		cout << "Purchase Quantity: " << random_quantity <<  endl << endl;
	}
	
	cout << "Store info: " << endl << endl;
	cout << store1.store_info() << endl << endl;
}
