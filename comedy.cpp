// --------------------------- comedy.cpp ---------------------------
// Aisha M
// CSS 343 D Due 3/13/2024
// ------------------------------------------------------------------------
/*  The Comedy class represents a comedy movie, which is a type of Movie.
   It inherits from the Movie class and provides specific functionality
   and comparison methods tailored to comedy movies. */
// ------------------------------------------------------------------------

#include "comedy.h"
#include "movie.h"
#include <cassert>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
/*
Comedy::Comedy(char genre, int stock, string &director, string &title,
               int releaseYear) {

  this->genre = genre;
  this->stock = stock;
  this->director = director;
  this->title = title;
  this->releaseYear = releaseYear;

  cout << "Comedy movie added to inventory." << this->title << this->director
       << this->releaseYear << endl;
}
*/

// --------------------------- operator== ---------------------------
// Discribtion: Overload the == operator to compare two comedy movies based on
// their title, director, and release year.
// Preconditions: None.
// PostCoditions: Returns true if the two comedy movies have the same title and
// release year, false otherwise.

bool Comedy::operator==(const Comedy &other) const {
  // cout << "Comedy operator== called" << endl;
  if (getTitle() == other.getTitle()) {
    return (getYear() == other.getYear());
  }
  return (getTitle() == other.getTitle());
}

// --------------------------- operator< ---------------------------
// Discribtion: Overload the < operator to compare two comedy movies based on
// their title and release year.
// Preconditions: None.
// PostCoditions: Returns true if the title of the first comedy movie is
// lexicographically less than the title of the second comedy movie. If the
// titles are equal, it compares their release years.
bool Comedy::operator<(const Comedy &other) const {
  // cout << "Comedy operator< called" << endl;
  if (this->getTitle() == other.getTitle()) {
    return (this->getYear() < other.getYear());
  }
  return (this->getTitle() < other.getTitle());
}
// --------------------------- operator> ---------------------------
// Discribtion: Overload the > operator to compare two comedy movies based on
// their title then by release year.
// Preconditions: None.
// PostCoditions: Returns true if the title of the first comedy movie is
// lexicographically greater than the title of the second comedy movie. If the
// titles are equal, it compares their release years.
bool Comedy::operator>(const Comedy &other) const {
  // cout << "Comedy operator> called" << endl;
  if (getTitle() == other.getTitle()) {
    return (getYear() > other.getYear());
  }
  return (getTitle() > other.getTitle());
}

// --------------------------- operator<= ---------------------------
// Discribtion: Overload the <= operator to compare two comedy movies based on
// their title then by release year.
// Preconditions: None.
// PostCoditions: Returns true if the title of the first comedy movie is
// lexicographically less than or equal to the title of the second comedy movie.
// If the titles are equal, it compares their release years.
bool Comedy::operator<=(const Comedy &other) const {
  // cout << "Comedy operator<= called" << endl;
  if (getTitle() == other.getTitle()) {
    return (getYear() <= other.getYear());
  }
  return (getTitle() <= other.getTitle());
}

// --------------------------- operator>= ---------------------------
// Discribtion: Overload the >= operator to compare two comedy movies based on
// their title then by release year.
// Preconditions: None.
// PostCoditions: Returns true if the title of the first comedy movie is
// lexicographically greater than or equal to the title of the second comedy
// movie. If the titles are equal, it compares their release years.
bool Comedy::operator>=(const Comedy &other) const {
  // cout << "Comedy operator>= called" << endl;
  if (getTitle() == other.getTitle()) {
    return (getYear() >= other.getYear());
  }
  return (getTitle() >= other.getTitle());
}
