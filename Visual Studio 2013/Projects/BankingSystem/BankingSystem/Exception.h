#ifndef __EXCEPTION__
#define __EXCEPTION__

#include "Define.h"

class Exception
{
private:
	String s;
public:
	Exception(String s) : s(s)	{}
	void ShowExceptionInfo()
	{
		cout << s << endl;
	}
	//void MeunNumberException();
};

#endif