// --------------------------- classic.h ---------------------------
// Aisha M
// CSS 343 D Due 3/13/2024
// ------------------------------------------------------------------------
/*  Description:
   The Classic class represents a classic movie, which is a type of Movie.
   It inherits from the Movie class and provides specific functionality
   and comparison methods tailored to classic movies.

   Public Methods:
   - Constructor: Initializes a Classic object with the given genre, stock,
     director, title, actor's first name, actor's last name, release month,
     and release year.

   Structs:
   - ClassicComparator: Provides a comparison function to compare two Classic
     movies based on their release years, release months, and actor's first
   names.

   Getter Methods:
   - getActorFirstName: Retrieves the actor's first name of the classic movie.
   - getActorLastName: Retrieves the actor's last name of the classic movie.
   - getMonth: Retrieves the release month of the classic movie.

   Private Members:
   - actorFirstName: A string representing the actor's first name of the classic
   movie.
   - actorLastName: A string representing the actor's last name of the classic
   movie.
   - releaseMonth: An integer representing the release month of the classic
   movie.
*/
// ------------------------------------------------------------------------

#pragma once
#include "movie.h"

using namespace std;

class Classic : public Movie {
public:
  // Constructor
  Classic(char genre, int stock, string director, string title,
          string actorFirstName, string actorLastName, int releaseMonth,
          int releaseYear)
      : Movie(genre, stock, director, title, releaseYear),
        actorFirstName(actorFirstName), actorLastName(actorLastName),
        releaseMonth(releaseMonth){};

  struct ClassicComparator {
    bool operator()(Movie *movie1, Movie *movie2) const {
      Classic *classic1 = dynamic_cast<Classic *>(movie1);
      Classic *classic2 = dynamic_cast<Classic *>(movie2);

      // std::cout << "ClassicComparator called" << std::endl;
      if (classic1->getYear() == classic2->getYear()) {
        if (classic1->getMonth() == classic2->getMonth()) {
          // originally compared last name first, but the output file provided
          // by prof showed that the first name was compared first
          if (classic1->getActorFirstName() == classic2->getActorFirstName()) {
            return classic1->getActorLastName() < classic2->getActorLastName();
          }
          return classic1->getActorFirstName() < classic2->getActorFirstName();
        }

        return classic1->getMonth() < classic2->getMonth();
      }
      return classic1->getYear() < classic2->getYear();
    }
  };

  // for classic movies we want to know if there is a similar movie
  bool isSimilar(Classic *other);

  // Getter methods
  std::string getActorFirstName() const { return actorFirstName; }
  std::string getActorLastName() const { return actorLastName; }
  int getMonth() const { return releaseMonth; }

private:
  std::string actorFirstName;
  std::string actorLastName;
  int releaseMonth;
};

// CLASSIC_H
