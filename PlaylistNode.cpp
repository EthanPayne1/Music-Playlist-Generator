#include <string>
#include <iostream>

#include "PlaylistNode.h"


PlaylistNode::PlaylistNode() : PlaylistNode("none", "none", "none",0){}

PlaylistNode::PlaylistNode(std::string uniqueID, std::string songName, std::string artistName, 
   int songLength) : uniqueID(uniqueID), songName(songName), artistName(artistName), 
   songLength(songLength),nextNodePtr(nullptr){}
     
void PlaylistNode::InsertAfter(PlaylistNode* nodeToInsert){
   PlaylistNode* temp = nextNodePtr;
   SetNext(nodeToInsert);
   nodeToInsert->SetNext(temp);
}
void PlaylistNode::SetNext(PlaylistNode* nodeNext){
     this->nextNodePtr = nodeNext;
   }
std::string PlaylistNode::GetID() const{
   return uniqueID;
   }
std::string PlaylistNode::GetSongName() const{
   return songName;
   }
std::string PlaylistNode::GetArtistName() const{
   return artistName;
   }
int PlaylistNode::GetSongLength() const{
   return songLength;
   }
PlaylistNode* PlaylistNode::GetNext() const{
   return nextNodePtr;
   }
void PlaylistNode::PrintPlaylistNode(){
   std::cout << "Unique ID: " << uniqueID << std::endl
         << "Song Name: " << songName << std::endl
         << "Artist Name: " << artistName << std::endl
         << "Song Length (in seconds): " << songLength << std::endl;
   }
   