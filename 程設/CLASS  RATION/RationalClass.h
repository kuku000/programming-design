#ifndef RATIONALCLASS_H
#define RATIONALCLASS_H
#include <iostream>
using namespace std;

struct Rational
{
	int numerator, denominator;	
};

class RationalClass
{
		friend ostream &operator<<( ostream &, const RationalClass & );
		friend istream &operator>>( istream &, RationalClass & );
	public:
		RationalClass(int=1, int=1);
		RationalClass operator+(const RationalClass&);
		RationalClass &operator+=(const RationalClass&);
		RationalClass operator-(const RationalClass&);
		RationalClass &operator-=(const RationalClass&);
		RationalClass operator*(const RationalClass&);
		RationalClass &operator*=(const RationalClass&);
		RationalClass operator/(const RationalClass&);
		RationalClass &operator/=(const RationalClass&);
		
		bool operator==(const RationalClass&) const;
		bool operator!=(const RationalClass&) const;
		bool operator>=(const RationalClass&) const;
		bool operator<(const RationalClass&) const;
		bool operator<=(const RationalClass&) const;
		bool operator>(const RationalClass&) const;
		
		int gcd(int, int) const;
		void reduction(Rational&);
		void inspection(RationalClass&);
	private:
		Rational R;
};

#endif
