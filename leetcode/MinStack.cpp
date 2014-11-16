#include <iostream>
#include <string>
#include <stack>
using namespace std;

class MinStack
{
public:
    void push(int x)
    {
        if (s2.empty())
        {
            s1.push(x);
            s2.push(x);
        }
        else
        {
            int y = s2.top();
            if (x <= y)
            {
                s1.push(x);
                s2.push(x);
            }
            else
            {
                s1.push(x);
            }

        }
    }

    void pop()
    {
        if (!s1.empty())
        {
            if (s1.top() > s2.top())
            {
                s1.pop();
            }
            else
            {
                s1.pop();
                s2.pop();
            }
        }
    }

    int top()
    {
        if (!s1.empty())
        {
            return s1.top();
        }
    }

    int getMin()
    {
        if (!s1.empty())
        {
            return s2.top(); 
        }
    }
private:
    stack<int> s1;
    stack<int> s2;
};

int main()
{
    MinStack ms;
    ms.push(2);
    ms.push(0);
    ms.push(3);
    ms.push(0);
    cout << ms.getMin() << endl;
    ms.pop();
    cout << ms.getMin() << endl;
    ms.pop();
    cout << ms.getMin() << endl;
    ms.pop();
    cout << ms.getMin() << endl;
    return 0;
}
