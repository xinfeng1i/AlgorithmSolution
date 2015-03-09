#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <cstdio>
#include <cstdlib>
using namespace std;

// RomSymbol = {I, V, X,  L,  C,   D,   M}
// RomValue  = {1, 5, 10, 50, 100, 500, 1000}
string intToRoman(int num)
{
	const int SYMBOL_NUM = 7;
	const char symbols[SYMBOL_NUM] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
	vector<int> nSymbol(SYMBOL_NUM, 0);

	string ans;
	nSymbol[6] = num / 1000;	
	num %= 1000;
	ans += string(nSymbol[6], symbols[6]);

	if (num >= 900)
	{
			ans += "CM"; 
			num %= 100;
	}
	else if (num >= 400 & num < 500)
	{
		ans += "CD";
		num %= 100;
	}
	else
	{
		nSymbol[5] = num / 500;		
		num %= 500;
		ans += string(nSymbol[5], symbols[5]);
	}

	nSymbol[4] = num / 100;		num %= 100;
	ans += string(nSymbol[4], symbols[4]);

	if (num >= 90)
	{
		ans += "XC";
		num %= 10;
	}
	else if(num >= 40 && num < 50)
	{
		ans += "XL";
		num %= 10;
	}
	else
	{
		nSymbol[3] = num / 50;
		num %= 50;
		ans += string(nSymbol[3], symbols[3]);
	}

	nSymbol[2] = num / 10;		
	num %= 10;
	ans += string(nSymbol[2], symbols[2]);

	if (num == 9) 
	{
		ans += "IX";
	}
	else if (num == 4)
	{
		ans += "IV";
	}
	else
	{
		nSymbol[1] = num / 5;		
		num %= 5;
		ans += string(nSymbol[1], symbols[1]);

		nSymbol[0] = num;
		ans += string(nSymbol[0], symbols[0]);
	}

	return ans;
}

int main()
{
	int n;
	cin >> n;
	cout << intToRoman(n) << endl;
	return 0;
}