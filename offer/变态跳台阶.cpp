#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 变态跳台阶
 *
 * 根据青蛙最后一跳的高度划分:
 * 最后一跳跳跃1,则前面有f(n-1)种跳法
 * 最后一跳跳跃2,则前面有f(n-2)种跳法
 * 以此类推...
 * 则有 f(n)=f(n-1)+f(n-2)+...f(0)
 * 定义f(0)等于1，通过简单的枚举很快发现这仅仅是
 * 是一个指数函数
 */

int jumpFloorII(int number) {
    if (number == 0) return 0;
    else return pow(2, number-1);

}
