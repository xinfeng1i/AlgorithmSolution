#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 100010;
int A[MAX_N];

int main()
{
	//freopen("in.txt", "r", stdin);
	for (int i = 0; i < MAX_N; ++i) A[i] = 0;

	int n;
	scanf("%d", &n);
	int ID = 0; int grade = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d", &ID, &grade);
		A[ID] += grade;
	}

	int maxID = -1;
	int maxScore = -1;
	for (int i = 0; i < MAX_N; ++i)
	{
		if (A[i] > maxScore)
		{
			maxID = i;
			maxScore = A[i];
		}
	}

	printf("%d %d\n", maxID, maxScore);
	return 0;
}