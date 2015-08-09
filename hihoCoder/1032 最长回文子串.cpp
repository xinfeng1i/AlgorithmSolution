#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAXLEN = 1000000 + 10;

char txt[MAXLEN];
char T[2 * MAXLEN];

void Preprocess(char* s)
{
	int n = strlen(s);
	memset(T, '\0', 2 * MAXLEN);
	for (int i = 0; i < n; ++i)
	{
		T[2 * i] = '#';
		T[2 * i + 1] = s[i];
	}
	T[2 * n] = '#';
}

/*
 * Manacher's Algorithm
 * 
 * ======|(centerLeft)========|(iMirror)===|(center)===|(i)=========|(centerRight)==
 * 
 * Case 1: L[iMirror] < centerRight - i;
 * Case 2: L[iMirror] == centerRight - i && centerRight == N - 1;
 * Case 3: L[iMirror] == centerRight - i && centerRight < N - 1;
 * Case 4: L[iMirror] > centerRight - i;
 * 
 * for case 1 and 2, L[i] = L[iMirror], the substring centered at i is contained in the
 * substring centered at center, symmetry
 * for case 3 and 4, L[i] >= centerRight - i, need to expand
 * finally if pralindrome centered at pos i exceeds centerRight, then update center = i
 * 
 * Time Complexity O(n), space complexity O(2 * n)
 */

int MaxPralindromeSubstring(char* s)
{
	Preprocess(s);
	int N = strlen(T);

	int maxCenter = 1;
	int maxLen = 1;

	int* L = new int[N];
	L[0] = 0;
	L[1] = 1;
	int center = 1;
	int centerLeft = 0;
	int centerRight = 0;
	int expand = 0;
	for (int i = 2; i < N; ++i)
	{
		int iMirror = 2 * center - i;
		centerLeft = center - L[center];
		centerRight = center + L[center];
		expand = 0;

		if (centerRight >= i)
		{
			if (L[iMirror] < centerRight - i)
			{
				L[i] = L[iMirror];	// case 1
			}
			else if (L[iMirror] == centerRight - i && centerRight == N - 1)
			{
				L[i] = L[iMirror];	// case 2
			}
			else if (L[iMirror] == centerRight - i && centerRight != N - 1)
			{
				expand = 1;
				L[i] = centerRight - i; // case 3
			}
			else if (L[iMirror] > centerRight - i)
			{
				expand = 1;
				L[i] = centerRight - i;	// case 4
			}
		}
		else
		{
			expand = 1;
			L[i] = 0;
		}

		if (expand == 1)
		{
			while (i + L[i] + 1 < N &&
				i - L[i] - 1 >= 0 &&
				T[i + L[i] + 1] == T[i - L[i] - 1])
			{
				L[i]++;
			}
		}

		if (i + L[i] > centerRight)
		{
			center = i;
		}

		if (L[i] > maxLen)
		{
			maxCenter = i;
			maxLen = L[i];
		}
	}

	delete[] L;

	int start = (maxCenter - maxLen) / 2;
	int end = start + maxLen - 1;
	//for (int i = start; i <= end; ++i) printf("%c", s[i]);
	//printf("\n");
	return maxLen;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	int N;
	scanf("%d\n", &N);
	for (int i = 0; i < N; ++i)
	{
		memset(txt, '\0', MAXLEN);
		scanf("%s", txt);
		int ans = MaxPralindromeSubstring(txt);
		printf("%d\n", ans);
	}
	return 0;
}

// summary: using char* & C I/O pass the TLE