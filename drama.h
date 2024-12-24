// --------------------------- drama.h ---------------------------
// Aisha M
// CSS 343 D Due 3/13/2024
// ------------------------------------------------------------------------
/* Description:
   The Drama class represents a drama movie, which is a type of Movie.
   It inherits from the Movie class and provides specific functionality
   and comparison methods tailored to drama movies.

   Public Methods:
   - Constructor: Initializes a Drama object with the given genre, stock,
     director, title, and release year.

   Structs:
   - DramaComparator: Provides a comparison function to compare two Drama
     movies based on their directors and titles.

   Overridden Methods:
   - operator<: Overrides the less than operator to compare Drama movies
     based on their directors and titles.
*/
// ------------------------------------------------------------------------

#pragma once
#include "movie.h"

class Drama : public Movie {
private:
public:
  // --------------------------- Constructor ---------------------------
  // Description: Initializes a Drama object with the given genre, stock,
  // director, title, and release year. Preconditions: The parameters must be
  // valid values. PostCoditions: Initializes a Drama object with the provided
  // values.
  Drama(char genre, int stock, std::string director, std::string title,
        int releaseYear)
      : Movie(genre, stock, director, title, releaseYear){};

  struct DramaComparator {
    // --------------------------- DramaComparator::operator()
    // Description: Provides a comparison function
    // to compare two Drama movies based on their directors and titles.
    // Preconditions: None.
    // PostCoditions: Returns true if the director of the first movie is
    // lexicographically less than the director of the second movie. If
    // directors are the same, compares titles lexicographically.
    bool operator()(const Movie *movie1, const Movie *movie2) const {
      // std::cout << "DramaComparator called" << std::endl;
      if (movie1->getDirector() == movie2->getDirector()) {
        return movie1->getTitle() < movie2->getTitle();
      }
      return movie1->getDirector() < movie2->getDirector();
    }

    /*
        bool operator()(const Movie &movie1, const Movie &movie2) const {
          std::cout << "DramaComparator called" << std::endl;
          if (movie1.getDirector() == movie2.getDirector()) {
            return movie1.getTitle() < movie2.getTitle();
          }
          return movie1.getDirector() < movie2.getDirector();
        }*/
  };

  // --------------------------- Drama::operator< ---------------------------
  // Description: Overrides the less than operator to compare Drama movies based
  // on their directors and titles. Preconditions: None. PostCoditions: Returns
  // true if the director of the current Drama movie is lexicographically less
  // than the director of the other movie. If directors are the same, compares
  // titles lexicographically.
  bool operator<(const Movie &other) const {
    // std::cout << "Drama operator< called" << std::endl;
    if (this->getDirector() == other.getDirector()) {
      return (this->getTitle() < other.getTitle());
    }
    return (this->getDirector() < other.getDirector());
  }
};

// DRAMA_H
