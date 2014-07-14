#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cassert>
using namespace std;

// given number a, b and operator ch, return eval(a ch b)
int calculateBinaryExpression(int a, int b, char ch)
{
    switch(ch)
    {
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '*':
        return a * b;
        break;
    case '/':
        assert(b != 0);
        return a / b;
        break;
    default:
        cerr << "WRONG OPERATOR !" << endl;
        return -1;
        break;
    }
}

// Make 24 game
// BASIC IDEA: permutation all the possible cases: A(4, 4) = 24;
//             Need 3 operators: 4 * 4 * 4 = 64;
//             All five possible adding parenthese:
//             (1) (A @ B) @ (C @ D)
//             (2) (A @ (B @ C) ) @ D
//             (3) ( (A @ B) @ C) @ D
//             (4) A @ ( ( B @ C) @ D)
//             (5) A @ ( B @ (C @ D) )
//             Total Possible cases: 24 * 64 * 5 = 7680, Brute Force 
// Input:  4 numbers in [1, 13], 
//         use '+','-','*','/' and '(',')' to make 24
// Output: If it is possible to make 24, output the expression
//         Else return -1;
// Notice: When calcalute x / y, need to assert (y != 0 && x % y == 0)
//         If Not, continue
string make24(int num1, int num2, int num3, int num4)
{
    vector<int> v(4, 0);
    v[0] = num1; v[1] = num2; v[2] = num3; v[3] = num4;
    sort(v.begin(), v.end());

    string ops("+-*/");

    do 
    {
        // The first parenthesis
        // (A @ B) @ (C @ D)
        for (size_t i = 0; i < ops.size(); ++i)
        {
            // A @ B
            char op1 = ops[i];
            if (op1 == '/' && (v[1] == 0 || v[0] % v[1] != 0)) continue;
            int ans1 = calculateBinaryExpression(v[0], v[1], op1);
            for (size_t j = 0; j < ops.size(); ++j)
            {
                // C @ D
                char op2 = ops[j];
                if (op2 == '/' && (v[3] == 0 || v[2] % v[3] != 0)) continue;
                int ans2 = calculateBinaryExpression(v[2], v[3], op2);

                for (size_t k = 0; k < ops.size(); ++k)
                {
                    // (A @ B) @ (C @ D)
                    char op3 = ops[k];
                    if (op3 == '/' && (ans2 == 0 || ans1 % ans2 != 0)) continue;
                    int ans = calculateBinaryExpression(ans1, ans2, op3);
                    if (ans == 24)
                    {
                        string str;
                        str.push_back('(');
                        str += to_string((long long)(v[0]));
                        str.push_back(op1);
                        str += to_string((long long)(v[1]));
                        str.push_back(')');
                        str.push_back(op3);
                        str.push_back('(');
                        str += to_string((long long)(v[2]));
                        str.push_back(op2);
                        str += to_string((long long)(v[3]));
                        str.push_back(')');
                        return str;
                    }
                }
            }
            
        }

        // The second parethesis
        // (A op2 (B op1 C)) op3 D
        for (size_t i = 0; i < ops.size(); ++i)
        {
            char op1 = ops[i];
            if (op1 == '/' && (v[2] == 0 || v[1] % v[2] != 0)) continue;
            int ans1 = calculateBinaryExpression(v[1], v[2], op1);
            for (size_t j = 0; j < ops.size(); ++j)
            {
                char op2 = ops[j];
                if (op2 == '/' && (ans1 == 0 || v[0] % ans1 != 0)) continue;
                int ans2 = calculateBinaryExpression(v[0], ans1, op2);
                for (size_t k = 0; k < ops.size(); ++k)
                {
                    char op3 = ops[k];
                    if (op3 == '/' && (v[3] == 0 || ans2 % v[3] != 0)) continue;
                    int ans = calculateBinaryExpression(ans2, v[3], op3);
                    if (ans == 24)
                    {
                        string str;
                        str.push_back('(');
                        str += to_string((long long)v[0]);
                        str.push_back(op2);
                        str.push_back('(');
                        str += to_string((long long)v[1]);
                        str.push_back(op1);
                        str += to_string((long long)v[2]);
                        str.push_back(')');
                        str.push_back(')');
                        str.push_back(op3);
                        str += to_string((long long)v[3]);
                        return str;
                    }
                }
            }
        }

        // The third parentheses
        // ( ( A op1 B) op2 C) op3 D
        for (size_t i = 0; i < ops.size(); ++i)
        {
            char op1 = ops[i];
            if (op1 == '/' && (v[1] == 0 || v[0] % v[1] != 0)) continue;
            int ans1 = calculateBinaryExpression(v[0], v[1], op1);
            for (size_t j = 0; j < ops.size(); ++j)
            {
                char op2 = ops[j];
                if (op2 == '/' && (v[2] == 0 || ans1 % v[2] != 0)) continue;
                int ans2 = calculateBinaryExpression(ans1, v[2], op2);
                for (size_t k = 0; k < ops.size(); ++k)
                {
                    char op3 = ops[k];
                    if (op3 == '/' && (v[3] == 0 || ans2 % v[3] != 0)) continue;
                    int ans = calculateBinaryExpression(ans2, v[3], op3);
                    if (ans == 24)
                    {
                        string str("((");
                        str += to_string((long long)v[0]);
                        str.push_back(op1);
                        str += to_string((long long)v[1]);
                        str.push_back(')');
                        str.push_back(op2);
                        str += to_string((long long)v[2]);
                        str.push_back(')');
                        str.push_back(op3);
                        str += to_string((long long)v[4]);
                        return str;
                    }
                }
            }
        }

        // The fourth parentheses
        // A op3 ( ( B op1 C ) op2 D)
        for (size_t i = 0; i < ops.size(); ++i)
        {
            char op1 = ops[i];
            if (op1 == '/' && (v[2] == 0 || v[1] % v[2] != 0)) continue;
            int ans1 = calculateBinaryExpression(v[1], v[2], op1);
            for (size_t j = 0; j < ops.size(); ++j)
            {
                char op2 = ops[j];
                if (op2 == '/' && (v[3] == 0 || ans1 % v[3] != 0)) continue;
                int ans2 = calculateBinaryExpression(ans1, v[3], op2);
                for (size_t k = 0; k < ops.size(); ++k)
                {
                    char op3 = ops[k];
                    if (op3 == '/' && (ans2 == 0 || v[0] % ans2 != 0)) continue;
                    int ans = calculateBinaryExpression(v[0], ans2, op3);
                    if (ans == 24)
                    {
                        string str;
                        str += to_string((long long)v[0]);
                        str.push_back(op3);
                        str += "((";
                        str += to_string((long long)v[1]);
                        str.push_back(op1);
                        str += to_string((long long)v[2]);
                        str.push_back(')');
                        str.push_back(op2);
                        str += to_string((long long)v[3]);
                        str.push_back(')');
                        return str;
                    }
                }
            }
        }
        
        // The fifth parenthese
        // A op3 ( B op2 ( C op1 D) );
        for (size_t i = 0; i < ops.size(); ++i)
        {
            char op1 = ops[i];
            if (op1 == '/' && (v[3] == 0 || v[2] % v[3] != 0)) continue;
            int ans1 = calculateBinaryExpression(v[2], v[3], op1);
            for (size_t j = 0; j < ops.size(); ++j)
            {
                char op2 = ops[j];
                if (op2 == '/' && (ans1 == 0 || v[1] % ans1 != 0)) continue;
                int ans2 = calculateBinaryExpression(v[1], ans1, op2);
                for (size_t k = 0; k < ops.size(); ++k)
                {
                    char op3 = ops[k];
                    if (op3 == '/' && (ans2 == 0 || v[0] % ans2 != 0)) continue;
                    int ans = calculateBinaryExpression(v[0], ans2, op3);
                    if (ans == 24)
                    {
                        string str;
                        str += to_string((long long)v[0]);
                        str.push_back(op3);
                        str.push_back('(');
                        str += to_string((long long)v[1]);
                        str.push_back(op2);
                        str.push_back('(');
                        str += to_string((long long)v[2]);
                        str.push_back(op1);
                        str += to_string((long long)v[3]);
                        str += "))";
                        return str;
                    }
                }
            }
        }

    } while(next_permutation(v.begin(), v.end()));

    return "-1";
}

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    string ans = make24(a, b, c, d);
    cout << ans << endl;
    return 0;
}
