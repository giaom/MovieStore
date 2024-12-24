// --------------------------- customersData.cpp ---------------------------
// Aisha M
// CSS 343 D Due 3/13/2024
// ------------------------------------------------------------------------
// This class represents a container for storing and managing customer
// information. It provides methods to load customer data from a file, retrieve
// customer information based on customer ID, check the existence of a customer
// by ID, and display all customer data.
// ------------------------------------------------------------------------

#include "transactions.h"
using namespace std;

// Transaction Constrcutor ---------------------------
Transaction::Transaction(char type, int customerID, Movie *movie) {
  this->type = type;
  this->customerID = customerID;
  this->movie = movie;
  pending = false;
}

// Destructor ---------------------------
Transaction::~Transaction() {}

// --------------------------- print ---------------------------
// Description: Prints the transaction details to the console.
// Preconditions: None.
// PostCoditions: Prints the transaction type, customer ID, and movie details to
// the console.
void Transaction::print() {
  if (type == 'B') {
    std::cout << "Borrowed " << movie->getTitle() << " by "
              << movie->getDirector() << endl;
  } else if ('R' == type) {

    std::cout << "Returned " << movie->getTitle() << " by "
              << movie->getDirector() << endl;
  } else {
    std::cout << "Print called on non Borrow or Return transaction."
              << std::endl;
  }
}
