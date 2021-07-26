#include <iostream>
using namespace std;

#ifndef Customer_h
#define Customer_h

class Customer {
  protected:
    string name, address;
    long long phoneNum;

  public:
    Customer();
    Customer(string n, string a, long long p);
    string getName();
    string getAddress();
    long long getPhoneNum();
    void setName(string n);
    void setAddress(string a);
    void setPhoneNum(long long p);
    friend ostream & operator << (ostream &out, Customer &c);
};

#endif
