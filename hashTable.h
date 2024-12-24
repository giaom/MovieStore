// --------------------------- HashTable.h ---------------------------
// Aisha M
// CSS 343 D Due 3/13/2024
// ------------------------------------------------------------------------
/* Generic hash table template class implemented using arrays and pointers.
 Provides pure virtual functions for adding, removing, and displaying items. */
// ------------------------------------------------------------------------

#pragma once
#include "customer.h"
#include "movie.h"
#include "store.h"

class MyHashTable {
public:
  MyHashTable();
  virtual ~MyHashTable();
  void add(Customer *customer);
  // Customer *remove(Customer *customer); // int customerId);
  Customer *find(int customerId);
  int hash(int customerId);

private:
  static const int TABLE_SIZE = 127; // Size of hash table, a prime number
  Customer *table[TABLE_SIZE];
};

/*
template <typename T> class HashTable {
public:
  // Pure virtual functions
  // Psuedocode:
  Method add/remove(item):
  Call hash function to get index
  If index is within valid range:
      Add/remove item to hashtable at index
  Else
  Print error message (invalid index)

  virtual void add(T *item) = 0;
  virtual void remove(T *item) = 0;
  virtual void display();

private:
  static const int max = 343;
  T *hashtable[max];

  // Pure virtual functions
  virtual void hash(T *item) = 0; // Returns index for item, but does not store.
};
*/
