#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * 斐波那契数列变种
 *
 * 根据第一个小矩形放置的方式，可以将问题归结为
 * f(n-1)的情况和f(n-2)的情况, 所以有：
 * f(n) = f(n-1) + f(n-2)
 */
int rectCover(int number) {
	if (number <= 0) return 0;
	int f1 = 1;
	int f2 = 2;
	int i = 1;
	while (i < number) {
		int f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
		i++;
	}
	return f1;
}

int main()
{
	cout << rectCover(1) << endl;
	cout << rectCover(2) << endl;
	cout << rectCover(3) << endl;
	cout << rectCover(4) << endl;
	return 0;

}
