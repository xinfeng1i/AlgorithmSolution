#include <stdio.h>
#include <stdlib.h>

typedef struct tagTime {
	int hour;
	int minite;
	int second;
} Time;

int main()
{
	int n, i;
	Time t1, t2;
	Time ans;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d %d %d", &t1.hour, &t1.minite, &t1.second);
		scanf("%d %d %d", &t2.hour, &t2.minite, &t2.second);
		
		ans.hour = t1.hour + t2.hour;
		ans.minite = t1.minite + t2.minite;
		ans.second = t1.second + t2.second;

		ans.minite += (ans.second / 60);
		ans.second %= 60;
		ans.hour += (ans.minite / 60);
		ans.minite %= 60;
		
		printf("%d %d %d\n", ans.hour, ans.minite, ans.second);
	}
	
	return 0;
}
