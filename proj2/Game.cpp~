#include "Game.h"
#include "Dragon.h"

// default constructor
Game::Game() {
  cout << "Welcome to Dragon Wars" << endl;
  cout << "What is your name?" << endl;
  getline(cin, m_name);
  LoadDragons();
}

// LoadDragons
void Game::LoadDragons() { 
  ifstream myFile;
  myFile.open(PROJ2_DRAGONS.c_str());
  
  string line, name, type, maxSize, rarity;
  //dragonSize sizes = tiny;
  //  int curSize = tiny + 1;
  bool isHatched = false;

  // read in file
  while (getline (myFile, name, ',')) {
    
    getline(myFile, type, ',');
    getline(myFile, maxSize, ',');
    getline(myFile, rarity);
    
    // cast string to int
    int maxSizeTwo = atoi(maxSize.c_str());        
    int rarityTwo = atoi(rarity.c_str());
    
    Dragon list1 (name, type, isHatched, dragonSize(1), dragonSize(maxSizeTwo), rarityTwo);
    
    m_dragons.push_back(list1);
  }
  myFile.close();
}

// SearchEgg
void Game::SearchEgg() {
  int rarityEgg;
  int randNum;
  int dragonNum;

  cout << "What rarity egg would you like to search for?" << endl;
  cout << "Enter a rarity (1 = very common and 10 = very rare):" << endl;
  cin >> rarityEgg;
  
  // user input validation
  while (rarityEgg > 10 || rarityEgg < 1) {
    cout << "Enter a rarity (1 = very common and 10 = very rare):" << endl;
    cin >> rarityEgg;
  }

  switch (rarityEgg) {
  
  case 1: // rarity 1
    randNum = rand() % 100 + 1;
    // found an egg
    if (randNum <= 91) {
      // find rand index of m_dragons
      dragonNum = rand() % m_dragons.size() + 1;
      // check rarity 
      while (m_dragons.at(dragonNum).GetRarity() != 1) {
	dragonNum = rand() % m_dragons.size() + 1;
	m_dragons.at(dragonNum).GetRarity();
      }
      // push back if found rarity 1 egg
      m_myDragons.push_back(m_dragons.at(dragonNum)); 
      cout << "You found a " << m_dragons.at(dragonNum).GetName() << " egg!";
    }
    // did not find egg
    else {
      cout << "Sorry, you did not find a dragon of that rarity." << endl;
    }
    break;
    
    // SAME CODE | DIFFERENT RARITY // 

  case 2: // rarity 2
    randNum = rand() % 100 + 1;
    if (randNum <= 82) {
      dragonNum = rand() % m_dragons.size() + 1;
      while (m_dragons.at(dragonNum).GetRarity() != 2) {
	dragonNum = rand() % m_dragons.size() + 1;
	m_dragons.at(dragonNum).GetRarity();
      }
      m_myDragons.push_back(m_dragons.at(dragonNum));
      cout << "You found a " << m_dragons.at(dragonNum).GetName() << " egg!";
    }
    else {
      cout << "Sorry, you did not find a dragon of that rarity." << endl;
    }
    break;
      
  case 3: // rarity 3
    randNum = rand() % 100 + 1;
    if (randNum <= 73) {
      dragonNum = rand() % m_dragons.size() + 1;
      while (m_dragons.at(dragonNum).GetRarity() != 3) {
	dragonNum = rand() % m_dragons.size() + 1;
	m_dragons.at(dragonNum).GetRarity();
      }
      m_myDragons.push_back(m_dragons.at(dragonNum));
      cout << "You found a " << m_dragons.at(dragonNum).GetName() << " egg!";
    }
    else {
      cout << "Sorry, you did not find a dragon of that rarity." << endl;
    }
    break;
    
  case 4: // rarity 4
    randNum = rand() % 100 + 1;
    if (randNum <= 64) {
      dragonNum = rand() % m_dragons.size() + 1;
      while (m_dragons.at(dragonNum).GetRarity() != 4) {
	dragonNum = rand() % m_dragons.size() + 1;
	m_dragons.at(dragonNum).GetRarity();
      }
      m_myDragons.push_back(m_dragons.at(dragonNum));
      cout << "You found a " << m_dragons.at(dragonNum).GetName() << " egg!";
    }
    else {
      cout << "Sorry, you did not find a dragon of that rarity." << endl;
    }
    break;
    
  case 5: // rarity 5
    randNum = rand() % 100 + 1;
    if (randNum <= 55) {
      dragonNum = rand() % m_dragons.size() + 1;
      while (m_dragons.at(dragonNum).GetRarity() != 5) {
	dragonNum = rand() % m_dragons.size() + 1;
	m_dragons.at(dragonNum).GetRarity();
      }
      m_myDragons.push_back(m_dragons.at(dragonNum));
      cout << "You found a " << m_dragons.at(dragonNum).GetName() << " egg!";
    }
    else {
      cout << "Sorry, you did not find a dragon of that rarity." << endl;
    }
    break;
    
  case 6: // rarity 6
    randNum = rand() % 100 + 1;
    if (randNum <= 46) {
      dragonNum = rand() % m_dragons.size() + 1;
      while (m_dragons.at(dragonNum).GetRarity() != 6) {
	dragonNum = rand() % m_dragons.size() + 1;
	m_dragons.at(dragonNum).GetRarity();
      } 
      m_myDragons.push_back(m_dragons.at(dragonNum));
      cout << "You found a " << m_dragons.at(dragonNum).GetName() << " egg!";
    }   
    else {
      cout << "Sorry, you did not find a dragon of that rarity." << endl;
    }   
    break;

  case 7: // rarity 7
    randNum = rand() % 100 + 1;
    if (randNum <= 37) {
      dragonNum = rand() % m_dragons.size() + 1;
      while (m_dragons.at(dragonNum).GetRarity() != 7) {
        dragonNum = rand() % m_dragons.size() + 1;
        m_dragons.at(dragonNum).GetRarity();
      }
      m_myDragons.push_back(m_dragons.at(dragonNum));
      cout << "You found a " << m_dragons.at(dragonNum).GetName() << " egg!";
    }
    else {
      cout << "Sorry, you did not find a dragon of that rarity." << endl;
    }
    break;

  case 8: // rarity 8
    randNum = rand() % 100 + 1;
    if (randNum <= 28) {
      dragonNum = rand() % m_dragons.size() + 1;
      while (m_dragons.at(dragonNum).GetRarity() != 8) {
        dragonNum = rand() % m_dragons.size() + 1;
        m_dragons.at(dragonNum).GetRarity();
      }
      m_myDragons.push_back(m_dragons.at(dragonNum));
      cout << "You found a " << m_dragons.at(dragonNum).GetName() << " egg!";
    }
    else {
      cout << "Sorry, you did not find a dragon of that rarity." << endl;
    }
    break;

  case 9: // rarity 9
    randNum = rand() % 100 + 1;
    if (randNum <= 19) {
      dragonNum = rand() % m_dragons.size() + 1;
      while (m_dragons.at(dragonNum).GetRarity() != 9) {
        dragonNum = rand() % m_dragons.size() + 1;
        m_dragons.at(dragonNum).GetRarity();
      }
      m_myDragons.push_back(m_dragons.at(dragonNum));
      cout << "You found a " << m_dragons.at(dragonNum).GetName() << " egg!";
    }
    else {
      cout << "Sorry, you did not find a dragon of that rarity." << endl;
    }
    break;

  case 10: // rarity 10
    randNum = rand() % 100 + 1;
    if (randNum <= 10) {
      dragonNum = rand() % m_dragons.size() + 1;
      while (m_dragons.at(dragonNum).GetRarity() != 10) {
        dragonNum = rand() % m_dragons.size() + 1;
        m_dragons.at(dragonNum).GetRarity();
      }
      m_myDragons.push_back(m_dragons.at(dragonNum));
      cout << "You found a " << m_dragons.at(dragonNum).GetName() << " egg!";
    }
    else {
      cout << "Sorry, you did not find a dragon of that rarity." << endl;
    }
    break;
    
  default:
    cout << endl;
  }
}

