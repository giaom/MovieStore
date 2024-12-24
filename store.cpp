// --------------------------- store.cpp ---------------------------
// Aisha M
// CSS 343 D Due 3/13/2024
// ------------------------------------------------------------------------
/* Manages customer information and inventory.
Utilizes instances of Customers and Inventory classes.
Implements methods for building the store, borrowing/returning movies, and
displaying information */
// ------------------------------------------------------------------------

#include "store.h"
#include "classic.h"
#include "comedy.h"
#include "customer.h"
#include "drama.h"
#include "hashTable.h"
#include "inventory.h"
#include "movie.h"
#include "transactions.h"
#include <cassert>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// Constructor ---------------------------
Store::Store() {
  customerList = new MyHashTable;
  inventory = new Inventory();
}
// Destructor ---------------------------
Store::~Store() {
  delete customerList;
  delete inventory;
}

// ------------------------ buildCustomersFromFile ------------------------
// Description: Reads customer info from a file and populates the store's
// customer list. Preconditions: The input file contains valid customer
// information in the specified format. PostCoditions: Populates the store's
// customer list with the customer information read from the file.
void Store::buildCustomersFromFile(const std::string &filename) {
  // file format:
  ifstream infile(filename);
  if (!infile) {
    cerr << "Error: could not open file " << filename << endl;
    return;
  }

  int customerID;
  string lastName;
  string firstName;

  // while not eof (end of file)
  while (!infile.eof()) {
    // read customer data from file.
    // Input format: int customer ID, string last name, string first name.
    // seperated by space. next line is next customer.
    customerID = -1;
    infile >> customerID >> lastName >> firstName;
    if (customerID == -1) {
      // no valid integer to read
      break;
    }

    if (customerList->find(customerID) == nullptr) {
      // create customer object
      Customer *customer = new Customer(customerID, lastName, firstName);
      // customer->printCustomer();
      //  add customer to customer list hashtable
      customerList->add(customer);
    } else {
      cout << "Customer #" << customerID << " already exists. " << endl;
    }
  }
}

// --------------------------- clearBlanks ---------------------------
// Description: Helper method, removes leading spaces from a string.
// Preconditions: None.
// PostCoditions: Modifies the string parameter by removing leading spaces.
void Store::clearBlanks(string &str) {
  if (str[0] == ' ') {
    // str = str.substr(1);
    str.erase(0, 1);
  }
}

// --------------------------- Store::buildInventory ---------------------------
// Description: Reads movie information from a file and cills store's inventory.
// Preconditions: The input file contains valid movie information in the
// specified format. PostCoditions: Populates the store's inventory with the
// movie information read from the file.
void Store::buildInventory(const std::string &fileName) {

  // input format:
  /* In data4movies.txt, the information about each movie is listed as follows:
For comedy movies: F, Stock, Director, Title, Year it released
For drama movies: D, Stock, Director, Title, Year it released
For classics movies: C, Stock, Director, Title, Major actor Release date
all feilds are separated by commas and the string may contain spaces
next line is next movie.
instructions:
create movie instance using movie data, save the above data in the instance
add movie to inventory
if incorrect data format, print error message and skip to next line
*/

  ifstream infile(fileName);
  if (!infile) {
    cerr << "Error: could not open file " << fileName << endl;
    return;
  }

  // while not eof (end of file)
  while (!infile.eof()) {
    string line;

    while (getline(infile, line)) {
      istringstream iss(line);

      char movieType;
      int stock, releaseYear, releaseMonth;
      string str, director, title, majorActor, actorFirstName, actorLastName;

      iss >> movieType;
      getline(iss, str, ',');
      iss >> stock;
      getline(iss, str, ',');
      getline(iss, director, ',');
      clearBlanks(director);

      getline(iss, title, ',');
      clearBlanks(title);

      // cout << movieType << "," << stock << "," << director << "," << title
      //     << "," << endl;

      if (movieType == 'F') {
        iss >> releaseYear;
        // cout << releaseYear << endl;

        // create comedy movie object
        Comedy *movie =
            new Comedy(movieType, stock, director, title, releaseYear);
        Movie *mov = movie;
        inventory->addMovie(mov);
      } else if (movieType == 'D') {
        iss >> releaseYear;
        Drama *movie =
            new Drama(movieType, stock, director, title, releaseYear);
        inventory->addMovie(movie);
      } else if (movieType == 'C') {
        iss >> actorFirstName >> actorLastName >> releaseMonth >> releaseYear;

        Classic *movie =
            new Classic(movieType, stock, director, title, actorFirstName,
                        actorLastName, releaseMonth, releaseYear);
        inventory->addMovie(movie);

      } else {
        cerr << "Error: invalid movie type " << movieType << endl;
        continue; // skip to next line
      }
    }
  }
}

