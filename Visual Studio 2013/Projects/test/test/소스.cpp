#include <iostream>
using namespace std;

class Rec{
private:
	int row, col, height;
public :
	Rec(){}
	int getheight(){
		return height;
	}
	void sethei(int x)
	{
		height = x;
	}
};

int main(void){
	Rec a;
	int h;
	a.sethei(3);
	h = a.getheight();
	cout << h;
}