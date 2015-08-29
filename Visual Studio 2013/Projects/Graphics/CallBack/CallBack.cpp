#include <iostream>

struct MyMsg{
	int appId;
	char *msgbody;
};

static void myfunc(MyMsg *msg);
static void(*callback)(MyMsg*);

int main(int argc, char *argv[])
{
	MyMsg msg1 = { 100, "This is a Callback Test" };
	callback = myfunc;
	callback(&msg1);
	return 0;
}

void myfunc(MyMsg *msg)
{
	std::cout << "App ID = " << msg->appId << std::endl;
	std::cout << "App Message = " << msg->msgbody << std::endl;
}