// --------------------------- customer.h ---------------------------
// Aisha M
// CSS 343 D Due 3/13/2024
// ------------------------------------------------------------------------
/* Represents customer information.
Includes data members for name and ID.
Implements a method to display borrowing and return history. */
// ------------------------------------------------------------------------

#pragma once
#include "inventory.h"
#include "movie.h"
#include "transactions.h"
#include <string>
#include <vector>

class MyHashTable;
class Transaction;
class Inventory;

class Customer {
private:
  std::string firstName;
  std::string lastName;
  int ID;
  // link list of transactions
  Transaction *transactionList;
  Customer *next;

public:
  // Constructor
  Customer(int ID, std::string lastName, std::string firstName);
  ~Customer();
  int getID() const { return ID; };
  friend class MyHashTable;
  friend class Transaction;

  void getHistory();
  void printCustomer();
  void doTransaction(Transaction *transaction, Inventory *inventory);
  std::string getCustName() const { return (firstName + " " + lastName); }
};

// CUSTOMER_H