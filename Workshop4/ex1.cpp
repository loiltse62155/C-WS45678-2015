#include <stdio.h>
#include <conio.h>
#include <math.h>

void printMenu();
int checkPrime(int);
int maxDigit(int);
int minDigit(int);

int main()
{
	int n, choose;
	do{
		printf("Enter number n: ");
		scanf("%d", &n);
	}while(n<0);
	printMenu();
	do{
		printf("\nEnter the process that you want to do: ");
		scanf("%d", &choose);
	}while (choose <0);
	switch(choose){
		case 1:{
			int check = checkPrime(n);
			if(check == 1){
				printf("\n %d is a prime !", n);
			}
			else{
				printf("\n%d is not a prime !", n);
			}
			}
			break;
		case 2: {
			printf("\nMax digit of %d is: %d",n, maxDigit(n));
			printf("\nMin digit of %d is: %d",n, minDigit(n));
			break;
		}
		case 3: break;
		};
	
	getch();
	return 0;
}

void printMenu(){
	printf("\n\tOPTIONS");
	printf("\n1: Process primes.");
	printf("\n2: Print min, max digit in an integer.");
	printf("\n3. Quit\n");
}

int checkPrime(int n){
	if (n <2){
		return 0;
	}
	else if (n > 2){
		if (n % 2 == 0){
			return 0;
		}
		for (int i = 3; i <= (int)sqrt((float)n); i+=2){
			if (n%i == 0){
				return 0;
			}
		}
	}
	return 1;
}

int maxDigit(int n){
	int max = n%10, d;
	n/=10;
	while(n != 0){
		d = n%10;
		if (d > max){
			max = d;
		}
		n/=10;
		
	}
	return max;
}

int minDigit(int n){
	int min = n%10, d;
	n/=10;
	while(n != 0){
		d = n%10;
		if (d < min){
			min = d;
		}
		n/=10;
		
	}
	return min;
}


