//#undef _UNICODE
//#undef UNICODE

#include <iostream>
#include <clocale>
#include <Windows.h>
#include <tchar.h>
#include "tios.h"
using namespace std;

int _tmain(int argc, TCHAR* argv[]) {
	//_wsetlocale(LC_ALL, L"Korean");
	locale::global(locale("Korean"));

	TCHAR str[] = _T("ABCÇÑ±Û");
	INT_PTR size = sizeof(str);
	INT_PTR len = _tcslen(str);
	FLOAT a = 3;

	_tcout << str << endl;
	_tcout << len << endl;
}