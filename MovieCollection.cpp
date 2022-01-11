#include "MovieCollection.hpp"
#include <iostream>

const int TABLE_SIZE = 100;

using namespace std;

//constructors
MovieCollection::MovieCollection()
	{}
MovieCollection::MovieCollection(istream &input)
	{
	Movie first;
	input>>first;
	while(input)
		{
		(*this)+=first;
		input>>first;
		}
	}
MovieCollection::MovieCollection(const MovieCollection &sample)
	{
	for(int index = 0; index < TABLE_SIZE; index++)
		{
		
		_mc[index] = sample._mc[index];
		}
	}
//HashFunction
int 
MovieCollection:: HashNum(Movie sample)
	{
	string Title = sample.title();
	int hashNum = sample.year();
	int length= Title.length();
		for(int i= 0; i<length; i++)
			{
			int k= Title[i];
			hashNum+=k;
			}
		hashNum= hashNum%TABLE_SIZE;
		
		return hashNum;
	}
//Methods
ostream&
MovieCollection::print(ostream &os)
	{
	for(int index = 0; index < TABLE_SIZE; index++)
		{
		list<Movie> :: iterator spot;
		for(spot = _mc[index].begin();spot !=_mc[index].end();spot++)
			os<<*spot<<endl;
		}
	 return os;
	}
void 
MovieCollection :: addValue(Movie newMovie)
	{
	if(look(newMovie))
		{
		_mc[HashNum(newMovie)].push_back(newMovie); 
		}
	}
bool
MovieCollection:: look( Movie newMovie)
	{
	bool stillNew = true;
	list<Movie> :: iterator olderMovie;
	olderMovie = _mc[HashNum(newMovie)].begin();
		while(newMovie!=*olderMovie && olderMovie!= _mc[HashNum(newMovie)].end())
			{olderMovie++;}
		if(newMovie==*olderMovie )
			{stillNew=false;}
		return stillNew;	
	}
void
MovieCollection:: clear()
	{
	for(int i=0; i<TABLE_SIZE; i++)
		_mc[i].clear();
	}
int 
MovieCollection:: size()
	{
	int count = 0;
	for(int i=0; i<TABLE_SIZE; i++)
		count+=_mc[i].size();
	return count;
	}
int
MovieCollection:: getRating(const string &title, int year)
	{
	
	Movie lookfor( title, year, -1);
	int rating = lookfor.rating();	
	list<Movie> :: iterator checkhere;
	checkhere = _mc[HashNum(lookfor)].begin();
		while(checkhere!= _mc[HashNum(lookfor)].end())
			{
			
			if(lookfor==*checkhere )
				{
				rating= checkhere->rating();
				break;
				}
			checkhere++;
			}
		return rating;
	}
int
MovieCollection:: maxSearchlength()
	{
	int max=0;
	for(int i=0; i<TABLE_SIZE; i++)
		{
		int indexMax = _mc[i].size();
		if(max<indexMax)
			max=indexMax;
		}
	return max;
	}
//Operators
MovieCollection
MovieCollection:: operator= (const MovieCollection& sample)
	{
	clear();
	for(int index = 0; index < TABLE_SIZE; index++)
		{
		_mc[index] = sample._mc[index];
		}
		return *this;
	}
const MovieCollection&
MovieCollection::operator+=(const Movie &newMovie)
	{
	addValue(newMovie);
	return *this;
	}
const MovieCollection&
MovieCollection:: operator+= (const MovieCollection &sample)
	{
	
	for(int index = 0; index < TABLE_SIZE; index++)
		{	
		list<Movie> :: const_iterator movie;
				for(movie = sample._mc[index].begin();  movie !=sample._mc[index].end(); movie++)
					addValue(*movie);	
		}
		return *this;
	}
ostream& operator<< (ostream &os, MovieCollection &m)
	{
	return m.print(os);
	}
const MovieCollection& 
MovieCollection::operator-= (const Movie &removeMe)
	{
	if(!look(removeMe))
		_mc[HashNum(removeMe)].remove(removeMe);
	return *this;
	}
const MovieCollection&
MovieCollection:: operator-= (const MovieCollection &sample)
	{
	for(int index = 0; index < TABLE_SIZE; index++)
		{	
		list<Movie> :: const_iterator movie;
				for(movie = sample._mc[index].begin();  movie !=sample._mc[index].end(); movie++)
					operator-=(*movie);	
		}
	return *this;
	}
	
	
//unionis almost working.. will compile logical error
const MovieCollection& 
MovieCollection:: operator+(const MovieCollection &sample)const
	{
	MovieCollection *largeList = new MovieCollection;
	*largeList=*this;
	*largeList+=sample;
	return *largeList;
	}

//intersections
const MovieCollection&
MovieCollection:: operator/(const MovieCollection &sample)const
	{
	MovieCollection *returnValue = new MovieCollection();
	{
	for(int index = 0; index < TABLE_SIZE; index++)
		{	
		list<Movie> :: const_iterator movie;
				for(movie = sample._mc[index].begin();  movie !=sample._mc[index].end(); movie++)
					//if(!sample.look(*movie))//if look returns false that means this is a repeat)
						returnValue->operator+=(*movie);	
		}
	}
	return *returnValue;
	}
	/*	
	*/
	





