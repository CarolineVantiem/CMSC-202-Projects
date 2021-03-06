#include "Train.h"
#include "Car.h"

// default constructor
Train::Train() {
  m_len = 0;
  m_number = 0;
  m_head = NULL;
}

// overloaded constructor
Train::Train(int num) {
  m_len = 0;
  m_number = num;
  m_head = NULL;
}

// destructor
Train::~Train() {
  Car *current = m_head;
  Car *temp;
  while (current != NULL) {
    temp = current->getNext();
    delete temp;
    temp = NULL;
    current = current->getNext();
  }
}

// ostream
void Train::display(ostream& out) const {
  Car *ptr = m_head;
  out << "Train: " << m_number << ' '; 
  int cargoType = 0;
  while (ptr != NULL) {
    cargoType = ptr->getCargo();
    if (cargoType == BIOLOGICAL) 
      out << "BIO"<< endl; 
    else if (cargoType == 1) 
      out << "POI"<< endl; 
    else if (cargoType == 2)
      out << "COM";
    else if (cargoType == 3)
      out << "OXI";
    else if (cargoType == 4)
      out << "RAD";
    else if (cargoType == 5)
      out << "ENGINE";
    else if (cargoType == 6)
      out << "CABOOSE";
    ptr = ptr->getNext();
  }
  bool status = isValid();
  if (status == 0) {
    cout << "(valid)" << endl;
  }
  else {
    cout << "(Invalid)" << endl;
  }
}

// returns whether the train is valid
bool Train::isValid() const {
  Car *node1 = m_head;
  bool status = 0;
  // index through the list
  while (node1 != NULL) {
    // check only if train is still valid
    
    if (status == 0) {
      // oxidizer cannot be adjacent to combustible
      if (node1->getCargo() == OXIDIZER) {
	node1 = node1->getNext();
	if (node1->getCargo() == COMBUSTIBLE) {
	  status = 1;
	}
      }
      else if (node1->getCargo() == COMBUSTIBLE) {
	node1 = node1->getNext();
	if (node1->getCargo() == OXIDIZER) {
	  status = 1;
	}
      }
    }
    node1 = node1->getNext();
    
    // check only if train is still valid
    if (status == 0) {
      // 3 combustible cannot be in a row
      if (node1->getCargo() == COMBUSTIBLE) {
	node1 = node1->getNext();
	if (node1->getCargo() == COMBUSTIBLE) {
	  node1 = node1->getNext();
	  if (node1->getCargo() == COMBUSTIBLE) {
	    status = 1;
	  }
	}
      }
    }
    node1 = node1->getNext();
    
    // check only if train is still valid
    if (status == 0) {
      // 5 biological cannot be in a row
      if (node1->getCargo() == BIOLOGICAL) {
	node1 = node1->getNext();
	if (node1->getCargo() == BIOLOGICAL) {
	  node1 = node1->getNext();
	  if (node1->getCargo() == BIOLOGICAL) {
	    node1 = node1->getNext();
	    if (node1->getCargo() == BIOLOGICAL) {
	      node1 = node1->getNext();
	      if (node1->getCargo() == BIOLOGICAL) {
		status = 1;
	      }
	    }
	  }
	}
      }
    }
    node1 = node1->getNext();
    
    // check only if train is still valid
    if (status == 0) {
      // biological cannot have 2 radioactives next to it
      if (node1->getCargo() == RADIOACTIVE) {
	node1 = node1->getNext();
	if (node1->getCargo() == BIOLOGICAL) {
	  node1 = node1->getNext();
	  if (node1->getCargo() == RADIOACTIVE) {
	    status = 1;
	  }
	}
      }
    }
    node1 = node1->getNext();
  }
  return status;
}

// Add car (node) to the train
int Train::addCar(const CARGO_TYPE& type, int num) {
  Car *node1 = new Car(type);
  // insert at the beginning
  if (num == 0) {
    node1->setNext(m_head);
    node1->setCargo(type);
    m_head = node1;    
    m_len++;
  }
  // insert in middle/end
  else {
    Car *node2 = m_head; 
    for (int i = 0; i < num - 1; i++) {
      node2 = node2->getNext();
    }
    node1->setNext(node2->getNext());
    node2->setNext(node1);
    node2->setCargo(type);
    m_len++;
  }
  return 0;
}
     
// removes a car at a given index
int Train::removeCar(int num) {
  Car *node1 = m_head;
  // delete the head
  if (num == 0) {
    m_head = node1->getNext();
    delete node1;
    node1 = NULL;
  }
  // delete an indexed node
  else {
    for (int i = 0; i < num - 1; i++) {
      node1 = node1->getNext();
    }
    // OR INDENTED
    Car *node2 = node1->getNext();
    node1->setNext(node2->getNext());
    delete node2;
    node2 = NULL;
  }
  return 0;
}

// removes cars of a cargo type
int Train::removeCar(CARGO_TYPE type) {
  Car *node1 = m_head; 
  
  Car *node2 = node1;
  Car *node3 = node1->getNext();
  // index through the list
  while (node3 != NULL) {
    // find the type
    if (node3->getCargo() == type) {
      node2->setNext(node3->getNext());
      Car *temp = node3;
      node3 = node3->getNext();
      delete temp;
      temp = NULL;
    }
    // keep indexing
    else {
      node2 = node3;
      node3 = node3->getNext();
    }
  }
  m_head = node1->getNext();
  // delete the first node
  delete node1;
  node1 = NULL;
  return 0;
}

// return current len of the train
int Train::getLength() const {
  return m_len;
}

// return number of the train
int Train::getNumber() const {
  return m_number;
}

// set a number for the train
void Train::setNumber(int num) {
  m_number = num;
}

// output train info
ostream &operator<<(ostream& out, const Train& train) {
  train.display(out);
  return out;
}
