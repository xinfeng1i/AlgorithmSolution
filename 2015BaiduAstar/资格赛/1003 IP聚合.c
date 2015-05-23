#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000 + 5
#define MAX_M 50 + 5

typedef struct tagIP
{
	int a;
	int b;
	int c;
	int d;
}IP;



IP allIPs[MAX_N];
IP netIPs[MAX_N];




int isIpEqual(IP* ip1, IP* ip2)
{
	if (ip1->a == ip2->a &&
	    ip1->b == ip2->b &&
	    ip1->c == ip2->c &&
	    ip1->d == ip2->d)
	    return 1;
	else
		return 0;
}

void solve()
{
	int n, m;
	scanf("%d %d", &n, &m);
	
	int i, j;
	for (i = 0; i < n; ++i)
	{
		scanf("%d.%d.%d.%d", &allIPs[i].a, &allIPs[i].b, &allIPs[i].c, &allIPs[i].d);
	}
	
	IP mask;
	for (j = 0; j < m; ++j)
	{
		scanf("%d.%d.%d.%d", &mask.a, &mask.b, &mask.c, &mask.d);
		// compute all the network ips for each mask ip
		for (i = 0; i < n; ++i)
		{
			netIPs[i].a = allIPs[i].a & mask.a;
			netIPs[i].b = allIPs[i].b & mask.b;
			netIPs[i].c = allIPs[i].c & mask.c;
			netIPs[i].d = allIPs[i].d & mask.d;
		}
		// count the distince network ips
		
		int ii, jj;
		int cnt = 0;
		int flag = 0;
		for (ii = 0; ii < n; ++ii)
		{
			flag = 0;
			for (jj = 0; jj < ii; ++jj)
			{
				if (isIpEqual(&netIPs[ii], &netIPs[jj]))
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0) cnt++;
		}
		
		printf("%d\n", cnt);
		
	}
	
}

int main()
{
	//freopen("data.in", "r", stdin);
	int T = 0;
	scanf("%d", &T);
	int nCase = 0;
	for (nCase = 1; nCase <= T; ++nCase)
	{
		printf("Case #%d:\n", nCase);
		solve();
	}
	
	return 0;
}
