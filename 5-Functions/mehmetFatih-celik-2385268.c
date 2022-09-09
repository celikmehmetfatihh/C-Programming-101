//Name: Mehmet Fatih Çelik
//ID: 2385268

#include <stdio.h>
#include <math.h>

float cost_calculator(char, int);
float change_calculator(float, float);

int main(){
	char size;
	int toppings, control=1;
	float money_paid, cost, change;
		
	do{		
		printf("Enter the size of the pizza (s/l): ");
		scanf("%c",&size);
		if (size!='s' && size!='l'){
			printf("Not a valid Pizza size!\n");
			break;
		}
		
		printf("Enter the number of toppings: ");
		scanf("%d",&toppings);
		if (toppings < 0){
			printf("Not a valid topping number!\n");
			break;
		}
		
		printf("Enter the amount paid (in Euro): ");
		scanf("%f",&money_paid);
		control=0;
	}while(control);
	
	cost = cost_calculator(size, toppings);
	change = change_calculator(cost, money_paid);
	
	if(control == 0){
		if(change>0)
			printf("Your Pizza costs %.2f Euro and you will get %.2f change back!",cost,change);
		else if (change <0)
			printf("Your Pizza costs %.2f Euro and you need to pay %.2f Euro more!",cost,fabs(change));
		else
			printf("Your Pizza costs %.2f Euro Thank you!",cost);
	}
	
	return 0;
}

float cost_calculator(char size, int toppings){
	float cost = 0;
	
	if (size == 's'){
		cost+=3;
		toppings--;
		cost+=toppings*0.85;
	}
	else if(size =='l'){
		cost+=5;
		toppings--;
		cost+=toppings*0.95;
	}
	
	return cost;
}

float change_calculator(float cost, float money_paid){
	float change = money_paid - cost;
	
	return change;
}
