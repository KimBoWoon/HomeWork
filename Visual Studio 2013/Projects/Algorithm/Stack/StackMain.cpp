#include "Stack.h"

int main() {
	Stack stack;

	try {
		stack.push(1);
		stack.push(2);
		stack.push(3);
		stack.push(4);
		stack.push(5);
		//stack.push(6);

		for (int i = 0; i < stack.capacity(); i++) {
			cout << stack.top() << endl;
			stack.pop();
		}
	}
	catch (const char* s) {
		cout << s << endl;
	}
}