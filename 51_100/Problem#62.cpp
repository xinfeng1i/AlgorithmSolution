#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <map>

using namespace std;

/*
 * return the hash of n, convert n to string,
 * string is in the accending order
 */
string hashNumber(long long n)
{
    string str_n = to_string(n);
    sort(str_n.begin(), str_n.end());
    return str_n;
}

int main()
{
    // hash table: hashAddress of n -> number chains with the same key
    map<string, vector<long long> > cntPerts;
    for (long long i = 345; i <= 10000; ++i)
    {
        long long num = i * i * i;
        string address = hashNumber(num);
        cntPerts[address].push_back(num);
    }

    for (auto it = cntPerts.begin(); it != cntPerts.end(); ++it)
    {
        if ((it->second).size() == 5)
        {
            for (auto itt = (it->second).begin(); itt != (it->second).end(); ++itt)
            {
                cout << *itt << " ";
            }
            cout << endl;
        }
    }

    return 0;
}

/// Rethink: Why does hash quick ?
/// what I use before this mothod is : put all the cubics numbers in a vector
/// like:
///         345 * 345 * 345
///         346 * 346 * 346
///         347 * 347 * 347
///         ...   ...   ...
///         10000 * 10000 * 10000
/// So if I want to know all the numbers with the same key with 345*345*345,
/// I have to search all the list, to judge if they have the same key, whose
/// Complexity is O(n(n-1)) = O(n^2), calculate the hash address of one
/// specific value many times, which is a waste of time
///
/// With hash method, the list would like this:
///         345*345*345     384*384*384     405*405*405
/// calculate hash address of every value once, which save us a lot of time
/// constuct the hash table use O(n), find the specific key O(n), So all of
/// time is O(n) + O(n) = O(n)
/// That's it ! 
