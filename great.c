#include <stdio.h>

int main()
{
	int a = 10, b = 20, c = 30;
	int ans;
	ans = ((a > b)&&(a > c))?a:((b > a)&&(b > c))?b:c;
	printf("%d", ans);
	return 0;
}
