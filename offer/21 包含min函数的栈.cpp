#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
using namespace std;

/**
 * 要求在O(1)的时间内实现栈的 push, pop & min 操作
 *
 * 基本思路：
 * 维持两个栈，其中一个是正常的栈，另一个栈总是维持当前栈结构的最小值.
 *   Push：比较新进入的值与 min_stack的最小值（栈顶元素），如果更小则推入
 *         新进入元素，反之则继续推入当前的最小值（栈顶元素）.
 *   Pop:  直接pop两个栈即可.
 *   Min:  取 min_stack 的栈顶元素. 
 */
class StackWithMin {
public:
	void Push(int x);
	void Pop();
	int Top();
	int GetMin();
private:
	stack<int> m_data;
	stack<int> m_min;
};
void StackWithMin::Push(int x) {
	m_data.push(x);
	if (m_min.empty()) {
		m_min.push(x);
	} else {
		int curMin = m_min.top();
		if (x < curMin) {
			curMin = x;
		}
		m_min.push(curMin);
	}
}
void StackWithMin::Pop() {
	assert(!m_data.empty());
	m_data.pop();
	m_min.pop();
}
int StackWithMin::Top() {
	assert(!m_data.empty());
	return m_data.top();
}
int StackWithMin::GetMin() {
	assert(!m_data.empty());
	return m_min.top();
}

// test
int main() {
	StackWithMin s;
	s.Push(4);
	cout << s.GetMin() << "\t Expected 4" << endl;
	s.Push(3);
	cout << s.GetMin() << "\t Expected 3" << endl;
	
	s.Pop();
	cout << s.GetMin() << "\t Expected 4" << endl;
	s.Push(5);
	cout << s.GetMin() << "\t Expected 4" << endl;
	s.Push(1);
	cout << s.GetMin() << "\t Expected 1" << endl;
	
	s.Pop();
	cout << s.GetMin() << "\t Expected 4" << endl;
	
	s.Pop();
	cout << s.GetMin() << "\t Expected 4" << endl;
	return 0;
}
