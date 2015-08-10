#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#if 0
int main()
{
	int T, s, q;
	scanf("%d %d %d", &T, &s, &q);

	int cnt = 1;
	while (s * q < T)
	{
		cnt++;
		s = s * q;
	}
	printf("%d\n", cnt);
	return 0;
}
#endif  //0