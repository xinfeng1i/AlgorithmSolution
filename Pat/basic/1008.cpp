
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int gcd(int m, int n)
{
    if (n == 0)
    {
        return 0;
    }
	int r = m % n;
	while (r != 0)
	{
		m = n;
		n = r;
		r = m % n;
	}
	return n;
}

/* Shift every number in |v| to right by |m| step
 * 
 * For example:
 * v = [1 2 3 4 5 6]
 * m = 2
 *
 * Result 
 * v = [5 6 1 2 3 4]
 */ 

void shiftRight(vector<int> &v, long m)
{
	int n = v.size();
    m = m % n;
	for (int i = n - 1; i >= n - gcd(n, m); i--)
	{
		int tmp = v[i];
		int cur_i = i;
		int next_i = (i - m + n) % n;
		while (next_i != i)
		{
			v[cur_i] = v[next_i];
			cur_i = next_i;
			next_i = (next_i - m + n) % n;
		}
		v[cur_i] = tmp;
	}
}


int main()
{
	int n = 0;
	int m = 0;
	cin >> n >> m;

	vector<int> input;
	input.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
	}

	shiftRight(input, m);
	for (int i = 0; i < input.size() - 1; i++)
	{
		cout << input[i] << " ";
	}
	if (input.size() >= 1)
	{
		cout << input[input.size() - 1] << endl;
	}

	
	return 0;

}

