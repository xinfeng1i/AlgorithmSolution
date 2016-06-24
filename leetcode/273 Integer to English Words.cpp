#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <stdio.h>
#include <stdlib.h>
#include <cassert>
using namespace std;

const string tb[20] = {"Zero", "One", "Two", "Three", "Four", "Five", 
	"Six", "Seven", "Eight", "Nine", "Ten", 
	"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", 
	"Sixteen", "Seventeen", "Eighteen", "Nineteen"};

const string decade[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

string helper(int num) {
	// assert num < 1000
	if (num < 20) {
		return tb[num];
	} else if (num < 100) {
		int a = num / 10;
		int b = num % 10;
		if (b == 0) {
			return decade[a];
		} else {
			return (decade[a] + " " + tb[b]);
		}
	} else {
		int a = num / 100;
		int b = (num % 100) / 10;
		int c = num % 10;
		if (b == 0 && c == 0) {
			return (tb[a] + " Hundred");
		} else {
			return (tb[a] + " Hundred " + helper(num % 100));
		}
	}
}

string numberToWords(int num) {
	if (num < 1000) {
		return helper(num);
	} else if (num < 1000000) {
		int a = num / 1000;
		int b = num % 1000;
		if (b == 0) {
			return helper(a) + " Thousand";
		} else {
			return helper(a) + " Thousand " + helper(b);
		}
	} else if (num < 1000000000) {
		int a = num / 1000000;
		int b = (num % 1000000) / 1000;
		int c = num % 1000;
		if (b == 0 && c == 0) {
			return helper(a) + " Million";
		} else if (b == 0 && c != 0) {
			return helper(a) + " Million " + helper(c);
		} else if (b != 0 && c == 0) {
			return helper(a) + " Million " + helper(b) + " Thousand";
		} else {
			return helper(a) + " Million " + helper(b) + " Thousand " + helper(c);
		}
	} else {
		int a = num / 1000000000;
		int b = (num % 1000000000) / 1000000;
		int c = (num % 1000000) / 1000;
		int d = num % 1000;
		if (b == 0 && c == 0 && d == 0) {
			return helper(a) + " Billion";
		} else if (b != 0 && c == 0 && d == 0) {
			return helper(a) + " Billion " + helper(b) + " Million";
		} else if (b == 0 && c == 0 && d != 0) {
			return helper(a) + " Billion " + helper(d); 
		} else if (b == 0 && c != 0 && d == 0) {
			return helper(a) + " Billion " + helper(c) + " Thousand";
		} else if (b == 0 && c != 0 && d != 0) {
			return helper(a) + " Billion " + helper(c) + " Thousand " + helper(d);
		} else if (b != 0 && c == 0 && d != 0) {
			return helper(a) + " Billion " + helper(b) + " Million " + helper(d);
		} else if (b != 0 && c != 0 && d == 0) {
			return helper(a) + " Billion " + helper(b) + " Million " + helper(c) + " Thousand"; 
		} else {
			return helper(a) + " Billion " + helper(b) + " Million " + helper(c) + " Thousand " + helper(d);
		}
	}
}

int main()
{
	int x;
	cout << "please enter a number (<1000):" << endl;
	while (cin >> x) {
		cout << helper(x) << endl;
	}
	return 0;
}