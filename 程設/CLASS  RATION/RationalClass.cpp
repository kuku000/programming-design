#include "RationalClass.h"
#include <iostream>
#include <cstdlib>
using namespace std;

RationalClass::RationalClass(int num, int den)
{
	R.numerator=num;
	R.denominator=den;
	inspection(*this);
}

ostream &operator<<( ostream &output, const RationalClass &rat)
{
	if(rat.R.denominator==1)
		output<<rat.R.numerator;
	else
		output<<rat.R.numerator<<"/"<<rat.R.denominator;
	return output;
}

istream &operator>>( istream &input, RationalClass &rat)
{
	input>>rat.R.numerator;
	input.ignore();
	input>>rat.R.denominator;
	rat.inspection(rat);
	return input;
}

RationalClass RationalClass::operator+(const RationalClass &rat)
{
	RationalClass total;
	total.R.numerator=R.numerator * rat.R.denominator + rat.R.numerator * R.denominator;
	total.R.denominator=R.denominator * rat.R.denominator;
	reduction(total.R);
	return total;
}

RationalClass &RationalClass::operator+=(const RationalClass &rat)
{
	R.numerator=R.numerator * rat.R.denominator + rat.R.numerator * R.denominator;
	R.denominator=R.denominator * rat.R.denominator;
	reduction(R);
	return *this;
}

RationalClass RationalClass::operator-(const RationalClass &rat)
{
	RationalClass total;
	total.R.numerator=R.numerator * rat.R.denominator - rat.R.numerator * R.denominator;
	total.R.denominator=R.denominator * rat.R.denominator;
	reduction(total.R);
	return total;
}

RationalClass &RationalClass::operator-=(const RationalClass &rat)
{
	R.numerator=R.numerator * rat.R.denominator - rat.R.numerator * R.denominator;
	R.denominator=R.denominator * rat.R.denominator;
	reduction(R);
	return *this;
}

RationalClass RationalClass::operator*(const RationalClass &rat)
{
	RationalClass total;
	total.R.numerator=R.numerator * rat.R.numerator;
	total.R.denominator=R.denominator * rat.R.denominator;
	reduction(total.R);
	return total;
}

RationalClass &RationalClass::operator*=(const RationalClass &rat)
{
	R.numerator*=rat.R.numerator;
	R.denominator*=rat.R.denominator;
	reduction(R);
	return *this;
}

RationalClass RationalClass::operator/(const RationalClass &rat)
{
	RationalClass total;
	total.R.numerator=R.numerator * rat.R.denominator;
	total.R.denominator=R.denominator * rat.R.numerator;
	reduction(total.R);
	if(total.R.denominator<0)
	{
		total.R.numerator-=(total.R.numerator*2);
		total.R.denominator-=(total.R.denominator*2);
	}
	return total;
}

RationalClass &RationalClass::operator/=(const RationalClass &rat)
{
	R.numerator*=rat.R.denominator;
	R.denominator*=rat.R.numerator;
	reduction(R);
	if(R.denominator<0)
	{
		R.numerator-=(R.numerator*2);
		R.denominator-=(R.denominator*2);
	}
	return *this;
}

bool RationalClass::operator==(const RationalClass &rat) const
{
	if(R.numerator!=rat.R.numerator)
		return false;
	else if(R.denominator!=rat.R.denominator)
		return false;
	else
		return true;
}

bool RationalClass::operator!=(const RationalClass &rat) const
{
	return !(*this==rat);
}

bool RationalClass::operator>=(const RationalClass &rat) const
{
	int common=R.denominator*rat.R.denominator/gcd(R.denominator, rat.R.denominator);
	int Original_numerator=R.numerator*common/R.denominator;
	int Rat_numerator=rat.R.numerator*common/rat.R.denominator;
	if(Original_numerator<Rat_numerator)
		return false;
	else
		return true;
}

bool RationalClass::operator<(const RationalClass &rat) const
{
	return !(*this>=rat);
}

bool RationalClass::operator<=(const RationalClass &rat) const
{
	int common=R.denominator*rat.R.denominator/gcd(R.denominator, rat.R.denominator);
	int Original_numerator=R.numerator*common/R.denominator;
	int Rat_numerator=rat.R.numerator*common/rat.R.denominator;
	if(Original_numerator>Rat_numerator)
		return false;
	else
		return true;
}

bool RationalClass::operator>(const RationalClass &rat) const
{
	return !(*this<=rat);
}

void RationalClass::inspection(RationalClass &rat)
{
	if(rat.R.denominator==0)
		rat.R.denominator=1;
	reduction(rat.R);
	if(rat.R.denominator<0)
	{
		rat.R.numerator-=(rat.R.numerator*2);
		rat.R.denominator-=(rat.R.denominator*2);
	}
}

void RationalClass::reduction(Rational &rat)
{
	int reduct=abs(gcd(rat.numerator, rat.denominator));
	rat.numerator/=reduct;
	rat.denominator/=reduct;
}

int RationalClass::gcd(int a, int b) const
{
	if(b==0)
		return a;
	else
		return gcd(b, a%b);
}
