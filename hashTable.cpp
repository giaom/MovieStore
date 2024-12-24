// --------------------------- HashTable.cpp ---------------------------
// Aisha M
// CSS 343 D Due 3/13/2024
// ------------------------------------------------------------------------
/* Generic hash table template class implemented using arrays and pointers.
 Provides pure virtual functions for adding, removing, and displaying items. */
// ------------------------------------------------------------------------

#include "hashTable.h"
#include "customer.h"
#include "movie.h"
#include <cassert>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// --------------------------- Constructor ---------------------------
// Description: Constructs a hash table object.
// Preconditions: None.
// PostCoditions: Initializes all elements of the hash table array to nullptr.
MyHashTable::MyHashTable() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    table[i] = nullptr;
  }
}

// --------------------------- Destructor ---------------------------
// Description: Destroys the hash table object. for bucket, make pointer point
// at next, delete current.
// Preconditions: None.
// PostCoditions: Deallocates memory for all elements of the hash table array.
MyHashTable::~MyHashTable() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    Customer *current = table[i];

    while (current != nullptr) {
      table[i] = current->next;
      delete current;
      current = table[i];
    }
  }
}

// --------------------------- MyHashTable::hash ---------------------------
// Description: Computes hash value for given customer. pass in customer.getID()
// Preconditions: customerID must be a valid integer.
// PostCoditions: Returns the hash value computed using the modulo operator.
int MyHashTable::hash(int customerID) {
  // Compute the hash value using the modulo operator
  return customerID % TABLE_SIZE;
}

// --------------------------- MyHashTable::add ---------------------------
// Description: Inserts a customer into the hash table.
// Preconditions: customer must point to a valid Customer object.
// PostCoditions: Inserts customer into appropriate bucket of the hash table
void MyHashTable::add(Customer *customer) {
  int index = hash(customer->getID());

  customer->next = table[index];
  table[index] = customer;
}

// --------------------------- MyHashTable::find ---------------------------
// Description: Retrieves a customer from the hash table based on customer ID.
// Preconditions: customerID must be a valid integer.
// PostCoditions: Returns a pointer to the customer if found in the hash table,
// otherwise returns nullptr.
Customer *MyHashTable::find(int customerID) {
  int hashValue = hash(customerID);

  Customer *current = table[hashValue];

  while (current != nullptr) {
    if (current->getID() == customerID) {
      break;
    }
    current = current->next;
  }
  // If the customer is not found, return nullptr
  return current;
}
