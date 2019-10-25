#include "Ups.h"
#include "Carrier.h"

#include <iostream>
using namespace std;

// default constructor
Ups::Ups() {}

// destructor
Ups::~Ups() {}

// deliver mail
int Ups::deliver() {
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
  cout << "Deliveries completed. Ups total earned $" << fixed << cost << endl;
  cout << endl;
  return 1;
}

int Ups::display() {
  cout << "*************************" << endl;
  cout << "Ups Truck Contents: " << endl;
  for (unsigned int i = 0; i < m_storage.size(); i++) {
    cout << *(m_storage.at(i));
  }
  
  return 1;
}


// ostream& print
ostream& Ups::print(ostream& os) const {
  return os;
}
