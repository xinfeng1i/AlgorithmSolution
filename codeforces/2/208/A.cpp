#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

struct Circle
{
    double center_;
    double radius_;
};

int main()
{
    int n = 0;
    cin >> n;
    vector<long> v(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    vector<Circle> circles(n - 1);
    for (int i = 0; i < n - 1; ++i)
    {
        circles[i].center_ = (v[i] + v[i+1]) / 2.0;
        circles[i].radius_ = abs(v[i] - v[i+1]) / 2.0;
    }

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n -1; ++j)
        {
            double tmpd = abs(circles[i].center_ - circles[j].center_);
            if (tmpd > abs(circles[i].radius_ - circles[j].radius_) && 
                tmpd < circles[i].radius_ + circles[j].radius_)
            {
                cout << "yes" << endl;
                return 0;
            }
        }
    }

    cout << "no" << endl;
    return 0;

}
