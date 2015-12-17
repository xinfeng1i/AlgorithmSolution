#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;


bool wordPattern(string pattern, string str) {
	vector<string> v;
	istringstream iss(str);
	string word;
	
	while (iss >> word) {
		v.push_back(word);
	}

	/* 流损坏问题导致，读取word个数不对
       TODO： 复习 stringstream
	do {
	   iss >> word;
	   cout << "word: " << word << endl;
	   v.push_back(word);
	   
	   if (iss.good()) cout << "good" << endl;
	   else if (iss.bad()) cout << "bad" << endl;
	   else if (iss.eof()) cout << "eof" << endl;
	   else if (iss.fail()) cout << "fail" << endl;
	} while (iss);
	*/

	map<char, string> hashtable1;
	map<string, char> hashtable2;
	int n1 = pattern.size();
	int n2 = v.size();
	if (n1 != n2) return false; // bijection, must have equal size
	for (int i = 0; i < n1; ++i) {
		if (hashtable1.find(pattern[i]) == hashtable1.end()) {
			hashtable1[pattern[i]] = v[i];			
		} else {
			if (hashtable1[pattern[i]] != v[i]) {
				return false;
			}
		}
		
		if (hashtable2.find(v[i]) == hashtable2.end()) {
			hashtable2[v[i]] = pattern[i];
		} else {
			if (hashtable2[v[i]] != pattern[i]) {
				return false;
			}
		}
	}
	return true;
}

int main()
{
	string pattern = "abba";
	string str = "dog cat cat dog";
	cout << wordPattern(pattern, str) << endl;
	return 0;
}
