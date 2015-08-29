#include "Singing_Room.h"

void Song::SetSong(ifstream& input)
{
	char str[100] = { NULL }, cnt = 0;

	input >> item.song_num >> item.singer >> item.dummy;
	input.getline(item.song_nameandlyrics, 100);
	for (int i = 0; i < strlen(item.song_nameandlyrics); i++)
	{
		if (item.song_nameandlyrics[i] != 9 && cnt == 0)
		{
			str[i] = item.song_nameandlyrics[i];
			continue;
		}
		cnt = 1;
		item.song_name = str;
		item.lyrics += item.song_nameandlyrics[i];
	}
}
void Song::Print() const
{
	cout << item.song_num << " " << item.singer << " " << item.dummy << " " << item.song_name << endl;
}
void Song::PrintLyrics() const
{
	cout << item.lyrics << endl;
}