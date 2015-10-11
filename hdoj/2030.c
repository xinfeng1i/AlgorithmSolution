#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n;
	int i, j, k;
	int len;
	int cnt;
	char line[1024];
	
	scanf("%d\n", &n);
	for (i = 0; i < n; ++i) {
		gets(line);
		len = strlen(line);
		cnt = 0;
		j = 0;
		/* 汉字的机内码用两个字节表示一个汉字，并且最高位均为1，因此其ASCII值小于0
		   并且连续两个ASCII码表示一个汉字 */
		while (j < len) {
			if (line[j] > 0)
			{
				j++;
			} else if (line[j] < 0) {
				j += 2;
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
