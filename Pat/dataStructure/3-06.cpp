#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstdlib>
using namespace std;

/******************************************************************** 
 * Infix expression to postfix expression
 *
 * Algorithm:
 * 1. Scan a token
 * 2. If the token is a number, push to the output queue
 * 3. If the token is a operator o1 ( + - * / ):
 *    3.1 while ( stack top is a operator o2 && o1 <= o2)
 *            pop o2, push o2 to output queue
 *    3.2 push o1 ot stack
 * 4. If the token is a '(', push to stack
 * 5. If the token is a ')':
 *    5.1 pop the operator in stack until encoutering a '('
 *    5.2 if not '(' encountered, ERROR: not matching
 *    5.3 else pop '(', not enqueue
 * 6. All tokens been read, check the stack:
 *    while (there are oprerator in the stack):
 *       If the token is a '(' or ')', ERROR: mismatched parentheses.
 *       pop the operator, push to the output queue
 * 7. Exit
 *********************************************************************/

bool isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int prec(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else 
    {
        return -1;
    }
}

int main()
{
    stack<char> s;
    queue<char> q;
    int ch;
    while ((ch = getchar()) != EOF)
    {
        if (isdigit(ch) || ch == '.')
        {
            q.push(ch);
        }
        else if (isOperator(ch))
        {
            while (!s.empty() && isOperator(s.top()) && prec(ch) <= prec(s.top()))
            {
                q.push(' ');
                q.push(s.top());
                s.pop();
            }
            q.push(' ');
            s.push(ch);
        }
        else if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            while (!s.empty() && isOperator(s.top()) && s.top() != '(')
            {
                q.push(' ');
                q.push(s.top());
                s.pop();
            }

            if (s.empty())
            {
                cerr << "ERROR: Mismatched parentheses! " << endl;
                exit(-1);
            }
            else
            {
                s.pop();
            }
        }
    }

    while (!s.empty())
    {
        if (s.top() == '(' || s.top() == ')')
        {
            cerr << "ERROR: Mismatched parentheses !" << endl;
            exit(-1);
        }
        else
        {
            q.push(' ');
            q.push(s.top());
            s.pop();
        }
    }

    bool isFirst = true;
    while (!q.empty())
    {
        printf("%c", q.front());
        q.pop();
    }
    printf("\n");

    return 0;

}
