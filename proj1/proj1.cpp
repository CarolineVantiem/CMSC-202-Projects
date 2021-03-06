/*********************************************
** File:        Proj1.cpp
** Project:     CMSC 202 Project 1, Spring 2018
** Author:      Caroline Vantiem
** Date:        02/20/18
** Section:     4
** E-mail:      Cvantie1@umbc.edu
**
** Description: This file contains the main driver
**              program for project 1. This program
**              reads in a file & calculates specific
**              temperatures for a given base temp.
*********************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

//-----------//
// CONSTANTS //
//-----------//
const int MAX_MENU = 4;    // main menu max
const int MIN_MENU = 0;    // main menu min
const int QUIT = 3;        // exit program

const int LOADFILE = 1;    // choice 1
const int TEMPS = 2;       // choice 2

const int HEIGHT = 6;      // height of grid
const int WIDTH = 5;       // width of grid
const int NUM_CHAR = 30;   // num of chars in grid

const int MAX_TEMP = 134;  // max input temp
const int MIN_TEMP = -130; // min input temp

const int OPEN = 1;        // file opened successfully
const int INVALID = 0;     // file could not be opened

// TEMPS
const double RURAL_TEMP = 1.01; 
const double SUBURBAN_TEMP = 1.03; 
const double COMMERCIAL_TEMP = 1.05;
const double URBAN_TEMP = 1.04;
const double DOWNTOWN_TEMP = 1.09;
const double PARK_TEMP = 1.02;
const double RURAL_FARM_TEMP = 1.0;

//---------------------//
// FUNCTION PROTOTYPES //
//---------------------//
int mainMenu();
int loadFile(char arr[][WIDTH], int dataLen);
void printGrid(char arr[][WIDTH], int dataLen);
void modelTemps(char arr[][WIDTH], int dataLen);

int main() {
  int option;
  int optionCase;
  int statusFile;
  char arr[HEIGHT][WIDTH];
  
  cout << "Welcome to the Urban Heat Island Model!" << endl;
  option = mainMenu();
  
  // menu do - while 
  do {
    
    if (option == LOADFILE)
      optionCase = 1;
    else if (option == TEMPS)
      optionCase = 2;

    
    switch (optionCase) {

    case 1:
      statusFile = loadFile(arr, NUM_CHAR);
      // only print grid if file was opened
      if (statusFile == OPEN)
	printGrid(arr, NUM_CHAR);
      else if (statusFile == INVALID)
	cout << "";
      option = mainMenu();
      break;

    case 2:
      // only print temps if file was given
      if (statusFile == OPEN)
	modelTemps(arr, NUM_CHAR);
      else if (statusFile == INVALID)
	cout << "No file was successfully opened. Enter a file." << endl;
      option = mainMenu();
      break;

    default:
      cout << "";
    }
  }
  while (option != 3);

  // end do - while loop
  cout << "Thank you for using the Urban Heat Island Model!" << endl;

  return 0;
}

//------------------------------------
// Name: mainMenu
// PreCondition:  no pre-conditions
// PostCondition: returns users option
//------------------------------------
int mainMenu() {
  int option;
  
  cout << "What would you like to do? " << endl;
  cout << "1. Load Land Cover File " << endl;
  cout << "2. Model Temperatures Based on Land Cover " << endl;
  cout << "3. Exit " << endl;
  cin >> option;

  // user input validation
  while (option <= MIN_MENU || option >= MAX_MENU) {
    cout << "Invalid option please enter a number 1-3 (inclusive)." << endl;
    cin >> option;
  }
  
  return option;
}

//-----------------------------------------------------
// Name: loadFile
// PreCondition:  user entered choice 1
// PostCondition: return if file was successfully opened
//-----------------------------------------------------
int loadFile(char arr[][WIDTH], int dataLen) {
  ifstream inputFile;
  int statusFile;
  string fileName;
  
  cout << "What is the name of the file to import?" << endl;
  cin >> fileName;
  inputFile.open(fileName.c_str());
  
  // check if file opened
  if (inputFile.is_open()) {
    statusFile = OPEN;
    // make 2D array
    for (int i = 0; i < HEIGHT; i++) {
      for (int j = 0; j < WIDTH; j++) {
	inputFile >> arr[i][j];
      }
    }
  }
  else {
    statusFile = INVALID;
    cerr << "The file " << fileName << " could not be opened" << endl;
  }
  inputFile.close();
  
  return statusFile;
}

//---------------------------------------------------
// Name: printGrid
// PreCondition:  file was successfully opened
// PostCondition: 2D array will be printed with chars
//---------------------------------------------------
void printGrid(char arr[][WIDTH], int dataLen) {
  cout << "File successfully loaded." << endl;
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      cout << arr[i][j] << setw(3) << " ";
    }
    cout << endl;
  }
}

//-------------------------------------------------------------
// Name: modelTemps
// PreCondition:  user enters choice 2
// PostCondition: model temps will be put in array and outputed
//-------------------------------------------------------------
void modelTemps(char arr[][WIDTH], int dataLen) {
  int counter = 0;
  double temp = 0.0;
  double grid[HEIGHT][WIDTH];
  
  cout << "What is the base temperature?" << endl;
  cin >> temp;
  
  // user input validation
  while (temp < MIN_TEMP || temp > MAX_TEMP) {
    if (temp < MIN_TEMP) {
      cout << "Temperature is too low, input a higher temperature." << endl;
      cin >> temp;
    }
    else if (temp > MAX_TEMP) {
      cout << "Temperature is too high, input a lower temperature." << endl;
      cin >> temp;
    }
  }
  
  // check what value to multiply by
  while (counter < dataLen) {
    for (int i = 0; i < HEIGHT; i++) {
      for (int j = 0; j < WIDTH; j++) {
	if (arr[i][j] == 'R')
	  grid[i][j] = temp * RURAL_TEMP;
	else if (arr[i][j] == 'S')
	  grid[i][j] = temp * SUBURBAN_TEMP;
	else if (arr[i][j] == 'C')
	  grid[i][j] = temp * COMMERCIAL_TEMP;
	else if (arr[i][j] == 'U')
	  grid[i][j] = temp * URBAN_TEMP;
	else if (arr[i][j] == 'D')
	  grid[i][j] = temp * DOWNTOWN_TEMP;
	else if (arr[i][j] == 'P')
	  grid[i][j] = temp * PARK_TEMP;
	else if (arr[i][j] == 'F')
	  grid[i][j] = temp * RURAL_FARM_TEMP;
      }
    }
    counter++;
  }
  
  // print grid
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      cout << fixed << setprecision(1);
      cout <<  grid[i][j] << setw(4) << " ";
    }
    cout << endl;
  }
}
	
      
    
