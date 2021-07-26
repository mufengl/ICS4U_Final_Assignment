#include "Flight.h"
#include <cstdlib>
#include <ctime> //for random number seed 

int main() {
  //Seed for random number generator
  srand(time(NULL));

  //Defining destinations
  string destinations[] = {"New York", "San Francisco", "San Jose", "Los Angeles", "Indianapolis", "Minneapolis", "Milwaukee", "Auston", "Atlanta", "Phoenix", "Boston"};

  //Setting up the system
  cout << "Welcome to the Fly-by-Night Flight Booking System!" << endl;
  cout << "Enter the amount of flights tomorrow: ";
  int numFlights;
  cin >> numFlights;
  while (numFlights < 1) {
    cout << "Enter a valid number of flights: " << endl;
    cin >> numFlights;
  }

  //Creating Flight object array
  Flight* daySchedule = new Flight[numFlights];
  
  //Setting up destinations for all flights
  for (int i=0; i<numFlights; i++) {
    int j = rand() % 11;
    daySchedule[i].setDestination(destinations[j]);
  }

  //Displaying menu
  cout << "Menu" << endl << "Enter 'Schedule' to see all the flights of the day." << endl << "Enter 'FlightFind' to see information about a specific flight." << endl << "Enter 'Diagram' to get a diagram showing you the seating plan" << endl << "Enter 'ReservationAdd' to add a reservation" << endl << "Enter 'ReservationRemove' to remove a reservation" << endl << "Enter 'Cancellation' to get the contact information for all customers on a flight if the flight has been cancelled" << endl << "Enter 'Manifest' to get a passenger manifest ordered numerically or alphabetically" << endl << "Enter 'Menu' to see the menu again" << endl << "Enter 'End' to shut down the system." << endl;

  //Taking user inquiry
  string input;
  cout << "\nPlease enter your query: " << endl;
  cin >> input;

  //Taking in more inquiries and identifying commands
  while (input != "End") {
    if (input == "Schedule") {
      displayAllFlights(daySchedule, numFlights, numFlights-1);

    } else if (input == "FlightFind") {
      int flightNum = getFlightNum(numFlights);
      if (flightNum == -1) {

      } else {
        displayFlight(daySchedule, flightNum);
      }

    } else if (input == "Diagram") {
      int flightNum = getFlightNum(numFlights);
      if (flightNum == -1) {

      } else {
        daySchedule[flightNum-1].flightDiagram();
      }

    } else if (input == "ReservationAdd") {
      int flightNum = getFlightNum(numFlights);
      
      if (flightNum == -1) {

      } else {
        daySchedule[flightNum-1].addReservation();
      }

    } else if (input == "ReservationRemove") {
      int flightNum = getFlightNum(numFlights);
      if (flightNum == -1) {

      } else {
        daySchedule[flightNum-1].removeReservation();
      }
    } else if (input == "Cancellation") {
      
      int flightNum = getFlightNum(numFlights);
      if (flightNum == -1) {

      } else {
        cout << "\nCustomers with reserved seats on the flight: \n" << endl;
        daySchedule[flightNum-1].contactInfo();
      }

    } else if (input == "Manifest") {
      int flightNum = getFlightNum(numFlights);
      if (flightNum == -1) {

      } else {
        string order;
        cout << "Would you like to print the manifest in alphabetical order or numerical order? Type A or N to respond, or -1 to quit" << endl;
        cin >> order;
        while ((order != "A") && (order != "N") && (order != "-1")) {
          cout << "Enter a valid answer" << endl;
          cin >> order;
        }
        if (order == "A") {
          cout << "Passenger Manifest (Ordered alphabetically by first name) " << endl;
          daySchedule[flightNum-1].contactInfoAlphabetical();
        } else if (order == "N") {
          cout << "Passenger Manifest (Ordered numerically) " << endl;
          daySchedule[flightNum-1].contactInfo();
        } else {}
      }
      
    } else if (input == "Menu") {
      cout << "Menu" << endl << "Enter 'Schedule' to see all the flights of the day." << endl << "Enter 'FlightFind' to see information about a specific flight." << endl << "Enter 'Diagram' to get a diagram showing you the seating plan" << endl << "Enter 'ReservationAdd' to add a reservation" << endl << "Enter 'ReservationRemove' to remove a reservation" << endl << "Enter 'Cancellation' to get the contact information for all customers on a flight if the flight has been cancelled" << endl << "Enter 'Manifest' to get a passenger manifest ordered numerically or alphabetically" << endl << "Enter 'End' to shut down the system." << endl;
    } else {
      cout << "Input doesn't match indicated commands, try again." << endl;
    }
    
    cout << "\nPlease enter your next query: " << endl;
    cin >> input;
  }  

  cout << "Program ended" << endl;
  return 0;
}