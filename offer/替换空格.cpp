#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;

void replaceSpace(char *str,int length) {
	int n = strlen(str);
	int n_space = 0;
	for (int i = 0; i < n; ++i) {
		if (str[i] == ' ') {
			n_space++;
		}
	}
	
	int new_n = n + n_space * 2;
	str[new_n] = '\0';
	int j = new_n - 1;
	int i = n - 1;
	while (i >= 0) {
		if (str[i] != ' ') {
			str[j] = str[i];
			j--;
			i--;
		} else {
			str[j--] = '0';
			str[j--] = '2';
			str[j--] = '\%';
			i--;
		}
	}
	return;
}

int main()
{
	char s1[1024] = "We Are Happy";
	printf ("%s\n", s1);
	replaceSpace(s1, 1024);
	printf ("%s\n", s1);
	return 0;
}
