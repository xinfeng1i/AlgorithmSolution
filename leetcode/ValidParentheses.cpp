#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isValid(string s)
{
    int n = s.size();
    stack<char> st;

    for (int i = 0; i < n; ++i)
    {
        char ch = s[i];
        if (ch == '(' || ch == '[' || ch == '{')
        {
            st.push(ch); 
        }
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            if (st.empty())
            {
                return false;
            }
            else
            {
                char out = st.top();
                st.pop();
                if (ch == ')' && out != '(') return false;
                else if (ch == ']' && out != '[') return false;
                else if (ch == '}' && out != '{') return false;
            }
        }
        else
        {
            return false;
        }
    }

    // still have not consumed parentheses
    if (!st.empty()) return false;
    return true;
}

int main()
{
    string s;
    cin >> s;
    cout << isValid(s) << endl;
    return 0;
}
