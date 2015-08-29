#ifndef _HAMMING_
#define _HAMMING_

class BinaryNumber
{
public:
	BinaryNumber();
	BinaryNumber(unsigned int val);

	unsigned int getValue() const;
	void setValue(unsigned int val);

	int getHammingWeight() const;
	int getHammingDistance(const BinaryNumber& bn) const;

private:
	unsigned int value;
	BinaryNumber xor(const BinaryNumber& bn) const;
};
#endif