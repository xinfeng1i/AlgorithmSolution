#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cmath>
using namespace std;

struct Node
{
	int id_;
	int level_;
	int amount_;
	double price_;
	set<Node*> children_;

	Node(int id):id_(id),
	             level_(0),
				 amount_(0),
				 price_(0.0)
	{}
};

int main()
{
	freopen("input.txt", "r", stdin);

	int n = 0;
	double p = 0.0;
	double r = 0;
	cin >> n >> p >> r;
    //scanf("%d %f %f", &n, &p, &r);

	// init
	vector<int> prev(n, -1);
	vector<Node*> a(n, NULL);
	for (int i = 0; i < n; ++i)
	{
		a[i] = new Node(i);
	}

	// read data
	int k = 0;
	int nr = 0;
	int ac = 0;
	for (int i = 0; i < n; ++i)
	{
		//cin >> k;
        scanf("%d", &k);
		if (k != 0)
		{
			for (int j = 0; j < k; ++j)
			{
				//cin >> nr;
                scanf("%d", &nr);
				prev[nr] = i;
				a[i]->children_.insert(a[nr]);
			}
		}
		else
		{
			//cin >> ac;
            scanf("%d", &ac);
			//cout << "ac:" << ac << endl;
			a[i]->amount_ = ac;

			int cur = i;
			while (prev[cur] != -1)
			{
				int iparent = prev[cur];
				a[iparent]->amount_ += ac;
				cur = iparent;
			}
		}
	}

	// bfs
	queue<Node*> q;
	q.push(a[0]);
	while (!q.empty())
	{
		Node* u = q.front();
		q.pop();
		for (auto it = u->children_.begin(); it != u->children_.end(); ++it)
		{
			Node* v = *it;
			v->level_ = u->level_ + 1;
			q.push(v);
		}
	}

	double sum = 0.0;
	for (int i = 0; i < n; ++i)
	{
		if (a[i]->children_.empty())
		{
			double curAmount = a[i]->amount_;
			int curLevel = a[i]->level_;	
			double curPrice = p * pow((1 + r/100.0), curLevel);
			sum += (curPrice) * curAmount;
		}
	}

	printf("%0.1f\n", sum);

	// destory
	for (int i = 0; i < n; ++i)
	{
		delete a[i];
		a[i] = NULL;
	}
	
	return 0;
}
