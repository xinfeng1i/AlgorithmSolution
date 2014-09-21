#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <stack>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;

const int N = 100010;
vector<string> essay;
map<string, pair<int, int> > cost;
map<string, vector<string> > graph;
map<string, vector<string> > rgraph;
map<string, vector<string> > newgraph;
set<string> newvertices;
set<string> vertices;
map<string, bool> visited;
stack<string> curStack;
vector<set<string> > allSCC;

int m, n;

string lowercase(string word)
{
	string ans(word);
	for (int i = 0; i < ans.size(); ++i)
	{
		if (ans[i] >= 'A' && ans[i] <= 'Z')
		{
			ans[i] = ans[i] - 'A' + 'a';
		}
	}
	return ans;
}

int countR(string word)
{
	int cnt = 0;
	for (size_t i = 0; i < word.size(); ++i)
	{
		if (word[i] == 'r' || word[i] == 'R')
		{
			cnt++;
		}
	}
	return cnt;
}

bool InSameSCC(string x, string y)
{
	for (size_t i = 0; i < allSCC.size(); ++i)
	{
		if (allSCC[i].count(x) != 0 && allSCC[i].count(y) != 0)
		{
			return true;
		}
	}
	return false;
}

string representativeWordOfSCC(string x)
{
	for (size_t i = 0; i < allSCC.size(); ++i)
	{
		if (allSCC[i].count(x) != 0)
		{
			return *(allSCC[i].begin());
		}
	}
	return x;
}

pair<int, int> minPair(pair<int, int> x, pair<int, int> y)
{
	if (x.first < y.first)
	{
		return x;
	}
	else
	{
		return y;
	}
}

void FirstDFS(string u)
{
	visited[u] = true;
	for (auto it = graph[u].begin(); it != graph[u].end(); ++it)
	{
		string v = *it;
		if (!visited[v])
		{
			FirstDFS(v);
		}
	}
	curStack.push(u);
}

void SecondDFS(string u, set<string>& curSCC)
{
	visited[u] = true;
	curSCC.insert(u);
	for (auto it = rgraph[u].begin(); it != rgraph[u].end(); ++it)
	{
		string v = *it;
		if (!visited[v])
		{
			SecondDFS(v, curSCC);
		}
	}
}
void PrintGraph(map<string, vector<string> >& graph)
{
	for (auto it = graph.begin(); it != graph.end(); ++it)
	{
		string u = it->first;
		cout << u << " : ";
		for (auto it2 = graph[u].begin(); it2 != graph[u].end(); ++it2)
		{
			string v = *it2;
			cout << v << " ";
		}
		cout << endl;
	}
}
void PrintSCCs(vector<set<string> > &SCCs)
{
	for (size_t i = 0; i < SCCs.size(); ++i)
	{
		cout << "\t" << i << " : ";
		for (auto it = SCCs[i].begin(); it != SCCs[i].end(); ++it)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << endl;
}

pair<int, int> DFS(string u)
{
	if (visited[u]) return cost[u];

	visited[u] = true;
	pair<int, int> curminCost(cost[u]);
	for (auto it = newgraph[u].begin(); it != newgraph[u].end(); ++it)
	{
		string v = *it;
		curminCost = minPair(curminCost, DFS(v));
	}
	cost[u] = curminCost;
	return curminCost;
}

int main()
{
	cin >> m;
	string word;
	for (int i = 0; i < m; ++i)
	{
		cin >> word;
		word = lowercase(word);
		essay.push_back(word);
	}

	cin >> n;
	string wordx, wordy;
	for (int i = 0; i < n; ++i)
	{
		cin >> wordx >> wordy;
		wordx = lowercase(wordx);
		wordy = lowercase(wordy);
		vertices.insert(wordx);
		vertices.insert(wordy);

		if (cost.count(wordx) == 0)
		{
			cost[wordx] = make_pair(countR(wordx), wordx.size());
		}
		if (cost.count(wordy) == 0)
		{
			cost[wordy] = make_pair(countR(wordy), wordy.size());
		}
		
		graph[wordx].push_back(wordy);
		rgraph[wordy].push_back(wordx);
	}

	//cout << "Original Graph:" << endl;
	//PrintGraph(graph);
	//cout << "reverse Graph:" << endl;
	//PrintGraph(rgraph);

	// first dfs
	visited.clear();
	for (auto it = vertices.begin(); it != vertices.end(); ++it)
	{
		visited[*it] = false;
	}
	for (auto it = vertices.begin(); it != vertices.end(); ++it)
	{
		string u = *it;
		if (!visited[u])
		{
			FirstDFS(u);
		}
	}

	//second dfs, find all the SCCs
	visited.clear();
	for (auto it = vertices.begin(); it != vertices.end(); ++it)
	{
		visited[*it] = false;
	}
	while (!curStack.empty())
	{
		string u = curStack.top();
		curStack.pop();
		if (!visited[u])
		{
			set<string> curSCC;
			SecondDFS(u, curSCC);
			pair<int, int> minCost(make_pair(N, N));
			for (auto it = curSCC.begin(); it != curSCC.end(); ++it)
			{
				string word = *it;
				minCost = minPair(minCost, cost[word]);
			}
			for (auto it = curSCC.begin(); it != curSCC.end(); ++it)
			{
				string word = *it;
				cost[word] = minCost;
			}
			allSCC.push_back(curSCC);
		}
	}

	//cout << "allSCC.size() : " << allSCC.size() << endl;
	//PrintSCCs(allSCC);

	// create new graph
	for (auto it = graph.begin(); it != graph.end(); ++it)
	{
		string u = it->first;
		for (auto it2 = graph[u].begin(); it2 != graph[u].end(); ++it2)
		{
			string v = *it2;
			if (!InSameSCC(u, v))
			{
				string headU = representativeWordOfSCC(u);
				string headV = representativeWordOfSCC(v);
				newgraph[headU].push_back(headV);
				newvertices.insert(headU);
				newvertices.insert(headV);
			}
		}
	}

	//cout << "new graph" << endl;
	//PrintGraph(newgraph);

	// dfs the new DAG graph
	visited.clear();
	for (auto it = newvertices.begin(); it != newvertices.end(); ++it)
	{
		visited[*it] = false;
	}
	for (auto it = newvertices.begin(); it != newvertices.end(); ++it)
	{
		if (!visited[*it])
		{
			pair<int, int> mincost =  DFS(*it);

			// update all the cost in the same SCC
			for (size_t i = 0; i < allSCC.size(); ++i)
			{
				if (allSCC[i].count(*it) != 0)
				{
					for (auto it2 = allSCC[i].begin(); it2 != allSCC[i].end(); ++it2)
					{
						cost[*it2] = mincost;
					}
				}
			}
		}
	}

	//cout << "print ans" << endl;

	int ansR = 0;
	int anslen = 0;
	for (size_t i = 0; i < essay.size(); ++i)
	{
		string word = essay[i];
		if (vertices.count(word) != 0)
		{
			ansR += cost[word].first;
			anslen += cost[word].second;
		}
		else
		{
			ansR +=	countR(word);
			anslen += word.size();
		}
	}
	cout << ansR << " " << anslen << endl;

	return 0;
}
