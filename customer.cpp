// --------------------------- customer.cpp ---------------------------
// Aisha M
// CSS 343 D Due 3/13/2024
// ------------------------------------------------------------------------
/* Represents customer information.
Includes data members for name and ID.
Implements a method to display borrowing and return history. */
// ------------------------------------------------------------------------

#include "customer.h"
#include "inventory.h"
#include <cassert>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

Customer::Customer(int ID, string lastName, string firstName) {
  this->ID = ID; // this-> is a pointer to the current object
  this->lastName = lastName;
  this->firstName = firstName;
  transactionList = nullptr;
  next = nullptr;
}

Customer::~Customer() {
  Transaction *current;

  while ((current = transactionList)) {
    transactionList = current->next;
    delete current;
  }
}

// --------------------------- doTransaction ---------------------------
// Discribtion: This function saves the transaction if it is valid
// on error cases it deletes the transactionProcesses a transaction for the
// customer, either borrowing or returning a movie. Preconditions: The
// transaction must be valid and contain a movie. The movie's stock must be
// greater than 0 for a borrow transaction. PostCoditions: For a borrow
// transaction, decreases the stock of the movie by one and marks the
// transaction as pending. For a return transaction, increases the stock of the
// movie by one if the movie was previously borrowed by the customer.
void Customer::doTransaction(Transaction *transaction, Inventory *inventory) {
  char type = transaction->getType();
  // cout << "Transaction Type: " << type << endl;

  if ('B' == type) {
    // Borrow Transaction

    Movie *movie = transaction->getMovie();

    if (('C' == movie->getGenre()) && (movie->stock <= 0)) {
      // for classic movies, if this is out of stock, try to find a similar
      // movie
      Classic *classicMovie = dynamic_cast<Classic *>(movie);
      for (auto it : inventory->classicMovies) {
        Classic *similarMovie = dynamic_cast<Classic *>(it);
        if (similarMovie->isSimilar(classicMovie) &&
            (similarMovie->stock > 0)) {
          char userInput;
          cout << classicMovie->getTitle() << " with "
               << classicMovie->getActorLastName() << " is not available now. "
               << "Would you like to borrow " << similarMovie->getTitle()
               << " with " << similarMovie->getActorLastName()
               << " instead? (Y/N): ";
          cin >> userInput;
          cin.ignore();
          if (userInput == 'Y' || userInput == 'y') {
            movie = similarMovie;
            transaction->setMovie(movie);
          } else {
            break;
          }
        }
      }
    }

    // before the transaction was created stock was checked to make sure it
    // was >0 so no need to do it here
    if (movie->stock <= 0) {
      cout << "ERROR: Borrow Transaction Failed -- Movie " << movie->getTitle()
           << " is out of stock" << endl;

      // must return on error conditions, don't add it to transactionList
      delete transaction; // so we don't leak memory
      return;
    }
    movie->stock--; // decrement the stock by one
    transaction->pending = true;
  } else if ('R' == type) {
    // Return Transaction

    Movie *movie = transaction->getMovie();
    // let's make sure they borrowed the movie
    Transaction *it = transactionList;
    while (nullptr != it) {
      // it can only be pending if it was borrowed, don't have to check type
      if (it->pending && (it->getMovie() == movie)) {
        break;
      }
      it = it->next;
    }
    if (nullptr != it) {
      // found it
      it->pending = false;
      movie->stock++; // increment the stock by one
    } else {
      cout << "ERROR: Return Transaction Failed -- "
           << "Movie is not currently borrowed" << endl;
      // must return on error conditions, don't add it to transactionList
      delete transaction; // so we don't leak memory
      return;
    }
  }

  transaction->next = transactionList;
  transactionList = transaction;
}

// --------------------------- printCustomer ---------------------------
// Discribtion: Prints the details of the customer, including their ID, first
// name, and last name. Preconditions: None. PostCoditions: Outputs the
// customer's ID, first name, and last name to the console.
void Customer::printCustomer() {
  cout << "Customer: " << ID << " " << firstName << " " << lastName << endl;
}

// --------------------------- getHistory ---------------------------
// Discribtion: Displays the borrowing and return history of the customer.
// Preconditions: None.
// PostCoditions: Prints the borrowing and return history of the customer to
// the console.
void Customer::getHistory() {
  cout << endl << "History for " << firstName << " " << lastName << ":\n";
  Transaction *it = transactionList;
  while (it != nullptr) {
    it->print();
    it = it->next;
  }
}