#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

int checkISBN(int n);

int main()
{
	int flag = 1;
	while (flag != 0) {
		int n;
		printf("\nEnter number (0 to quit):  ");
		scanf_s("%d", &n);
		switch (n) {
		case 0: {
			printf("\nHave a nice day !");
			flag = 0;
			break;
		}
		default: {
			int check = checkISBN(n);
			if (check == 1) {
				printf("\nThe ISBN is valid!");
			}
			else {
				printf("\nThe ISBN is invalid!");
			}

		}
		}
	}

	_getch();
	return 0;
}

int checkISBN(int n)
{
	int I[10] = { 0 }, C[10];
	int result, i, c = 10, total = 0;
	for (i = 9; i >= 0;i--) {
		I[i] = n % 10;
		n /= 10;
	}
	/*for (int i = 0; i < 10; i++) {
		printf("%d", I[i]);
	}*/
	for (i = 0; i < 9 && c > 1; i++) {
		C[i] = I[i] * c;
		c--;

	}
	for (i = 0; i < 9; i++) {
		total += C[i];
	}
	total += I[9];
	if (total % 11 == 0) {
		result = 1;
	}
	else {
		result = 0;
	}
	return result;

}