#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdio>
#include <cmath>
using namespace std;

const int INF = 30000;

void TugOfWar(vector<int> sofar, vector<int> rest, int totalSum, int totalSize, int& mindiff, vector<int>& s)
{
	// base case
	if (rest.empty())
	{
		// the current generate set satisfy the condition
		if (sofar.size() == totalSize / 2)
		{
			int cursum = accumulate(sofar.begin(), sofar.end(), 0);
			int othersum = totalSum - cursum;
			if (abs(cursum - othersum) < mindiff)
			{
				mindiff = abs(cursum - othersum);
				s.clear();
				s.resize(sofar.size());
				copy(sofar.begin(), sofar.end(), s.begin());
			}
		}
		return;
	}

	// only two choice
	// try one choice, include the first element
	int tmp = rest[0];
	vector<int> sofar1(sofar.begin(), sofar.end());
	sofar1.push_back(tmp);
	vector<int> rest1(rest.begin() + 1, rest.end());
	TugOfWar(sofar1, rest1, totalSum, totalSize, mindiff, s);

	// try the other choice, not include the first element
	vector<int> sofar2(sofar.begin(), sofar.end());
	vector<int> rest2(rest.begin() + 1, rest.end());
	TugOfWar(sofar2, rest2, totalSum, totalSize, mindiff, s);

	return;
}

int main()
{
	vector<int> v;
	v.push_back(23);
	v.push_back(45);
	v.push_back(-34);
	v.push_back(12);
	v.push_back(0);
	v.push_back(98);
	v.push_back(-99);
	v.push_back(4);
	v.push_back(189);
	v.push_back(-1);
	v.push_back(4);
	sort(v.begin(), v.end());

	int totalSum = accumulate(v.begin(), v.end(), 0);
	int totalSize = 11;
	int mindiff = INF;
	vector<int> sofar;
	vector<int> s;
	TugOfWar(sofar, v, totalSum, totalSize, mindiff, s); 
	
	cout << "Min diff: " << mindiff << endl;
	cout << "One set is:" << endl;
	copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	vector<int> otherset;
	otherset.resize(totalSize - s.size());
	set_difference(v.begin(), v.end(), s.begin(), s.end(), otherset.begin());
	cout << "The other set is:" << endl;
	copy(otherset.begin(), otherset.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}
