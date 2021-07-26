#include "Seat.h"

#ifndef Flight_h
#define Flight_h

class Flight {
  private:
    string destination;
    Seat *flight = new Seat[10];

  public:
    Flight();
    ~Flight();
    Seat seatInfo(int i);
    string getDestination();
    void setDestination(string d);
    void flightDiagram();
    void addReservation();
    void removeReservation();
    void contactInfo();
    void contactInfoAlphabetical();
    friend ostream & operator << (ostream &out, Flight &f);
    
};
void displayAllFlights(Flight *f, int numFlights, int i);
void displayFlight(Flight *f, int numFlight);
int getFlightNum(int numFlights);

#endif