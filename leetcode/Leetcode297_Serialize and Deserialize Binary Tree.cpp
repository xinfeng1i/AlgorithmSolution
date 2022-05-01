#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iostream>
#include <string>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

vector<int> split(string s, char sep) {
    vector<int> ans;
    int n = (int)s.size();
    int i = 0;
    int j = 0;
    while (j < n) {
        while (j < n && s[j] != sep) j++;
        string temp = s.substr(i, j - i);
        int num = atoi(temp.c_str());
        ans.push_back(num);
        i = j + 1;
        j++;
    }
    return ans;
}

void dump(TreeNode* root, vector<int>& data) {
    if (root == NULL) {
        // Notice here: the NULL value cannot be -1 because already have -1 in tree nodes
        data.push_back(10000);  
        return;
    }
    data.push_back(root->val);
    dump(root->left, data);
    dump(root->right, data);
}

TreeNode* restore(vector<int>& data) {
    if (data.empty()) return NULL;
    if (data[0] == 10000) {
        data.erase(data.begin());
        return NULL;
    }

    TreeNode* root = new TreeNode(data[0]);
    data.erase(data.begin());
    root->left = restore(data);
    root->right = restore(data);
    return root;
}

string serialize(TreeNode* root) {
    vector<int> v;
    dump(root, v);

    string s = "";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i == 0) {
            s += to_string(v[i]);
        }
        else {
            s += "#" + to_string(v[i]);
        }
    }
    return s;
}

TreeNode* deserialize(string data) {
    vector<int> v = split(data, '#');
    return restore(v);
}

void preorder(TreeNode* root) {
    if (root == NULL) return;
    cout << " " << root->val << endl;
    preorder(root->left);
    preorder(root->right);
}


int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);

    string s = serialize(root);
    cout << s << endl;

    TreeNode* r = deserialize(s);
    cout << "preorder: " << endl;
    preorder(r);

    return 0;
}