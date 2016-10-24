#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool isExponent(char* str) {
	if (strlen(str) == 0) return false;
	if (strlen(str) == 1 && (*str == '+' || *str == '-')) return false;
	bool sign = true;
	char* p = str;
	if (*p == '+' || *p == '-') {
		if (*p == '-') sign = false;
		p++;
	}
	
	if (*p == '\0') return false;
	
	while (*p!='\0' && (*p>='0' && *p <='9')) p++;
	if (*p == '\0') return true;
	else return false;
	
}

bool isNumeric(char* str)
{
	if (str == NULL) return false;
	if (strlen(str) == 0) return false;
	if (strlen(str) == 1 && (*str == '+' || *str=='-')) return false;
	bool sign = true;
	char* p = str;
	if (*p == '+' || *p == '-') {
		if (*p == '-') sign = false;
		p++;
	}
	
	while (*p!='\0' && (*p>='0' && *p <='9')) p++;
	if (*p == '\0') return true;
	
	if (*p == '.') {
		p++;
		while (*p!='\0' && (*p>='0' && *p <='9')) p++;
		if (*p == '\0') return true;
		
		if (*p == 'E' || *p == 'e') {
			return isExponent(p+1);
		}
		
		return false;
	} else if (*p == 'E' || *p == 'e') {
		return isExponent(p+1);
	} else {
		return false;
	}
}

int main()
{
	char* s1 = "+100";
	char* s2 = "5e2";
	char* s3 = "-123";
	char* s4 = "3.1416";
	char* s5 = "-1E-16";
	cout << isNumeric(s1) << endl;
	cout << isNumeric(s2) << endl;
	cout << isNumeric(s3) << endl;
	cout << isNumeric(s4) << endl;
	cout << isNumeric(s5) << endl;
	
	char* p1 = "12e";
	char* p2 = "1a3.14";
	char* p3 = "1.2.3";
	char* p4 = "+-5";
	char* p5 = "12e4.3";
	cout << isNumeric(p1) << endl;
	cout << isNumeric(p2) << endl;
	cout << isNumeric(p3) << endl;
	cout << isNumeric(p4) << endl;
	cout << isNumeric(p5) << endl;
	return 0;

}
