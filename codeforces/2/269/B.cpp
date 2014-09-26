#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> cnt(2010, 0);
struct Animal
{
	int id;
	int difficulty;

	bool operator<(const Animal& other) const
	{
		if (difficulty != other.difficulty)
		{
			return difficulty < other.difficulty;
		}
		else
		{
			return id < other.id;
		}
	}
};

int main()
{
	int n;
	cin >> n;
	int tmp;

	vector<Animal> v(n);
	for (int i = 1; i <= n; ++i)
	{
		cin >> tmp;
		cnt[tmp]++;

		v[i-1].id = i;
		v[i-1].difficulty = tmp;
	}

	int cnt2 = 0;
	int index2 = -1;
	int cnt3 = 0;
	int index3 = -1;
	for (int i = 0; i < 2010; i++)
	{
		if (cnt[i] == 2)
		{
			index2 = i;
			cnt2++;
		}
		else if (cnt[i] >= 3)
		{
			cnt3++;
			index3 = i;
		}
	}

	if (cnt2 < 2 && cnt3 < 1)
	{
		cout << "NO" << endl;
		return 0;
	}

	sort(v.begin(), v.end());
	cout << "YES" << endl;
	if (index3 != -1)
	{
		int pos1 = -1;
		int pos2 = -1;
		int pos3 = -1;
		// find three pos
		for (size_t i = 0; i < v.size(); i++)
		{
			if (v[i].difficulty == index3)
			{
				pos1 = i;
				pos2 = i+1;
				pos3 = i+2;
				break;
			}
		}
		// print the ans ,first line
		for (size_t i = 0; i < pos1; ++i)
		{
			cout << v[i].id << " ";
		}
		cout << v[pos1].id << " ";
		cout << v[pos2].id << " ";
		cout << v[pos3].id << " ";
		for (size_t i = pos3 + 1; i < v.size(); ++i)
		{
			cout << v[i].id << " ";
		}
		cout << endl;
		// second line
		for (size_t i = 0; i < pos1; ++i)
		{
			cout << v[i].id << " ";
		}
		cout << v[pos1].id << " ";
		cout << v[pos3].id << " ";
		cout << v[pos2].id << " ";
		for (size_t i = pos3 + 1; i < v.size(); ++i)
		{
			cout << v[i].id << " ";
		}
		cout << endl;
		// third line
		for (size_t i = 0; i < pos1; ++i)
		{
			cout << v[i].id << " ";
		}
		cout << v[pos2].id << " ";
		cout << v[pos1].id << " ";
		cout << v[pos3].id << " ";
		for (size_t i = pos3 + 1; i < v.size(); ++i)
		{
			cout << v[i].id << " ";
		}
		cout << endl;
	}
	else if (index2 != -1)
	{
		int diff1 = -1;
		for (size_t i = 0; i < cnt.size(); ++i)
		{
			if (cnt[i] == 2)
			{
				diff1 = i;
				break;
			}
		}
		int diff2 = -1;
		for (size_t i = 0; i < cnt.size(); ++i)
		{
			if (cnt[i] == 2 && i != diff1)
			{
				diff2 = i;
				break;
			}
		}
		
		int a1 = -1; int a2 = -1;
		int b1 = -1; int b2 = -1;
		for (int i = 0; i < v.size(); ++i)
		{
			if (v[i].difficulty == diff1)
			{
				a1 = i;
				break;
			}
		}
		for (int i = 0; i < v.size(); ++i)
		{
			if (v[i].difficulty == diff2)
			{
				b1 = i;
				break;
			}
		}
		a2 = a1 + 1;
		b2 = b1 + 1;

		// print ans
		// first line
		for (size_t i = 0; i < v.size(); ++i)
		{
			cout << v[i].id << " ";
		}
		cout << endl;
		// second line
		for (size_t i = 0; i < a1; ++i)
		{
			cout << v[i].id << " ";
		}
		cout << v[a2].id << " ";
		cout << v[a1].id << " ";
		for (size_t i = a2+1; i < v.size(); ++i)
		{
			cout << v[i].id << " ";
		}
		cout << endl;
		// third line
		for (size_t i = 0; i < b1; ++i)
		{
			cout << v[i].id << " ";
		}
		cout << v[b2].id << " ";
		cout << v[b1].id << " ";
		for (size_t i = b2+1; i < v.size(); ++i)
		{
			cout << v[i].id << " ";
		}
		cout << endl;

	}

	return 0;
}
