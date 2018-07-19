#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int intRandom(int min, int max){
	return min + rand() % (max - min + 1);
}

int main(){
	int total, x, y, count;
	do{
		printf("Enter the total of 2 dice: ");
		scanf("%d", &total);
	}while(total < 2 || total >12);
	count = 1;
	do{
		x = intRandom(1, 6);
		y = intRandom(1, 6);
		printf("\nResult of throw %d \" %d + %d\"", count, x, y);
		count++;
 }while(x + y != total);
	printf("\nYou got your total in %d throws !", count-1);
	getch();
	return 0;
}
