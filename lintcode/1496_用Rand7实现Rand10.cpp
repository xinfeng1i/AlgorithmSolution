#include <climits>
#include <cassert>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;

/*
 * fake definition
 */
int rand7() {
    return 2;
}


/* 
 * ����˼·�� ͨ���������� r1+r2 ���ϸ�˹�ֲ� [2, 14]���� 8 ��ȡ�÷�ֵ������Ϊ 1/49x7
 * ��ˣ�ͨ������ͬ�����Ľ���ӳ�䣬��֤���ص�ÿ�����ĸ���Ϊ1/7����
 */
int rand10() {
    int r1 = rand7();
    int r2 = rand7();
    int sum = r1 + r2;

    if (sum == 8) {
        return 8;
    } else if (sum == 9 || sum == 14) {
        return 9;
    } else if (sum == 10 || sum == 13) {
        return 10;
    } else {
        return r1;
    }
}