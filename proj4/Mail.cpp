#include "Mail.h"
#include <iostream>
using namespace std;

// default constructor
Mail::Mail() {}

// overloaded constructor
Mail::Mail(int carrier, string sender, string recipient, float size, float base) {
  m_carrier = carrier;
  m_sender = sender;
  m_recipient = recipient;
  m_size = size;
  m_baseCost = base;
}

// return m_carrier
int Mail::getCarrier() {
  return m_carrier;
}

// return m_sender
string Mail::getSender() {
  return m_sender;
}

// return m_recipient
string Mail::getRecipient() {
  return m_recipient;
}

// return m_size
float Mail::getSize() {
  return m_size;
}

// return m_baseCost
float Mail::getBaseCost() {
  return m_baseCost;
}

// ostream
ostream& operator<<(ostream& os, Mail& m) {
  os << m.toString() << endl;
  return os;
}
