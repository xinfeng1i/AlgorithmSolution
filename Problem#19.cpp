#include <iostream>
#include <string>

using namespace std;

bool isLeapYear(int year)
{
    if ( (year % 4 == 0 && year % 100 != 0) ||
            (year % 400 == 0) )
    {
        return true;
    }
    else
    {
        return false;
    }
}

class MyYear
{
private:
    bool isLeap;    // is a leap year or not
    int firstDay;   // 1 Jan is which day {Monday ... Sunday}
public:
    // constuctor
    MyYear(int year)
    {
        if (isLeapYear(year))
        {
            isLeap = true;
        }
        else
        {
            isLeap = false;
        }

        long tmp = 0;
        for (int i = 1900; i < year; i++)
        {
            if (isLeapYear(i))
            {
                tmp += 366;
            }
            else
            {
                tmp += 365;
            }
        }
        firstDay = (tmp % 7);
    }

    // destructor
    ~MyYear()
    {};

    int cntSundays() // count Sundays fell on the first of the month
    {
        int monthdays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int monthdays2[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (!isLeap)
        {
            int cnt = 0;
            if (firstDay == 6)
            {
                cnt++;
            }

            int days = 0;
            for (int i = 0; i < 11; i++)
            {
                days += monthdays[i];
                if ( (days % 7 + firstDay) % 7 == 6)
                {
                    cnt++;
                }
            }
            return cnt;
        }


        if (isLeap)
        {
            int cnt = 0;
            if (firstDay == 6)
            {
                cnt++;
            }

            int days = 0;
            for (int i = 0; i < 11; i++)
            {
                days += monthdays2[i];
                if ( (days % 7 + firstDay) % 7 == 6)
                {
                    cnt++;
                }
            }
            return cnt;
        }
    }
};

int main()
{
    int sum = 0;
    for (int i = 1901; i <= 2000; i++)
    {
        MyYear y(i);
        sum += y.cntSundays();
    }
    cout << "result: " << sum << endl;
    return 0;
}
