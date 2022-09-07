#include "ZFraction.h"

// parameter-less constructor
ZFraction::ZFraction()
{
	this->Num = 0;
	this->Denom = 1;

}

// num only constructor
ZFraction::ZFraction(int num) 
{
	this->Num = num;
	this->Denom = 1;

}

// num-denom constructor  
ZFraction::ZFraction(int num = 0, int denom = 1)
{
	// check denom is not null throw error otherwise
	if (denom == 0)
	{
		cerr<<"denom cannot be null"<<endl;
	}
	else
	{
		// simplifiy fraction
		if (num % denom == 0)
		{
			int factor = num / denom;
			denom /= factor;
		}

		this->Num = num;
		this->Denom = denom;
	}

}
// getters 
int ZFraction::getNum(void) 
{
	return this->Num;
}
int ZFraction::getDenom(void)
{
	return this->Denom;
}

// stream overload
ostream& operator <<(ostream& out,  ZFraction Fraction)
{
	out << Fraction.getNum() << "/" << Fraction.getDenom();
	return out;
}

int gcd(int n1, int n2)
{
	int gcd = 1;
	for (int i = 1; i <= n1 && i <= n2; ++i)
	{
		// Checks if i is factor of both integers
		if (n1 % i == 0 && n2 % i == 0)
			gcd = i;
	}
	return gcd;
}

void ZFraction::simplify(void)
{
	// simplifiy fraction using gcd
	int div = gcd(abs(this->Num), abs(this->Denom));

	this->Num /= div;
	this->Denom /= div;
}
//Fraction Fraction::operator+ (const Fraction& f) const
ZFraction  ZFraction::operator+(ZFraction& F2)
{
	int a = this->Num;
	int b = this->Denom;

	int c = F2.getNum();
	int d = F2.getDenom();

	int num = a * d + c * b;
	int denom = b * d;

	ZFraction z = ZFraction(num, denom);
	// simplifiy fraction using gcd
	z.simplify();
	return z;
}

//Fraction substraction
ZFraction  ZFraction::operator-(ZFraction& F2)
{
	int a = this->Num;
	int b = this->Denom;

	int c = F2.getNum();
	int d = F2.getDenom();

	int num = a * d - c * b;
	int denom = b * d;

	ZFraction z = ZFraction(num, denom);
	// simplifiy fraction using gcd
	z.simplify();
	return z;
}

//Fraction product
ZFraction  ZFraction::operator*(ZFraction& F2)
{
	int a = this->Num;
	int b = this->Denom;

	int c = F2.getNum();
	int d = F2.getDenom();

	ZFraction z = ZFraction(a*c, b*d);
	// simplifiy fraction using gcd
	z.simplify();
	return z;
}

// equality 
bool ZFraction::operator==(ZFraction& b) 
{
	bool equal = false;
	ZFraction diff = *this - b;
	
	if (diff.getNum() == 0)
	{
		equal = true;
	}
	return equal;
}

// inequality 
bool ZFraction::operator!=(ZFraction& b)
{
	bool inequal = false;
	ZFraction diff = *this - b;

	if (diff.getNum() != 0)
	{
		inequal = true;
	}
	return inequal;
}

// greater
bool ZFraction::operator>(ZFraction& b)
{
	bool predicate = false;
	ZFraction diff = *this - b;

	if (diff.getNum() > 0)
	{
		predicate = true;
	}
	return predicate;
}

// smaller
bool ZFraction::operator<(ZFraction& b)
{
	bool predicate = false;
	ZFraction diff = *this - b;

	if (diff.getNum() < 0)
	{
		predicate = true;
	}
	return predicate;
}
