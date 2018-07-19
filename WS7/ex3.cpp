#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

void printMenu()
{
	printf("\n==============SOFT DRINK MANAGEMENT===========");
	printf("\n1. Adding a new soft drink");
	printf("\n2. Printing out items which belong to a known make");
	printf("\n3. Printing out items whose volumes are between v1 and v2 (integers)");
	printf("\n4. Printing the list in ascending order based on volumes then prices");
	printf("\nPress others to quit\n");
}

char* lTrim(char s[])
{
	int i = 0;
	while (s[i] == ' ') {
		i++;
	}
	if (i > 0) {
		strcpy(&s[0], &s[i]);
	}
	return s;
}

//Function delete blank on the right
char*rTrim(char s[])
{
	int i = strlen(s) - 1;
	while (s[i] == ' ') {
		i--;
	}
	s[i + 1] = '\0';
	return s;
}

//Function delete blank between the string

char* trim(char s[])
{
	rTrim(lTrim(s));
	char *ptr = strstr(s, "  ");
	while (ptr != NULL) {
		strcpy(ptr, ptr + 1);
		ptr = strstr(s, "  ");
	}
	return s;

}

int addSoft(char name[][20], char make[][20], int * volume, int *price, int*duration, int k)
{
	printf("\nEnter name of soft drink: ");
	fflush(stdin);
	scanf("%[^\n]", name[k]);
	printf("\nEnter the way to make: ");
	fflush(stdin);
	scanf("%[^\n]", make[k]);
	printf("\nEnter the volume of soft drink: ");
	scanf("%d", &volume[k]);
	printf("\nEnter the price of soft drink: ");
	scanf("%d", &price[k]);
	printf("\nEnter the duration of soft drink: ");
	scanf("%d", &duration[k]);
	k++;
	return k;
}

void printKnownMake(char name[][20], char make[][20], int * volume, int *price, int*duration, int* k)
{
	char search[20];
	int count = 1;
	printf("\nEnter the known make you want to find: ");
	fflush(stdin);
	scanf("%[^\n]", search);
	char* ptr = NULL;
	for(int i = 0; i<*k; i++){
		ptr = strstr(make[i], search);
		if( ptr != NULL){
			printf("\nFound %s on line %d: ", make[i], i+1);
			printf("\nName of soft drink: %s", name[i]);
			printf("\nVolume of soft drink: %d", volume[i]);
			printf("\nPrice of soft drink: %d", price[i]);
			printf("\nDuration of soft drink: %d", duration[i]);
		}
		count ++;
	}
	if(count == *k){
			printf("\nNot found !");	
	}
}


void printBetween(char name[][20], char make[][20], int * volume, int *price, int*duration, int* k, int v1, int v2)
{
	int count = 1;
	for(int i = 0; i<*k; i++){
		if(volume[i] > v1 && volume[i] < v2){
			printf("\nName of soft drink: %s", name[i]);
			printf("\nMake of soft drink: %s", make[i]);
			printf("\nVolume of soft drink: %d", volume[i]);
			printf("\nPrice of soft drink: %d", price[i]);
			printf("\nDuration of soft drink: %d", duration[i]);
		}
		count ++;
	}
	if(count == *k){
		printf("\nNo items found!");
	}
}

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void swap2(char a[], char b[])
{
	char t[20];
	strcpy(t, a);
	strcpy(a, b);
	strcpy(b, t);	
}

void sortAscending(char name[][20], char make[][20], int * volume, int *price, int*duration, int* k)
{
	for(int i = 0; i< *k-1; i++){
		for(int j = i+1; j<*k; j++){
			if(volume[i] > volume[j]){
				swap2(name[i], name[j]);
				swap2(make[i], make[j]);
				swap(volume+i, volume+j);
				swap(price+i, price+j);
				swap(duration+i, duration+j);
				printf("\n");
			}
			else if (volume[i] == volume[j]){
				if(price[i] > price[j]){
				swap2(name[i], name[j]);
				swap2(make[i], make[j]);
				swap(volume+i, volume+j);
				swap(price+i, price+j);
				swap(duration+i, duration+j);	
				printf("\n");
				}
			}
		}
	}
}

void printString(char name[][20], char make[][20], int * volume, int *price, int*duration, int* k)
{
	for(int i = 0; i<*k; i++){
		printf("\nName of soft drink: %s", name[i]);
		printf("\nMake of soft drink: %s", make[i]);
		printf("\nVolume of soft drink: %d", volume[i]);
		printf("\nPrice of soft drink: %d", price[i]);
		printf("\nDuration of soft drink: %d", duration[i]);		
	}
}

int main()
{
	int choose, flag = 1, k = 0;
	char name[100][20], make[100][20];
	int volume[100], price[100], duration[100];
	while(flag != 0){
		printMenu();
		printf("\nEnter your choice: ");
		scanf("%d", &choose);
		switch(choose){
			case 1: {
				k = addSoft(name, make, volume, price, duration, k);	
				break;
			}
			case 2: {
				printKnownMake(name, make, volume, price, duration, &k);
				break;
			}
			
			case 3:{
				int v1, v2;
				do{
					printf("\nEnter the first volume: ");
					scanf("%d", &v1);
					printf("\nEnter the last volume: ");
					scanf("%d", &v2);
				}while(v1 <0 || v2 <=0);
				printBetween(name, make, volume, price, duration, &k, v1, v2);
				break;
			}
			case 4: {
				sortAscending(name, make, volume, price, duration, &k);
				printString(name, make, volume, price, duration, &k);
				break;
			}
			default: {
				flag = 0;
				break;
			}
		}
		getch();
		system("cls");
	}	
	return 0;
}
