#include "Customer.h"

#ifndef Seat_h
#define Seat_h

class Seat : public Customer {
  private:
    bool available;
    int seatNum;

  public:
    Seat();
    Seat(int i);
    Seat(int n, bool a, string name, string ad, long long pn);
    Seat& operator= (const Seat& s);
    int getSeatNum();
    bool checkAvailability();
    void setAvailability(bool avail);
    void setCustomer(string name, string ad, long long pn);
    friend ostream & operator << (ostream &out, Seat &s);

    
};

#endif