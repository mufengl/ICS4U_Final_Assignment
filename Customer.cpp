#include "Customer.h"

//constructors
Customer::Customer() {
  name = "";
  address = "";
  phoneNum = 0;
}

Customer::Customer(string n, string a, long long  p) {
  name = n;
  address = a;
  phoneNum = p;
}

//getters
string Customer::getName() {
  return name;
}

string Customer::getAddress() {
  return address;
}

long long Customer::getPhoneNum() {
  return phoneNum;
}

//setters
void Customer::setName(string n) {
  name = n;
}

void Customer::setAddress(string a) {
  address = a;
}

void Customer::setPhoneNum(long long p) {
  phoneNum = p;
}

//ostream overload
ostream & operator << (ostream &out, Customer &c){
  out << "Name: " + c.name << endl << "Address: " + c.address << endl << "Phone Number: " + to_string(c.phoneNum) << endl;
  return out;
}
