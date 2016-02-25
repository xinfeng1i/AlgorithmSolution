#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
using namespace std;

#if 0
long long GCD(long long a, long long b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}

struct RationalNum {
	long long numerator;
	long long denominator;

	bool sign;
	long long intPart;
	long long simpleNumerator;
	long long simpleDenominator;
	
	RationalNum(long long a, long long b) : numerator(a), denominator(b) {}
	RationalNum operator+(const RationalNum& other) const;
	RationalNum operator-(const RationalNum& other) const;
	RationalNum operator*(const RationalNum& other) const;
	RationalNum operator/(const RationalNum& other) const;
	void Simplity();
	void PrintNumber();

};

RationalNum RationalNum::operator+(const RationalNum& other) const {
	RationalNum temp(0, 1);
	if (denominator == other.denominator) {
		temp.denominator = denominator;
		temp.numerator = numerator + other.numerator;
	} else {
		temp.denominator = denominator * other.denominator;
		temp.numerator = numerator * other.denominator + denominator * other.numerator;
	}
	return temp;
}

RationalNum RationalNum::operator-(const RationalNum& other) const {
	RationalNum temp(0, 1);
	if (denominator == other.denominator) {
		temp.denominator = denominator;
		temp.numerator = numerator - other.numerator;
	} else {
		temp.denominator = denominator * other.denominator;
		temp.numerator = numerator * other.denominator - denominator * other.numerator;
	}
	return temp;
}

RationalNum RationalNum::operator*(const RationalNum& other) const {
	RationalNum temp(0, 1);
	temp.denominator = denominator * other.denominator;
	temp.numerator = numerator * other.numerator;
	return temp;
}

RationalNum RationalNum::operator/(const RationalNum& other) const {
	RationalNum temp(other);
	if (temp.numerator < 0) {
		temp.numerator *= -1;
		temp.denominator *= -1;
	}

	RationalNum ans(0, 1);
	ans.denominator = denominator * temp.numerator;
	ans.numerator = numerator * temp.denominator;
	return ans;
}

void RationalNum::Simplity(){
	sign = true;
	intPart = 0;
	simpleNumerator = numerator;
	simpleDenominator = denominator;
	// bypass the sign
	if (simpleNumerator < 0) {
		sign = false;
		simpleNumerator *= -1;
	}
	// simplified fraction
	long long k = GCD(simpleNumerator, simpleDenominator);
	simpleNumerator /= k;
	simpleDenominator /= k;
	// int part
	intPart = simpleNumerator / simpleDenominator;
	simpleNumerator %= simpleDenominator;
	if (sign == false) {
		if (intPart != 0) {
			intPart *= -1;
			sign = true;
		} else {
			simpleNumerator *= -1;
			sign = true;
		}
	}
}

void RationalNum::PrintNumber() {
	if (denominator == 0) {
		printf("Inf");
		return;
	}

	Simplity();
	if (intPart == 0) {
		if (simpleNumerator == 0) printf("0");
		else if (simpleNumerator > 0) printf("%lld/%lld", simpleNumerator, simpleDenominator);
		else if (simpleNumerator < 0) printf("(%lld/%lld)", simpleNumerator, simpleDenominator);
	} else if (intPart > 0) {
		if (simpleNumerator == 0) printf("%lld", intPart);
		else printf("%lld %lld/%lld", intPart, simpleNumerator, simpleDenominator);
	} else if (intPart < 0) {
		if (simpleNumerator == 0) printf("(%lld)", intPart);
		else printf("(%lld %lld/%lld)", intPart, simpleNumerator, simpleDenominator);
	}
}


int main()
{
	long long a1, b1;
	long long a2, b2;
	scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
	RationalNum x(a1, b1);
	RationalNum y(a2, b2);
	RationalNum ans1 = x + y;
	RationalNum ans2 = x - y;
	RationalNum ans3 = x * y;
	RationalNum ans4 = x / y;

	x.PrintNumber();
	printf(" + ");
	y.PrintNumber();
	printf(" = ");
	ans1.PrintNumber();
	printf("\n");

	x.PrintNumber();
	printf(" - ");
	y.PrintNumber();
	printf(" = ");
	ans2.PrintNumber();
	printf("\n");

	x.PrintNumber();
	printf(" * ");
	y.PrintNumber();
	printf(" = ");
	ans3.PrintNumber();
	printf("\n");

	x.PrintNumber();
	printf(" / ");
	y.PrintNumber();
	printf(" = ");
	ans4.PrintNumber();
	printf("\n");

	return 0;
}
#endif //0