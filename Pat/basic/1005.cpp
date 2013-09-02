#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

set<int> numbersCoveredBy(int n)
{
	set<int> result;
	while (n != 1)
	{
		if (n % 2 == 0)
		{
			n /= 2;
			result.insert(n);
		}
		else
		{
			n = (n * 3 + 1) / 2;
			result.insert(n); 
		}
	}
	return result;
}

set<int> keyNumbers(const vector<int> &v)
{
	set<int> keyNums(v.begin(), v.end());
	set<int> tmp;
	for (size_t i = 0; i < v.size(); i++)
	{
		tmp = numbersCoveredBy(v[i]);
		for (set<int>::iterator it = tmp.begin(); it != tmp.end(); it++)
		{
			keyNums.erase(*it);
		}
	}
	return keyNums;
}

int main()
{
	int n = 0;
	cin >> n;

	vector<int> input;
	input.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
	}

    set<int> keys = keyNumbers(input);
    vector<int> result(keys.begin(), keys.end());
    for (size_t i = result.size() - 1; i >= 1; i--)
    {
        cout << result[i] << " ";
    }
    if (result.size() >= 1)
    {
        cout << result[0] << endl;
    }

    return 0;
}
