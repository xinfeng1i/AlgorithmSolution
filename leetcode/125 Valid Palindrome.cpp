#include "MyHeader.h"

bool isPalindrome(string s)
{
    int n = s.size();
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        // skip non-alpha and non-digit
        if ( !isalpha(s[i]) && !isdigit(s[i]) )
        {
            i++;
            continue;
        }

        if ( !isalpha(s[j]) && !isdigit(s[j]) )
        {
            j--;
            continue;
        }
        
        if ( isalpha(s[i]) && isalpha(s[j]) )
        {
            if (toupper(s[i]) != toupper(s[j]))
            {
                return false;
            }
            else
            {
                i++;
                j--;
            }
        }
        else if ( isdigit(s[i]) && isdigit(s[j]) )
        {
            if (s[i] != s[j])
            {
                return false;
            }
            else
            {
                i++;
                j--;
            }
        }
        else
        {
            return false;
        }

    }

    return true;
}