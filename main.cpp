#include <iostream>
#include "Node.h"
#include "PlayList.h"
#include "Song.h"
#include "LinkedSet.h"

using namespace std;

void promptAction(int& state);

int main() {
 
	int runningState = -1; // 1 = add, 2 = remove, 3 = loop, 4 = unloop, 5 = display
								 // 0 = quit, (-1 = start)
	
	string title = "";
	string author = "";
	string album = "";
	PlayList playlist;
	
	while (runningState != 0)
	{
		
		if (runningState != 0)
		{
			promptAction (runningState);
			cout << endl;
			switch (runningState) 
			{
				case 0 :			// quit
				{
					cout << "Goodbye!" << endl;
					break;
				}
				case 1 :			// add
				{
				   cout << "Enter the title of your song to add: ";
				   cin >> title;
				   cout << "Enter the author of your song to add: ";
				   cin >> author;
				   cout << "Enter the album of your song to add: ";
				   cin >> album;
				   Song new_song (title, author, album);
				   if (playlist.add (new_song) == 1) cout << "Song added." << endl;
				   else cout << "Song already exists in playlist." << endl;
				   title = "";
				   author = "";
				   album = "";
				   break;
			   }
			   case 2 :			// remove
			   {
			   	cout << "Enter the title of your song to remove: ";
				   cin >> title;
				   cout << "Enter the author of your song to remove: ";
				   cin >> author;
				   cout << "Enter the album of your song to remove: ";
				   cin >> album;
				   Song new_song (title, author, album);
				   if (playlist.remove (new_song) == 1) cout << "Song removed." << endl;
				   else cout << "Song doesn't exist in playlist." << endl;
				   title = "";
				   author = "";
				   album = "";
				   break;
				}
				case 3 :			// loop
				{
					playlist.loop();	   
					break;
				}
				case 4 :			// unloop
				{
					playlist.unloop();
					break;
				}
				case 5 :			// display
				{
					cout << "Your Playlist" << endl << endl;
					playlist.displayPlayList();
					break;
				}
			}
		}
	}	
    
    return 0;
}

// Menu prompt
void promptAction (int& state)
{
	cout << endl << "-----------------------------------------------------" << endl;
	cout << "Choose an action (0-5): " << endl;
	cout << "0. quit" << endl;
	cout << "1. add" << endl;
	cout << "2. remove" << endl;
	cout << "3. loop" << endl;
	cout << "4. unloop" << endl;
	cout << "5. display" << endl;
	cin >> state;
	
	cout << endl << "-----------------------------------------------------" << endl;
	// input validation
	while ((state < 0) || (state > 5))
	{
		cout << endl << "You have selected an invalid action." << endl;
		promptAction (state);
	}
}
			
	
