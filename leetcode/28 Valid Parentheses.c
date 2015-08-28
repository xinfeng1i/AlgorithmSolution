#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int isLegal(char* str)
{
	int n = strlen(str);
	char* stack = (char*)malloc(sizeof(char) * n);
	int top = 0;
	
	char* p = str;
	while(*p)
	{
		if (*p == '(')
		{
			stack[top++] = *p;
		}
		else if (*p == ')')
		{
			stack[top--] = '\0';
			if (top < 0) return 0;
		}
		else
		{
			return 0;
		}
		p++;
	}
	
	free(stack);
	stack = NULL;
	return top == 0;
}

int recur(int n, int i, char* s, char** ans, int* size)
{
	if (i == 2 * n)
	{
		if (isLegal(s))
		{
		//	printf("here %d : %s\n", cnt++, s);
			strcpy(ans[(*size)], s);
			*size += 1;
			return 1;
		}
		else
		{
			return 0;
		}
	}

	s[i] = '(';
	int ok = recur(n, i+1, s, ans, size);

	s[i] = ')';
	ok = recur(n, i+1, s, ans, size);
}


char** generateParenthesis(int n, int* returnSize) 
{
	int MAX_N = (int)pow(2.0, (double)(2 * n));
	char** ans = (char**)malloc(sizeof(char*) * MAX_N);
	
	int i = 0;
	for (i = 0; i < MAX_N; ++i)
	{
		ans[i] = (char*)malloc(sizeof(char) * (2 * n + 2));
		memset(ans[i], '\0', (2 * n + 2));
	}
	\
		
	*returnSize = 0;
	
	char*  s = (char*)malloc(sizeof(char) * (2 * n + 2));
	memset(s, '\0', 2 * n + 2);
	
	recur(n, 0, s, ans, returnSize);
	
	return ans;
}

int main()
{
	int size = 0;
	char** ans = generateParenthesis(5, &size);
	
	int i = 0;
	for (i = 0; i < size; ++i)
	{
		printf("%s\n", ans[i]);
	}
	
	return 0;
}
