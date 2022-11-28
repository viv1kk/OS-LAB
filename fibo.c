#include<stdio.h>

int main()
{
	int n1=0, n2=1, n3,i,num;
	printf("Enter the number of elements : ");
	scanf("%d", &num);
	printf("Series : ");
	printf("%d, %d, ", n1, n2);

	for(int i = 2; i < num; i++)
	{
		n3 = n1+n2;
		printf("%d, ", n3);
		n1 = n2;
		n2 = n3;
	}
	printf("\n");
	return 0;
}
