#include "StarWars.h"
#include "Ship.h"
#include "Imperial.h"
#include "Rebel.h"
#include "Tqueue.cpp"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
using namespace std;

// default constructor
StarWars::StarWars() {}

// destructor
StarWars::~StarWars() {
  for (int i = 0; i < m_rebelShips.size(); i++) {
    delete m_rebelShips[i];
  }
  
  for (int i = 0; i < m_imperialShips.size(); i++) {
    delete m_imperialShips[i];
  }
}

// load ships
bool StarWars::loadShips(char* files[]) {
  string name, type, attack1, defense1;
  int numFiles = 2;
  Ship *shipPtr;
  
  ifstream myFile;
  // iterate over 2 files
  for (int i = 0; i < numFiles; i++) {
    myFile.open(files[i]);
    
    while (getline(myFile, name, ',')) {
      getline(myFile, type, ',');
      getline(myFile, attack1, ',');
      myFile >> defense1;
      int attack = atoi(attack1.c_str());
      int defense = atoi(defense1.c_str());
      
      // imperial file[0]
      if (i == 0) {
	shipPtr = new Imperial(name, type, attack, defense);
	m_imperialShips.push_back(shipPtr);
      }
      // rebel file[1]
      if (i == 1) {
	shipPtr = new Rebel(name, type, attack, defense);
	m_rebelShips.push_back(shipPtr);
      }
    }
    myFile.close();
  }
  return 1;
}

// start
void StarWars::Start(char* files[]) {
  int numShips;
  
  cout << "Welcome to Star Wars" << endl;
  
  cout << endl;
  
  loadShips(files);
  
  cout << "How many ships would you like on a team?" << endl;
  cin >> numShips;
  
  createTeams(numShips);
  
  cout << endl;
  
  battle();
}

// create teams
void StarWars::createTeams(int numShips) {
  int num1 = 0, num2 = 0;
  int randIndex = 0, randIndex2 = 0;
  int imperialSize = m_imperialShips.size(), rebelSize = m_rebelShips.size();
 
  // enqueue m_enemyShips
  srand(time(NULL));
  randIndex = rand() % imperialSize + 1;
  while (num1 < numShips) {
    m_enemyShips.enqueue(m_imperialShips[randIndex]);
    randIndex = rand() % imperialSize + 1;
    num1++;
  }
  
  // enqueue m_myShips
  srand(time(NULL));
  randIndex2 = rand() % rebelSize + 1;
  while (num2 < numShips) {
    m_myShips.enqueue(m_rebelShips[randIndex2]);
    randIndex2 = rand() % rebelSize + 1;
    num2++;
  }
}

// battle
void StarWars::battle() {
  cout << "The battle begins..." << endl;
  
  // rand start team
  int randStart = 0;
  bool attackStatus;
  srand(time(NULL));
  randStart = rand() % 100 + 1;
  
  while (m_enemyShips.size() != 0 && m_myShips.size() != 0) {
    
    // imperial starts
    if (randStart <= 49) {   
      attackStatus = m_enemyShips.queueFront()->attack(m_myShips.queueFront());
      
      // imperial was destroyed
      if (attackStatus == 1) {
	m_enemyShips.dequeue();
      }
      // imperial was damaged / attack back
      else if (attackStatus == 0) {
	attackStatus = m_myShips.queueFront()->attack(m_enemyShips.queueFront()); 
	// rebel was destroyed
	if (attackStatus == 1) {
	  m_myShips.dequeue();
	}
	else {
	  randStart = rand() % 100 + 1;
	  attackStatus = m_enemyShips.queueFront()->attack(m_myShips.queueFront());
	}
      }
      
    }
    
    // rebel starts
    else if (randStart >= 50) {
      attackStatus = m_myShips.queueFront()->attack(m_enemyShips.queueFront());  
      
      // rebel was destroyed
      if (attackStatus == 1) {
	m_myShips.dequeue();
      }
      // rebel was damaged / attack back
      else if (attackStatus == 0) {
	attackStatus = m_enemyShips.queueFront()->attack(m_myShips.queueFront());
	// imperial was destroyed
	if (attackStatus == 1) 
	  m_enemyShips.dequeue();
	else
	  randStart = rand() % 100 + 1;
      }
      randStart = rand() % 100 + 1;
    }
    randStart = rand() % 100 + 1;
  }
  
  if (m_enemyShips.size() == 0) 
    cout << "You win!!!" << endl;
  else
    cout << "The enemy wins!!!" << endl;
}
