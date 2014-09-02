#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <functional>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

// special stack: 
// Push: O(logn)
// Pop:	 O(logn)
// PeekMedian: O(1)
class MyStack
{
public:
    void Push(int key);
    int Pop();
    int PeekMedian();
private:
    multiset<int, greater<int> > lower; // numbers smaller than median, decrease order
    multiset<int> higher;				// numbers greater than median, increase order
    stack<int> s;						// normal stack
};

void MyStack::Push(int key)
{
    s.push(key);
    if (lower.size() == higher.size())
    {
        if (lower.size() == 0)
        {
            higher.insert(key);
        }
        else
        {
            int x = *lower.begin();
            int y = *higher.begin();
            if (key >= x)
            {
                higher.insert(key);
            }
            else
            {
                lower.insert(key);
            }
        }
    }
    else if (lower.size() + 1 == higher.size())
    {

		int y = *higher.begin(); 
		if (key <= y)
		{
			lower.insert(key);
		}
		else
		{
			// adjust lower and higher, keep lower.size() = higher.size() 
			//                               lower.size() = higher.size() + 1
			//                               lower.size() = higher.size() - 1
			higher.insert(key);
			int yy = *higher.begin();
			higher.erase(yy);
			lower.insert(yy);
		}

    }
    else if (lower.size() == higher.size() + 1)
    {
        int x = *lower.begin();
        if (key >= x)
        {
            higher.insert(key);
        }
        else
        {
            lower.insert(key);
            int xx = *lower.begin();
            lower.erase(xx);
            higher.insert(xx);
        }
    }
}

int MyStack::Pop()
{
    // empty stack
    if (s.size() == 0)
    {
        return -1;
    }

    int key = s.top();
    s.pop();

    if (lower.size() == higher.size())
    {
        if (lower.count(key) > 0)
        {
            lower.erase(key);
        }
        else
        {
            higher.erase(key);
        }
    }
    else if (lower.size() + 1 == higher.size())
    {
        if (higher.count(key) > 0)
        {
            higher.erase(key);
        }
        else
        {
            lower.erase(key);
            int y = *higher.begin();
            higher.erase(y);
            lower.insert(y);
        }
    }
    else if (lower.size() == 1 + higher.size())
    {
        if (lower.count(key) > 0)
        {
            lower.erase(key);
        }
        else
        {
            higher.erase(key);
            int x = *lower.begin();
            lower.erase(x);
            higher.insert(x);
        }
    }
    return key;
}

int MyStack::PeekMedian()
{
    // empty stack
    if (s.size() == 0)
    {
        return -1;
    }

    if (lower.size() == higher.size())
    {
        return *lower.begin();
    }
    else if (lower.size() + 1 == higher.size())
    {
        return *higher.begin();
    }
    else if (lower.size() == 1 + higher.size())
    {
        return *lower.begin();
    }
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    char keyword[50];
    int key;
    MyStack ms;
    for (int k = 0; k < n; ++k)
    {
        scanf("%s", keyword);
        if (strcmp(keyword, "Push") == 0)
        {
            scanf("%d", &key);
            ms.Push(key);
        }
        else if (strcmp(keyword, "Pop") == 0)
        {
            int ans = ms.Pop();
            if (ans == -1)
            {
                printf("Invalid\n");
            }
            else
            {
                printf("%d\n", ans);
            }
        }
        else if (strcmp(keyword, "PeekMedian") == 0)
        {
            int ans = ms.PeekMedian();
            if (ans == -1)
            {
                printf("Invalid\n");
            }
            else
            {
                printf("%d\n", ans);
            }
        }
        else
        {
            printf("Invalid\n");
        }
        
    }
    return 0;
}
