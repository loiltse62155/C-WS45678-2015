#include <stdio.h>
#include <conio.h>

void printMenu();
void printFibo();
int testDate(int, int, int);

int main(){
	printMenu();
	int choose;
	printf("\nEnter the option: ");
	scanf("%d", &choose);
	switch(choose){
		case 1:{
			printFibo();			
			break;
		}
		case 2:{
			int d, m, y;
		    printf("Enter day, month, year: ");
		    scanf ("%d%d%d", &d, &m, &y);
			if (testDate(d, m, y)){
				printf("\nValid date !");
			}
			else{
				printf("\nInvalid date !");
			}
			break;
		} 
		case 3: break;
		
	}
	
	getch();
	return 0;
}

void printMenu(){
	printf("\n\tOPTIONS");
	printf("\n1: Fibonacci Sequence.");
	printf("\n2: Check a date.");
	printf("\n3: Quit");
}

void printFibo(){
	int n;
	do{
		printf("\nEnter an integer: ");
		scanf("%d", &n);
	}while(n <= 0);
	int f1 = 1, f2 = 1, f = 1;
	if (n <2){
		printf("%d", 1);
	}
	else{
		printf("%d", 1);
		printf("\t%d", f);
		for(int i = 3; i <= n; i++ ){
			f = f1 + f2;
			f1 = f2;
			f2 = f;
			printf("\t%d", f);
		}
	
	}
}

int testDate(int d, int m, int y){
    int maxd = 31;
    if (d < 1 || d > 31 || m < 1 || m > 12){
        return 0;
    }
    if (m == 4 || m == 6 || m == 9 || m == 11){
        maxd = 30;
    }
    else if (m == 2){
        if (y % 400 == 0 || (y%4 == 0 && y%100 != 0)){
            maxd = 29;
        }
        else{
            maxd = 28;
        }
            
    }
    return d <= maxd;
}

