//Name-Surname: Mehmet Fatih Çelik
//ID: 2385268
#include <stdio.h>
#include <math.h>

int main(){
	double x, y, f;
	printf("Enter x = ");
	scanf("%lf",&x);
	printf("Enter y = ");
	scanf("%lf",&y);
	printf("Result\n======\n");
	
	f = 2*x*sin(y)+pow(x*y, 0.5)+cos(x)+(4*x+3)/(3*pow(x,2)+2*y+4);
	printf("x=%.2lf y=%.2lf f=%.2lf",x,y,f);
	
	return 0;
}
