#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int d = 256;	// the number of characters in the alphabeta
/* Robin Karp Algorithm
 * For each substring whose length is m of txt, caculate a number
 * In case the number is too big to fill into memory, mod some prime p
 * so that the result can fill into memory. Slide the pat one by one,
 * to check the hash number and the correspoding hash number in txt,
 * if equals, then recheck the character one by one.
 * otherwise, not match
 * -------
 * INPUT:
 * txt - [0...n-1]
 * pat - [0...m-1]
 * q - a prime as module
 */
void RobinKarp(const char* txt, const char* pat, int q)
{
	int n = strlen(txt);
	int m = strlen(pat);

	// Preprocess: caculate the hash number of pat and the first substring
	int t = 0;	// hash value of current substring	
	int p = 0;	// hash value of pattern string
	int h = 1;	// h = d^(m-1) % q
	
	for (int i = 0; i < m - 1; ++i)
	{
		h = (h * d) % q;
	}
	int c = 1;
	for (int i = m-1; i >= 0; --i)
	{
		p += ((c % q) * (pat[i] % q)) % q;	// p = pat[m-1] * 1 + pat[m-2] * d...
		t += ((c % q) * (txt[i] % q)) % q;
		c = (c * d) % q;
	}

	// Match: Slide pattern one by one
	for (int s = 0; s <= n - m; ++s)
	{
		if (p == t)
		{
			bool found = true;
			for (int i = 0; i < m; ++i)
			{
				if (pat[i] != txt[s+i])
				{
					found = false;
					break;
				}
			}
			if (found) cout << "Pattern Found at Index " << s << endl;
		}
		
		//not the last match, update t next t[s+1] = (t - t[s+1] * h) * d + t[s+m+1];
		if (s < n - m)
		{
			t = ((t - txt[s] * h) * d + txt[s+m]) % q;
			// Notice: the hash number of substring may < 0, need fix to >0
			if (t < 0) t += q;
		}
	}
	return;
}

int main()
{
	const char* txt = "geeks for geeks";
	const char* pat = "geeks";
	RobinKarp(txt, pat, 101);
	return 0;
}
