#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
void nhapMang(int *a, int n) {
	for (int i = 0; i < n;i++) {
		printf("\na[%d] = ", i);
		scanf_s("%d", &a[i]);
	}
}

void xuatMang(int *a, int n) {
	printf("\nThe array: ");
	for (int i = 0; i < n;i++) {
		printf("%d\t", a [i]);
	}
}

int search(int *a, int n) {
	int look;
	printf("\nEnter the number you want to search: ");
	scanf_s("%d", &look);
	for (int i = 0; i < n; i++) {
		if (a[i] == look) {
			return 1;
		}
		
	}
	return 0;

}

void ThemPhanTu(int a[], int &n, int ViTriThem, int PhanTuThem)
{
	for (int i = n - 1; i >= ViTriThem; i--)
	{
		a[i + 1] = a[i];
	}
	a[ViTriThem] = PhanTuThem;
	n++;
}

void printfInRange(int *a, int n, int x, int y) {
	for (int i = 0; i < n; i++) {
		if (a[i] >= x && a[i] <= y) {
			printf("%d\t", a[i]);
		}
	}
}

void sapXepMang(int *a, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n;j++) {
			if (a[i] > a[j]) {
				a[i] = a[i] + a[j];
				a[j] = a[i] - a[j];
				a[i] = a[i] - a[j];
			}
		}
	}
}

void printMenu() {
	printf("==========ARRAY=========\n");
	printf("1. Add a value !\n");
	printf("2. Search a value !\n");
	printf("3. Print out the array !\n");
	printf("4. Print out values in a range !\n");
	printf("5. Printf out the array in ascending order !\n");
	printf("Press any other keys to quit !\n");
}

int main()
{
	int a[MAX];
	int n;
	do {
		printf("\nType the number of elements in array: ");
		scanf_s("%d", &n);
	} while (n < 0);
	nhapMang(a, n);
	int choose, flag = 1;
	
	while (flag != 0) {
		printMenu();
		printf("\nType the number you want to choose: ");
		scanf_s("%d", &choose);
		switch (choose) {
		case 1: {
			int k, pos;
			printf("\nType the number you want to add: ");
			scanf_s("%d", &k);
			printf("\nType the position: ");
			scanf_s("%d", &pos);
			ThemPhanTu(a, n, pos, k);
			break;
		}
		case 2: {
			
			int test = search(a, n);
			if (test == 1) {
				printf("\nThe element  exists !");
			}
			else {
				printf("\nThe element does not exist!");
			}
			break;
		}
		case 3: {
			//printf("%d", n);
			xuatMang(a, n);
			break;
		}
		case 4: {
			int minVal, maxVal;
			printf("\nType the min and max values: ");
			scanf_s("%d%d", &minVal, &maxVal);
			printfInRange(a, n, minVal, maxVal);
			
			break;
		}
		case 5: {
			sapXepMang(a, n);
			xuatMang(a, n);
			break;
		}
		default: {
			flag = 0;
			break;
		}
		}
		_getch();
		system("cls");
	}

	//_getch();
	return 0;
}