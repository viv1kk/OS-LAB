#include <stdio.h>
#include <limits.h>

int main()
{
    int n;
    printf("Enter the number of Processes : ");
    scanf("%d", &n);
    int AT[n];
    int BT[n];
    int PR[n];

    printf("Enter the AT and Priority of each Process :\n");
    for(int i = 0; i<n; i++)
    {
        scanf("%d", &BT[i]);
        scanf("%d", &PR[i]);
    }

    int i = 1;
    while(i < n)
    {
        int key = PR[i];
        int a = BT[i];
        int j = i-1;

        while(j >= 0 && PR[j] > key)
        {
            PR[j+1] = PR[j];
            BT[j+1] = BT[j];
            j--;
        }
        PR[j+1] = key;
        BT[j+1] = a;
        i++;
    }

	int CT[n];
	int count = 0;
	for(int i = 0; i < n; ++i)
	{
		count += BT[i];
		CT[i] = count;
	}

    int TAT[n];
	float sumTat = 0.0f;

	for(int i = 0; i < n; i++)
	{
		TAT[i] = CT[i];
		sumTat += (float)TAT[i];
	}

	int WT[n];
	float sumWT = 0.0f;
	for(int i = 0; i < n; i++)
	{
		WT[i] = TAT[i]-BT[i];
		sumWT += (float)WT[i];
	}

	printf("PID\tPR\tBT\tCT\tTAT\tWT\n");

	for(int i = 0; i < n; i++)
	{
		printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i, PR[i], BT[i], CT[i], TAT[i],WT[i]);
	}

	printf("Average TAT : %f\n", (sumTat/n));
	printf("Average WT : %f\n", (sumWT/n));

    for(int j = 0; j < n; j++)
    {
        printf("%d, %d\n", PR[j], BT[j]);
    }

    return 0;
}
