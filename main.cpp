#include <iostream>
#include "PlaylistNode.h"

using namespace std;
void outputFullPlaylist(string title, PlaylistNode* head);
PlaylistNode* addSong(PlaylistNode* head); 
PlaylistNode* removeSong(PlaylistNode* head); 
PlaylistNode* changeSongPosition(PlaylistNode* head); 
void outputSongsByArtist(PlaylistNode* head);   
void outputTotalPlaylistTime(PlaylistNode* head); 

// Prints the menu for the user to interact with
void PrintMenu(const string playlistTitle) {
   cout << playlistTitle << " PLAYLIST MENU" << endl;
   cout << "a - Add song\n"
        <<"d - Remove song\n"
        <<"c - Change position of song\n"
        <<"s - Output songs by specific artist\n"
        <<"t - Output total time of playlist (in seconds)\n"
        <<"o - Output full playlist\n"
        <<"q - Quit" << endl << endl;
     
}

// Holds the switch statement for executing the programs methods 
PlaylistNode* ExecuteMenu(char option, string playlistTitle, PlaylistNode* headNode) {
  switch  (option) {
      case 'a':
         // add song
        headNode = addSong(headNode);
         break;
         
      case 'd':
         // remove a song
         headNode = removeSong(headNode);
            break;
      case 'c':
            // change position of song
            headNode = changeSongPosition(headNode);
            break;
      case 's':
            // output the songs by artist
            outputSongsByArtist(headNode);
            break;
      case 't':
            // ouput total time of playlist (in seconds)
            outputTotalPlaylistTime(headNode);
            break;
      case 'o':
            // output the full playlist
            outputFullPlaylist(playlistTitle,headNode);
            break;
      case 'q':
            // quit
            break;
      default:
         // it broke
            break;
  
  }
   
   return headNode; 
}

// Prints the full playlist for the user
void outputFullPlaylist(string title, PlaylistNode* head){ 
    cout << title << " - OUTPUT FULL PLAYLIST" << endl;
   if(head == nullptr){
      cout << "Playlist is empty" << endl << endl;
      return;
      }
      
      PlaylistNode* curr = head;
      for (int count = 1; curr != nullptr; count++, curr=curr->GetNext()){
         cout << count << "." << endl;
        curr->PrintPlaylistNode();
         cout << endl;
         }
   }

int main() {
  string title;
  
  
  cout << "Enter playlist's title:" << endl;
  cout << endl;
  getline(cin,title);
  
  // Do/While loop so the user can select an option in the switch statement 
   PlaylistNode* head = nullptr;
   char option;
   do{
      PrintMenu(title);
      cout << "Choose an option:" << endl;
      cin >> option;
      while (option != 'a' && option != 'd' && option != 'c' && option != 's' && option != 't' && option !='o'
         && option != 'q') {
         cout << "Choose an option:" << endl;
         cin >> option;
         
         }
      cin.ignore();
      if(option != 'q'){
         head = ExecuteMenu(option,title,head);
         }
   }
   while(option!='q');
  
   
   return 0;
}

PlaylistNode* addSong(PlaylistNode* head){
   string id;
   string songName;
   string songArtist;
   int songLength;
   
   cout << "ADD SONG" << endl;
   cout << "Enter song's unique ID:" << endl;
   getline(cin,id);
   cout << "Enter song's name:" << endl;
   getline(cin,songName);
   cout << "Enter artist's name:" << endl;
   getline(cin,songArtist);
   cout << "Enter song's length (in seconds):" << endl << endl;;
   cin >> songLength;
   cin.ignore();
   PlaylistNode* ptrNode = new PlaylistNode(id,songName,songArtist,songLength);
  
   if (head == nullptr) { // list is empty
      head = ptrNode;

      }
   else { // list is not empty
    PlaylistNode* curr = head;
      for (; curr->GetNext() != nullptr; curr = curr->GetNext());
      // curr is at the end of the list
      curr->InsertAfter(ptrNode);
      }
      return head;
   }
   

