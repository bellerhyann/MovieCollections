#ifndef _MOVIECOLLECTION_HPP_
#define _MOVIECOLLECTION_HPP_
/**
Creator: Belle Erhardt
12/2020
HashTable
*/

#include "Movie.hpp"
#include <string>
#include <iostream>  
#include <list>  


class MovieCollection
{
private:
std::list< Movie > _mc[100];
public:

//Basic constructor
MovieCollection();
//Input Stream constructor
MovieCollection(std::istream &input);
//Copy constructor
MovieCollection(const MovieCollection &sample); 

 //HashFunction
 int HashNum(Movie sample);

//Methods
void
addValue(Movie newMovie);
bool
look( Movie newMovie);
std:: ostream& print(std::ostream &os);
void
clear();
int 
size();
int
getRating(const std::string &title, int year);
int
maxSearchlength();
//Operators	
MovieCollection operator= (const MovieCollection&);
const MovieCollection& operator+= (const Movie &newMovie);
const MovieCollection& operator+= (const MovieCollection &sample);
friend std::ostream& operator<< (std::ostream &os, MovieCollection &m);
const MovieCollection& operator-= (const Movie &newMovie);
const MovieCollection& operator-= (const MovieCollection &sample);
const MovieCollection& operator+(const MovieCollection &sample)const;//union
const MovieCollection& operator/(const MovieCollection &sample)const;//intersection
};
#endif
