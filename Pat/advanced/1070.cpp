#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct Mooncake
{
	double amount_; // using int the 3rd sample WA
	double price_;
	double avgPrice_;
	bool operator< (const Mooncake& other) const
	{
		return price_ * other.amount_ > other.price_ * amount_;
	}
};

int main()
{
	int n; int D;
	scanf("%d %d", &n, &D);

	vector<Mooncake> v(n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%lf", &v[i].amount_);
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%lf", &v[i].price_);
	}
	for (int i = 0; i < n; ++i)
	{
		v[i].avgPrice_ = v[i].price_ / v[i].amount_;
	}

	sort(v.begin(), v.end());
	double ans = 0.0;
	for (int i = 0; i < n; ++i)
	{
		if (D <= 0) break;
		if (v[i].amount_ <= D)
		{
			D -= v[i].amount_;
			ans += v[i].price_;
		}
		else
		{
			ans += v[i].price_ * D / v[i].amount_;
			D = 0;
			break;
		}
	}
	printf("%.2f\n", ans);
	return 0;
}


