//Name: Mehmet Fatih Çelik
//ID: 2385268

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct circle{
	int radius, x, y;
};

void addCircle(struct circle*,int *);
void searchPoints(struct circle*,int);
void storeCircles(struct circle*, int);

int main(){
	
	struct circle circles[10];
	
	int choice;
	int count = 0;
		do{
		printf("\n1) Add circle\n");
		printf("2) Search points\n");
		printf("3) Store circles\n");
		printf("4) Exit\n");
		printf("What would you like to do? ");
		scanf("%d",&choice);
		
		if(choice == 1)
			addCircle(circles,&count);
		
		else if(choice == 2)
			searchPoints(circles,count);
		else if(choice == 3)
			storeCircles(circles,count);
		else{
			if(choice != 4)
				printf("Please enter a valid number!\n");
		}
		
	}while(choice!=4);
	
	return 0;
}

void addCircle(struct circle *circles,int *count){
	int x, y, r;
	
	if((*count) == 10){
		printf("The list is already full! You cannot add more!\n");
		exit(-1);
	}
	
	printf("Enter the x-coordinate of circle:\n");
	scanf("%d",&x);
	printf("Enter the y-coordinate of circle:\n");
	scanf("%d",&y);
	printf("Enter the radius of circle:\n");
	scanf("%d",&r);
	
	circles[*count].radius = r;
	circles[*count].x = x;
	circles[*count].y = y;
	
	(*count)++;
}

void searchPoints(struct circle *circles, int count){
	int i, x, y, flag = 0;
	
	printf("Enter the x-coordinate of point: ");
	scanf("%d",&x);
	printf("Enter the y-coordinate of point: ");
	scanf("%d",&y);
	
	for(i=0; i<count; i++){
		if ((pow((circles[i].x - x),2) + pow((circles[i].y - y),2)) == pow(circles[i].radius,2)){
			if(flag == 0)
				printf("This point lies on the following circles:\n");
			printf("circle: x=%d, y=%d, r=%d\n",circles[i].x,circles[i].y,circles[i].radius);
			
			flag = 1;
		}
	}
	
	if(!flag)
		printf("This point does not lie on available circles!\n");
}

void storeCircles(struct circle *circles, int count){
	int i;
	FILE *outFile;
	outFile = fopen("circles.txt", "w");
	if (outFile == NULL){
		printf("Error occured while opening the file!\n");
		exit(-1);
	}
	
	for(i=0;i<count;i++)
		fprintf(outFile,"x = %d, y = %d, r = %d\n",circles[i].x,circles[i].y,circles[i].radius);
	
	printf("circles.txt is successfully created!\n");
	fclose(outFile);
}
