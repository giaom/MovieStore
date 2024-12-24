// --------------------------- store.h ---------------------------
// Aisha M
// CSS 343 D Due 3/13/2024
// ------------------------------------------------------------------------
/* Manages customer information and inventory.
Utilizes instances of Customers and Inventory classes.
Implements methods for building the store, borrowing/returning movies, and
displaying information */
// ------------------------------------------------------------------------

#pragma once
//#include "customersData.h"
#include "hashTable.h"
#include "inventory.h"
#include "movie.h"
#include <set>

class MyHashTable;
class Inventory;

class Store {

public:
  // Constructor
  Store();
  ~Store();
  void clearBlanks(std::string &str);
  void findComedyMovie(std::string title, int year);
  void findDramaMovie(std::string director, std::string title);

  // Method to build store from file
  void buildCustomersFromFile(const std::string &filename);
  //  method to build inventory from file
  void buildInventory(const std::string &fileName);
  // Method to get information about a movie
  Movie getMovie();
  // Method to borrow a movie by a customer
  bool borrow(Customer customer, Movie movie);
  Movie *ReadMovieAttributes(std::istringstream &iss);
  void processTransactionsFromFile(const std::string &filename);
  // Method to return a movie by a customer
  bool returnMovie(Customer customer, Movie movie);

  // Method to display the current inventory
  void displayInventory();
  // Method to display borrowing and return history of a customer
  void displayHistory(Customer customer);

private:
  Inventory *inventory;      // Data member to store inventory information
  MyHashTable *customerList; // HashTable to store customers

  //  TODO: convert HastTable to be a template
  //  HashTable<Customer> customerList; // HashTable to store customers
};

// STORE_H
