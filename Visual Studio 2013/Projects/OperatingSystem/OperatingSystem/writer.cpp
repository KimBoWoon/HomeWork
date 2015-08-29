//#include <iostream>
//#include <process.h>
//#include <fstream>
//#include <windows.h>
//#include <ctime>
//using namespace std;
//
//int readAW();
//int readWW();
//int readAR();
//int readWR();
//void writer(int second);
//
//int AW = readAW();
//int WW = readWW();
//int AR = readAR();
//int WR = readWR();
//
//int main(int argc, char* argv[]) {
//	//int second = atoi(argv[1]) * 1000;
//	int second = 3000;
//	Sleep(second);
//	cout << "signal" << endl;
//	//reader(atoi(argv[2]) * 1000);
//	writer(3000);
//}
//
//int readAW() {
//	ifstream in;
//	int AW;
//	in.open("aw.txt");
//	while (true) {
//		if (in.eof())
//			break;
//		in >> AW;
//	}
//	in.close();
//	return AW;
//}
//int readWW() {
//	ifstream in;
//	int WW;
//	in.open("ww.txt");
//	while (true) {
//		if (in.eof())
//			break;
//		in >> WW;
//	}
//	in.close();
//	return WW;
//}
//int readAR() {
//	ifstream in;
//	int AR;
//	in.open("ar.txt");
//	while (true) {
//		if (in.eof())
//			break;
//		in >> AR;
//	}
//	in.close();
//	return AR;
//}
//int readWR() {
//	ifstream in;
//	int WR;
//	in.open("wr.txt");
//	while (true) {
//		if (in.eof())
//			break;
//		in >> WR;
//	}
//	in.close();
//	return WR;
//}
//void writer(int second) {
//	ofstream wwout, awout;
//	char str[50];
//
//	wwout.open("ww.txt", ios_base::app);
//	awout.open("aw.txt", ios_base::app);
//	//acquire();
//
//	while (AW + AR > 0) {
//		_strtime_s(str);
//		wwout << ++WW << " " << _getpid() << " " << str << endl;
//		//okToWrite.wait();
//		_strtime_s(str);
//		wwout << --WW << " " << _getpid() << " " << str << endl;
//	}
//	_strtime_s(str);
//	wwout << AW++ << " " << _getpid() << " " << str << endl;
//
//	//release();
//
//	//acquire();
//	_strtime_s(str);
//	wwout << --AW << " " << _getpid() << " " << str << endl;
//	if (WW > 0)
//		;//okToWrite.signal();
//	else if (WR > 0)
//		;//okToRead.broadcast();
//	//release();
//}