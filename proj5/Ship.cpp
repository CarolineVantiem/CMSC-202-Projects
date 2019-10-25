#include "Ship.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// default constructor
Ship::Ship(string name, string type, int attack, int defense) {
  m_name = name;
  m_type = type;
  m_attack = attack;
  m_defense = defense;
}

// return m_name
string Ship::getName() {
  return m_name;
}

// set name
void Ship::setName(string name) {
  m_name = name;
}

// return m_type
string Ship::getType() {
  return m_type;
}

// set type
void Ship::setType(string type) {
  m_type = type;
}

// return m_attack
int Ship::getAttack() {
  return m_attack;
}

// set attack
void Ship::setAttack(int attack) {
  m_attack = attack;
}

// return m_defense
int Ship::getDefense() {
  return m_defense;
}

// set defense
void Ship::setDefense(int defense) {
  m_defense = defense;
}

// friend ostream&
ostream& operator<<(ostream& os, Ship& b) {
  return os;
}

