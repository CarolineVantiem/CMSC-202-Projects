#include "Dragon.h"

// overloaded constructor
Dragon::Dragon(string name, string type, bool isHatched, dragonSize curSize,
	       dragonSize maxSize, int rarity) {
  m_name = name;
  m_type = type;
  m_isHatched = isHatched;
  m_curSize = curSize;
  m_maxSize = maxSize;
  m_rarity = rarity;
}

// GetName
string Dragon::GetName() {
  return m_name;
}

// SetName
void Dragon::SetName(string name) {
  m_name = name;
}

// GetType
string Dragon::GetType() {
  return m_type;
}

// SetType
void Dragon::SetType(string Type) {
  m_type = Type;
}

// GetIsHatched
bool Dragon::GetIsHatched() {
  return m_isHatched;
}

// HatchDragon 
void Dragon::HatchDragon() {
  int randNum;
  randNum = rand() % 100 + 1;
  // if egg isn't already hatched
  if (randNum <= 50) {
    m_isHatched = false;
  }
  else {
    m_isHatched = true;
  }
}

// GetCurSize
dragonSize Dragon::GetCurSize() {
  return m_curSize;
}

// SetCurSize
void Dragon::SetCurSize(dragonSize curSize) {
  m_curSize = curSize;
}

// GetMaxSize
dragonSize Dragon::GetMaxSize() {
  return m_maxSize;
}

// SetMaxSize
void Dragon::SetMaxSize(dragonSize maxSize) {
  m_maxSize = maxSize;
}

// GetRarity
int Dragon::GetRarity() {
  return m_rarity;
}

// SetRarity
void Dragon::SetRarity(int rarity) {
  m_rarity = rarity;
}

// AttemptGrow
bool Dragon::AttemptGrow() {
  if (m_curSize < m_maxSize) 
    return true;
  else
    return false;
}

// AttackDragon
bool Dragon::AttackDragon(Dragon& newDragon) {
  string breathAttack = BreathAttack(); 
  bool result; 
  
  if (breathAttack == "You got breath attack") {
    return true; 
  }
  
  if (m_curSize < newDragon.m_curSize) {
    cout << "Your " << m_name << " attacks the " << newDragon.m_name << 
      "!" << endl;
    cout << "The enemy " << newDragon.m_name << " defeated your " << 
      m_name << "!" << endl;
    return false;
  }
  
  else if (m_curSize == newDragon.m_curSize) {
    cout << "Your " << m_name << " attacks the " << newDragon.m_name << 
      "!" << endl;
    cout << "The battle results in a draw" << endl; 
    result = AttemptGrow(); 
    if (result == true) {
      SetCurSize(dragonSize(m_curSize + 1)); 
      cout << "Your dragon grows a bit larger." << endl;
    }
    else
      { 
	cout <<"Your dragon cannot grow larger " << endl;
      }
    return true; 
  }
  if (m_curSize > newDragon.m_curSize) {
    cout << "Your " << m_name << " attacks the " << newDragon.m_name << 
      "!" << endl;
    cout << "WIN!" << endl; 
    cout << "Your " << m_name << " defeated the " << newDragon.m_name <<
      "!" << endl;
    result = AttemptGrow();
    if (result == true) {
      SetCurSize(dragonSize(m_curSize + 1));
      cout << "Your dragon grows a bit larger." << endl;
    } 
    else 
      {
	cout << "Your dragon cannot grow larger " << endl; 
      }
    return true; 
  }
}

// BreathAttack
string Dragon::BreathAttack() {
  string msg; 
  int num;
  num = rand() % 100 + 1; 
  if (num <= 5) {
    msg = "You got breath attack";
  }
  else {
    msg = "Try again! "; 
  }
  
  return msg; 
}
