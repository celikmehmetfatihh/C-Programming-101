//Name: Mehmet Fatih Çelik
//ID: 2385268

#include <stdio.h>

int main(){
	double population, vaccinatedPeople, percVaccinated;
	
	printf("Enter your country population: ");
	scanf("%lf",&population);
	printf("Enter the number of people vaccinated: ");
	scanf("%lf",&vaccinatedPeople);
	
	percVaccinated = 100*vaccinatedPeople/population;
	
	printf("%.lf%c  people vaccinated.\n",percVaccinated,'%');
	
	if(percVaccinated >= 70)
		printf("Your country is immune against the virus");
	else
		printf("%.lf%c more people should be vaccinated to be immune against the virus.",70-percVaccinated,'%');
	
	return 0;
}
