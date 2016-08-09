#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
using namespace std;

/**
 * 问题：判断出栈序列是否合法
 * 基本思路：用一个栈做模拟，根据入站序列push，根据出栈序列pop
 * 具体来讲，如果栈顶元素刚好等于出栈元素，那么直接出栈，并且移到下一个待出栈元素
 * 否则，不断的按照入栈序列push，直到碰倒待出栈元素，如果直到序列空都没能找到，那么
 * 序列非法，否则将待出栈元素也push到栈内 
 */
bool IsPopOrder(const vector<int>& push_order, const vector<int>& pop_order) {
	assert(push_order.size() == pop_order.size());
	
	int n = (int)push_order.size();
	int i = 0;
	int j = 0;
	
	stack<int> s;
	while (j < n) {
		int pop_elem = pop_order[j];
		if (!s.empty() && s.top() == pop_elem) {
			s.pop(); // 在栈顶找到的需要pop的元素，直接pop出去 
			j++;     // 轮询下一个需要pop的元素 
		} else {
			// 栈顶没有找到需要pop的元素
			// 不断的将后续元素push到栈，直到碰到要pop的元素 
			while (i < n && push_order[i] != pop_elem) {
				int push_elem = push_order[i];
				s.push(push_elem);
				i++;
			}
			
			// 直到进栈序列空也没有找到需要pop的元素，序列非法 
			if (i >= n) {
				return false;
			} else { // 找到需要pop的元素，将pop元素进栈 
				assert(push_order[i] == pop_elem);
				s.push(push_order[i]);
				i++;
			}
		}
	}
	
	return s.empty() && j >= n;
}

// test
int main() {
	int a[] = {1, 2, 3, 4, 5};
	int b[] = {4, 5, 3, 2, 1};
	int c[] = {4, 3, 5, 1, 2};
	int d[] = {1, 2, 3, 4, 5};
	int e[] = {5, 4, 3, 2, 1};
	int f[] = {1, 3, 2, 4, 5};
	int g[] = {1, 3, 2, 5, 4};
	vector<int> A(a, a+5);
	vector<int> B(b, b+5);
	vector<int> C(c, c+5);
	vector<int> D(d, d+5);
	vector<int> E(e, e+5);
	vector<int> F(f, f+5);
	vector<int> G(g, g+5);
	cout << IsPopOrder(A, B) << " \t Expected true" << endl;
	cout << IsPopOrder(A, C) << " \t Expected false" << endl;
	cout << IsPopOrder(A, D) << " \t Expected true" << endl;
	cout << IsPopOrder(A, E) << " \t Expected true" << endl;
	cout << IsPopOrder(A, F) << " \t Expected true" << endl;
	cout << IsPopOrder(A, G) << " \t Expected true" << endl;

	int h[] = {1};
	int i[] = {1};
	int j[] = {2};
	vector<int> H(h, h+1);
	vector<int> I(i, i+1);
	vector<int> J(j, j+1);
	
	cout << IsPopOrder(H, I) << " \t Expected True" << endl;
	cout << IsPopOrder(H, J) << " \t Expected false" << endl;
	
	return 0;
}
