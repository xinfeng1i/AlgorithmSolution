#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string.h>
using namespace std;

/*
 * Hash table
 */
class Solution
{
public:
  //Insert one char from stringstream
    void Insert(char ch)
    {
    	tb[ch]++;
    	if (tb[ch] == 1) {
    		v.push_back(ch);
		} else {
			vector<char>::iterator it;
			it = find(v.begin(), v.end(), ch);
			if (it != v.end()) {
				v.erase(it);
			}
		}
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
    	if (v.empty()) return '#';
    	else return v[0];
    }
private:
	unordered_map<char, int> tb;
	vector<char> v;
};
