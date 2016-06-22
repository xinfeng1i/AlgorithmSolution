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
#include <math.h>
#include <limits.h>
#include <time.h>
using namespace std;

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};

/**
 * The logic is as follows:
 * cache the next element of the list into a m_next variable and
 * use the has_next variable to indicate whether we has the next element
 * The diagram is:
 *   __    __ __ __ __ __ __ __ __
 *  cache   1  2 3  4   5  6  7  8
 *  When we construct the Iterator we cache the first element and mark has_next to be true
 *  When we peek element, we just return the cached element
 *  When we next element, we return the cached element and cache the new element
 *  When we judge whether has next element, we just return the mark label
 */
class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    has_next = Iterator::hasNext();
	    m_next = -1;
	    if (has_next) m_next = Iterator::next();
	    
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
	    return m_next;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    int temp = m_next;
	    has_next = Iterator::hasNext();
	    if (has_next) m_next = Iterator::next();
	    return temp;
	}

	bool hasNext() const {
	    return has_next;
	}
private:
    int m_next;
    bool has_next;
};