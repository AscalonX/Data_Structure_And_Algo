#ifndef __SONG_H__
#define __SONG_H__

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include "priority_queue.h"

using namespace std;

class Song {
  public:
    std::string artist,title;
    int count;

    Song() { }
    Song(const Song &s) : artist(s.artist), title(s.title), count(s.count) { }
    Song(std::string artist,std::string title,int count) :  artist(artist), title(title), count(count) { }

    friend std::ostream& operator<<(std::ostream &out,const Song &s) {
      return out << "Artist: " << s.artist << " Title: " << s.title << " count: " << s.count;
    }

};


//  you have to write something below this line 
//  you *MIGHT* have to change the declaration of pq1 and pq2
struct CompareSongByArtistTitleCount {
    bool operator()(const Song& a, const Song& b) const {
      if(a.artist == b.artist){
        if(a.title == b.title){
          return a.count > b.count;
        }
        else{
          return a.title > b.title;
        }
      }else{
        return a.artist > b.artist;
      }
    }
};

/**
 * Comparator for pq2.
 * This will create a max-heap based on 'artist' (alphabetical 'A' first).
 * If artists are equal, it uses 'title' (alphabetical 'A' first) as a tie-breaker.
 */
struct CompareSongByCountArtistTitle {
    bool operator()(const Song& a, const Song& b) const {
      if(a.count == b.count){
        if(a.artist == b.artist){
          return a.title > b.title;
        }
        else{
          return a.artist > b.artist;
        }
      }
      else{
        return a.count < b.count;
      }
    }
};


// Now, declare pq1 and pq2 using these comparators as the second template argument.
CP::priority_queue<Song, CompareSongByArtistTitleCount> pq1;
CP::priority_queue<Song, CompareSongByCountArtistTitle> pq2;

#endif
