#include <stdio.h>

int main()
{
	int i, fact = 1, num = 5;
	for(i = 1; i <= num; i++)
	{
		fact = fact*i;
	}
	printf("%d", fact);
	return 0;
}
