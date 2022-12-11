#include <stdio.h>
#define NUM 3

int main()
{
    int num;
    scanf("%d", &num);
    
    int process[num];
    int arrivalT[num];
    int burst[num];

    printf("Enter processes : ");
    for(int i = 0; i < num; i++)
    {
        scanf("%d", &process[i]);   
    }


    printf("Enter Arrival time : ");
    for(int i = 0; i < num; i++)
    {
        scanf("%d", &arrivalT[i]);   
    }

    printf("Enter Burst time : ");
    for(int i = 0; i < num; i++)
    {
        scanf("%d", &burst[i]);   
    }

//	int process[NUM] = {1,2,3};
//	int arrivalT[NUM] = {0,1,2};
//	int burst[NUM] = {10, 20, 30};


    


	int completionT[num];

	int count = 0;
	for(int i = 0; i < num; ++i)
	{
		count +=burst[i];
		completionT[i] = count;
	}


	int TAT[num];
	float sumTat = 0.0f;

	for(int i = 0; i < num; i++)
	{
		TAT[i] = completionT[i]-arrivalT[i];
		sumTat += (float)TAT[i];
	}

	int waitT[num];
	float sumWT = 0.0f;
	for(int i = 0; i < num; i++)
	{
		waitT[i] = TAT[i]-burst[i];
		sumWT += (float)waitT[i];
	}

	printf("PID\tAT\tBT\tCT\tTAT\tWT\n");

	for(int i = 0; i < num; i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\n", process[i], arrivalT[i], burst[i], completionT[i], TAT[i],waitT[i]);
	}

	printf("Average TAT : %f\n", (sumTat/num));
	printf("Average WT : %f\n", (sumWT/num));


	return 0;
}
