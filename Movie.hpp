#ifndef _MOVIE_HPP_
#define _MOVIE_HPP_

// FILE: Movie.hpp
// AUTHOR: Stephen Blythe
// DATE: 8/2020
//    Definition file for Movie class 
// Edited 12/8 by: Belle Erhardt

#include <string>
#include <iostream>

class Movie
{
private:
  std::string _title;   // Movie title
  int _year;            // Movie release year
  double _rating;       // Movie rating
  
public:
  // default constructor
  Movie() : _title(), _year(1900), _rating(0) {}

  // fully qualified constructor
  Movie(const std::string &title, int year, double rating);
  
  // accessor and modifier for movie title
  const std::string& title() const {return _title;}
  std::string& title() {return _title;}

  // accessor and modifier for movie release year
  const int year() const {return _year;}
  int& year() {return _year;}

  // accessor and modifier for movie rating
  const double rating() const {return _rating;}
  double& rating() {return _rating;}
  
  // overloaded assignment operator
  const Movie& operator=(const Movie &other);

  // overloaded equality / inequality operators
  //   NTE: equality only looks at title and release year, not rating .
  bool operator==(const Movie &other) const;
  bool operator!=(const Movie &other) const;

  bool operator<(const Movie &other) const;
  
  // finctions to write out/read in Movie via a stream 
  std::ostream& print (std::ostream &os) const;
  std::istream& read (std::istream &is);

  // overloaded << and >> operators. 
  friend std::ostream& operator<< (std::ostream &os, const Movie &m);
  friend std::istream& operator>> (std::istream &is, Movie &m);
};

#endif
