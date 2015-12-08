#include <iostream>
#include <map>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	int teamID, playerID, score;
	map<int, int> teamScoreList;
	for (int i = 0; i < n; ++i) {
		scanf("%d-%d %d", &teamID, &playerID, &score);
		teamScoreList[teamID] += score;
	}
	
	int champID = -1;
	int champScore = -1;
	map<int, int>::iterator it;
	for (it = teamScoreList.begin(); it != teamScoreList.end(); ++it) {
		if (it->second > champScore) {
			champID = it->first;
			champScore = it->second;
		}
	}
	printf("%d %d\n", champID, champScore);
	return 0;
}
