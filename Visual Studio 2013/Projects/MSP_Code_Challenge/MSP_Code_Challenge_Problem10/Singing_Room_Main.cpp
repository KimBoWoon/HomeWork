#include "Singing_Room.h"

void main()
{
	ifstream input;
	int num;
	vector<Song> v;

	input.open("노래방.txt");
	if (input.fail())
	{
		cerr << "파일 없음" << endl;
		exit(1);
	}
	while (!(input.eof()))
	{
		Song s;
		s.SetSong(input);
		v.push_back(s);
	}

	cout << "번호 가수 - 제목" << endl;
	cout << "------------------------------" << endl;
	for (int i = 0; i<v.size(); i++)
		v[i].Print();

	while (true)
	{
		try
		{
			cout << endl << "노래 번호를 입력해주세요" << endl;
			cout << "0을 입력하면 프로그램이 종료됩니다. : ";
			cin >> num;
			cout << endl;
			if (num > v.size())
				throw "입력범위가 초과했습니다.";
			if (num == 0)
				return;
			v[num - 1].PrintLyrics();
		}
		catch (const char *s)
		{
			cout << s << endl;
		}
	}

	input.close();
}