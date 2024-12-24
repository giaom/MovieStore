#include "classic.h"
#include "movie.h"
#include <cassert>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

bool Classic::isSimilar(Classic *other) {

  if ((getDirector() == other->getDirector()) &&
      (getTitle() == other->getTitle()) && (getYear() == other->getYear())) {
    return true;
  }
  return false;
}