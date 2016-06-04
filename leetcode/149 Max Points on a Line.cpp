#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};


int GCD(int a, int b) {
    if (b == 0) return a;
    else return GCD(b, a%b);
}

struct cmp {
	bool operator() (const Point& a, const Point& b) const  {
		if (a.x != b.x) return a.x < b.x;
		else return a.y < b.y;
	}
};

inline vector<int> LinebyTwoPoints(Point a, Point b) {
    int A = b.y - a.y;
    int B = a.x - b.x;
    int C = b.x * a.y - a.x * b.y;
    
   // cout << " A = " << A;
   // cout << " B = " << B;
   // cout << " C = " << C << endl;
    
    if (A != 0 && B != 0 && C != 0) {	
	    int d = GCD(GCD(A, B), C);
	    A /= d; B /= d; C /= d;
    } else if (A == 0 && C == 0 && B != 0) {
    	B = 1;
	} else if (B == 0 && C == 0 && A != 0) {
		A = 1;
	} else if (C == 0 && A != 0 && B != 0) {
		int d = GCD (A, B);
		A /= d; B /= d;
	} else if (A == 0 && B != 0 && C != 0) {
		int d = GCD(B, C);
		B /= d; C /= d;
	} else if (B == 0 && A != 0 && C != 0) {
		int d = GCD(A, C);
		A /= d; C /= d;
	}
    vector<int> ans;
    ans.push_back(A);
    ans.push_back(B);
    ans.push_back(C);
    //cout << "after norm:" << endl;
   // cout << "\t A = " << A;
    //cout << "\t B = " << B;
    //cout << "\t C = " << C << endl;
    return ans;
}
int maxPoints(vector<Point>& points) {
	if (points.size() <= 1) return points.size();
    map<vector<int>, set<Point, cmp>> tb;
    int n = (int) points.size();
    
    map<Point, int, cmp> p_cnt;
    for (int i = 0; i < n; ++i) {
    	p_cnt[points[i]]++;
	}
    
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
        	if (!(points[i].x == points[j].x && points[i].y == points[j].y)) {
	            vector<int> line = LinebyTwoPoints(points[i], points[j]);
	            tb[line].insert(points[i]);
	            tb[line].insert(points[j]);
            }
        }
    }
    
    int cnt = 0;
    for (auto it = tb.begin(); it != tb.end(); ++it) {
    	int temp = 0;
    	for (auto p : it->second) {
    		temp += p_cnt[p];
		}
        cnt = max(cnt, temp);
    }
    //cout << "now cnt = " << cnt << endl;
    
    for (auto it = p_cnt.begin(); it != p_cnt.end(); ++it) {
    	cnt = max(cnt, it->second);
	}
    
    return cnt;
}

int main()
{
	Point p1, p2, p3;
	p1.x = 0; p1.y = 0;
	p2.x = 1; p2.y = 1;
	p3.x = 0; p3.y = 0;
	
	vector<Point> v;
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	
	int ans = maxPoints(v);
	cout << "ans = " << ans << endl;
	return 0;
}
