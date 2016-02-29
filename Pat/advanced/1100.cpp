#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

#if 0

string lowDigit[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string highDigit[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

int main()
{
	freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	getchar();

	for (int i = 0; i < n; ++i) {
		string line;
		getline(cin, line);
		// number
		if (line[0] >= '0' && line[0] <= '9') {
			int num = atoi(line.c_str());
			if (num < 13) {
				cout << lowDigit[num] << endl;
			} else {
				int gewei = num % 13;
				int shiwei = num / 13;

				// NOTE: lowdigit == 0, then only output high digit
				if (gewei == 0) {
					cout << highDigit[shiwei] << endl;			
				} else {
					cout << highDigit[shiwei] << " " << lowDigit[gewei] << endl;
				}
			}
		} else {
			size_t found = line.find(' ');
			if (found == string::npos) {
				istringstream iss(line);
				string s;
				iss >> s;
				if (s == "tret") {
					cout << 0 << endl;
				} else {
					bool highDigitFound = false;
					for (int num1 = 1; num1 < 13; ++num1) {
						if (highDigit[num1] == s) {
							highDigitFound = true;
							cout << num1 * 13 << endl;
							break;
						}
					}

					if (!highDigitFound) {
						for (int num2 = 0; num2 < 13; ++num2) {
							if (lowDigit[num2] == s) {
								cout << num2 << endl;
								break;
							}
						}
					}
					
				}
			} else {
				istringstream iss(line);
				string s1, s2;
				iss >> s1 >> s2;
				int num1 = 0, num2 = 0;
				for (num1 = 1; num1 < 13; ++num1) {
					if (highDigit[num1] == s1) {
						break;
					}
				}
				for (num2 = 0; num2 < 13; ++num2) {
					if (lowDigit[num2] == s2) {
						break;
					}
				}

				cout << num1 * 13 + num2 << endl;
				
			}
		}
	}
	return 0;
}
#endif //0