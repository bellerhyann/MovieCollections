#include <iostream>
#include <fstream>
#include <string>

#include "Movie.hpp"
#include "MovieCollection.hpp"

using namespace std;

int main(int argc, char *arv[])
{
  MovieCollection simple;
  ifstream ifile("someMovies.txt");
  MovieCollection fromFile(ifile);
  ifile.close();
  MovieCollection duplicate(fromFile);

  Movie temp("Fantasia", 1940, 9);
  simple+= temp;
  cout << simple; // should give Fantasia only
  cout << "========================================================="
       <<endl << endl;
  
  fromFile+=temp;
  // should give: Mark of Zorro, Cinderella, , Magnificent Seven,
  //    Funny Thing Happened on the Way to the Forum, MASH, Star Wars,
  //    Airplane!, Shining, Fantasia ... (not necessarily in this orer)
  cout << fromFile; 
  cout << "========================================================="
       <<endl << endl;

  // should give: Mark of Zorro, Cinderella, , Magnificent Seven,
  //    Funny Thing Happened on the Way to the Forum, MASH, Star Wars,
  //    Airplane!, Shining  ... (not necessarily in this order, but not
  //       including Fantasia!)
  cout << duplicate;
  cout << "========================================================="
       <<endl << endl;
  

  MovieCollection otherDup;
  Movie fod("Field of Dreams" , 1989, 10);
  otherDup = duplicate += fod;
  
  // should give: Mark of Zorro, Cinderella, , Magnificent Seven,
  //    Funny Thing Happened on the Way to the Forum, MASH, Star Wars,
  //    Airplane!, Shining, Field of Dreams  ... (not necessarily in this
  //    order)
  cout << duplicate;
  cout << "========================================================="
       <<endl << endl;
  
  // should give: Mark of Zorro, Cinderella, , Magnificent Seven,
  //    Funny Thing Happened on the Way to the Forum, MASH, Star Wars,
  //    Airplane!, Shining, Field of Dreams  ... (not necessarily in this
  //    order)
  cout << otherDup;
  cout << "========================================================="
       <<endl << endl;

  Movie cinders("Cinderella", 1950, 7);
  otherDup-=cinders;

  // same as last output, but without Cinderella. 
  cout << otherDup;
  cout << "========================================================="
       <<endl << endl;

  // same as last output, but WITH Cinderella.
  cout << duplicate;
  cout << "========================================================="
       <<endl << endl;

  duplicate.clear();

  // should be empty. 
  cout << duplicate;
  cout << "========================================================="
       <<endl << endl;
  
  // same as last output of otherDup, certainly not empty!
  cout << otherDup;
  cout << "========================================================="
       <<endl << endl;
}
