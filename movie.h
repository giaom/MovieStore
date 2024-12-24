// --------------------------- movie.h ---------------------------
// Aisha M
// CSS 343 D Due 3/13/2024
// ------------------------------------------------------------------------
/* The Movie class represents a movie entity with various attributes. It
 * includes data members to store information about the movie, such as stock,
 * director, title, release year, and availability status. It also includes
 * methods to add and remove stock, display movie information, and check
 * availability. */
// ------------------------------------------------------------------------

#pragma once
#include <cassert>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

class Movie {
private:
  char genre; // Data member to store genre
  char media; // D -> DVD

  std::string director; // Data member to store movie director
  std::string title;    // Data member to store movie title
  int releaseYear;      // Data member to store movie release year

public:
  // Constructor
  Movie(char genre, int stock, std::string director, std::string title,
        int releaseYear);

  virtual ~Movie() {}

  int stock; // Data member to store movie stock
  // Getter methods

  char getGenre() const { return genre; };
  int getStock() const { return stock; };
  std::string getDirector() const { return director; };
  std::string getTitle() const { return title; };
  int getYear() const { return releaseYear; };

  void Display();

  // Comparison operators
  bool operator==(const Movie &other) const;
  bool operator<(const Movie &other) const;
  bool operator<=(const Movie &other) const;
};

// MOVIE_H
