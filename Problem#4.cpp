#include <iostream>
#include <string>

using namespace std;

/*
 * Judge whether 'n' is a Palindrome
 */
bool isPalindrome(const long long n)
{
    string str_n = to_string(n);
    cout << "to String is :" << str_n << endl;
    int begin = 0;
    int end = str_n.size() - 1;
    while (begin <= end && str_n[begin] == str_n[end])
    {
        begin++;
        end--;
    }

    if (begin > end)
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool isPalindromeRecursively(long long n)
{
    string str_n = to_string(n);

    // base case
    if (str_n.empty())
    {
        return true;
    }


}

int main()
{
    //cout << "1 is Prime ? " << isPalindrome(1) << endl;
    //cout << "3 is Palindrome ? " << isPalindrome(3) << endl;
    //cout << "12 is Palindrome? " << isPalindrome(12) << endl;
    //cout << "33 is Palindrome? " << isPalindrome(33) << endl;
    //cout << "234 is Palindrome? " << isPalindrome(234) << endl;
    //cout << "353 is Palindrome? " << isPalindrome(353) << endl;
    //cout << "999 is Palindrome? " << isPalindrome(999) << endl;
    string s("ab");
    cout << "s size:" << s.size() << endl;
    size_t begin = 0;
    size_t end = s.size() - 1;
    string sub = s.substr(begin, s.size() - 2);
    cout << "sub:" << sub << endl;
    return 0;
}
