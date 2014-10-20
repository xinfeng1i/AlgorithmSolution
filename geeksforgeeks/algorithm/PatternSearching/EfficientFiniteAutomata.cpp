#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int CHARACTER_NUMBER = 256;
// TODO CANNOT Figure OUT the logic behind the method
vector<vector<int> > BuildTransmissionTable(const string& Pat)
{
    int m = Pat.size();
    vector<vector<int> > table(m+1, vector<int>(CHARACTER_NUMBER, 0));
    // fill the first row
    int x = Pat[0];
    table[0][x] = 1;

    // 
    int lps = 0;
    for (int i = 1; i <= m; ++i)
    {
        // copy values from row whose index is lps to current row
        for (int x = 0; x < CHARACTER_NUMBER; ++x)
        {
            table[i][x] = table[lps][x];
        }

        // update the entry correspoding to this character
        // NOTICE: This Step may NOT RIGNT. if i == m, then Pat[m] will
        // be out of range
        table[i][Pat[i]] = i + 1;

        // update lps for next row filled
        if (i < m)
        {
            lps = table[lps][Pat[i]];
        }
    }

    return table;
}

// Pat search is same with the previous one
void EfficientFASearch(const string& txt, const string& Pat)
{
    int n = txt.size();
    int m = Pat.size();

    vector<vector<int> > table = BuildTransmissionTable(Pat);
    int q = 0;
    for (int i = 0; i < n; ++i)
    {
        int x = txt[i];
        q = table[q][x];
        if (q == m)
        {
            cout << "Pattern Found At Index " << i - m + 1 << endl;
        }
    }
    return;
}

int main()
{
    string txt = "GEEKS FOR GEEKS";
    string Pat = "GEEKS";
    EfficientFASearch(txt, Pat);
    return 0;
}
