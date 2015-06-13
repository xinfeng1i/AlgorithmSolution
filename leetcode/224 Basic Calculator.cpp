#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <utility>
using namespace std;

int calculate(string s)
{
	stack<char> ops;
	stack<int> vals;
	
	int n = s.size();
	int i = 0;
	while (i < n)
	{
		// skip space
		if (s[i] == ' ')
		{
			i++;
		}
		// number
		else if (s[i] >= '0' && s[i] <= '9')
		{
			int num = 0;
			do
			{
				num = num * 10 + (s[i] - '0');
				i++;
			}
			while(i < n && s[i] >= '0' && s[i] <= '9');
			vals.push(num);
		}
		// push back operator
		else if (s[i] == '+' || s[i] == '-')
		{
			while (!ops.empty() && (ops.top() == '+' || ops.top() == '-') )
			{
				char ch = ops.top();
				ops.pop();
				int n2 = vals.top();
				vals.pop();
				int n1 = vals.top();
				vals.pop();

				if (ch == '+')
				{
					vals.push(n1 + n2);
				}
				else if (ch == '-')
				{
					vals.push(n1 - n2);
				}
			}
			ops.push(s[i]);
			i++;
		}

		// left parentthese, push
		else if (s[i] == '(')
		{
			ops.push(s[i]);
			i++;
		}
		// right parenthese, pop
		else if (s[i] == ')')
		{
			while (!ops.empty() && ops.top() != '(')
			{
				char ch = ops.top();
				ops.pop();
				int n2 = vals.top();
				vals.pop();
				int n1 = vals.top();
				vals.pop();

				if (ch == '+')
				{
					vals.push(n1 + n2);
				}
				else if (ch == '-')
				{
					vals.push(n1 - n2);
				}

			}
			// pop left parenthese
			if (!ops.empty())
			{
				ops.pop();
			}
			i++;
		}



	}
	while (!ops.empty())
	{
		char ch = ops.top();
		ops.pop();
		int n2 = vals.top();
		vals.pop();
		int n1 = vals.top();
		vals.pop();

		if (ch == '+')
		{
			vals.push(n1 + n2);
		}
		else if (ch == '-')
		{
			vals.push(n1 - n2);
		}
	}

	return vals.top();

}

int main()
{
	string s = "(1+(4+5+2)-3)+(6+8)";
	int ans = calculate(s);
	cout << ans << endl;
	return 0;
}
