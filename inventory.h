// --------------------------- inventory.h ---------------------------
// Aisha M
// CSS 343 D Due 3/13/2024
// ------------------------------------------------------------------------
/* Represents the inventory of movies.
Utilizes a hash table for efficient lookup.
Implements methods for adding movies, borrowing/returning movies, and
displaying the inventory. */
// ------------------------------------------------------------------------

#pragma once
#include "classic.h"
#include "comedy.h"
#include "customer.h"
#include "drama.h"
#include "movie.h" // Include necessary header files
#include <set>

class Inventory {
public:
  // void add(Movie *movie) override;
  Inventory();
  ~Inventory();

  void addMovie(Movie *movie);
  void displayInventory();
  Movie *findMovie(Movie *movie);

  // private:
  //  ordered map for: comedy movies sorted by Title, then Year released

  std::set<Movie *, Comedy::ComedyComparator> comedyMovies;
  std::set<Movie *, Drama::DramaComparator> dramaMovies;
  std::set<Movie *, Classic::ClassicComparator> classicMovies;
};

// INVENTORY_H