// --------------------------- ReadMovieAttributes ---------------------------
// Description: Reads attributes of a movie from a string stream and creates a
// movie object based on the provided attributes. Preconditions: The string
// stream contains valid movie attributes in the specified format.
// PostCoditions: Returns a pointer to the created Movie object.
Movie *Store::ReadMovieAttributes(std::istringstream &iss) {
  Movie *findMovie = nullptr;
  char movieType;
  char mediaType;

  int releaseYear; // releaseMonth;
  string str, director, title, majorActor, actorFirstName, actorLastName;

  iss >> mediaType;
  if ('D' != mediaType) {
    cout << "ERROR: " << mediaType << " Invalid Media Type. Try Again." << endl;
    return nullptr;
  }

  iss >> movieType;

  if ('F' == movieType) {
    // title and year
    getline(iss, title, ',');
    clearBlanks(title);
    iss >> releaseYear;
    findMovie = new Comedy(movieType, 0, "", title, releaseYear);

  } else if ('D' == movieType) {
    // director and title
    getline(iss, director, ',');
    clearBlanks(director);

    getline(iss, title, ',');
    clearBlanks(title);
    //  Drama *comedy = new Drama('D', 0, director, title, 0);
    findMovie = new Drama(movieType, 0, director, title, 0);

  } else if ('C' == movieType) {
    int releaseMonth;
    int releaseYear;
    string actorFirstName, actorLastName;
    iss >> releaseMonth >> releaseYear >> actorFirstName >> actorLastName;

    // cout << "ReadMovieAttributes: " << movieType << releaseMonth <<
    // releaseYear
    //     << actorFirstName << actorLastName << endl;

    findMovie = new Classic(movieType, 0, "", "", actorFirstName, actorLastName,
                            releaseMonth, releaseYear);
  } else {
    cout << "ERROR: " << movieType << " Invalid Genre. Try Again." << endl;
  }
  return findMovie;
}

// --------------------------- buildMoviesFromFile ---------------------------
// Description: Reads movie information from a file and cills store's inventory.
// Preconditions: The input file contains valid movie information in the
// specified format.
// PostCoditions: Populates the store's inventory with the
// movie information read from the file.
void Store::processTransactionsFromFile(const std::string &fileName) {
  ifstream infile(fileName);
  if (!infile) {
    cerr << "Error: could not open file " << fileName << endl;
    return;
  }

  // while not eof (end of file)
  while (!infile.eof()) {
    string line;

    while (getline(infile, line)) {
      istringstream iss(line);

      char transactionType;

      int customerID;
      Movie *movie;
      Customer *customer;

      iss >> transactionType;
      // cout << "processTransaction: " << transactionType << endl;

      if ('I' == transactionType) {
        // for displaying inventory we don't need get any more info nor store
        // the transaction
        displayInventory();
      } else if ('H' == transactionType) {
        iss >> customerID;

        customer = customerList->find(customerID);
        if (customer == nullptr) {
          // no such customer
          cout << "ERROR: Borrow Transaction Failed -- Customer " << customerID
               << " does not exist" << endl;
        } else {
          customer->getHistory();
        }

      } else if ('B' == transactionType || 'R' == transactionType) {
        string transactionStr;
        ('B' == transactionType) ? transactionStr = "Borrow"
                                 : transactionStr = "Return";

        iss >> customerID;

        // first find customer
        customer = customerList->find(customerID);
        if (customer == nullptr) {
          // no such customer
          cout << "ERROR: " << transactionStr
               << " Transaction Failed -- Customer " << customerID
               << " does not exist" << endl;
        } else {
          // now find movie

          Movie *findMovie = ReadMovieAttributes(iss);
          if (findMovie) {
            movie = inventory->findMovie(findMovie);
            // delete the temp findMovie, b/c we want to use the one in the
            // inventory
            delete findMovie;
            if (movie == nullptr) {
              // no such movie
              cout << "ERROR: " << transactionStr
                   << " Transaction Failed -- Movie does not Exist in the "
                      "Inventory"
                   << endl;
            } else {

              // ok we need a transaction to save
              Transaction *transaction =
                  new Borrow(transactionType, customerID, movie);
              customer->doTransaction(transaction, inventory);
            }
          }
        }
      } else {
        cout << "ERROR: invalid transaction type: " << transactionType << endl;
      }
    }
  }
}

// --------------------------- displayInventory ---------------------------
// Description: Displays the inventory of the store.
// Preconditions: None.
// PostCoditions: Prints the inventory of the store to the console.
void Store::displayInventory() { inventory->displayInventory(); }

// --------------------------- displayHistory ---------------------------
// Description: Displays the borrowing and return history of a customer.
// Preconditions: None.
// PostCoditions: Prints the history of a customer to the console.
void Store::displayHistory(Customer customer) {}