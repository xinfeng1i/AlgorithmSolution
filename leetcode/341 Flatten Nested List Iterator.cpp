#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};
 
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        vec = FlattenList(nestedList);
		it = vec.begin();
    }

    int next() {
        return *it++;
    }

    bool hasNext() {
        return it != vec.end();
    }
public:
	vector<int> FlattenList(const vector<NestedInteger> &nestedList) {
		vector<int> ans;
		if (nestedList.empty()) 
			return ans;
		for (size_t i = 0; i < nestedList.size(); ++i) {
			if (nestedList[i].isInteger()) {
				ans.push_back(nestedList[i].getInteger());
			} else {
				vector<int> temp = FlattenList(nestedList[i].getList());
				for (size_t i = 0; i < temp.size(); ++i) ans.push_back(temp[i]);
			}
		}
		return ans;
	}
private:
	vector<int> vec;
	vector<int>::iterator it;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */