#include "Imperial.h"
#include "Ship.h"
#include <iostream>
using namespace std;

// attack
bool Imperial::attack(Ship* enemy) {
  // 0 - imperial is damaged
  if (enemy->getDefense() < getAttack()) {
    cout << getName() << " attacks the " << enemy->getName() << endl;
    cout << getName() << " was damaged" << endl;
    return 0;
  }
  // 1 - imperial is destroyed
  else if (enemy->getDefense() > getAttack()) {
    cout << getName() << " attacks the " << enemy->getName() << endl;
    cout << getName() << " was destroyed" << endl;
    return 1;
  }
  // 1 - imperial is destroyed
  else if (enemy->getDefense() == getAttack()) {
    cout << getName() << " attacks the " << enemy->getName() << endl;
    cout << getName() << " was destroyed" << endl;
    return 1;
  }
}

// ostream
ostream& Imperial::toString(ostream& os) {
  return os;
}
