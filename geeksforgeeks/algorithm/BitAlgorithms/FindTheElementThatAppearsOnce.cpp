#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * Problem Statement:
 * Given an array where every element occurs three times, except one 
 * element which ocuurs only once. Find the element that occurs once.
 * Time  Complexity: O(n)
 * Space Complexity: O(1)
 */

int FindOccurOnceElement(vector<int> v)
{
	int n = v.size();
	int ones = 0;
	int twos = 0;
	for (int i = 0; i < n; ++i)
	{
		int x = v[i];
		
		// ones & x: occurs both in x and ones bits
		// these bits occurs twice, so add thest bits to twos
		twos = twos | (ones & x);

		// minus the bits already add to twos
		// keep the bits that not add to twos;
		ones = ones ^ x;

		// mask the bits occurs both in ones and twos, which
		// means these bits ocuurs three times
		int mask_bits = ~(ones & twos);

		// minus the bits that occurs three times
		// keep twos only bits that ocuurs two times, not five times, eight times
		twos = twos & mask_bits;

		// minus the bits that ocuurs three times
		// keep ones only bits that ocuurs one time, not four time, seven times
		ones = ones & mask_bits;
	}

	return ones;
}

// method 2:
// count the number of ones on every bits, if is divible by 3
// ignore it, eles keep it
// Complexity: O(32 * n) = O(n)
int FindOccurOnceElement2(vector<int> v)
{
	int n = v.size();
	const int BIT_LEN = 32;
	int ret = 0;
	for (int i = 0; i < BIT_LEN; ++i)
	{
		int bit = (1 << i);
		int cnt = 0;
		for (int j = 0; j < n; ++j)
		{
			int x = v[j];	
			if (x & bit)
			{
				cnt++;
			}
		}
		
		if (cnt % 3 != 0)
		{
			ret = (ret | bit);
		}
	}
	return ret;
}

int main()
{
	vector<int> v;
	v.push_back(12);
	v.push_back(1);
	v.push_back(12);
	v.push_back(3);
	v.push_back(12);
	v.push_back(1);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(2);
	v.push_back(2);
	v.push_back(3);
	v.push_back(7);
	//int ans = FindOccurOnceElement2(v);
	int ans = FindOccurOnceElement(v);
	cout << ans << endl;
	return 0;
}
