#include <iostream>
#include <string>
#include "Song.h"

// Default Constructor

Song::Song() {}  // end default constructor

// Parameterized Constructor

Song::Song(const std::string& title, const std::string& author, const std::string& album) 
{  
		
	title_ = title;
	author_ = author;
	album_ = album;
			
} // end parameterized constructor
			
/** 
Sets the title of the song.
@post title_ is now title. 
*/
void Song::setTitle(std::string title) 
{

	title_ = title;
	
} // end setTitle

/** 
Sets the author of the song.		
@post author_ is now author. 
*/			
void Song::setAuthor(std::string author) 
{
	
	author_ = author;

} // end setAuthor
	
/** 
Sets the album the song belongs to.		
@post album_ is now album. 
*/
void Song::setAlbum(std::string album) 
{

	album_ = album;
	
} // end setAlbum
		
/** 
Retrieves the title of the song.		
@return title_ 
*/
std::string Song::getTitle() const 
{

	return title_;
	
} // end getTitle
		
/** 
Retrieves the author of the song.	
@return author_ 
*/
std::string Song::getAuthor() const 
{

	return author_;
	
} // end getAuthor
		
/** 
Retrieves the album the song belongs to.		
@return album_ 
*/
std::string Song::getAlbum() const 
{

	return album_;
	
} // end getAlbum
		
/**
Overloaded operator that compares two songs.		
@param Two songs: lhs, rhs		
@return True if the two songs are the same, False if they aren't. 
*/
bool operator==(const Song& lhs, const Song& rhs) 
{
	
	if ((lhs.getTitle() == rhs.getTitle()) && (lhs.getAuthor() == rhs.getAuthor()) 
	&& (lhs.getAlbum() == rhs.getAlbum())) 
	{
		
		return true;
	
	}
	
	return false;
	
} // end overloaded == operator




