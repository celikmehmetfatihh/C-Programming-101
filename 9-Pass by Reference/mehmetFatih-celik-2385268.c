#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void CreateArray (char *, int);
int CheckLetters (char *, char , int );
char DisplayDuplicateLetter(char *, int);

int main(){
	int numLetters,i;
	printf("Please enter the number of letters (N)? ");
	scanf("%d",&numLetters);
	
	char *array;
	array = (char*)malloc(sizeof(char)*numLetters);
	
	CreateArray(array, numLetters);
	
	int controller = 0, returned;
	char guess;
	for(i=0;i<5;i++){
		fflush(stdin);
		printf("Guess the duplicate letter: ");
		scanf("%c",&guess);
		returned = CheckLetters(array,guess,numLetters);
		
		if (returned){
			printf("True char! Congrats!\n");
			controller = 1;
			break;
		}
		else{
			printf("Wrong character, try again!\n");
		}
			
	}

	if(controller)
		printf("You win!");
	else
		printf("Sorry you loose!");
	
	return 0;
}

void CreateArray (char *array, int num){
	
	int i;
	
	for(i=0;i<num;i++){
		array[i] = 'A' + (rand() % 26);
	}
}

int CheckLetters (char *array, char guess, int num){
	int i, controller=0;
	char duplicated;
	
	duplicated = DisplayDuplicateLetter(array, num);
	
	for(i=0;i<num;i++){
		if(array[i] == guess && guess == duplicated){
			controller = 1;
			break;
		}
	}
	
	return controller;
}

char DisplayDuplicateLetter(char *array, int num){
	int i,j;
	char duplicated;
	
	for(i=0;i<num;i++){
		for(j=i+1;j<num;j++){
			if (array[j] == array[i]){
				duplicated = array[i];
			} 
		}
	}

	printf("The duplicate letter: %c",duplicated);
	
}
