#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// even the board is 1000000 * 1000000, if could reach, the max
// step cannot beyond 1000000;
// so the cannot reachabily can be define more than 1000000
const int INF = 1000000;
int n, m, x, y, a, b;

int check(int tx, int ty)
{
    // if destination (tx, ty) == source (x, y)
    // then move 0 step
    if (tx == x && ty == y) return 0;

    // if there is no step in row direction, then 
    // then (x, Y) cannot move even one step
    // so is in the column direction
    if (x - a < 1 && x + a > n) return INF;
    if (y - b < 1 && y + b > m) return INF;

    int dx = abs(tx - x);
    int dy = abs(ty - y);
    
    // if the dx cannot be divisible by a
    // or the dy cannot be divisible dy b
    if (dx % a != 0 || dy % b != 0) return INF;

    int k1 = dx / a;
    int k2 = dy / b;
    // the row direction dx / a must have the same
    // even or odd with the direction dy / b, if not, cannot reach.
    if (k1 % 2 != k2 % 2) return INF;

    return max(k1, k2);
}


int main()
{
    cin >> n >> m >> x >> y >> a >> b;
    int ans = INF;
    ans = min(ans, check(1, 1));
    ans = min(ans, check(n, 1));
    ans = min(ans, check(1, m));
    ans = min(ans, check(n, m));
    if (ans == INF)
    {
        cout << "Poor Inna and pony!" << endl;
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}

// Summary:
// This is the finally version of chess board, next time 
// this problem cannot be unsolved.
