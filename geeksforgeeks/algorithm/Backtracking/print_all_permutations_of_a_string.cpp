#include <iostream>
#include <string>
using namespace std;

// method 1
void PrintPermutations(string sofar, string rest)
{
    if (rest == "") 
    {
        cout << sofar << endl;
        return;
    }

    for (size_t i = 0; i < rest.size(); ++i)
    {
        string sofar1 = sofar + string(1, rest[i]);
        string remain = rest.substr(0, i) + rest.substr(i+1);
        PrintPermutations(sofar1, remain);
    }
    
    return;
}

void PrintAllPermutations(const string& s)
{
    PrintPermutations("", s);
}


// Method2: backtracking
void myPermutation(string s, int cur, int n)
{
    if (cur >= n - 1)
    {
        cout << s << endl;
        return;
    }
    
    for (int i = cur; i < n; ++i)
    {
        swap(s[i], s[cur]);
        myPermutation(s, cur+1, n);
        swap(s[i], s[cur]);
    }
    return;
}

int main()
{
    string s;
    cin >> s;
    myPermutation(s, 0, s.size());
    return 0;
}
