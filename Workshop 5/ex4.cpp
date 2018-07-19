#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

void printMenu();
double findBD(int*, float*, int*);
void input(int*, float*, int*);
void solveQE(float*, float*, float*); 

int main(){
	
	int choose, flag =1;
	while(flag !=0 ){
	printMenu();
	printf("\nChoose the button: ");
	scanf("%d", &choose);
	switch(choose){
		case 1:{
			float a, b, c;
			solveQE(&a, &b, &c);
			break;
		}
		case 2: {
			int d, n;
			float r;
			input(&d, &r, &n);
			double P = findBD(&d, &r, &n);
			printf("\nYour amount after this duration: %.4lf", P);
			break;
		}
		case 3:{
			flag = 0;
			break;
	}
	default: flag = 1;
	}
	getch();
	system("cls");
}
	
	
	return 0;
}

void printMenu(){
	printf("\tMENU");
	printf("\n1-Quadratic equation solving");
	printf("\n2-Bank deposit problem");
	printf("\n3Quit");
}

double findBD(int *d, float *r, int *n){
	return *d*(pow((double)(1+*r),(double) *n));
}

void input(int *d, float *r, int *n){
	do{
		printf("\nEnter your deposit: ");
		scanf("%d", d);
	}while (*d < 0);
	do{
		printf("\nEnter the number of years: ");
		scanf("%d", n);
	}while(*n < 0);
	do{
		printf("\nEnter your yearly rate: ");
		scanf("%f", r);
	}while(*r < 0 || *r > 0.1);
	
}

void solveQE(float *a, float *b, float *c){
	do{
		printf("\nEnter 3 foundations: ");
		scanf("%f%f%f", a, b, c);
	}while(*a == 0);
	float delta = (*b**b) - 4**a**c;
	float  S1, S2;
	if(delta < 0){
		printf("\nThe quadratic equation has no solution !");
	}
	else if(delta == 0){
		S1 = (-*b )/(2**a);
		printf("\nThe quadratic equation has a repeated solution: x = %.2f", S1);
	}
	if (delta > 0){
			S1 = (-*b + sqrt(delta) )/(2**a);
			S2 = (-*b - sqrt(delta) )/(2**a);
			printf("The quadratic equation has 2 clarified solutions: x1 = %.2f, \tx2 = %.2f", S1, S2);
		}
}