// HatchDragon
void Game::HatchEgg() {
  int dragonNum;
  
  if (m_myDragons.size() >= 1) {
    DisplayMyDragons();
    cout << "Which dragon would you like to try and hatch?" << endl;
    cin >> dragonNum; 
    m_myDragons.at(dragonNum - 1).HatchDragon(); 
    if (m_myDragons.at(dragonNum - 1).GetIsHatched() == true) {
      cout << "Your egg hatched into a " << m_myDragons.at(dragonNum - 1).
	GetName();
    }
    else {
      cout << "The dragon did not hatch or is already hatched." << endl;
    }
  }
  else {
    cout << "You do not have any eggs to hatch" << endl;
  }
}      
    
// StartGame
void Game::StartGame() {
  int menu;
  menu = MainMenu();
  
  // do - while user doesn't enter 5 (quit)
  do {
    switch (menu) {
      
    case 1: // search 
      SearchEgg();
      cout << endl;
      menu = MainMenu();
      break;
      
    case 2: // hatch
      HatchEgg();
      cout << endl;
      menu = MainMenu();
      break;
      
    case 3: // display
      DisplayMyDragons();
      cout << endl;
      menu = MainMenu();
      break;
      
    case 4: // attack
      Attack();
      cout << endl;
      menu = MainMenu();
      break;
      
    default:
      cout << endl;
    }
  }
  while (menu != 5);
  cout << "Thank you for playing Dragon Wars" << endl;
}

