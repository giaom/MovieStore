// --------------------------- comedy.h ---------------------------
// Aisha M
// CSS 343 D Due 3/13/2024
// ------------------------------------------------------------------------
/*  The Comedy class represents a comedy movie, which is a type of Movie.
   It inherits from the Movie class and provides specific functionality
   and comparison methods tailored to comedy movies.

   Public Methods:
   - Constructor: Initializes a Comedy object with the given genre, stock,
     director, title, and release year.

   Overridden Methods:
   - operator==: Overrides the equality operator to compare Comedy movies
     based on their titles and release years.
   - operator<: Overrides the less than operator to compare Comedy movies
     based on their titles and release years.
   - operator>: Overrides the greater than operator to compare Comedy movies
     based on their titles and release years.
   - operator<=: Overrides the less than or equal to operator to compare Comedy
     movies based on their titles and release years.
   - operator>=: Overrides the greater than or equal to operator to compare
   Comedy movies based on their titles and release years.

   Structs:
   - ComedyComparator: Provides a comparison function to compare two Comedy
     movies based on their titles and release years.
*/
// ------------------------------------------------------------------------

#pragma once
#include "movie.h"
#include <map>

class Comedy : public Movie {

public:
  // Constructor
  Comedy(char genre, int stock, std::string director, std::string title,
         int releaseYear)
      : Movie(genre, stock, director, title, releaseYear){};

  // overwrite operator for ordered map sorted by Title then Year released
  bool operator==(const Comedy &other) const;
  bool operator<(const Comedy &other) const;
  bool operator>(const Comedy &other) const;
  bool operator<=(const Comedy &other) const;
  bool operator>=(const Comedy &other) const;

  struct ComedyComparator {
    bool operator()(const Movie *movie1, const Movie *movie2) const {
      // std::cout << "ComedyComparator called" << std::endl;
      if (movie1->getTitle() == movie2->getTitle()) {
        return movie1->getYear() < movie2->getYear();
      }
      return movie1->getTitle() < movie2->getTitle();
    }
  };

private:
};

// COMEDY_H
