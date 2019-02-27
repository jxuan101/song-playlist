#ifndef SONG_H_
#define SONG_H_

#include <iostream>
#include <string>

class Song 
{
	
	public:
	
		Song();  // default constructor

		Song(const std::string& title, const std::string& author = "", 
		const std::string& album = "");  // parameterized constructor
		
		/** 
		Sets the title of the song.
		@post title_ is now title. 
		*/
		void setTitle(std::string title);
		
		/** 
		Sets the author of the song.
		@post author_ is now author. 
		*/		
		void setAuthor(std::string author);
		
		/** 
		Sets the album the song belongs to.
		@post album_ is now album. 
		*/
		void setAlbum(std::string album);
		
		/** 
		Retrieves the title of the song.
		@return title_ 
		*/
		std::string getTitle() const;
		
		/**
		 Retrieves the author of the song.
		@return author_ 
		*/
		std::string getAuthor() const;
		
		/** 
		Retrieves the album the song belongs to.
		@return album_ 
		*/
		std::string getAlbum() const;
		
		/** 
		Overloaded operator that compares two songs.
		@param Two songs: lhs, rhs
		@return True if the two songs are the same, False if they aren't. 
		*/
		friend bool operator==(const Song& lhs, const Song& rhs);
	
	private:
	
		std::string title_;	// title of the song
		std::string author_;	// author of the song
		std::string album_;	// album the song belongs to

}; // end Song

#endif // SONG_H_
