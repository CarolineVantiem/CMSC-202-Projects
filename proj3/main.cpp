#include "Train.h"
#include "Car.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[]) {  
  vector <Train*> vec;
  CARGO_TYPE newType;
  
  int trainNum;
  int counter = 0;
  string num, status, name;
  ifstream myFile;
  myFile.open(argv[1]);
  
  while (getline (myFile, num, ',')) {
    int numTwo = atoi(num.c_str());
    getline (myFile, status, ',');
    getline (myFile, name, ',');
    Train *newTrain = new Train();
    trainNum = newTrain->getNumber();
    // check train num
    if (numTwo != trainNum) {
      newTrain->setNumber(numTwo);
    }
    
    // add
    if (status == "add") {
      // bio
      if (name == "BIOLOGICAL") {
	newType = BIOLOGICAL;
	newTrain->addCar(newType, counter);
	vec.push_back(newTrain);
	counter++;
      }
      else if (name == "LOCOMOTIVE") {
	newType = LOCOMOTIVE;
	newTrain->addCar(newType, counter);
	vec.push_back(newTrain);
	counter++;
      }
      else if (name == "POISONOUS") {
	newType = POISONOUS;
	newTrain->addCar(newType, counter);
	counter++;
	vec.push_back(newTrain);
	
      }
      else if (name == "COMBUSTIBLE") {
	newType = COMBUSTIBLE;
	newTrain->addCar(newType, counter);
	counter++;
	vec.push_back(newTrain);
	
      }
      else if (name == "OXIDIZER") {
	newType = OXIDIZER;
	newTrain->addCar(newType, counter);
	counter++;
	vec.push_back(newTrain);
      }
      else if (name == "RADIOACTIVE") {
	newType = RADIOACTIVE;
	newTrain->addCar(newType, counter);
	counter++;
	vec.push_back(newTrain);
	
      }
      else if (name == "LOCOMOTIVE") {
	newType = LOCOMOTIVE;
	newTrain->addCar(newType, counter);
	counter++;
	vec.push_back(newTrain);
      }
      else if (name == "CABOOSE") {
	newType = CABOOSE;
	newTrain->addCar(newType, counter);
	counter++;
	vec.push_back(newTrain);	
      }
    }
  }
  
  // doesnt print out vector elements
  for (unsigned int i = 0; i < vec.size(); i++) {
    vec[i]->display(cout);
  }
  cout << endl;
  
  return 0;
}

























  
  
