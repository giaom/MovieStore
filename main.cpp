// --------------------------- main.cpp ---------------------------
// Aisha M
// CSS 343 D Due 3/13/2024
// ------------------------------------------------------------------------
// Driver, includes main. Start tests from here.
// Tests included are building and printing given files to match given output.
// ------------------------------------------------------------------------

#include "classic.h"
#include "comedy.h"
#include "customer.h"
#include "drama.h"
#include "hashTable.h"
#include "inventory.h"
#include "movie.h"
#include "store.h"
#include "transactions.h"
#include <cassert>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
  std::cout << "Hello World!\n";
  Store store;

  store.buildInventory("data4movies.txt");
  store.buildCustomersFromFile("data4customers.txt");
  store.processTransactionsFromFile("data4commands.txt");

  cout << "\n------------------------------------------------------\n"
          "------------------ MY TESTS: ------------------ \n"
       << endl;
  
  Store store2;
  // In my test customer attempts to borrow 6 times but theres only 2 copies
  store2.buildInventory("data4moviesAM.txt");
  store2.buildCustomersFromFile("data4customers.txt");
  store2.processTransactionsFromFile("data4commandsAM.txt");

  cout << "\n--------- End ---------\n" << endl;
}