//Name: Mehmet Fatih Celik
//ID: 2385268

#include <stdio.h>

int main(){
	int choice, base, dec_input;						 //count for controlling the binary digits
	char my_char;										 //controller for controlling the if the input has a trouble or not
	int count=7,y0,y1,y2=0, dec_counter=0, controller=0; //dec_controller for controlling the decimal digits
	
	do{
		printf("Welcome to Octal to Binary Encoder!\n\n");
		printf("  (1) Compute and Display the output\n");
		printf("  (2) Quit\n");
		printf("You choose: ");
		scanf("%d",&choice);
		printf("You have chosen option %d\n\n",choice);
		
		if (choice == 1){
			printf("Which base will you use to enter input (base 2 or base 10)? ");
			scanf("%d",&base);
			if (base ==2){
				controller=0;
				while(controller==0){					  
					y0 =0,y1 =0,y2 =0;   //reassaigning the variables for the other iterations
					count =7;
					
					printf("Please enter your input: ");
					fflush(stdin);
					
					do{
					
						scanf("%c",&my_char);
						
						if((count == 1 || count== 3 || count==5 || count==7)&&my_char!='\n'){
							if(my_char == '1')
								y0=1;
							controller=1;			
						}
						
						if((count == 2 || count== 3 || count==6 || count==7)&&my_char!='\n'){
							if(my_char == '1')
								y1=1;
							controller=1;
						}
						
						if((count == 4 || count== 5 || count==6 || count==7)&&my_char!='\n'){	
							if(my_char == '1')
								y2=1;
							controller=1;
						}
						count--;
						
						if(my_char>49 && my_char!='\n'){
							printf("%c",my_char);
							controller=0;				
						}
					}while(my_char!='\n');
					if (controller == 0)
						printf("  is not a valid number in base 2! Please try again!\n\n");
					if (count>-2){
						printf("You entered less than 8 bits! Please try again!\n");
						controller=0;
					}
					if (count<-2){
						printf("You entered more than 8 bits! Please try again!\n");
						controller=0;		
					}		
				}

				printf("Y2 is %d Y1 is %d Y0 is %d\n\n",y2,y1,y0);
			}
			
			else if(base == 10){
				printf("Please enter your input: ");
				do{
					scanf("%d",&dec_input);
					if (dec_input >255){
						printf("Decimal %d cannot be represented with 8 bits. Please try again!\n",dec_input);
						printf("Please enter your input: ");
					}
				}while(dec_input >255);
				
				y0 =0,y1 =0,y2 =0; //reassaigning the variables for the other iterations
				
				while(dec_input!=0){
					if (dec_input%2 == 1){
						if (dec_counter == 1 || dec_counter == 3 || dec_counter == 5 || dec_counter==7)
							y0=1;
						
						if(dec_counter == 2 || dec_counter == 3 || dec_counter == 6 || dec_counter == 7)
							y1=1;
							
						if(dec_counter == 4 || dec_counter == 5 || dec_counter == 6 || dec_counter == 7)
							y2=1;
					}
					
					dec_input/=2;
					dec_counter++;
				}
				printf("Y2 is %d Y1 is %d Y0 is %d\n\n",y2,y1,y0);
			}
			else
				printf("Invalid number in base 2/10\n");
		}
		else if (choice == 2)
			printf("BYEE!!\n");
		else
			printf("Please enter 1 or 0!\n\n");
	}while(choice!=2);
	
	return 0;
}
