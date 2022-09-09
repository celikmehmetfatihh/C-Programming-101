//Name: Mehmet Fatih Celik
//ID: 2385268

#include <stdio.h>
#include <stdlib.h>

#define N 20

void bins(int[]);

int main(){
	int waitingTimes[N], i;
	
	for(i=0;i<N;i++)
		waitingTimes[i] = rand()%61;

	
	bins(waitingTimes);
	
	
	return 0;
}

void bins(int waitingTimes[N]){
	int histogram[N-8], i, j;
	
	for(j=0;j<N-8;j++) //making all zero because we increment them according to waiting times
		histogram[j] = 0;
		
	for(i=0;i<N;i++){
		if(waitingTimes[i] >= 0 && waitingTimes[i] <= 5)
			histogram[0]++;
		else if(waitingTimes[i] <= 10)
			histogram[1]++;
		else if(waitingTimes[i] <= 15)
			histogram[2]++;
		else if(waitingTimes[i] <= 20)
			histogram[3]++;
		else if(waitingTimes[i] <= 25)
			histogram[4]++;
		else if(waitingTimes[i] <= 30)
			histogram[5]++;
		else if(waitingTimes[i] <= 35)
			histogram[6]++;
		else if(waitingTimes[i] <= 40)
			histogram[7]++;
		else if(waitingTimes[i] <= 45)
			histogram[8]++;
		else if(waitingTimes[i] <= 50)
			histogram[9]++;
		else if(waitingTimes[i] <= 55)
			histogram[10]++;
		else
			histogram[11]++;			
	}
	
	printf("Patient's Waiting times:\n");
	
	for(i=0;i<N;i++)
		printf("%d ",waitingTimes[i]);
	
	printf("\n\nHistogram of patient’s waiting times:\n");
	
	printf("  0-5 minutes:   %d\n",histogram[0]);
	printf("  6-10 minutes:  %d\n",histogram[1]);
	printf("  11-15 minutes: %d\n",histogram[2]);
	printf("  16-20 minutes: %d\n",histogram[3]);
	printf("  21-25 minutes: %d\n",histogram[4]);
	printf("  26-30 minutes: %d\n",histogram[5]);
	printf("  31-35 minutes: %d\n",histogram[6]);
	printf("  36-40 minutes: %d\n",histogram[7]);
	printf("  41-45 minutes: %d\n",histogram[8]);
	printf("  46-50 minutes: %d\n",histogram[9]);
	printf("  51-55 minutes: %d\n",histogram[10]);
	printf("  56-60 minutes: %d\n",histogram[11]);
}
