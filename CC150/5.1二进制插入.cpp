#include <iostream>
#include <string>
#include <vector>
using namespace std;

int binInsert(int n, int m, int j, int i) {
	return (m << j) ^ n;
}

int main()
{
	cout << binInsert(1024, 19, 2, 6) << endl;
	return 0;
}
