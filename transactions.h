// --------------------------- customersData.h ---------------------------
// Aisha M
// CSS 343 D Due 3/13/2024
// ------------------------------------------------------------------------
// This class represents a container for storing and managing customer
// information. It provides methods to load customer data from a file, retrieve
// customer information based on customer ID, check the existence of a customer
// by ID, and display all customer data.
// ------------------------------------------------------------------------

#pragma once
#include "customer.h"
#include "inventory.h"
#include "movie.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Transaction {
public:
  // Constructor and Desctructor
  Transaction(char type, int customerID, Movie *movie);
  ~Transaction();

  friend class Customer;

  void print();

  // Getter methods
  char getType() const { return type; }
  int getCustomerID() const { return customerID; }
  Movie *getMovie() const { return movie; }
  void setMovie(Movie *movie) { this->movie = movie; }
  /*
      // Setter methods
      void setType(char type) { this->type = type; }
      void setCustomerID(int customerID) { this->customerID = customerID; }


      // method to add transaction to history
      void addToHistory(const std::string &transaction);
    */
  Transaction *next;

private:
  char type;
  int customerID;
  Movie *movie;
  bool pending; // transaction is still pending, ie: if the movie has been
                // borrowed but not returned yet
};

// TRANSACTIONS_H

class Borrow : public Transaction {
public:
  Borrow(char type, int customerID, Movie *movie)
      : Transaction(type, customerID, movie){};
  //~Borrow();
};

class Return : public Transaction {
public:
  Return(char type, int customerID, Movie *movie)
      : Transaction(type, customerID, movie){};
  //~Return();
};
