#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct MyQueue
{
	stack<int> s1;
	stack<int> s2;
	bool EnQueue(int item);
	bool DeQueue(int &value);
};

bool MyQueue::EnQueue(int item)
{
	if (s1.size() >= n1)
	{
		return false;	 // full queue
	}
	else
	{
		s1.push(item);
		return true;
	}
}

bool DeQueue(int &value)
{
	if (s1.empty() && s2.empty())
	{
		return false;	// empty queue
	}

	if (s2.empty())
	{
		while (!s1.emtpy())
		{
			if (s2.size() >= n2)
			{
				return false;
			}
			else
			{
				s2.push(s1.top());
				s1.pop();
			}
		}
	}

	value = s2.top();
	s2.pop();
	return true;
}

int main()
{
	int n1, n2;
	scanf("%d %d\n", &n1, &n2);

	int cur1 = 0; int cur2 = 0;
	stack<int> s1, s2;
	char ch; int tmp;
	while (true)
	{
		scanf("%c", &ch);
		if (ch == 'T') break;
		else if (ch == 'A')
		{
			scanf("%d", &tmp);	

			bool flag = true;
			while (!s1.empty())
			{
				if (s2.size() >= n2)
				{
					flag = false;
					break;
				}
				s2.push(s1.top());
				s1.pop();
			}
			s1.push(tmp);
			printf("%d\n", tmp);
			while(!s2.empty())
			{
				s1.push(s2.top());
				cur1++;
				s2.pop();
				cur2--;	
			}
		}
		else if (ch == 'D')
		{
			if (s1.size() > 0)
			{
				printf("%d\n", s1.top());
				s1.pop();
			}
			else
			{
				printf("ERROR:Empty\n");
			}
		}
	}

	return 0;
}
