//Name: Mehmet Fatih Çelik
//ID: 2385268

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define cons 15

char ** populate_list(char **, int *);
void count_courses(char **, int, int *, int *);
void display_frequency(int, int);

int main(){
	int i, size;
	char **courseNames;
	
	courseNames = populate_list(courseNames, &size);
	
	int freqCNG, freqEEE;
	count_courses(courseNames, size, &freqCNG, &freqEEE);
	display_frequency(freqCNG, freqEEE);
	
	for(i=0;i<size;i++)//freeing 2-D array
		free(courseNames[i]);
	free(courseNames);
	
	return 0;
}

char ** populate_list(char **courseNames, int *size){
	char **courseNames2;
	int num = 10; /* since I dont know how many course will user input, I created limit of 10,
	if user exceeds this limit, I will reallocate my array with 5 more limit.*/
	
	courseNames = (char**)malloc(num*sizeof(char*)); //rows allocation
	if (courseNames == NULL){
		printf("Out of memory!");
		exit(-1);
	}
	
	printf("Enter the list of courses:\n");
	int i = 0, spaceController, j;
	char inp[cons];
	
	do{
		gets(inp);
		
		spaceController = 0;
		for(j=0;j<strlen(inp);j++){ // if there is space it will be 1
			if (inp[j] == 32){
				spaceController=1;
				break;
			}
		}
		
		if(!spaceController && strcmp(inp,"Exit"))// if controller is 0 give error
			printf("Wrong course name! Course name format is departmentcode coursecode\n");
		
		else if(strncmp(inp,"CNG",3) && strncmp(inp,"EEE",3) && strcmp(inp,"Exit"))
			printf("Wrong course name! Course name should start with EEE or CNG!\n");
		
		else if(strcmp(inp,"Exit")){
			if (i>=num){ // reallocation condition
				num +=5;
				courseNames2 = (char**)realloc(courseNames,num*sizeof(char*));
				free(courseNames);
				courseNames = courseNames2; /*This method worked fine, if any other more efficient way exists please feedback me */
				
				if (courseNames == NULL){
					printf("Out of memory for reallocation");
					exit(-1);
				}
			}
			
			courseNames[i] = (char *)malloc(cons*sizeof(char)); // columns allocation
			if(courseNames == NULL){
				printf("Out of memory!");
				exit(-1);
			}
			
			strcpy(courseNames[i], inp);
			i++; // for other allocations
		}
	}while(strcmp(inp,"Exit"));
	
	*size = i;
	
	return courseNames;
}

void count_courses(char **courseNames, int size, int *freqCNG, int *freqEEE){
	*freqCNG = 0;
	*freqEEE = 0;
	int i;
	
	for(i=0;i<size;i++){
		if(!strncmp(courseNames[i],"CNG",3))
			(*freqCNG)++;
		else if(!strncmp(courseNames[i],"EEE",3))
			(*freqEEE)++;
	}	
}

void display_frequency(int freqCNG, int freqEEE){
	printf("\nNumber of courses per department:\n");
	printf("CNG : %d\n",freqCNG);
	printf("EEE : %d",freqEEE);
}
