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

bool cmpIntervals(const Interval& a, const Interval& b)
{
	return a.end < b.start;
}

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
{
	vector<Interval>::iterator it;
	it = lower_bound(intervals.begin(), intervals.end(), newInterval, cmpIntervals);

	vector<Interval> ans;
	for (auto iter = intervals.begin(); iter != it; ++iter)
	{
		ans.push_back(*iter);
	}

	// Attention 1: it == end()
	if (it == intervals.end())
	{
		ans.push_back(newInterval);
		return ans;
	}
	else
	{

		// Attention 2: x >= k, x and k may not overlap
		if (it->start > newInterval.end)
		{
			ans.push_back(newInterval);
			ans.push_back(*it);
		}
		else
		{
			Interval mergedInterval(min(it->start, newInterval.start),
									max(it->end, newInterval.end));

			ans.push_back(mergedInterval);
		}

		int sz = ans.size();
		for (auto iter = it + 1; iter != intervals.end(); ++iter)
		{
			// not overlap
			if (ans[sz-1].end < iter->start)
			{
				ans.push_back(*iter);
				sz++;
			}
			else
			{
				ans[sz-1].end = max(ans[sz-1].end, iter->end);
			}
		}
		return ans;
	}
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

	Interval newInterval;
	cout << "Insert new Interval:" << endl;
	cin >> newInterval.start >> newInterval.end;


	vector<Interval> ans = insert(v, newInterval);
	cout << "After merge:" << endl;
	for (int i = 0; i < ans.size(); ++i)
	{
		cout << "[" << ans[i].start << "," << ans[i].end << "]" << endl;
	}

	return 0;
}