// DisplayMyDragons
void Game::DisplayMyDragons() {
  string egg = "egg";
  string dragon = "dragon";
  int j = 0;
  cout << "********************" << endl;
  cout << m_name << "'s Dragons" << endl;
  cout << setw(16) << "Name";
  cout << setw(16) << "Type";
  cout << setw(16) << "Egg/Dragon";
  cout << setw(16) << "Current Size";
  cout << setw(16) << "Max Size";  
  
  cout << endl;

  for (unsigned int i = 0; i < m_myDragons.size(); i++) {
    j = j + 1;
    cout << j << '.';
    if (m_myDragons.at(i).GetIsHatched() == 0) {
      cout << setw(16) << m_myDragons.at(i).GetName();
      cout << setw(16) << m_myDragons.at(i).GetType();
      cout << setw(16) << egg;
      cout << setw(16) << m_myDragons.at(i).GetCurSize();
      cout << setw(16) << m_myDragons.at(i).GetMaxSize();
      cout << endl;
    }
    else {
      cout << setw(16) << m_myDragons.at(i).GetName();
      cout << setw(16) << m_myDragons.at(i).GetType();
      cout << setw(16) << dragon;
      cout << setw(16) << m_myDragons.at(i).GetCurSize();
      cout << setw(16) << m_myDragons.at(i).GetMaxSize();
      cout << endl;
    }
  }
}


// MainMenu
int Game::MainMenu() {
  int menu;

  // main menu display
  cout << "What would you like to do?" << endl;
  cout << "1. Search for an egg" << endl;
  cout << "2. Try to hatch egg" << endl;
  cout << "3. Display all dragons and eggs" << endl;
  cout << "4. Attack!" << endl;
  cout << "5. Quit" << endl;
  cin >> menu;
  
  // user input validation
  while (menu < 1 || menu > 5) {
    cout << "What would you like to do?" << endl;
    cout << "1. Search for an egg"<< endl;
    cout << "2. Try to hatch egg" << endl;
    cout << "3. Display all dragons and eggs" << endl;
    cout << "4. Attack!" << endl;
    cout << "5. Quit" << endl;
    cin >> menu;
  }
  return menu;
}

// Attack()
void Game::Attack() {
  bool dragonBool; 
  int randNum = rand() % m_dragons.size(); 
  Dragon newDragon = m_dragons.at(randNum);
  int randcursize = rand() % (m_dragons.at(randNum).GetMaxSize()) + 1;
  
  newDragon = Dragon(newDragon.GetName(), newDragon.GetType(), 1, dragonSize(randcursize), newDragon.GetMaxSize(), newDragon.GetRarity()); 
  int userInput; 
  string need; 
  cout << "Attack!" << endl; 
  DisplayMyDragons(); 
  cout << "You found an enemy dragon " << m_dragons.at(randNum).GetName() << " to fight! "<< endl; 
  cout << "Do you want to fight it? (y/n): " << endl;
  cin >> need; 

  cout << "Which dragon would you like to fight with? " << endl;
  cin >> userInput; 
  
  dragonBool = m_myDragons.at(userInput - 1).AttackDragon(newDragon); 
  
  if (dragonBool == false) { 
    m_myDragons.erase(m_myDragons.begin() + userInput - 1); 
  }
}

// DisplayAllDragons
void Game::DisplayAllDragons() {
  cout << "********************" << endl;
  cout << m_name << "'s Dragons" << endl;
  
  cout << '\t' << "Name" 
       << '\t' << "Type" 
       << '\t' << "Egg/Dragon" 
       << '\t'<< "Current Size" 
       << '\t' << "Max Size" 
       << endl;

  for (unsigned int i = 0; i < m_dragons.size(); i++) {
    cout << m_dragons.at(i).GetName() 
	 << '\t'
	 << m_dragons.at(i).GetType()
	 << '\t'
	 << m_dragons.at(i).GetIsHatched()
	 << '\t'
	 << m_dragons.at(i).GetCurSize()
	 << '\t'
	 << m_dragons.at(i).GetMaxSize()
	 << endl; 
  }
}
