#include "Letter.h"
#include "Mail.h"

#include <iostream>
using namespace std;

// default constructor
Letter::Letter() {}

// overloaded constructor
Letter::Letter(int carrier, string sender, string recipient, float size, float base) :
  Mail(carrier, sender, recipient, size, base) {}

// destructor
Letter::~Letter() {}

string Letter::toString() {
  ostringstream x;
  x << "-------------------------" << endl;
  x << "LETTER" << endl;
  x << "To: " << m_recipient << endl;
  x << "From: " << m_sender << endl;
  x << "Weight: " << m_size << " square inches" << endl;
  x << "-------------------------" << endl;
  string y = x.str();
  return y;
}
