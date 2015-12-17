#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int lengthOfLastWord(string s) {
	int n = s.size();
	int i = n - 1;
	// skip extra spaces at the end
	while (i >= 0 && s[i] == ' ') i--;

	// not found any alphabet
	if (i < 0) {
		return 0;
	} else {
		int j = i;
		while (j >= 0 && s[j] != ' ') j--;
		return (i - j);
	} 
}

int main()
{
	string s = "I am goood   ";
	cout << lengthOfLastWord(s) << endl;
	return 0;
}
