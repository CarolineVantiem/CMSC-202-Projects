#include "MailHouse.h"
#include "Carrier.h"
#include "Mail.h"
#include "Ups.h"
#include "FedEx.h"
#include "Letter.h"
#include "Package.h"

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
using namespace std;

// default constructor
MailHouse::MailHouse() {}

// load file into m_mail / populate m_carriers
int MailHouse::loadMail(char* inputFile) {
  ifstream myFile;
  myFile.open(inputFile);
  
  // carrier pointers
  Carrier *UpsPtr = new Ups();
  Carrier *FedExPtr = new FedEx();
  
  // get first line
  int UpsCap, FedExCap;
  float UpsSpeed, FedExSpeed, letterBase, packageBase;
  myFile >> UpsCap >> FedExCap >> UpsSpeed >> FedExSpeed 
	 >> letterBase >> packageBase;
  
  // set max cap.
  UpsPtr->setMaxCapacity(UpsCap);
  FedExPtr->setMaxCapacity(FedExCap);
  
  // set rate
  UpsPtr->setRate(UpsSpeed);
  FedExPtr->setRate(FedExSpeed);
  
  // populate m_carriers with carrier pointers
  m_carriers.push_back(UpsPtr);
  m_carriers.push_back(FedExPtr);
  
  // set rest of file
  Mail *mailPtr;
  int UpsCounter = 0, FedExCounter = 0;
  int carrierType, mailType;
  string sender, recipient;
  double weight;
  char c;
  while (myFile >> carrierType >> c >> mailType >> c) {
    getline(myFile, sender, ',');
    getline(myFile, recipient, ',');
    myFile >> weight;
    
    // mail type - letter
    if (mailType == LETTER) {
      mailPtr = new Letter(carrierType, sender, recipient, weight, letterBase);
      // UPS - FEDEX counter + 1
      if (carrierType == UPS) 
	UpsCounter++;
      else if (carrierType == FEDEX)
	FedExCounter++;
    }
    
    // mail type - package
    else if (mailType == PACKAGE) {
      mailPtr = new Package(carrierType, sender, recipient, weight, packageBase);
      // UPS - FEDEX counter + 1
      if (carrierType == UPS) 
	UpsCounter++;
      else if (carrierType == FEDEX)
	FedExCounter++;
    }
    
    m_mail.push_back(mailPtr);
  }
  myFile.close();
  
  // check size fail - 0 or success - 1
  if (UpsCounter > UpsCap ||  FedExCounter > FedExCap) 
    return 0;
  else
    return 1;
}
  
// fill the carriers with respective mail
int MailHouse::fillCarriers() {
  int carrier;
  int UpsCounter = 0, FedExCounter = 0;

  // iterate through m_mail
  for (unsigned int i = 0; i < m_mail.size(); i++) {
    carrier = m_mail.at(i)->getCarrier();
    
    // UPS type
    if (carrier == UPS) {
      m_carriers.at(UPS)->insert(m_mail.at(i));
      UpsCounter++;
    }
    
    // FEDEX type
    else if (carrier == FEDEX) {
      m_carriers.at(FEDEX)->insert(m_mail.at(i));
      FedExCounter++;
    }
  }
  
  // display UPS / FEDEX truck contents
  for (unsigned int i = 0; i < m_carriers.size(); i++) {
    m_carriers.at(i)->display();
  }

  // check size fail - 0 or success - 1
  if (UpsCounter == 0 || FedExCounter == 0) 
    return 0;
  else
    return 1;
}

// deliver mail / m_carriers clear respective vectors
int MailHouse::deliverMail() {
  // iterate through m_carriers
  for (unsigned int i = 0; i < m_carriers.size(); i++) {
    m_carriers.at(i)->deliver();
  }
  return 1;
}

// clean up
int MailHouse::cleanUp() {
  // clean up m_mail
  for (unsigned int i = 0; i < m_mail.size(); i++) {
    delete m_mail.at(i);
  }
  
  // clean up m_carriers
  for (unsigned int i = 0; i < m_carriers.size(); i++) {
    delete m_carriers.at(i);
  }
  return 1;
}
