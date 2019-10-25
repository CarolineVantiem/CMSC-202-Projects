#include "Package.h"
#include "Mail.h"

#include <iostream>
using namespace std;

// default constructor
Package::Package() {}

// overlaoded constructor
Package::Package(int carrier, string sender, string recipient, float size, float base) :
  Mail(carrier, sender, recipient, size, base) {}

// destructor
Package::~Package() {}

// convert to string
string Package::toString() {
  ostringstream x;
  x << "-------------------------" << endl;
  x << "PACKAGE" << endl;
  x << "To: " << m_recipient << endl;
  x << "From: " << m_sender << endl;
  x << "Weight: " << m_size << " lbs" << endl;
  x << "-------------------------" << endl;
  string y = x.str();
  return y;
}
