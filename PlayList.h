#ifndef PLAYLIST_H_
#define PLAYLIST_H_

#include <iostream>
#include "Node.h"
#include "LinkedSet.h"
#include "Song.h"

class PlayList: public LinkedSet<Song> 
{
	
	private: 
		
		// the pointer to the last node
		Node<Song>* tail_ptr_;
		
		/**
		Obtains the pointer to last node in the playlist.
		@return: a pointer to the last node
		*/
		Node<Song>* getPointerToLastNode() const;
		
		/**
		Obtains the pointer that points to a song in the playlist.
		@post: previous_ptr is null if target is not in PlayList or if target
		       is the first node, otherwise it points to the node preceding target.
		@return: either a pointer to the node containing target
		         or the null pointer if that target is not in the playlist.
		*/
		Node<Song>* getPointerTo(const Song& target, Node<Song>*& previous_ptr) const;
		
	public:
		
		// default constructor
		PlayList();
		
		// parameterized constructor
		PlayList(const Song& a_song);
		
		// (deep) copy constructor
		PlayList(const PlayList& a_play_list); 
		
		/**
		Adds a new addition to the playlist.
		@parameters: new_song to add
		@post: item_count_++
		*/
		bool add(const Song& new_song) override;
		
		/**
		Removes a song from the playlist.
		@parameters: a_song to remove
		@post: item_count_--, order is preserved
		*/
		bool remove(const Song& a_song) override;
		
		/**
		Loops the playlist.
		@post: the pointer to the last node will have a pointer to the first 
		node instead of nullptr.
		*/
		void loop();
		
		/**
		Unloops the playlist.
		@post: the pointer to the last node will have a pointer to the 
		nullptr instead of the first node.
		*/
		void unloop();
		
		/**
		Displays the entire playlist.
		@return: Prints a list of songs that are currently in the playlist. 
		If empty, then print nothing.
		*/
		void displayPlayList();
		
		// destructor
		~PlayList();

}; // end PlayList

#endif // PLAYLIST_H_
