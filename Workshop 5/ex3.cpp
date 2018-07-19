#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void printMenu();
int checkDate(int, int, int);
void swap(char*, char*);

int main (){
	int n, flag = 1;
	printMenu();
	while(flag != 0){
	printf("\nType the choosing number: ");
	scanf("%d", &n);
	
	switch(n){
		case 1:{
			int d, m, y;
			printf("\nEnter day, month, year which you want to check: ");
			scanf("%d%d%d", &d, &m, &y);
			if(checkDate(d, m, y) != 0){
				printf("\nValid date !");
			}
			else{
				printf("\nInvalid day !");
			}
			break;
		}
		case 2: {
			char a, b;
			fflush(stdin);
			printf("\nEnter the first character: ");
			scanf("%c", &a);
			fflush(stdin);
			printf("\nEnter the last character: ");
			scanf("%c", &b);
			if(a<b){
//				a = a + b;
//				b = a - b;
//				a = a - b;
				swap(&a, &b);
				
			}
			for (char c = a; c>= b; c--){
				printf("\n%c\t%d\t%o\t%X", c, c, c, c);
			}
			
			break;
		}
		case 3:{flag = 0;
			break;
		} 
		default: flag = 1	;
		
	}
}
	getch();
	return 0;
}

void printMenu(){
	printf("\tMENU\n");
	printf("1-Processing date data");
	printf("\n2-Character data");
	printf("\n3-Quit");
	printf("\n======================");
}

int checkDate(int d, int m, int y){
	int maxd = 31;
	if(d < 0 || d > 31|| m<0 || m>12 || y<0){
		return 0;
	}
	if(m == 2){
		if((y%400 == 0 || ((y%4==0)&&(y%100 != 0)))){
			maxd = 29;
		}
	else{
			maxd = 28;
		}
	}
	return d <= maxd;
}

void swap(char *a, char *b){
	char t;
		t = *a;
		*a = *b;
		*b = t;
}

