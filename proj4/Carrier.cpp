#include "Carrier.h"
#include "Mail.h"

#include <iostream>
using namespace std;

// default constructor
Carrier::Carrier() {}

// insert mail into m_storage
int Carrier::insert(Mail *m) {
  m_storage.push_back(m);
  return 1;
}

// set max cap.
void Carrier::setMaxCapacity(int max) {
  m_max_capacity = max;
}

// set rate
void Carrier::setRate(float rate) {
  m_delivery_rate = rate;
}

// ostream&
ostream& operator<<(ostream& os, const Carrier& c) {
  for (unsigned int i = 0; i < c.m_storage.size(); i++) {
    cout << *(c.m_storage.at(i)) << endl;
  }
  return os;
}

