#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;

unordered_map<string, string> parent;
unordered_map<string, long> myrank;

void MakeSet(string x)
{
	parent[x] = x;
	myrank[x] = 0;
}

// path compression
string MyFind(string x)
{
	if (x == parent[x]) return x;
	parent[x] = MyFind(parent[x]);
	return parent[x];
}

// union by rank
void MyUnion(string x, string y)
{
	string rootx = MyFind(x);
	string rooty = MyFind(y);
	if (rootx != rooty)
	{
		if (myrank[rootx] < myrank[rooty])
		{
			parent[rootx] = rooty;
		}
		else
		{
			parent[rooty] = rootx;
			if (myrank[rootx] == myrank[rooty])
			{
				myrank[rootx]++;
			}
		}
	}
}

int main()
{
	freopen("data.in", "r", stdin);
	long N;
	cin >> N;

	int operationFlag;
	string name1, name2;
	for (long i = 0; i < N; ++i)
	{
		cin >> operationFlag >> name1 >> name2;

		if (parent.find(name1) == parent.end()) MakeSet(name1);
		if (parent.find(name2) == parent.end()) MakeSet(name2);

		if (operationFlag == 0)
		{
			if (MyFind(name1) != MyFind(name2))	MyUnion(name1, name2);
		}
		else
		{
			if (MyFind(name1) == MyFind(name2))
			{
				cout << "yes" << endl;
			}
			else
			{
				cout << "no" << endl;
			}
		}
	}
	return 0;
}