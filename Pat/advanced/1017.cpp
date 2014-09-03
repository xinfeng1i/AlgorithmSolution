#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

struct mytime
{
    int hh_;
    int mm_;
    int ss_;

// costructor
    mytime(){}
    mytime(int hh, int mm, int ss):hh_(hh), mm_(mm), ss_(ss){} 

// operator< overload
    bool operator<(const mytime& y) const
    {
        if (hh_ != y.hh_)
        {
            return hh_ < y.hh_;
        }
        else if (mm_ != y.mm_)
        {
            return mm_ < y.mm_;
        }
        else
        {
            return ss_ < y.ss_;
        }
    }
// operator overload
    friend double operator-(const mytime& a, const mytime& b);
    friend mytime operator+(const mytime& a, double b);
};

double operator-(const mytime& a, const mytime& b)
{
    double ans = 0.0;
    int x = a.hh_ * 3600 + a.mm_ * 60 + a.ss_;
    int y = b.hh_ * 3600 + b.mm_ * 60 + b.ss_;
    ans = (x - y) / 60.0;
    return ans;
}

mytime operator+(const mytime& a, double b)
{
    mytime ans;

    /*
    int minutes = floor(b);
    int seconds = (b - minutes) * 60;

    ans.ss_ = (a.ss_ + seconds) % 60;
    int remain_mm = (a.ss_ + seconds) / 60;
    ans.mm_ = (a.mm_ + minutes + remain_mm) % 60;
    int remain_hh = (a.mm_ + minutes + remain_mm) / 60;
    ans.hh_ = a.hh_ + remain_hh;
    */
    int minutes = floor(b);
    ans.ss_ = a.ss_;
    ans.mm_ = (a.mm_ + minutes) % 60;
    ans.hh_ = a.hh_ + (a.mm_ + minutes) / 60;

    return ans;
}

struct customer
{
    mytime arriveTime_;
    double processTime_;

    bool operator< (const customer& y) const
    {
        return arriveTime_ < y.arriveTime_;
    }
};

const mytime open_time(8, 0, 0);
const mytime close_time(17, 0, 0); 

// 判断当前顾客是否需要等待
// 如果不需要，返回可以立即服务的窗口编号
// 如果需要，返回等待时间最少的窗口编号
bool needWait(vector<mytime>& windows, const mytime& arrive_time, int& w_index)
{
    int earlist_window = 0;
    mytime earlist_time(24, 0, 0);
    for (size_t i = 0; i < windows.size(); ++i)
    {
        // windows[i] <= arrive_time 不需要等
        if (!(arrive_time < windows[i]))
        {
            w_index = i;
            return false;
        }

        // 更新最快可以服务的窗口
        if (windows[i] < earlist_time)
        {
            earlist_time = windows[i];
            earlist_window = i;
        }
    }
    
    w_index = earlist_window;
    return true;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n, k;
    scanf("%d %d", &n, &k);
    
    deque<customer> q(n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d:%d:%d %lf", &q[i].arriveTime_.hh_,
                             &q[i].arriveTime_.mm_,
                             &q[i].arriveTime_.ss_,
                             &q[i].processTime_);
    }

    sort(q.begin(), q.end());

    vector<mytime> windows(k, open_time);

    double waiting_time = 0.0;
    int waiting_cnt = 0;

    while (!q.empty())
    {
        customer cur = q.front();
        q.pop_front();

        // 过期达到客户，跳过
        if (close_time < cur.arriveTime_)
        {
            continue;
        }
        int wid = -1;
        bool flag = needWait(windows, cur.arriveTime_, wid);

        // 需要等待，更新等待时间
        // 并且更新窗口可用时间      窗口时间 > 顾客时间
        if (flag)
        {
            waiting_time += (double)(windows[wid] - cur.arriveTime_);
            windows[wid] = windows[wid] + cur.processTime_;
            waiting_cnt++;
        }
        // 不需要等待，直接更新窗口的可用时间 窗口时间 <= 顾客时间
        else 
        {
            windows[wid] = cur.arriveTime_ + cur.processTime_;
            waiting_cnt++;
        }
    }

    if (waiting_cnt == 0)
    {
        waiting_time = 0.0;
        printf("0.0\n");
    }
    else
    {
        waiting_time = waiting_time / waiting_cnt;
        printf("%.1f\n", waiting_time);
    }
    return 0;
}