PlaylistNode* removeSong(PlaylistNode* head){
   string songID;
   PlaylistNode* curr;
   PlaylistNode* prev;
   
   cout << "REMOVE SONG" << endl;
   cout << "Enter song's unique ID:" << endl;
   cin >> songID;
   
   // Find the node to remove
   prev = nullptr;
   curr = head;
   while(curr!=nullptr && curr->GetID() != songID) {
      prev = curr;
      curr = curr->GetNext();
      }
      // When we get here. either we found the node with songID or we are off the list
      if(curr != nullptr) {
         // did not fall of the earth
         string name = curr->GetSongName();
         prev->SetNext(curr->GetNext());
         curr->SetNext(nullptr);
         delete curr;
         cout << "\"" << name << "\"" << " removed." << endl << endl;
         }
         else{
            cout << songID << " not found." << endl << endl;
            }
   
  return head;
}


PlaylistNode* changeSongPosition(PlaylistNode* head){
   /* Valid positions are 1 to n 
    less than 1 place at the front
    greater than n place at end */
   
   int startPos;
   int endPos;
   string name;
   PlaylistNode* nodeToMove = head;
   PlaylistNode* curr;
   PlaylistNode* prev= nullptr;
   PlaylistNode* insertAfterNode = nullptr;
   int count = 0;
   bool found = false;
   
   cout << "CHANGE POSITION OF SONG" << endl;
   cout << "Enter new song's current position:" << endl;
   cin >> startPos;
   cout << "Enter new position for song:" << endl;
   cin >> endPos;
   if (endPos < 1) endPos = 1;
   
   // find node to move, , size of list
   for (count = 0, curr = head; curr != nullptr; curr = curr->GetNext(), count++){
      if(!found){
         if (count + 1 == startPos){
            found = true;
             }
         }
         else {
            prev = curr;
            }
      }
      found = false;
   if (endPos> count) endPos = count;
   // account for the direction 
      endPos = (startPos < endPos) ? endPos : endPos - 1; 
      if (endPos > 0) {
         for (insertAfterNode = head, count = 1; insertAfterNode != nullptr && count < endPos;
              insertAfterNode = insertAfterNode->GetNext(), count++);
         
         }
      // Remove the node that we are moving
      name = nodeToMove->GetSongName();
      if (prev == nullptr) {
         // Node to move is at the front of he list
         head = nodeToMove->GetNext();
         }
         else{
            prev->SetNext(nodeToMove->GetNext());
            
            }
         nodeToMove->SetNext(nullptr);
         
      // nodeToMove still points to the node we want to move, but the node we want to move is free from the list
      
      if (insertAfterNode == nullptr){
         // place node to move in front of head
         nodeToMove->SetNext(head);
         head = nodeToMove;
         }
         else{
            // place node to move after insertAfterNode
            insertAfterNode->InsertAfter(nodeToMove);
            }
   
   cout << "\""<< name << "\" moved to position " << endPos << endl << endl;
   return head;
   } 


void outputSongsByArtist(PlaylistNode* head){
   string artistName;
   
   cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
   cout << "Enter artist's name:" << endl << endl;
   getline(cin, artistName);
   
   PlaylistNode* curr = head;
   for (int count = 1; curr != nullptr; count++, curr = curr->GetNext()){
      if (curr->GetArtistName() == artistName){
         cout << count << "." << endl;
         curr->PrintPlaylistNode();
         cout << endl;
         }
      
      }
   
   }   

void outputTotalPlaylistTime(PlaylistNode* head){ 
   cout << "OUTPUT TOTAL TIME OF PLAYLIST(IN SECONDS)" << endl;
   
   int totalTime = 0;
   
   for(PlaylistNode* curr = head; curr != nullptr; curr = curr->GetNext()){
      totalTime += curr->GetSongLength();
      
      }
   cout << "Total time: " << totalTime << " seconds" << endl << endl;
   
}