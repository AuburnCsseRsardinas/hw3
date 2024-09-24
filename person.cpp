#include <iostream>
#include <string>
#include "person.h"
#include "address.h"
#include "credit_card.h"

using std::string;

Person::Person()
{
	name_ = "";
	phone_ = "";

	address a1;
	credit_card c1;

	person_address_ = a1;
	person_credit_card_ = c1;
}

Person::Person(string name, string phone, address person_address,
		   credit_card  person_credit_card)
{
	name_ = name;
	phone_ = phone;
	person_address_ = person_address;
	person_credit_card_ = person_credit_card;
}

void Person::name(string pname) { name_ = pname; }
string Person::name() { return name_; }

void Person::phone(string pphone) { phone_ = pphone; }
string Person::phone() { return phone_; }

void Person::person_address(address paddress) { person_address_ = paddress; }
address Person::person_address() { return person_address_; }

void Person::person_credit_card(credit_card pcc) { person_credit_card_ = pcc; }
credit_card Person::person_credit_card() { return person_credit_card_; }

string Person::person_info()
{
	return "Name: " + name_ + "\n" +
		   "Phone: " + phone_ + "\n" +
		   "Address: \n" + person_address_.address_info() + "\n" +
		   "Credit Card: \n" + person_credit_card_.credit_card_info();
}
