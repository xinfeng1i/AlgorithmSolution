#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <stdio.h>
#include <stdlib.h>
using namespace std;



// List n || 先手胜1表示，后手胜0表示
//      1 || 1
//      2 || 1
//      3 || 1
//      4 || 0
//      5 || 1
//      6 || 1
//      7 || 1
//      8 || 0
// 假设当前有n个石子，先手有3种选择
// 选择1或者2后者3个，剩余n-1, n-2, n-3个石子
// 如果剩余的n-1, n-2, n-3中存在后手的必胜的策略
// 则先手则必然能胜利
// 换句话说，如果之前的三个中存在0，则当前n有先胜策略
// 这样的话，可以从上图看出，其实就是4的倍数必然输，反之必胜
bool canWinNim(int n) {
	return n % 4 != 0;
}

int main()
{
	cout << canWinNim(1348820612) << endl;
	return 0;
}