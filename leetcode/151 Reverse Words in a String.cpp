#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
using namespace std;

// Space complexity: O(n)
void reverseWords(string &s) {
	string ans;
	int i = 0;
	int n = (int)s.size();
	while (i < n && s[i] == ' ') i++; // skip the leading space
	
	bool hasFirstWord = false; // if we have the found the first word in string
	while (i < n) {
		int j = i ;
		while (j < n && s[j] != ' ') j++;
		if (!hasFirstWord) {
			ans = s.substr(i, j-i) + ans;
			hasFirstWord = true;
		} else {
			ans = s.substr(i, j-i) + " " + ans; // skip consecutive spaces
		}
		

		while (j < n && s[j] == ' ') j++;
		i = j;
	}
	s = ans;
	return;
}

// space complexity: O(1) in place
void reverseWords(char* s) {
	int n = strlen(s);
	
	// Reverse the whole string
	for (int k1 = 0, k2 = n-1; k1 < k2; ++k1, --k2) {
		int ch = s[k1];
		s[k1] = s[k2];
		s[k2] = ch;
	}
	
	int idx = 0;
	int i = 0;
	while (i < n && s[i] == ' ') i++; // skip leading spaces
	while (i < n) {
		int j = i;
		while (j < n && s[j] != ' ') j++; // find word in [i, j)
		
		// reverse the word in [i, j)
		for (int k1 = i, k2 = j-1; k1 < k2; k1++, k2--) {
			int ch = s[k1];
			s[k1] = s[k2];
			s[k2] = ch;
		}
		
		int k = i;
		if (idx != 0) s[idx++] = ' '; // if not the first word, insert a space
		while (k < j) s[idx++] = s[k++]; // append the word in right position
		
		while (j < n && s[j] == ' ') j++; // skip consecutive spaces
		i = j;
	}
	s[idx] = '\0';
	return;
}

int main()
{
	char s[] = "   the sky is blue";
	reverseWords(s);
	printf("%saaa\n", s);
	return 0;
}
