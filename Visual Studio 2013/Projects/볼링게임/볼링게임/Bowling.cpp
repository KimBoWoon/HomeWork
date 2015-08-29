/**********************************************************
*              컴퓨터공학부 20113259 김보운               *
*                  실습 시험 - 볼링 게임                  *
**********************************************************/
#include <iostream>
#include <fstream>
#include <memory>
using namespace std;

class Bowling
{
private:
	int value, arr[21], sum;
public:
	Bowling(int v);
	void read(ifstream &in);
	void compute();
};
Bowling::Bowling(int v) : sum(0), value(v)
{
	if (arr != NULL)
		memset(arr, 0, sizeof(int) * value);
}
void Bowling::read(ifstream &in)
{
	for (int i = 0; i < value; i++)
		in >> arr[i];
}
void Bowling::compute()
{
	int i, sum = 0, cnt = 0;

	for (i = 0; i < value;)
	{
		if (arr[i] + arr[i + 1] == 3)
		{
			sum += arr[i] + arr[i + 1] + arr[i + 2];
			i += 2;
			cnt++;
		}
		else if (arr[i] == 3)
		{
			sum += arr[i] + arr[i + 1] + arr[i + 2];
			i++;
			cnt++;
		}
		else if (arr[i] + arr[i + 1] < 3)
		{
			sum += arr[i] + arr[i + 1];
			i += 2;
			cnt++;
		}
		else if (arr[i] + arr[i + 1] > 3)
		{
			cout << "error" << endl;
			break;
		}
		if (cnt == 10)
			i = value;
	}
	if (i == value)
		cout << sum << endl;
}

int main(void)
{
	ifstream in;
	int cases;

	in.open("input.txt");
	if (in.fail())
	{
		cerr << "파일 없음" << endl;
		exit(1);
	}

	in >> cases;

	while (cases--)
	{
		int value;

		in >> value;

		Bowling b(value);

		b.read(in);
		b.compute();
	}
	in.close();
}