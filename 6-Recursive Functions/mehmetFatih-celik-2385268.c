//Name: Mehmet Fatih Çelik
//ID: 2385268

#include <stdio.h>

int growth_population(int, int);
void analysis(int);

int main(){
	int in_rabbit, month, rab_controller, num_rabit;
	
	do{
		rab_controller=0;
		printf("Enter initial number of rabbits: ");
		scanf("%d",&in_rabbit);
		
		if(in_rabbit==0){
			rab_controller=1;
			printf("Sorry you cannot enter 0!\n");
		}
		
	}while(rab_controller==1);
	
	printf("Number of months: ");
	scanf("%d",&month);
	
	num_rabit= growth_population(month, in_rabbit);
	
	printf("At the end of month %d, rabbit population will be %d\n", month, num_rabit);
	
	analysis(num_rabit);
	
	return 0;
}

int growth_population(int m, int initial_rabbits){
	if (m==0)	
		return initial_rabbits;
	else
		return (1.25*growth_population(m-1, initial_rabbits));
}

void analysis(int rabbits){
	if (rabbits < 100)
		printf("Your farm will be a hobby farm!");
	else if (rabbits <=200)
		printf("Your farm will be a small farm!");
	else if (rabbits <=500)
		printf("Your farm will be a medium farm!");
	else if (rabbits <=1000)
		printf("Your farm will be a big farm!");
	else
		printf("Your farm will be a huge farm!");
}
