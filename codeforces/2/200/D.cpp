#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    string input;
    cin >> input;

    stack<char> s;
    long sz = input.size();
    for (long i = 0; i < sz; ++i)
    {
        // if stack is not empty and top element equals current char in input
        // they can reverse to '+' and '-', i.e., these two identical element 
        // can be eliminated. so pop
        if(!s.empty() && s.top() == input[i])
        {
            s.pop();
        }
        // if encounter with different element, nothing can be done to
        // eliminated, push to stack
        else
        {
            s.push(input[i]);
        }
    }

    if (s.empty())
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;

}

// This is a data structure - stack
// I didn't recognize this is a stack problem. Though I finger out that if
// there are two successive element, they can be convert either '+' or '-'
// then only depends on the element just before these two element.
// BUT THIS IS A STACK MODEL, we can just eliminate the these two identical
// elements. 
// Rememeber STACK
