#ifndef __SINGING_ROOM__
#define __SINGING_ROOM__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

struct Item
{
	int song_num;
	string singer, dummy, song_name, lyrics;
	char song_nameandlyrics[100];
};
class Song
{
private:
	Item item;
public:
	void SetSong(ifstream& input);
	void Print() const;
	void PrintLyrics() const;
};

#endif