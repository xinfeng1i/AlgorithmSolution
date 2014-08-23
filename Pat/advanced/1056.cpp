#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
using namespace std;

struct player
{
	int id_;
	int weight_;
	int rank_;
	int finalRank_;
};

bool cmpWeight(const player& x, const player& y) 
{
	return x.weight_ > y.weight_;
}

bool cmpID(const player& x, const player& y)
{
	return x.id_ < y.id_;
}
bool cmpRank(const player& x, const player& y)
{
	if (x.rank_ != y.rank_) return x.rank_ > y.rank_;
	else return x.id_ < y.id_;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	vector<player> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i].weight_;
		v[i].id_ = i;
		v[i].rank_ = -1;
	}

	vector<player> groups;
	groups.reserve(n);
	int x = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		groups.push_back(v[x]);
	}

	int cnt = 0;
	vector<player> losers;
	while (groups.size() > 1)
	{
		cnt++;
		vector<player> winners;
		for (int i = 0; i < groups.size(); i += m)
		{
			
			sort(groups.begin() + i, 
				 min(groups.begin() + i + m, groups.end()),
				 cmpWeight);	
			for (int j = i + 1; j < min(i+m, int(groups.size()));++j)
			{
				groups[j].rank_ = cnt;
				losers.push_back(groups[j]);
			}
			winners.push_back(groups[i]);
		}
		groups.clear();
		swap(winners, groups);
	}
	groups[0].rank_ = cnt+1;

	losers.push_back(groups[0]);
	sort(losers.begin(), losers.end(), cmpRank);
	for (int i = 0; i < losers.size(); ++i)
	{
		losers[i].finalRank_ = i+1;
		if (i-1 >= 0 && losers[i].rank_ == losers[i-1].rank_)
		{
			losers[i].finalRank_ = losers[i-1].finalRank_;
		}
	}

	sort(losers.begin(), losers.end(), cmpID);

	for (int i = 0; i < losers.size(); ++i)
	{
		if (i == 0) printf("%d", losers[i].finalRank_);
		else printf(" %d", losers[i].finalRank_);
	}
	printf("\n");
	return 0;
}
