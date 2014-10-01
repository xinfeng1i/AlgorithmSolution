#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
using namespace std;

// Exhausive Searching
// Find all the subset, check whether satisfy the constraint
void subsetSum(vector<int> sofar, vector<int> rest, int k)
{
	// base case
	if (rest.empty())
	{
		if (accumulate(sofar.begin(), sofar.end(), 0) == k)
		{
			copy(sofar.begin(), sofar.end(), ostream_iterator<int>(cout, " "));
			cout << endl;
		}
		return;
	}
	
	int tmp = rest[0];
	// not choose the element
	vector<int> sofar1(sofar.begin(), sofar.end());
	vector<int> rest1(rest.begin() + 1, rest.end());
	subsetSum(sofar1, rest1, k);

	// choose the element
	vector<int> sofar2(sofar.begin(), sofar.end());
	sofar2.push_back(tmp);
	vector<int> rest2(rest.begin()+1, rest.end());
	subsetSum(sofar2, rest2, k);
}


// backtracking
bool SubsetSum2(vector<int> sofar, vector<int> rest, int k)
{
	// base case
	if (rest.empty())
	{
		if (k != 0) return false;
		else { copy(sofar.begin(), sofar.end(), ostream_iterator<int>(cout, " ")); return true; }
	}
	
	// try one choice
	vector<int> sofar1(sofar.begin(), sofar.end());
	sofar1.push_back(rest[0]);
	vector<int> rest1(rest.begin() + 1, rest.end());
	// lead to a solution
	if (SubsetSum2(sofar1, rest1, k - rest[0])) return true;
	
	vector<int> sofar2(sofar.begin(), sofar.end());
	vector<int> rest2(rest.begin() + 1, rest.end());
	// otherwise, try an alternative choice
	if (SubsetSum2(sofar2, rest2, k)) return true;

	// try both choice, still cannot find a solution
	return false;
}

int main()
{
	int k = 53;
	vector<int> sofar;
	vector<int> rest;
	rest.push_back(15);
	rest.push_back(22);
	rest.push_back(14);
	rest.push_back(26);
	rest.push_back(32);
	rest.push_back(9);
	rest.push_back(16);
	rest.push_back(8);
	bool ok = SubsetSum2(sofar, rest, k);
	if (!ok)
	{
		cout << "cannot find a solution" << endl;
	}
	else
	{
		cout << "Find solution" << endl;
	}
	return 0;
}
