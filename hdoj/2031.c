#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char buf[1024];
char Int2Char(int x);
void ConvertNum(int n, int R);

int main()
{
	int n, R;
	while (scanf("%d %d", &n, &R) != EOF) {
		ConvertNum(n, R);
		printf("%s\n", buf);
	}
	return 0;
}

char Int2Char(int x)
{
	if (x < 10) return x + '0';
	else return (x - 10) + 'A';
}

void ConvertNum(int n, int R)
{
	int r, i, j, len, positive;
	char temp;
	/* 注意特例n=0的判断 */
	if (n == 0) {
		buf[0] = '0';
		buf[1] = '\0';
		return;
	}
	
	/* 负数的处理 */
	positive = 1;
	if (n < 0) positive = -1;
	n = abs(n);
	i = 0;
	while (n != 0) {
		r = n % R;
		buf[i++] = Int2Char(r);
		n /= R;
	}
	if (positive == -1) buf[i++] = '-';
	buf[i] = '\0';
	len = strlen(buf);
	for (i = 0, j = len - 1; i < j; i++, j--) {
		temp = buf[i];
		buf[i] = buf[j];
		buf[j] = temp;
	}
}
