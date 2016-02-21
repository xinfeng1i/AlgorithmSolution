#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> result;
    int wordLength = words[0].size();
    int totalLength = wordLength * words.size();
    int n = s.size();
    int i = 0;
    
    map<string, int> wordCount;
    for (vector<string>::iterator it = words.begin(); it != words.end(); ++it) {
		wordCount[*it] += 1;
	}
    
    while (i < n && i + totalLength <= n) {
        string curWord = s.substr(i, wordLength);
        map<string, int> temp(wordCount.begin(), wordCount.end());
        
        // find curWord in list
        if (temp.find(curWord) != temp.end()) {
            bool found = true;
            // whether the following words in list ?
            for (int j = i; j < i + totalLength; j += wordLength) {
                if (temp.find(s.substr(j, wordLength)) == temp.end()) {
                    found = false;
                    break;                    
                } else {
                    temp[s.substr(j, wordLength)] -= 1;
                    if (temp[s.substr(j, wordLength)] == 0)
					   temp.erase(s.substr(j, wordLength));
                }
            }
            
            // we have find all the words
            if (found && temp.empty()) {
                result.push_back(i);
                i++; // NOTICE: CAN ONLY STEP ONE
            } else { // either we not find some word or we didn't use all the words
                i++;
            }            
        } else {
            i++;
        }
        
    }
    return result;
}

int main()
{
	string s = "barfoofoobarthefoobarman";
	vector<string> words;
	words.push_back("foo");
	words.push_back("bar");
	words.push_back("the");
	vector<int> res = findSubstring(s, words);
	for (size_t i = 0; i < res.size(); ++i) {
		cout << " " << res[i] << endl;
	}
	return 0;
}
