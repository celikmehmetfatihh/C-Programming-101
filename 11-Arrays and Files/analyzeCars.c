//Name: Mehmet Fatih Celik
//ID: 2385268

#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[]){
	char carName[15];
	int year;
	double price;
	
	FILE *inFile, *outFile;
	inFile = fopen(argv[1], "r");
	
	if(inFile == NULL){
		printf("Error occured while reading from the file!");
		exit(1);
	}
	
	int counter = 0;
	printf("Available cars are as follows:\n\n");
	while(fscanf(inFile,"%s %d %lf", carName, &year, &price) != EOF){
		printf("Car %d: %s %d %.0lf\n", counter+1, carName, year, price);
		counter++;
	}

	int firstFav, secFav, i;
	printf("\nChoose your first favorite car: ");
	scanf("%d",&firstFav);
	printf("Choose your second favorite car: ");
	scanf("%d",&secFav);
	
	outFile = fopen("FavoriteCars.txt","w");
	if (outFile == NULL){
		printf("Error occured while writing to the file!");
		exit(1);
	}
	
	rewind(inFile); // make cursor position to start of the file
	
	for(i=0; i<(firstFav-1); i++){ // if firstFav = n, jump n-1 times lines from the file
		while(fgetc(inFile)!= '\n');
	}
	
	fscanf(inFile,"%s %d %lf", carName, &year, &price);
	fprintf(outFile,"%s %d %.0lf\n", carName, year, price);
	
	rewind(inFile); // make cursor position to start of the file
	
	for(i=0; i<(secFav-1); i++){ // if secFav = n, jump n-1 times lines from the file
		while(fgetc(inFile)!= '\n');
	}
	
	fscanf(inFile,"%s %d %lf", carName, &year, &price);
	fprintf(outFile,"%s %d %.0lf\n", carName, year, price);
	
	printf("\nYour favorite cars are added to FavoriteCars.txt!\n");
	
	fclose(inFile);
	fclose(outFile);
	
	return 0;
}
