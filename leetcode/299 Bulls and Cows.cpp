#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string getHint(string secret, string guess)
{
    string s1 = "";
    string s2 = "";
    vector<int> cnt1(10, 0);
    vector<int> cnt2(10, 0);
    int nBulls = 0;
    int nCows = 0;
    int n = secret.size();
    for (int i = 0; i < n; ++i){
        if (secret[i] == guess[i]) {
            nBulls++;
        } else {
            cnt1[ secret[i] - '0' ] += 1;
            cnt2[ guess[i] - '0'] += 1;
        }
    }
    
    for (int i = 0; i < 10; ++i) {
        int temp = min(cnt1[i], cnt2[i]);
        if (temp == 0) {
            continue;
        } else {
            nCows += temp;
        }
    }

    char ans[10000] = {'\0'};
    sprintf(ans, "%dA%dB", nBulls, nCows);
    return string(ans);
}

int main()
{
    string s1 = "1123";
    string s2 = "0111";
    cout << getHint(s1, s2) << endl;
    return 0;
}
