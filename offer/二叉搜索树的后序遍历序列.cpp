#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * 利用BST的性质进行判断
 * 1. 存有疑问点：当序列为空的时候，应该也是BST的后续遍历
 *                因为其对应空的BST
 *
 */

bool PostOrderOfBSTHelper(vector<int> seq, int lo, int hi) {
	if (lo > hi) return true; // Empty seq is NULL tree.
	int root = seq[hi];
	int i = lo;
	while (i < hi && seq[i] < root) i++;
	if (i >= hi) return true; // only has left tree
	
	int j = i;
	while (j < hi && seq[j] > root) j++;
	if (j >= hi) return true; // the vals in right tree is valid
	
	return false;
}

bool VerifySquenceOfBST(vector<int> sequence) {
	int n = static_cast<int>(sequence.size());
	return PostOrderOfBSTHelper(sequence, 0, n-1);
}

int main()
{
	vector<int> seq = {1, 3, 2};
	cout << VerifySquenceOfBST(seq) << endl;
	vector<int> seq2 = {15, 10, 20};
	cout << VerifySquenceOfBST(seq2) << endl;
	vector<int> seq3 = {25, 30, 20};
	cout << VerifySquenceOfBST(seq3) << endl;
	return 0;
}
