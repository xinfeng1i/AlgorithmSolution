#include <iostream>
#include <string>
#include <cmath>
using namespace std;

typedef long long llong;
int main()
{
	long long n, a, b;
	cin >> n >> a >> b;

	if (a * b >= 6 * n)
	{
		cout << a * b << endl;
		cout << a << " " << b << endl;
		return 0;
	}


	// mid是面积几何均值+1，如果a,b同时大于mid, 则必然有a*b > 6*n;
	long long mid = (long long)ceil(sqrt(6.0 * n));
	//cout << "mid:" << mid << endl;

	// if 条件保证了a，b中至少有一个值小于mid
	bool isSwap = false;
	if (a > b)
	{
		swap(a, b);
		isSwap = true;
	}
	
	// 此时a必然小于等于mid
	long long ans = 1000000000000000000LL;
	long long ansa = 0;
	long long ansb = 0;
	// 对于增加后的a可能取的所有值，计算满足a*b >= 6*n的最小b
	// 得到合法的a,b后，更新ans的值
	for (long long newa = a; newa <= mid; ++newa)
	{
		long long newb = (long long)ceil(n * 6.0 / newa);
		//cout << "newa : " << newa << endl;
		//cout << "newb : " << newb << endl;
		if (newb >= b && newa * newb < ans)
		{
			ans = newa * newb;
			ansa = newa;
			ansb = newb;
		}
	}

	if (isSwap)
	{
		swap(ansa, ansb);
	}

	cout << ans << endl;
	cout << ansa << " " << ansb << endl;
	return 0;
}

/* 
 * 总结：数学题，暴力法解决
 * 从目前的情况来看，数学题目还是比较不擅长，此题目实际上是一个二元一次约束
 * 不等式，对于两个变量一个限制条件的情况来说，除了枚举似乎没有更好的方式解决
 * 当然我们可以枚举其中一个变量的合法取值，然后在约束条件下计算出第二个变量
 * 的合法取值，在根据目标函数来确定这组变量是否是所需变量
 *
 * 以前好像还碰过一道类似的题目，直接枚举从开始一直到最大上线的情况，应该和这
 * 是一类题目，这算是二次踩坑了。下次碰到类似的题目一定不能再错了
 */
