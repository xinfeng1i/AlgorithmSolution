#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

struct Point
{
    long long x;
    long long y;

    Point(long long xx, long long yy):x(xx), y(yy){}
    Point():x(0), y(0){}
    ~Point(){}

    bool operator<(const Point& other) const
    {
    if ((x * x + y * y) < (other.x * other.x + other.y * other.y))
    {
        return true;
    }
    else if ((x * x + y * y) == (other.x * other.x + other.y * other.y))
    {
        if (abs(x) < abs(other.x))
        {
            return true;
        }
        else if (abs(x) == abs(other.x))
        {
            if (x != other.x)
            {
                return x > other.x;
            }
            else
            {
                if (abs(y) < abs(other.y))
                {
                    return true;
                }
                else if (abs(y) == abs(other.y))
                {
                    return y > other.y;
                }
                else
                {
                    return false;
                }
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
    }
};

void moveRight(long long r)
{
    cout << 1 << " " << r << " " << "R" << endl;
}
void moveLeft(long long l)
{
    cout << 1 << " " << l << " " << "L" << endl;
}
void moveUp(long long u)
{
    cout << 1 << " " << u << " " << "U" << endl;
}
void moveDown(long long d)
{
    cout << 1 << " " << d << " " << "D" << endl;
}
void pickUp()
{
    cout << 2 << endl;
}
void putDown()
{
    cout << 3 << endl;
}

int diffZero(long long x)
{
    if (x != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    long n = 0;
    cin >> n;
    set<Point> points;
    long long sumXY = 0;
    for (long i = 0; i < n; ++i)
    {
        Point tmp;
        cin >> tmp.x >> tmp.y;
        sumXY += diffZero(tmp.x) + diffZero(tmp.y);
        points.insert(tmp);
    }

    //sort(points.begin(), points.end());
    //cout << "size: " << points.size() << endl;
    //cout << "Output: " << endl;
    cout << 2 * n + 2 * sumXY << endl; 
    for (auto it = points.begin(); it != points.end(); ++it)
    {
        if (it->y == 0 && it->x > 0)
        {
            moveRight(it->x);
            pickUp();
            moveLeft(it->x);
            putDown();
        }
        else if (it->y == 0 && it->x < 0)
        {
            moveLeft(-it->x);
            pickUp();
            moveRight(-it->x);
            putDown();
        }
        else if (it->x == 0 && it->y > 0)
        {
            moveUp(it->y);
            pickUp();
            moveDown(it->y);
            putDown();
        }
        else if (it->x == 0 && it->y < 0)
        {
            moveDown(-it->y);
            pickUp();
            moveUp(-it->y);
            putDown();
        }
        else if (it->x > 0 && it->y > 0)
        {
            moveRight(it->x);
            moveUp(it->y);
            pickUp();
            moveDown(it->y);
            moveLeft(it->x);
            putDown();
        }
        else if (it->x < 0 && it->y > 0)
        {
            moveLeft(-it->x);
            moveUp(it->y);
            pickUp();
            moveDown(it->y);
            moveRight(-it->x);
            putDown();
        }
        else if (it->x < 0 && it->y < 0)
        {
            moveLeft(-it->x);
            moveDown(-it->y);
            pickUp();
            moveUp(-it->y);
            moveRight(-it->x);
            putDown();
        }
        else if (it->x > 0 && it->y < 0)
        {
            moveRight(it->x);
            moveDown(-it->y);
            pickUp();
            moveUp(-it->y);
            moveLeft(it->x);
            putDown();
        }
    }

    return 0;
}
