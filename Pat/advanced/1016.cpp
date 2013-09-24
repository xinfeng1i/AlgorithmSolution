#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class dateTime
{
private:
    int month_;
    int date_;
    int hour_;
    int minute_;
public:
    explicit dateTime(const string& s)
    {
        month_ = 10 * (s[0] - '0') + (s[1] - '0');
        date_ = 10 * (s[3] - '0') + (s[4] - '0');
        hour_ = 10 * (s[6] - '0') + (s[7] - '0');
        minute_ 10 * (s[9] - '0') + (s[10] - '0');
    }

    ~dateTime()
    {}

    bool operator<(const dateTime& rhs) const
    {
        if (month_ < rhs.month_)
        {
            return true;
        }
        else if (month_ > rhs.month_)
        {
            return false;
        }
        else if (month_ == rhs.month_)
        {
            if (date_ < rhs.date_)
            {
                return true;
            }
            else if (date_ > rhs.date_)
            {
                return false;
            }
            else if (date_ == rhs.date_)
            {
                if (hour_ < rhs.hour_)
                {
                    return true;
                }
                else if (hour_ > rhs.hour_)
                {
                    return false;
                }
                else if (hour_ == rhs.hour_)
                {
                    if (minute_ < rhs.minute_)
                    {
                        return true;
                    }
                    else if (minute_ >= rhs.minute_)
                    {
                        return false;
                    }
                }
            }
        }
    }

    bool operator==(const dateTime& rhs) const
    {
        return (month_ == rhs.month_ && date_ == rhs.date_ &&
                hour_ == rhs.hour_ && minute_ == rhs.minute_);
    }

    // return time_different
    int substractTime(const dateTime& beg) const
    {
        if (date_ == beg.date_)
        {
            return (hour_ * 24 + minute_) - (beg.hour_ * 24 + beg.minute_);
        }
        else if(date_ > beg.date_)
        {
            return (((date_ - beg.date_) * 1440 + hour_ * 24 + minute_)
                   - (beg.hour_ * 24 + beg.minute_));
        }
    }
};

struct phoneRecord
{
    string name_;
    string time_;
    string state_;

    bool operator<(const phoneRecord& rhs) const
    {
        if (name_ < rhs.name_)
        {
            return true;
        }
        else if (name_ > rhs.name_)
        {
            return false;
        }
        else
        {
            if (dateTime(time_) < dateTime(rhs.time_))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
};

int caculateToll(dateTime beg_time, int total_time, int a[24])
{
}

int main()
{
    int toll[24];
    for (int i = 0; i < 24; ++i)
    {
        cin >> toll[i];
    }

    int numRecord = 0;
    cin >> numRecord;

    vector<phoneRecord> list(numRecord);
    for (int i = 0; i < numRecord; ++i)
    {
        cin >> list[i].name_ >> list[i].time_ >> list[i].state;
    }

    sort(list.begin(), list.end());

    int sz = list.size();
    int cur = 0;
    while (cur < sz)
    {
        int next = cur + 1;
        while (list[next].name_ == list[cur].name_)
        {
            next++;
        }

        cout << list[cur].name_ << " " << (list[cur].time_).substr(0, 2) << endl;

        for (int i = cur; i < next; ++i)
        {
            if (list[i].state_ == "on-line" && list[i+1].state_ == "off-line")
            {
                dateTime beg_time(list[i].time_);
                dateTime end_time(list[i+1].time_);
                int total_time = end_time.substractTime(beg_time);
                cout << (list[i].time_).substr(3,8) << " "
                     << (list[i+1].time_).substr(3, 8) << " ";
                // ToDo: print total time and total fee
            }
        }

        // TODO: print totoal fee
        cout << "Total amount: " << "$" << ;
    }
}
