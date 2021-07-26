#include "Flight.h"
#include <string>

//constructors
Flight::Flight() {
  for (int i=1;i<=10;i++) {
    flight[i-1] = Seat(i);
  }
  destination = "";
}

//destructor
Flight::~Flight() {
  delete [] flight;
}

//getters
Seat Flight::seatInfo(int i) {
  return flight[i];
}

string Flight::getDestination() {
  return destination;
}

//setters
void Flight::setDestination(string d) {
  destination = d;
}

//diagram
void Flight::flightDiagram() {
  cout << "Seating diagram: (Green = available, red = reserved)" << endl;
  cout << "Front" << endl;
  for (int i=0;i<10;i=i+2) {
    for (int j=1;j<=2;j++) {
      if (flight[i+j-1].checkAvailability() == true) {
        cout << "[" << "\033[32m" << i+j << "\033[0m" << "]";
      } else {
        cout << "[" << "\033[31m" << i+j << "\033[0m" << "]";
      }
    }
    cout << endl;
  }
  cout << "Back" << endl;
}

//reservation control
void Flight::addReservation() {
  cout << "Enter Seat Number, or return to main menu by entering -1" << endl;
  int seatN;
  cin >> seatN;
  bool avail = flight[seatN-1].checkAvailability();
  while ((avail == false && seatN != -1) || (seatN < -1 || seatN > 10 || seatN == 0)) {
    cout << "Seat is invalid, please enter the number of an unreserved/valid seat or use '-1' to quit" << endl;
    cin >> seatN;
    avail = flight[seatN-1].checkAvailability();
  }
  cin.ignore(1, '\n');
  if (seatN == -1) {
    return;
  }
  long long phoneNum;
  
  string name, address;
  cout << "Enter name for reservation: ";
  getline(cin, name);
  
  cout << "Enter address for reservation: " << endl;
  getline(cin, address);
  cout << "Enter phone number for reservation, or enter -1 to cancel the reservation: " << endl;
  cin >> phoneNum;
  if (phoneNum == -1) {
    return;
  }
  flight[seatN-1].setCustomer(name, address, phoneNum);
  flight[seatN-1].setAvailability(false);
  cout << "Reservation successful" << endl;
}

void Flight::removeReservation() {
  cout << "Enter Seat Number, or return to main menu by entering -1" << endl;
  int seatN;
  cin >> seatN;
  bool avail = flight[seatN-1].checkAvailability();
  while ((avail == true && seatN!=-1) || (seatN < -1 || seatN > 10 || seatN == 0)) {
    cout << "Seat is not valid for reservation cancellation, please enter the number of a reserved seat." << endl;
    cin >> seatN;
    avail = flight[seatN-1].checkAvailability();
  }
  if (seatN == -1) {
    return;
  }
  
  long long phoneNum;
  cout << "Enter phone number for reservation to cancel the reservation, or enter -1 to quit: " << endl;
  cin >> phoneNum;
  if (phoneNum == -1) {
    return;
  }
  if (phoneNum == flight[seatN-1].getPhoneNum()) {
    flight[seatN-1].setCustomer("", "", 0);
    flight[seatN-1].setAvailability(true);
    cout << "Cancellation successful" << endl;
  } else {
    cout << "Cancellation failed due to incorrect phone number" << endl;
  }
  
}

//display info control
void Flight::contactInfo() {
  for (int i=0;i<10;i++) {
    if (flight[i].checkAvailability() == false) {
      cout << "Seat number: " + to_string(i+1) << endl;
      cout << "Customer name: " + flight[i].getName() << endl;
      cout << "Phone number: " + to_string(flight[i].getPhoneNum()) << endl << endl;
    }
  }
}

void Flight::contactInfoAlphabetical() {
  int *counter = new int();
  *counter = 0;
  for (int j=0;j<10;j++) {
    if (flight[j].checkAvailability() == false) {
      *counter = *counter + 1;
    }
  }
  int k = 0;
  Seat *seats = new Seat[*counter];
  for (int i=0;i<10;i++) {
    if (flight[i].checkAvailability() == false) {
      seats[k] = flight[i];
      k++;
    }
  }

  int pos_min;
  Seat temp;
  for (int i=0; i < *counter; i++) { 
    pos_min = i; 
    for (int j=i+1; j < *counter; j++) {
      if (seats[j].getName() < seats[pos_min].getName()) {
        pos_min=j; 
      }
    }
    temp = seats[i];
    seats[i] = seats[pos_min];
    seats[pos_min] = temp;
  }
  for (int i=0;i < *counter;i++) {
    cout << "Customer name: " + seats[i].getName() << endl;
    cout << "Seat number: " + to_string(seats[i].getSeatNum()) << endl;
    cout << "Phone number: " + to_string(seats[i].getPhoneNum()) << endl << endl;
  }
  delete counter;
}

//ostream overload
ostream & operator << (ostream &out, Flight &f) {
  for (int i=1;i<=10;i++) {
    Seat temp = f.seatInfo(i-1);
    out << temp << endl;
  }
  return out;
}

//Functions outside the class
void displayAllFlights(Flight *f, int numFlights, int i) {
  if (i == 0) {
    cout << "Scheduled Flight No. " + to_string(i+1) + " to " + f[i].getDestination() << endl;
    cout << f[i] << endl;
  } else {
    displayAllFlights(f, numFlights, i-1);
    cout << "Scheduled Flight No. " + to_string(i+1)  + " to " + f[i].getDestination() << endl;
    cout << f[i] << endl;
  }
}

void displayFlight(Flight *f, int numFlight) {
   cout << "Scheduled Flight No. " + to_string(numFlight) + " to " + f[numFlight-1].getDestination() << endl;
  cout << f[numFlight-1];
}

int getFlightNum(int numFlights) {
  cout << "Enter Flight Number: " << endl;
  int num;
  cin >> num;
  while (((num < -1) || (num > numFlights) || num == 0) && (num!=-1)) {
    cout << "Enter a Valid Flight Number: " << endl;
    cin >> num;
  }
  return num;
}
