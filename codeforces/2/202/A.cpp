#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    long n;
    cin >> n;
    vector<int> v(n, 0);
    for (long i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    map<int, int> cnt;
    cnt.insert(pair<int,int>(25, 0));
    cnt.insert(pair<int,int>(50, 0));
    cnt.insert(pair<int,int>(100,0));


    for (long i = 0; i < n; ++i)
    {
        switch(v[i])
        {
            case 25: cnt[25]++;
                     break;
                     
            case 50: cnt[50]++;
                     cnt[25]--;
                     if (cnt[25] < 0)
                     {
                        cout << "NO" << endl;
                        return 0;
                     }
                     break;

            case 100: cnt[100]++;
                      if (cnt[25] < 1)
                      {
                        cout << "NO" << endl;
                        return 0;
                      }

                      if (cnt[50] >= 1)
                      {
                        cnt[50]--;
                        cnt[25]--;
                      }
                      else
                      {
                          if (cnt[25] >= 3)
                          {
                            cnt[25] -= 3;
                          }
                          else
                          {
                            cout << "NO" <<endl;
                            return 0;
                          }
                      }
                      break;
        }
    }

    cout << "YES" << endl;
    
    return 0;
}
