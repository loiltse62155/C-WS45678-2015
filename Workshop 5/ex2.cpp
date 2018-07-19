#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int intRandom(int min, int max){
	return min + rand() % (max - min + 1);
}

int main(){
	int total, x, y, count;
	printf("\tBALL LOTTERY\n========================\n");
	do{
		printf("Enter the total of 2 balls: ");
		scanf("%d", &total);
	}while(total < 2 || total >20);
	count = 2;
	do{
		x = intRandom(1, 10);
		y = intRandom(1, 10);
		printf("\nResult of picks %d and %d: %d + %d", count - 1,count, x, y);
		count++;
 }while(x + y != total);
	printf("\nYou got your total in %d picks !", count-1);
	getch();
	return 0;
}
