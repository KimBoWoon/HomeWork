#include "Between_Classes.h"

BetweenClasses::BetweenClasses()
{
	week[0] = "월요일";
	week[1] = "화요일";
	week[2] = "수요일";
	week[3] = "목요일";
	week[4] = "금요일";
	input.open("mytime.txt");
	InitTimetable(v1, input);
	input.open("friendtime.txt");
	InitTimetable(v2, input);
}
void BetweenClasses::InitTimetable(char v[6][5], ifstream &input)
{
	if (input.fail())
	{
		cerr << "파일을 찾을 수 없습니다!" << endl;
		exit(1);
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 5; j++)
			input >> v[i][j];
	}
	input.close();
}
void BetweenClasses::Overlab() const
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (v1[j][i] == '-' && v2[j][i] == '-')
				cout << week[i] << j + 1 << "교시" << endl;
		}
	}
}
void BetweenClasses::Print(char v[6][5]) const
{
	cout << "	" << "MON" << "	" << "TUE" << "	" << "WED" << "	" << "THU" << "	" << "FRI" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << i + 1 << "	";
		for (int j = 0; j < 5; j++)
			cout << v[i][j] << "	";
		cout << endl;
	}
	cout << endl;
}
ostream& operator<< (ostream &os, BetweenClasses &bc)
{
	bc.Print(bc.v1);
	bc.Print(bc.v2);
	return os;
}