#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Item
{
	int x, y;
};
class Bracelet
{
private:
	vector<Item> item;
	int size;
	char start, end;
public:
	Bracelet();
	void SetBracelet(Item item);
	void checkBracelet();
	void Print() const;
};

Bracelet::Bracelet()
{
	cout << "사이즈를 입력하세요 : ";
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		Item item;
		cout << "팔찌 입력" << endl;
		cin >> start >> end;
		item.x = start;
		item.y = end;
		SetBracelet(item);
	}
}
void Bracelet::SetBracelet(Item item)
{
	this->item.push_back(item);
}
void Bracelet::checkBracelet()
{
	for (int i = 0; i < item.size() - 1; i++)
	{
		if ((item[i].y != item[i + 1].x) || (item[item.size() - 1].y != item[0].x))
		{
			cout << "FAIL" << endl;
			return;
		}
	}
	Print();
}
void Bracelet::Print() const
{
	for (int i = 0; i < item.size(); i++)
	{
		if (item.size() - 1 == i)
			cout << "(" << (char)item[i].x << ", " << (char)item[i].y << ")";
		else
			cout << "(" << (char)item[i].x << ", " << (char)item[i].y << ")" << " - ";
	}
	cout << endl;
}

int main()
{
	while (true)
	{
		Bracelet b;
		string command;

		b.checkBracelet();

		cout << "One More? (y/n) : ";
		cin >> command;
		if (command.compare("n") == 0 || command.compare("N") == 0)
			break;
	}
}