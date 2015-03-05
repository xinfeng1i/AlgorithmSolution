#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval
{
	int start;
	int end;
	Interval() : start(0), end(0){}
	Interval(int s, int e) : start(s), end(e){}
};

bool cmpIntervals(Interval a, Interval b)
{
	if (a.start != b.start) return a.start < b.start;
	else return a.end < b.end;
}

vector<Interval> merge(vector<Interval>& intervals)
{
	if (intervals.size() <= 1) return intervals;
	
	// sorting intervals accoriding to start points
	sort(intervals.begin(), intervals.end(), cmpIntervals);

	// ans
	vector<Interval> ans;
	int sz = 0;
	ans.push_back(intervals[0]); sz++;

	// compare one by one
	for (size_t i = 1; i < intervals.size(); ++i)
	{
		// not overlap
		if (ans[sz-1].end < intervals[i].start)
		{
			ans.push_back(intervals[i]);
			sz++;
		}
		else // overlap
		{
			ans[sz-1].end = max(ans[sz-1].end, intervals[i].end);	
		}
	}

	return ans;
}

int main()
{
	cout << "Enter interval Number:" << endl;
	int n;
	cin >> n;
	vector<Interval> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i].start >> v[i].end;
	}

	vector<Interval> ans = merge(v);
	cout << "After merge:" << endl;
	for (int i = 0; i < ans.size(); ++i)
	{
		cout << "[" << ans[i].start << "," << ans[i].end << "]" << endl;
	}

	return 0;
}
