#ifndef _PLAYLISTNODE_H
#define _PLAYLISTNODE_H
#include <string>
class PlaylistNode{

   public:
     PlaylistNode();
     PlaylistNode(std::string uniqueID, std::string songName, std::string artistName, int songLength);
     
     void InsertAfter(PlaylistNode* nodeToInsert);
     void SetNext(PlaylistNode* nodeNext);
     std::string GetID() const;
     std::string GetSongName() const;
     std::string GetArtistName() const;
     int GetSongLength() const;
     PlaylistNode* GetNext() const;
     void PrintPlaylistNode();
   
   
   private:
         std::string uniqueID;
         std::string songName;
         std::string artistName;
         int songLength;
         PlaylistNode* nextNodePtr;









};

#endif