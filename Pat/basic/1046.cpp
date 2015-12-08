#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	int say1, num1;
	int say2, num2;
	int win1 = 0;
	int win2 = 0;
	for (int i = 0; i < n; ++i) {
		cin >> say1 >> num1 >> say2 >> num2;
		if (num1 == say1 + say2 && num2 != say1 + say2) {
			win1++;
		} else if (num1 != say1 + say2 && num2 == say1 + say2) {
			win2++;
		} else {
			continue;
		}
	}
	cout << win2 << " " << win1 << endl;
	return 0;
}
