#include <iostream>
#include <string>
#include <vector>
using namespace std;

long calculateTime(const string& s)
{
    long h = (s[0] - '0') * 10 + (s[1] - '0');
    long m = (s[3] - '0') * 10 + (s[4] - '0');
    long sec = (s[6] - '0') * 10 + (s[7] - '0');
    return h * 3600 + m * 60 + sec;
}

int main()
{
    int M = 0;
    cin >> M;

    string minSignInIdNumber("");
    string minSignInTime("23:59:59");
    string maxSignOutIdNumber("");
    string maxSignOutTime("00:00:00");

    string idNumber;
    string signInTime;
    string signOutTime;
    for (int i = 0; i < M; ++i)
    {
        cin >> idNumber >> signInTime >> signOutTime;
        if (calculateTime(signInTime) < calculateTime(minSignInTime))
        {
            minSignInTime = signInTime;
            minSignInIdNumber = idNumber;
        }
        if (calculateTime(signOutTime) > calculateTime(maxSignOutTime))
        {
            maxSignOutTime = signOutTime;
            maxSignOutIdNumber = idNumber;
        }
    }
    cout << minSignInIdNumber << " " << maxSignOutIdNumber << endl;
    return 0;
}
