#include "Seat.h"

//constructors
Seat::Seat() : Customer() {
  seatNum = 0;
  available = true;
}

Seat::Seat(int i) : Customer() {
  seatNum = i;
  available = true;
}

Seat::Seat(int n, bool a, string name, string ad, long long pn) : Customer(name, ad, pn) {
  seatNum = n;
  available = a;
}

//operator= overload
Seat& Seat::operator= (const Seat& s) {
  seatNum = s.seatNum;
  available = s.available;
  name = s.name;
  address = s.address;
  phoneNum = s.phoneNum;
  return *this;
}

//getters
int Seat::getSeatNum() {
  return seatNum;
}

bool Seat::checkAvailability() {
  return available;
}

//setters
void Seat::setAvailability(bool avail) {
  available = avail;
}

void Seat::setCustomer(string n, string ad, long long pn)  {
  name = n;
  address = ad;
  phoneNum = pn;
}

//ostream overload
ostream & operator << (ostream &out, Seat &s) {
  if (s.available == true) {
    out << "Seat Number: " << s.seatNum << endl << "Availability: available" << endl;
    return out;
  } else {
    out << "Seat Number: " << s.seatNum << endl << "Availability: unavailable " << endl << "Customer Info: \n" << "Name: " + s.name << endl << "Address: " + s.address << endl << "Phone Number: " + to_string(s.phoneNum) << endl;
    return out;
  }
}