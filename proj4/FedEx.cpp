#include "FedEx.h"
#include "Carrier.h"

#include <iostream>
using namespace std;

// default constructor
FedEx::FedEx() {}

// destructor
FedEx::~FedEx() {}

// deliver
int FedEx::deliver() {
  double cost = 0, size, base;
  
  // iterate through m_storage
  for (unsigned int i = 0; i < m_storage.size(); i++) {
    cout << "Delivered: " << endl;
    cout << *(m_storage.at(i));
    
    // get cost of delivery
    size = m_storage.at(i)->getSize();
    base = m_storage.at(i)->getBaseCost();
    cost = size * base * m_delivery_rate + cost;
  }
  cout.precision(2);
  cout << "Deliveries completed. FedEx total earned $" << fixed << cost << endl;
  cout << endl;
  return 1;
}
  
int FedEx::display() {
  cout << "*************************" << endl;
  cout << "FedEx Truck Contents: " << endl;
  for (unsigned int i = 0; i < m_storage.size(); i++) {
    cout << *(m_storage.at(i));
  }
  cout << "*************************" << endl;
  return 1;
}

// ostream& print
ostream& FedEx::print(ostream& os) const {
  return os;
}
