#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int rate[24];

class timeDate
{
public:
    int month_;
    int day_;
    int hour_;
    int minute_;
public:
    timeDate(string time)
    {
        month_ = (time[0] - '0') * 10 + (time[1] - '0');
        day_ = (time[3] - '0') * 10 + (time[4] - '0');
        hour_ = (time[6] - '0') * 10 + (time[7] - '0');
        minute_ = (time[9] - '0') * 10 + (time[10] - '0');
    }
    timeDate():month_(0), day_(0), hour_(0), minute_(0)
    {}
    
    void printTime()
    {
        printf("%02d:%02d:%02d:%02d\n", month_, day_, hour_, minute_);
    }

    friend bool operator<(const timeDate& a, const timeDate& b);
    friend bool operator==(const timeDate& a, const timeDate& b);
    friend bool operator!=(const timeDate& a, const timeDate& b);
};

bool operator<(const timeDate& a, const timeDate& b)
{
    if (a.month_ != b.month_)
    {
        return a.month_ < b.month_;
    }
    else
    {
        if (a.day_ != b.day_)
        {
            return a.day_ < b.day_;
        }
        else
        {
            if (a.hour_ != b.hour_)
            {
                return a.hour_ < b.hour_;
            }
            else
            {
                return a.minute_ < b.minute_;
            }
        }
    }
}

bool operator==(const timeDate& a, const timeDate& b)
{
    return (a.month_ == b.month_ && a.day_ == b.day_ &&
            a.hour_ == b.hour_ && a.minute_ == b.minute_);
}

bool operator!=(const timeDate& a, const timeDate& b)
{
    return !(a==b);
}

struct Record
{
    string name_;
    timeDate time_;
    string state_;
};

bool cmpRecord(const Record& a, const Record& b)
{
    if (a.name_ != b.name_)
    {
        return a.name_ < b.name_;
    }
    else
    {
        return a.time_ < b.time_;
    }
}

double computeFee(const Record& a, const Record& b)
{
    double cost = 0.0;
    timeDate t1 = a.time_;
    timeDate t2 = b.time_;
    if (t1.day_ == t2.day_ && t1.hour_ == t2.hour_)
    {
        return (double)(t2.minute_ - t1.minute_) * rate[t1.hour_ % 24] / 100.0;
    }
    else if (t1.day_ == t2.day_ && t1.hour_ != t2.hour_)
    {
        if (t1.minute_ != 0)
        {
            cost += rate[t1.hour_ % 24] / 100.00  * (double)(60 - t1.minute_);
            t1.hour_ += 1;
        }
        if (t2.minute_ != 0)
        {
            cost += rate[t2.hour_ % 24] / 100.00  * (double)t2.minute_;
        }
        if (t1.hour_ != t2.hour_)
        {
            for (int k = t1.hour_; k < t2.hour_; ++k)
            {
                cost += rate[k % 24] / 100.00 * 60;
            }
        }

        return cost;
    }
    else if (t1.day_ != t2.day_)
    {
        while (t2.day_ != t1.day_)
        {
            t2.day_--;
            t2.hour_ += 24;
        }
        Record x, y;
        x.name_ = "AAA";
        y.name_ = "AAA";
        x.time_ = t1;
        y.time_ = t2;
        x.state_ = "on-line";
        y.state_ = "off-line";
        return computeFee(x, y);
    }
}

long computeDiffTime(const Record& a, const Record& b)
{
    timeDate t1 = a.time_;
    timeDate t2 = b.time_;
    long x1 = (24 * t1.day_ + t1.hour_) * 60 + t1.minute_;
    long x2 = (24 * t2.day_ + t2.hour_) * 60 + t2.minute_;
    return x2 - x1;
}

int main()
{
    //freopen("1016data.txt", "r", stdin);

    for (int i = 0; i < 24; ++i)
    {
        cin >> rate[i];
    }

    int n;
    cin >> n;
    vector<Record> v(n);
    string name, time, state;
    for (int i = 0; i < n; ++i)
    {
        cin >> name >> time >> state;
        v[i].name_ = name;
        v[i].time_ = timeDate(time);
        v[i].state_ = state;
    }

    sort(v.begin(), v.end(), cmpRecord);

    int ibegin = 0;
    int iend = 0;
    while (ibegin < n)
    {
        iend = ibegin;
        while (iend < n && v[iend].name_ == v[ibegin].name_)
        {
            iend++;
        }
        
        double totalcost = 0.0;
        long totaldiffTime = 0;
        
        // judge whether this client has at least one valid pair
        // if not, print nothing, continue to next loop
        // else print the phone bills as sample
        bool hasValidPair = false;
        for (int k = ibegin; k < iend - 1; ++k)
        {
            if (v[k].state_ == "on-line" && v[k+1].state_ == "off-line")
            {
                hasValidPair = true;
            }
        }
        if (hasValidPair)
        {
            cout << v[ibegin].name_  << " " << time.substr(0, 2) << endl;
            for (int k = ibegin; k < iend - 1; )
            {
                if (v[k].state_ == "on-line" && v[k+1].state_ == "off-line")
                {
                    // compute and output
                    double curcost = computeFee(v[k], v[k+1]);
                    long curdiffTime = computeDiffTime(v[k], v[k+1]);

                    totalcost += curcost;
                    totaldiffTime += curdiffTime;

                    printf("%02d:%02d:%02d ", 
                            v[k].time_.day_, v[k].time_.hour_, v[k].time_.minute_);
                    printf("%02d:%02d:%02d ",
                            v[k+1].time_.day_, v[k+1].time_.hour_, 
                            v[k+1].time_.minute_);

                    printf("%ld ", curdiffTime);
                    printf("$%0.2f\n", curcost);

                    k += 2;
                }
                else
                {
                    k++; 
                }
            }

            printf("Total amount: $%0.2f\n", totalcost);
        }

        ibegin = iend;

    }
    return 0;
}
