#pragma once
#include <iostream>
using namespace std;
class ZFraction
{
private :
	int Num;
	int Denom; //cannot be null
public :
	// parameter-less constructor
	ZFraction();
	// num parameter constructor
	ZFraction(int num);
	// num-denom parameter constructor
	ZFraction(int num, int denom);

	// getters
	int getNum(void);
	int getDenom(void);

	void simplify(void);

	// operators + -  * == << > and <
	friend ostream &operator<<(ostream &flux, const ZFraction Fraction);

	ZFraction operator+(ZFraction& b);
	ZFraction operator-(ZFraction& b);
	ZFraction operator*(ZFraction& b);
	bool operator==(ZFraction& b);
	bool operator!=(ZFraction& b);
	bool operator>(ZFraction& b);
	bool operator<(ZFraction& b);

};

int gcd(int n1, int n2);