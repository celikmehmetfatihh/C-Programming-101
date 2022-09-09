//Name: Mehmet Fatih Celik
//ID: 2385268

#include <stdio.h>

int main(){
	char cus;
	int cus_d=0, cus_h=0, cus_p=0, patient_untreated=0, patient_counter=0;
	
	do{
		fflush(stdin);
		printf("Type (d: dermatologist, h: heart surgeon, p: pediatrician, x: exit): ");
		scanf("%c",&cus);
		
		if (cus=='p'){
			cus_p++;
			patient_counter++;
			if (cus_p >5){
				printf("Patient %d untreated!\n",patient_counter);
				patient_untreated++;
			}
			else
				printf("Pediatrician %d treats patient %d\n",cus_p,patient_counter);
		}
		
		if (cus=='d'){
			cus_d++;
			patient_counter++;
			if (cus_d >2){
				printf("Patient %d untreated!\n",patient_counter);
				patient_untreated++;
			}
			else
				printf("Dermatologist %d treats patient %d\n",cus_d,patient_counter);
		}
		
		if (cus=='h'){
			cus_h++;
			patient_counter++;
			if (cus_h >3){
				printf("Patient %d untreated!\n",patient_counter);
				patient_untreated++;
			}
			else
				printf("Heart surgeon %d treats patient %d\n",cus_h,patient_counter);
		}	
	}while(cus!='x');
	
	printf("%d patients treated, %d patient not treated!",patient_counter-patient_untreated,patient_untreated);
	
	
	return 0;
}
