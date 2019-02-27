#include <iostream>
#include "PlayList.h"
#include <vector>

// default constructor
PlayList::PlayList() 
{

	tail_ptr_ = nullptr;
	
}  // end default constructor

// parameterized constructor
PlayList::PlayList(const Song& a_song)
{

	head_ptr_ = nullptr;
	
	tail_ptr_ = nullptr;
	
	add(a_song);
	
}  // end parameterized constructor

// copy constructor
PlayList::PlayList(const PlayList& a_play_list): LinkedSet(a_play_list)    // inheriting base class copy constructor
{

	tail_ptr_ = getPointerToLastNode();

}  // end copy constructor

/**
Adds a new addition to the playlist.
@parameters: new_song to add
@post: item_count_++
*/
bool PlayList::add(const Song& new_song)
{

	if (isEmpty())	// adding first node
	{
		
		Node<Song>* firstNodePtr = new Node<Song>;
		
		firstNodePtr->setItem(new_song);
		
		firstNodePtr->setNext(nullptr);
		
		head_ptr_ = firstNodePtr;
		
		tail_ptr_ = firstNodePtr;	
		
		item_count_++;
		
		return true;
		
	}
	
	else if (!contains(new_song))	// adding at the end of chain
	{
	
		Node<Song>* nodeToAddPtr = new Node<Song>;
		
		nodeToAddPtr->setItem(new_song);
		
		nodeToAddPtr->setNext(nullptr);
		
		tail_ptr_->setNext(nodeToAddPtr);
		
		tail_ptr_ = nodeToAddPtr;
		
		item_count_++;
		
		return true;
	
	}
	
	else
	{
	
		return false;
	
	}
	
}  // end add
		
/**
Removes a song from the playlist.
@parameters: a_song to remove
@post: item_count_--, order is preserved
*/
bool PlayList::remove(const Song& a_song)
{
	
	
	Node<Song>* precedingNodePtr = nullptr;
		
	Node<Song>* nodeToDeletePtr = getPointerTo(a_song, precedingNodePtr);
	
	if (!isEmpty() && contains(a_song))
	{

		if ((precedingNodePtr == nullptr) && (nodeToDeletePtr == head_ptr_))   // deleting first node
		{
		
			head_ptr_ = nodeToDeletePtr->getNext();
		
			nodeToDeletePtr->setNext(nullptr);
			
			delete nodeToDeletePtr;
			
			nodeToDeletePtr = nullptr;
			
			item_count_--;
			
			return true;
		
		}
		
		else	// deleting last or middle nodes
		{
		
			precedingNodePtr->setNext(nodeToDeletePtr->getNext());
			
			nodeToDeletePtr->setNext(nullptr);
			
			delete nodeToDeletePtr;
			
			nodeToDeletePtr = nullptr;
			
			item_count_--;
			
			return true;
			
		}
		
	}
	
	else
	{
	
		return false;
	
	}
	
}  // end remove
		
/**
Loops the playlist.
@post: the last node will have a pointer to the first node instead of nullptr.
*/
void PlayList::loop()
{
	if (!isEmpty())
	{ 
		tail_ptr_->setNext(head_ptr_);
		std::cout << "Your playlist is now on loop." << std::endl;
	}
	else std::cout << "Your playlist is empty. Add a song to loop." << std::endl;
	
}  // end loop
		
/**
Unloops the playlist.
@post: the last node will have a pointer to the nullptr instead of the first node.
*/
void PlayList::unloop()
{
	if (!isEmpty())
	{
		tail_ptr_->setNext(nullptr);
		std::cout << "You have ended the loop." << std::endl;
	}
	else std::cout << "Your playlist is not currenty on loop." << std::endl;
	
}  // end unloop
		
/**
Displays the entire playlist.
@return: Prints a list of songs that are currently in the playlist. 
		If empty, then print nothing.
*/
void PlayList::displayPlayList()
{

	std::vector<Song> playlist_contents = toVector();
	
	if (item_count_ == 0) 
	{
		std::cout << "Your playlist is empty. Use add to add a new song." << std::endl;
	}
	else
	{
		for(int i = 0; i < item_count_; i++)
		{
		
			std::cout << i << " * Title: " << playlist_contents[i].getTitle() << " * Author: ";
			std::cout << playlist_contents[i].getAuthor() << " * Album: "; 
			std::cout << playlist_contents[i].getAlbum() << " *" << std::endl;
		
		}
		
		if (tail_ptr_->getNext() == head_ptr_)
		{
			std::cout << std::endl << "Your playlist is on loop." << std::endl;
		}
	}
	
	std::cout << std::endl << "End of playlist" << std::endl;

}  // end displayPlayList
		
// destructor
PlayList::~PlayList()
{
	if (!isEmpty()) unloop();
	clear();

}  // end destructor
		
/**
Obtains the pointer to last node in the playlist.
@return: a pointer to the last node
*/
Node<Song>* PlayList::getPointerToLastNode() const
{

	int counter = 0;
	
	Node<Song>* movingPtr = head_ptr_;
	
	while (counter < item_count_)	// traverse through chain
	{
	
		if (movingPtr->getNext() == nullptr)	// found the last node before nullptr
		{
		
			return movingPtr;
		
		}
		
		else
		{
		
			movingPtr = movingPtr->getNext();
			
			counter++;
		
		}
	
	}
	
	return movingPtr;
	
}  // end getPointerToLastNode

/**
Obtains the pointer that points to a song in the playlist.
@post: previous_ptr is null if target is not in PlayList or if target
       is the first node, otherwise it points to the node preceding target.
@return: either a pointer to the node containing target
         or the null pointer if that target is not in the playlist.
*/
Node<Song>* PlayList::getPointerTo(const Song& target, Node<Song>*& previous_ptr) const
{

	int counter = 0;
	
	Node<Song>* movingPtr = head_ptr_;
	
	if (isEmpty() || !contains(target))	// not in the playlist
	{
	
		previous_ptr = nullptr;
		
		return movingPtr = nullptr;
	
	}
	
	else if (contains(target) && movingPtr->getItem() == target)		// first node
	{
	
		previous_ptr = nullptr;
		
		return movingPtr;
	
	}
	
	else	// middle nodes and last node
	{
	
		previous_ptr = movingPtr;
		
		movingPtr = movingPtr->getNext();
		
		while (counter < item_count_)
		{
		
			if (movingPtr->getItem() == target)
			{
			
				return movingPtr;
			
			}
			
			else
			{
			
				previous_ptr = movingPtr;
				
				movingPtr = movingPtr->getNext();
				
				counter++;
			
			}
		
		}
		
		return movingPtr;	
	
	}
	
}  // end getPointerTo









