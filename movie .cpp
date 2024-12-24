// --------------------------- movie.cpp ---------------------------
// Aisha M
// CSS 343 D Due 3/13/2024
// ------------------------------------------------------------------------
/* The Movie class represents a movie entity with various attributes. It
 * includes data members to store information about the movie, such as stock,
 * director, title, release year, and availability status. It also includes
 * methods to add and remove stock, display movie information, and check
 * availability. */
// ------------------------------------------------------------------------

#include "movie.h"
#include <cassert>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// Constructor ---------------------------
Movie::Movie(char genre, int stock, string director, string title,
             int releaseYear) {
  this->media = 'D'; // only DVDs according to specs
  this->genre = genre;
  this->stock = stock;
  this->director = director;
  this->title = title;
  this->releaseYear = releaseYear;
}

// --------------------------- Movie::Display ---------------------------
// Description: Displays the details of the movie.
// Preconditions: None.
// PostCoditions: Prints the genre, media type, title, director, release year,
// and stock of the movie.
void Movie::Display() {
  cout << genre << " " << media << " " << title << " " << director << " "
       << releaseYear << " " << stock << endl;
}

// --------------------------- Movie::operator== ---------------------------
// Description: Overloads == operator copares 2 Movie objects by Title then Year
// Preconditions: None.
// PostCoditions: Returns true if the titles and release years of the two movies
// are equal, otherwise returns false.
bool Movie::operator==(const Movie &other) const {
  // cout << "Movie operator== called" << endl;
  if (getTitle() == other.getTitle()) {
    return (getYear() == other.getYear());
  }
  return (getTitle() == other.getTitle());
}

// --------------------------- Movie::operator< ---------------------------
// Description: Overloads < to compare 2 Movie objects sorted by Title then Year
// Preconditions: None.
// PostCoditions: Returns true if the title of the current movie is
// lexicographically less than the title of the other movie, or if the titles
// are the same and the release year of the current movie is less than that of
// the other movie; otherwise, returns false. overwrite operator for ordered map
bool Movie::operator<(const Movie &other) const {
  // cout << "Movie operator< called" << endl;
  if (getTitle() == other.getTitle()) {
    return (getYear() < other.getYear());
  }
  return (getTitle() < other.getTitle());
}

// --------------------------- Movie::operator<= ---------------------------
// Description: overwrite operator for ordered map sorted by Title then Year
// released to compare two Movie objects less or equal to
// Preconditions: None.
// PostCoditions: Returns true if the title of the current movie is
// lexicographically less than or equal to the title of the other movie, or if
// the titles are the same and the release year of the current movie is less
// than or equal to that of the other movie; otherwise, returns false.
bool Movie::operator<=(const Movie &other) const {
  // cout << "Movie operator<= called" << endl;
  if (getTitle() == other.getTitle()) {
    return (getYear() <= other.getYear());
  }
  return (getTitle() <= other.getTitle());
}
