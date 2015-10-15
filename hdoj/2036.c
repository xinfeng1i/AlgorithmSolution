#include <stdio.h>
#include <stdlib.h>

typedef struct tagPoint {
	int x;
	int y;
} Point;

Point A[110];
double DotMultiply(Point AP, Point AQ);

int main()
{
	int n;
	int i;
	double sum;
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		for (i = 0; i < n; ++i) {
			scanf("%d %d", &(A[i].x), &(A[i].y));
		}
		sum = 0.0;
		for (i = 0; i < n; ++i) {
			Point AP = A[i];
			Point AQ = A[(i+1) % n];
			sum += DotMultiply(AP, AQ) * 0.5;
		}
		printf("%.1lf\n", sum);
	}
	return 0;
}

/* 向量的叉乘
 * AP * AQ = |x1 y1| = x1y2-x2y1
 *           |x2 y2|
 * 方向服从右手法则
 */
double DotMultiply(Point AP, Point AQ)
{
	return (double)AP.x * AQ.y - (double)AP.y * AQ.x;
}
