#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool match(char* str, char* pattern)
{
	//cout << "call match:" << str << " " << pattern << endl;
	if (strlen(str)==0 && strlen(pattern)==0) return true;
	if (str == NULL || pattern == NULL) return false;
	char* p1 = str;
	char* p2 = pattern;
	
	// 初始串为空串时，必须有*字符匹配0次，方可匹配
	if (strlen(p1)==0) {
		if (strlen(p2) == 2) {
			if ((*p2 >= 'a' && *p2 <= 'z' || *p2 == '.') && *(p2+1) == '*') {
				return true;
			}
		}
		return false;
	}
	if (strlen(p1)>=1 && strlen(p2) == 0) return false;
	
	if (*p2 >= 'a' && *p2 <= 'z') {
		if (*(p2+1)=='\0') {
			return *p1 == *p2 && strlen(p1) == 1;
		} else {
			if (*(p2+1)>='a'&&*(p2+1) <= 'z') {
				return *p1 == *p2 && match(p1+1, p2+1);
			} else if (*(p2+1) == '.') {
				return *p1 == *p2 && match(p1+1, p2+1);
			} else if (*(p2+1) == '*') {
				return match(p1, p2+2) || ((*p1==*p2) && match(p1+1, p2));
			}
		}
	} else if (*p2 == '.') {
	    if (*(p2+1)=='\0') {
			return strlen(p1) == 1;
		} else {
			if (*(p2+1)>='a'&&*(p2+1) <= 'z') {
				return match(p1+1, p2+1);
			} else if (*(p2+1) == '.') {
				return match(p1+1, p2+1);
			} else if (*(p2+1) == '*') {
				return match(p1, p2+2) || match(p1+1, p2);
			}
		}
		
	} else if (*p2 == '*') {
		return false;
	}
}

int main()
{
	char* str = "aaa";
	char* p1 = "a.a";
	char* p2 = "ab*ac*a";
	char* p3 = "aa.a";
	char* p4 = "ab*a";
	cout << match(str, p1) << endl;
	cout << match(str, p2) << endl;
	cout << match(str, p3) << endl;
	cout << match(str, p4) << endl;
	
	cout << "bad case:" << endl;
	char* str2 = "bcbbabab";
	char* pp2 = ".*a*a";
	cout << match(str2, pp2) << endl;
	
	return 0;
}
