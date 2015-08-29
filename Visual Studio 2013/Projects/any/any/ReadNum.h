#ifndef __READ__NUM
#define __READ__NUM

const int MAX = 20;

class Read{
	unsigned int number;
	static char digits[10][MAX];
	static char teens[20][MAX];
	static char ties[10][MAX];
	static char units[4][MAX];
public:
	Read(unsigned int n);
	void read() const;
};

#endif