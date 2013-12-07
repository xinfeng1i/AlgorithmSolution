#include <iostream>
#include <string>
#include <vector>

/**
 * A more concise algorithm: recursion
 * 
 * If has s[i]=s[i+1], recusively return the remainder string s,
 * else return s // base case
 */
string simulate(string s)
{
    for (size_t i = 0; i + 1 < s.size(); ++i)
    {
        if (s[i] == s[i + 1])
        {
            return simulate(s.substr(0, i), s.substr(i+2));
        }
    }

    return s;
}
