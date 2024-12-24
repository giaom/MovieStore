// --------------------------- inventory.cpp ---------------------------
// Aisha M
// CSS 343 D Due 3/13/2024
// ------------------------------------------------------------------------
/* Represents the inventory of movies.
Utilizes a hash table for efficient lookup.
Implements methods for adding movies, borrowing/returning movies, and
displaying the inventory. */
// ------------------------------------------------------------------------

#include "inventory.h"
#include <cassert>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Constructor for  inventory
Inventory::Inventory() {}

// Destructor for  inventory
Inventory::~Inventory() {
  // cout << "Inventory destructor called" << endl;

  for (auto it = comedyMovies.begin(); it != comedyMovies.end(); ++it) {
    delete *it;
  }
  comedyMovies.clear();
  for (auto movie : dramaMovies) {
    delete movie;
  }
  dramaMovies.clear();
  for (auto movie : classicMovies) {
    delete movie;
  }
  classicMovies.clear();
}

// --------------------------- addMovie ---------------------------
// Description: Adds a movie to the inventory.
// Preconditions: movie must point to a valid Movie object.
// PostCoditions: Inserts the movie into the appropriate set based on its genre.
void Inventory::addMovie(Movie *movie) {
  char genre = movie->getGenre();
  if ('F' == genre) {
    comedyMovies.insert(movie);

  } else if ('D' == genre) {
    dramaMovies.insert(movie);

  } else if ('C' == genre) {
    classicMovies.insert(movie);

  } else {
    std::cout << "Error: invalid movie type " << genre << std::endl;
  }
}

// --------------------------- displayInventory ---------------------------
// Description: Displays the current inventory of movies.
// Preconditions: None.
// PostCoditions: Prints list of comedies, dramas, and classics with details
void Inventory::displayInventory() {
  cout << "-----------------------------------------------------" << endl;
  cout << "-------------------- Inventory ----------------------" << endl;
  cout << "-----------------------------------------------------" << endl;
  cout << "Comedies:" << endl;

  cout << "Genre Media Title Director "
       << "Year Stock" << endl;
  for (auto movie : comedyMovies) {
    movie->Display();
  }

  cout << "-----------------------------------------------------" << endl;
  cout << "Dramas:" << endl;

  cout << "Genre Media Title Director "
       << "Year Stock" << endl;
  for (auto movie : dramaMovies) {
    movie->Display();
  }

  cout << "-----------------------------------------------------" << endl;
  cout << "Classics:" << endl;

  cout << "Genre Media Title Director "
       << "Year Stock" << endl;

  ostringstream ossMovie, ossMajorActor;
  Classic *prevMovie = nullptr;
  int totalStock = 0;

  for (auto it : classicMovies) {
    Classic *movie = dynamic_cast<Classic *>(it);

    // if (prevMovie && (prevMovie->getTitle() == movie->getTitle())) {
    if (prevMovie && movie->isSimilar(prevMovie)) {
      totalStock += movie->getStock();

      ossMajorActor << movie->getActorFirstName() << " "
                    << movie->getActorLastName() << " -- " << movie->getStock()
                    << endl;
    } else {
      if (prevMovie) {
        cout << ossMovie.str() << totalStock << endl;
        cout << ossMajorActor.str() << endl;
        totalStock = 0;
        ossMovie.str("");
        ossMovie.clear();
        ossMajorActor.str("");
        ossMajorActor.clear();
      }

      ossMovie << movie->getGenre() << " D " << movie->getTitle() << " "
               << movie->getDirector() << " " << movie->getMonth() << " "
               << movie->getYear() << " ";

      ossMajorActor << movie->getActorFirstName() << " "
                    << movie->getActorLastName() << " -- " << movie->getStock()
                    << endl;
      totalStock += movie->getStock();
    }
    prevMovie = movie;
  }

  cout << ossMovie.str() << totalStock << endl;
  cout << ossMajorActor.str() << endl;

  // movie->Display();

  cout << "-----------------------------------------------------" << endl;
}

// --------------------------- findMovie ---------------------------
// Description: Finds a movie in the inventory.
// Preconditions: movie must point to a valid Movie object.
// PostCoditions: Returns a pointer to the found movie if it exists in the
// inventory, otherwise returns nullptr.
Movie *Inventory::findMovie(Movie *movie) {
  Movie *found = nullptr;
  ;
  if (movie == nullptr) {
    std::cout << "nullptr not valid movie" << std::endl;
    return found;
  }
  if ('F' == movie->getGenre()) {
    auto it = comedyMovies.find(movie);
    if (it != comedyMovies.end()) {
      found = *it;
    }
  } else if ('D' == movie->getGenre()) {
    auto it = dramaMovies.find(movie);
    if (it != dramaMovies.end()) {
      found = *it;
    }
  } else if ('C' == movie->getGenre()) {
    auto it = classicMovies.find(movie);
    if (it != classicMovies.end()) {
      found = *it;
    }
  }

  if (found) {
    // found->Display();
  }
  return found;
}
