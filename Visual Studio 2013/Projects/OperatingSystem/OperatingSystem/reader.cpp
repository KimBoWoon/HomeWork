#include <iostream>
#include <process.h>
#include <fstream>
#include <windows.h>
#include <ctime>
using namespace std;

int readAW();
int readWW();
int readAR();
int readWR();
void reader(int second);

int AW = readAW();
int WW = readWW();
int AR = readAR();
int WR = readWR();

class Node {
private:
	Node* nextNode;
public:
	Node() : nextNode(NULL)	{}
};

class ConditionVariable {
private:
	Node* n;
public:
	ConditionVariable() : n(NULL)	{}
};

class Semaphore {
private:
	/*struct semid_ds *buf;*/
	ConditionVariable c;
public:
	void P();
	void V();
};
void Semaphore::P() {
	
}
void Semaphore::V() {

}

int main(int argc, char* argv[]) {
	//int second = atoi(argv[1]) * 1000;
	int second = 3000;
	Sleep(second);
	cout << "signal" << endl;
	//reader(atoi(argv[2]) * 1000);
	reader(3000);
}

int readAW() {
	ifstream in;
	int AW;
	int pid = _getpid();
	time_t time = 0;
	
	in.open("aw.txt");
	while (true) {
		if (in.eof())
			break;
		in >> AW >> pid >> time;
	}
	in.close();
	return AW;
}
int readWW() {
	ifstream in;
	int WW;
	int pid = _getpid();
	time_t time = 0;

	in.open("ww.txt");
	while (true) {
		if (in.eof())
			break;
		in >> WW >> pid >> time;
	}
	in.close();
	return WW;
}
int readAR() {
	ifstream in;
	int AR;
	int pid = _getpid();
	time_t time = 0;

	in.open("ar.txt");
	while (true) {
		if (in.eof())
			break;
		in >> AR >> pid >> time;
	}
	in.close();
	return AR;
}
int readWR() {
	ifstream in;
	int WR;
	int pid = _getpid();
	time_t time = 0;

	in.open("wr.txt");
	while (true) {
		if (in.eof())
			break;
		in >> WR >> pid >> time;
	}
	in.close();
	return WR;
}
void reader(int second) {
	ofstream arout, wrout;
	char str[50];

	wrout.open("wr.txt", ios_base::app);
	arout.open("ar.txt", ios_base::app);

	//look.acquire(); P()
	while (AW + WW > 0) {
		_strtime_s(str);
		wrout << ++WR << " " << _getpid() << " " << str << endl;
		//okToRead.wait();
		_strtime_s(str);
		wrout << --WR << " " << _getpid() << " " << str << endl;
	}
	_strtime_s(str);
	arout << ++AR << " " << _getpid() << " " << str << endl;
	//look.release(); V();

	//look.acquire(); P();
	_strtime_s(str);
	arout << --AR << " " << _getpid() << " " << str << endl;
	if (AR == 0 && WW > 0)
		;//okToWrite.signal();
	//look.release(); V();

	wrout.close();
	arout.close();
}