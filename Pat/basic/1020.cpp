#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct Mooncake
{
    double amount_;
    double price_;
	
	bool operator< (const Mooncake& other) const
	{
		return (double)price_ / amount_ > double(other.price_) / (other.amount_);
	}
};

int main()
{
	int n; 
	int demand;
	cin >> n >> demand;
	
	vector<Mooncake> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i].amount_;
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i].price_;
	}

	sort(v.begin(), v.end());
	
	double profit = 0.0;
	for (int i = 0; i < n; ++i)
	{
		if (v[i].amount_ < demand)
		{
			demand -= v[i].amount_;
			profit += v[i].price_;
		}
		else
		{
			profit += v[i].price_ * demand / double(v[i].amount_);
			v[i].amount_ -= demand;
			demand = 0;
			break;
		}
	}

	printf("%0.2f\n", profit);

	return 0;
}





