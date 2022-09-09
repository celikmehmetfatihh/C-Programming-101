//Name: Mehmet Fatih Çelik
//ID: 2385268

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct photo{
	char name[20], cityName[20];
	int size;
};

void load_photos(struct photo*, int);
void search_photos(struct photo*, char*, int);
void delete_photo(struct photo*, char*, int*);
void save_photos(struct photo*, int);

int main(){
	struct photo *photos;
	
	FILE *inFile;
	inFile = fopen("photos.txt","r");
	if (inFile == NULL){
		printf("Error occured while reading the file!");
		exit(1);
	}
	
	int size = 0;
	char line[1024]; 
	while((fscanf(inFile,"%[^\n]\n",line))!=EOF) //for calculating the number of lines in the file
		size++;
		
	fclose(inFile);
	
	photos = (struct photo*)malloc(sizeof(struct photo)*size);
	if(photos == NULL){
		printf("Error occured while allocating the memory!\n");
		exit(1);
	}
	
	load_photos(photos,size);
	
	int option;
	do{
		printf("\n----- MENU-----\n");
		printf("1. Search Photos\n");
		printf("2. Delete Photos\n");
		printf("3. Exit\n");
		
		
		printf("\nEnter your option: ");
		scanf("%d",&option);
		
		if(option == 1){
			char cityName[15];
			printf("Enter the city name: ");
			scanf("%s",&cityName);
			
			search_photos(photos, cityName, size);
		}
		
		else if(option == 2){
			char photoName[15];
			printf("Enter the photo name: ");
			scanf("%s",&photoName);
			
			delete_photo(photos, photoName, &size);//size: pass by reference, we need to decrement it. 
		}
		else{
			if(option != 3)
				printf("Please enter a valid option!");
		}
		
	}while(option != 3);
	
	save_photos(photos, size);
	printf("The photos.txt file has been updated successfully!");
	
	return 0;
}

void load_photos(struct photo *photos, int size){
	int i=0;
	FILE *inFile;
	inFile = fopen("photos.txt","r");
	if (inFile == NULL){
		printf("Error occured while reading the file!");
		exit(1);
	}

	char *token;
	char line[1024];
	
	while((fscanf(inFile,"%[^\n]\n",line))!=EOF){
		
		token = strtok(line,";");
		strcpy(photos[i].name,token);
		
		photos[i].size = atoi(strtok(NULL,";"));
		
		token = strtok(NULL,";");
		strcpy(photos[i].cityName,token);
		
		i++;
	}
	fclose(inFile);
	printf("The photos.txt file has been loaded successfully!\n");
}

void search_photos(struct photo *photos, char *cityName, int size){
	int i, controller = 0;
	
	for(i=0;i<size;i++){
		if(strcmp(photos[i].cityName,cityName) == 0){
			if(!controller)
				printf("Photos taken at Nicosia are as follows:\n");
			controller = 1;
			printf("%s\n",photos[i].name);
		}	
	}
	
	if(controller == 0)
		printf("There is not any available photo taken at city %s.\n",cityName);
}

void delete_photo(struct photo *photos, char *photoName, int *size){
	int i, found = 0, position;
	for(i=0; i<*size; i++){
		if(strcmp(photos[i].name,photoName) == 0){
			found = 1;
			position = i;
		}		
	}
	
	if(found == 0)
		printf("That image is not in your store so cannot delete!\n");
	else{
		printf("%s deleted from the PhotoBook!\n",photos[position].name);
		
		for(i=position; i<*size; i++){
			strcpy(photos[i].name,photos[i+1].name);
			photos[i].size = photos[i+1].size;
			strcpy(photos[i].cityName,photos[i+1].cityName);
		}
		
		(*size)--;
	}	
	
}

void save_photos(struct photo *photos, int size){
	int i = 0;
	FILE *outFile;
	outFile = fopen("photos.txt","w");
	if (outFile == NULL){
		printf("Error occured while reading the file!");
		exit(1);
	}
	
	for(i=0;i<size;i++)
		fprintf(outFile,"%s;%d;%s\n",photos[i].name,photos[i].size,photos[i].cityName);
	
	fclose(outFile);
}
