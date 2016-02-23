#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
using namespace std;

map<string, int> gCityHappiness;
map<string, map<string, int> > gDist;
set<string> gAllCities;

string ChooseMinDistCity(string srcCity, map<string,bool>& visited, map<string, int>& distFromSrc) {
	string resCity = "";
	int resDist = INT_MAX;
	for (auto it = visited.begin(); it != visited.end(); ++it) {
		if (it->second == false && distFromSrc[it->first] < resDist) {
			resCity = it->first;
			resDist = distFromSrc[it->first];
		}
	}
	return resCity;
}

void Dijkstra(string srcCity, int n, map<string, int>& distFromSrc, map<string, vector<string> >& parent) {
	map<string,bool> visited;
	distFromSrc.clear();	// dist from the src city
	parent.clear();
	for (auto it = gAllCities.begin(); it != gAllCities.end(); ++it) {
		visited[*it] = false;
		distFromSrc[*it] = INT_MAX;
	}

	distFromSrc[srcCity] = 0;
	for (int i = 0; i < n; ++i) {
		string uCity = ChooseMinDistCity(srcCity, visited, distFromSrc);
		visited[uCity] = true;
		for (auto it = gDist[uCity].begin(); it != gDist[uCity].end(); ++it) {
			string vCity = it->first;
			int uvCost = it->second;
			if (!visited[vCity]) {
				if (distFromSrc[uCity] != INT_MAX && 
					distFromSrc[uCity] + uvCost < distFromSrc[vCity]) {
					distFromSrc[vCity] = distFromSrc[uCity] + uvCost;
					parent[vCity].clear();
					parent[vCity].push_back(uCity);
				} else if (distFromSrc[uCity] != INT_MAX && 
					distFromSrc[uCity] + uvCost == distFromSrc[vCity]) {
					parent[vCity].push_back(uCity);
				}
			}
		}
	}	
}

vector<vector<string> > GetAllPaths(string src, string dest, map<string, vector<string> >& parent)
{
	vector<vector<string> > result;
	if (dest == src) {
		vector<string> temp;
		temp.push_back(src);
		result.push_back(temp);
		return result;
	}

	for (size_t i = 0; i < parent[dest].size(); ++i) {
		string preCity = parent[dest][i];
		vector<vector<string> > paths = GetAllPaths(src, preCity, parent);
		for (size_t j = 0; j < paths.size(); ++j) {
			vector<string> curPath = paths[j];
			curPath.push_back(dest);
			result.push_back(curPath);
		}
	}
	return result;
}

int GetPathHappiness(const vector<string>& path) {
	int happiness = 0;
	for (size_t i = 0; i < path.size(); ++i) {
		string city = path[i];
		if (gCityHappiness.find(city) != gCityHappiness.end()) {
			happiness += gCityHappiness[city];
		}
	}
	return happiness;
}


void PrintVector(const vector<string>& v) {
	for (size_t i = 0; i < v.size(); ++i) {
		if (i == 0) cout << v[i];
		else cout << "->" << v[i];
	}
	cout << endl;
}

int main()
{
	freopen("input.txt", "r", stdin);
	// input
	int n; int k;
	string startCity;
	cin >> n >> k >> startCity;

	gAllCities.insert(startCity);

	string tempCity;
	int happiness;
	for (int i = 0; i < n - 1; ++i) {
		cin >> tempCity >> happiness;
		gCityHappiness[tempCity] = happiness;
		gAllCities.insert(tempCity);
	}

	string fromCity, toCity;
	int cost;
	for (int i = 0; i < k; ++i) {
		cin >> fromCity >> toCity >> cost;
		gDist[fromCity][toCity] = cost;
		gDist[toCity][fromCity] = cost;
	}

	// Dijkstra, calculate the minmimum cost path
	map<string, int> distFromSrc;
	map<string, vector<string> > parent;
	Dijkstra(startCity, n, distFromSrc, parent);

	// recursively get all paths from startCity to ROM
	vector<vector<string> > MyAllPaths = GetAllPaths(startCity, "ROM", parent);

	// Select all the paths with Max Happiness
	vector<vector<string> > MyAllPathsWithMaxHappiness;
	int MaxHappiness = -1;
	for (size_t i = 0; i < MyAllPaths.size(); ++i) {
		//PrintVector(MyAllPaths[i]);
		int curHappiness = GetPathHappiness(MyAllPaths[i]);
		if (curHappiness > MaxHappiness) {
			MaxHappiness = curHappiness;
			MyAllPathsWithMaxHappiness.clear();
			MyAllPathsWithMaxHappiness.push_back(MyAllPaths[i]);
		} else if (curHappiness == MaxHappiness) {
			MyAllPathsWithMaxHappiness.push_back(MyAllPaths[i]);
		}
	}


	// Select the road with Max average happiness
	vector<string> finalPath;
	int averageHappiness = -1;
	for (size_t i = 0; i < MyAllPathsWithMaxHappiness.size(); ++i) {
		int happy = GetPathHappiness(MyAllPathsWithMaxHappiness[i]);
		int average = happy / (int(MyAllPathsWithMaxHappiness[i].size()) - 1);
		if (average > averageHappiness) {
			averageHappiness = average;
			finalPath = MyAllPathsWithMaxHappiness[i];
		}
	}

	//cout << "final result" << endl;
	cout << MyAllPaths.size() << " " << distFromSrc["ROM"] << " " 
	     << GetPathHappiness(finalPath) << " " << averageHappiness << endl;
	PrintVector(finalPath);


	return 0;
}