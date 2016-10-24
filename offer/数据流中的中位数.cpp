#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

class Solution {
public:
    void Insert(int num)
    {
		if (h1.size() == h2.size()) {
			if (h1.empty()) {
				h1.insert(num);
			} else {
				if (num <= *h1.begin()) {
					h1.insert(num);
				} else {
					h2.insert(num);
				}
			}
		} else if (h1.size() == h2.size() + 1) {
			if (num <= *h1.begin()) {
				h1.insert(num);
				h2.insert(*h1.begin());
				h1.erase(h1.begin());
			} else {
				h2.insert(num);
			}
		} else { // h1.size() + 1 == h2.size()
			if (h1.empty() || num <= *h1.begin()) {
				h1.insert(num);
			} else {
				h2.insert(num);
				h1.insert(*h2.begin());
				h2.erase(h2.begin());
			}
		}
		
    }

    double GetMedian()
    {
    	if (h1.size() == h2.size()) {
    		return (*h1.begin() + *h2.begin()) / 2.0;
    	} else if (h1.size() == h2.size() + 1) {
    		return *h1.begin();
		} else {
			return *h2.begin();
		}
    }
    
private:
	set<int, greater<int>> h1;
	set<int, less<int>> h2;
};
