#include "Car.h"

// default constructor
Car::Car() {
  m_cargo = LOCOMOTIVE;
  m_next = NULL;
}

// overloaded constructor
Car::Car(CARGO_TYPE type) {
  m_cargo = type;
  m_next = NULL;
}

// destructor
Car::~Car() {}

// returns current cargo
CARGO_TYPE Car::getCargo() const {
  return m_cargo;
}

// sets a new cargo type
void Car::setCargo(CARGO_TYPE type) {
  m_cargo = type;
}

// returns the next node in the list
Car *const Car::getNext() const {
  return m_next;
}

// set the next car to the given pointer
void Car::setNext(Car* ptr) {
  m_next = ptr;
}

// return the length of the train
int Car::getLength() const {
  int len = 0;
  Car *current = m_next;
  while (current != NULL) {
    len++;
    current = current->getNext(); 
  }
  return len;
}	  
