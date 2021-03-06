#include "Ship.h"
#include "Rebel.h"
#include <iostream>
using namespace std;

bool Rebel::attack(Ship *enemy) {
  // 0 - Rebel is damaged
  if (enemy->getDefense() < getAttack()) {
    cout << getName() << " attacks the " << enemy->getName() << endl;
    cout << getName() <<  " was damaged" << endl;
    return 0;
  }
  
  // 1 - Rebel is destroyed
  else if (enemy->getDefense() > getAttack()) { 
    cout << getName() << " attacks the " << enemy->getName() << endl;
    cout << getName() << " was destroyed" << endl;
    return 1;
  }
  
  // 1 - Rebel is destroyed
  else if (enemy->getDefense() == getAttack()) {
    cout << getName() << " attacks the " << enemy->getName() << endl;
    cout << getName() << " was destroyed" << endl;
    return 1;
  }
}

ostream& Rebel::toString(ostream& os) {
  return os;
}
