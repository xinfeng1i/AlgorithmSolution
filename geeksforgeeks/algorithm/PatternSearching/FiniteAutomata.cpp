#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int ALPHABETA_SIZE = 256;
/*
 * The FA currently at state q, q \in [0, m], current character is x
 * Return the next state according to the Tramission Table
 * \delta(q, x) = \sigma (qx)
 * -------
 * The FA at state q, which means it has step over q character of Pattern
 * so It expect the next character is the (q+1)th character of Pattern,
 * which stored in Pat[q]
 */
int getNextState(const string& Pat, int q, int x)
{
    int m = Pat.size();
    // if the next character is exactly which it expects, return;
    if (q < m && x == Pat[q])
    {
        return q + 1;
    }

    // otherwise, the current character x is not equal to the expected
    // Pat[q], so we need shift the Pat to right, which means x may
    // equal to some Pat[ns], ns \in [0, q-1].
    // If x = some Pat[ns], ns \in [0, q-1], we must further check 
    // whether all the pos before ns is matched, if it is, which
    // means [0...ns] can all matched, so we return ns + 1;
    for (int ns = q - 1; ns >= 0; --ns)
    {
        if (x == Pat[ns])
        {
            bool prevMatched = true;
            for (int i = 0; i < ns; ++i)
            {
                if (Pat[i] != Pat[q-ns+i])
                {
                    prevMatched = false;
                    break;
                }
            }
            if (prevMatched) return ns + 1;
        }
    }
    
    return 0;
}

/*
 * Compute the Transmission Table base on get Next State Function
 */
vector<vector<int> > ComputeTransmissionTable(const string& Pat)
{
    int m = Pat.size();
    vector<vector<int> > table(m+1, vector<int>(ALPHABETA_SIZE, 0));
    for (int q = 0; q <= m; ++q)
    {
        for (int x = 0; x < ALPHABETA_SIZE; ++x)
        {
            table[q][x] = getNextState(Pat, q, x);
        }
    }
    return table;
}

/*
 * FA Pattern Match Algorithm
 * First Preprocess: build the transmission table
 */
void FAPatternMatch(const string& txt, const string& Pat)
{
    int n = txt.size();
    int m = Pat.size();

    vector<vector<int> > table = ComputeTransmissionTable(Pat);
    int q = 0;
    for (int i = 0; i < n; ++i)
    {
        int x = txt[i];  
        q = table[q][x];
        if (q == m)
        {
            cout << "Pattern Found At Index: " << i + 1 - m << endl;
        }
    }
}

int main()
{
    cout << "\n\n*****TEST CASE 1*****" << endl;
    string txt = "AABAACAADAABAAABAA";
    string Pat = "AABA";
    FAPatternMatch(txt, Pat);

     
    cout << "\n\n*****TEST CASE 2*****" << endl;
    string txt2 = "THIS IS A TEST TEXT";
    string Pat2 = "TEST";
    FAPatternMatch(txt2, Pat2);
    return 0;
}
