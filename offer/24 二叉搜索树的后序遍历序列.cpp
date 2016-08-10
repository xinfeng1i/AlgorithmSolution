#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

/**
 * 问题：判断一个数组是否是BST的后续遍历序列
 * 基本思路: BST后续遍历序列有如下结构, |small elems| large elems | root|
 * 只要数组能递归的保持如下结构，则说明是BST的后序遍历序列. 
 */
bool IsPostOrderOfBST(const vector<int>& A) {
	// base case: NULL array or have only one value
	if (A.size() <= 1) return true;
	
	int n = (int) A.size();
	int elem = A[n-1];
	int i = 0;
	vector<int> left;
	vector<int> right;
	// 不断将小于elem的元素推入左子数组 
	while (i < n-1 && A[i] < elem) {
		left.push_back(A[i]);
		i++;
	}
	
	// 上一次循环退出有两种情况：i >= n-1， 这个循环不会执行，right为空
	// A[i] > elem, 此时不断将大于的元素放入右子数组 
	while (i < n-1 && A[i] > elem) {
		right.push_back(A[i]);
		i++;
	}
	
	// 将元素全部消耗完，且左右子数组都是BST
	return i == n-1 && IsPostOrderOfBST(left) && IsPostOrderOfBST(right); 
}

// test
int main() {
	int a[] = {1, 3, 2};
	int b[] = {1, 2, 3};
	int c[] = {2, 1, 3};
	int d[] = {2, 3, 1};
	int e[] = {3, 1, 2};
	int f[] = {3, 2, 1};
	int g[] = {5, 7, 6, 9, 11, 10, 8};
	int h[] = {7, 4, 6, 5};
	vector<int> A(a, a+3);
	vector<int> B(b, b+3);
	vector<int> C(c, c+3);
	vector<int> D(d, d+3);
	vector<int> E(e, e+3);
	vector<int> F(f, f+3);
	vector<int> G(g, g+7);
	vector<int> H(h, h+4);
	cout << IsPostOrderOfBST(A) << "\t Expected True" << endl;
	cout << IsPostOrderOfBST(B) << "\t Expected True" << endl;
	cout << IsPostOrderOfBST(C) << "\t Expected True" << endl;
	cout << IsPostOrderOfBST(D) << "\t Expected True" << endl;
	cout << IsPostOrderOfBST(E) << "\t Expected False" << endl;
	cout << IsPostOrderOfBST(F) << "\t Expected True" << endl;
	cout << IsPostOrderOfBST(G) << "\t Expected True" << endl;
	cout << IsPostOrderOfBST(H) << "\t Expected False" << endl;
	
	return 0;
}
