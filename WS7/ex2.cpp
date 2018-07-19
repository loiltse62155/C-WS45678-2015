#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

void printMenu()
{
	printf("\n==============EMPLOYEE MANAGEMENT===========");
	printf("\n1. Adding a new employee");
	printf("\n2. Find data about employees using a name inputted");
	printf("\n3. Remove an employees based on a code inputted");
	printf("\n4. Print the list in descending order based on salary + allowance");
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

int addEmp(char code[][8], char name[][20], double*salary, double *allowance, int k)
{
	fflush(stdin);
	printf("\nEnter code number: ");
	scanf("%[^\n]", (code[k]));
	strupr(code[k]);
	fflush(stdin);
	printf("Enter employee's name: ");
	scanf("%[^\n]", (name[k]));
	trim(name[k]);
	strupr(name[k]);
	do{
		printf("Enter the salary: ");
		scanf("%lf", &salary[k]);
	}while(salary[k] < 0);
	do{
		printf("Enter the allowance: ");
		scanf("%lf", &allowance[k]);
	}while(allowance[k] < 0);
	k++;
	return k;
}

void printString(char code[][8], char name[][20],double* salary, double* allowance, int *k)
{
	int i;
	for(i = 0; i<*k;i++){
	//	puts(code[i]);
	//	puts(name[i]);
		printf("\nCode of employee: %s\n", code[i]);
		printf("Name of employee: %s\n", name[i]);
		printf("salary: %.2lf\t", salary[i]);
		printf("allowance: %.2lf\t", allowance[i]);
	}
}

void searchEmp(char code [][8], char name[][20],double*salary, double*allowance, int k)
{
	char search[20];
	fflush(stdin);
	printf("\nType name of student you want to find: ");
	scanf("%[^\n]", search);
	strupr(search);
	char*ptr;	
	for(int i = 0; i<=k; i++){	
	ptr = strstr(name[i], search);
	if(ptr != NULL){
		printf("\nFound: ");
		puts(name[i]);
		printf("at line %d", i+1);
		printf("\nData about %s: ", name[i]);
		printf("\nCode: %s", code[i]);
		printf("\nSalary %.2lf, allowance %.2lf", salary[i], allowance[i]);
		break;
		}
	}
	if(ptr ==NULL)
	printf("\nNot found !");
}

int Remove(char code[][8], char name[][20], double*salary, double*allowance, int k)
{
	char remove[8];
	fflush(stdin);
	printf("\nType code of employee you want to remove: ");
	scanf("%[^\n]", remove);
	strupr(remove);		
	for(int i = 0; i<=k; i++){
		if(strcmp(remove, code[i])==0){
			for(int j=i; j<k; j++){
		
				strcpy(name[i], name[i+1]);
				strcpy(code[i], code[i+1]);
				salary[i] = salary[i+1];
				allowance[i] = allowance[i+1];
				k--;				
				}
			}
		}
			//	xuatMang(name, &k);
	return k;	
}

void swap( double*a, double *b)
{
	*a = *a -*b;
	*b = *a +*b;
	*a = *b - *a;
}

void swap2(char a[], char b[])
{
	char t[20];
	strcpy(t, a);
	strcpy(a, b);
	strcpy(b, t);	
}

void SortDes(char code[][8], char name[][20], double *salary, double *allowance, int *k)
{
	int i, j;
	char t[20];
	for (i = 0; i < *k - 1; i++) {
		for (j = i+1; j<*k; j++) {
			if((salary[i] + allowance[i] )< (salary[j]+allowance[j])){
				swap(salary+i, salary+j);
//				double temp = salary[i];
//				salary[i] = salary [j];
//				salary[j] = temp;
				swap(allowance+i, allowance+j);
//				 temp = allowance[i];
//				allowance[i] = allowance [j];
//				allowance[j] = temp;

				swap2(name[i], name[j]);
				swap2(code[i], code[j]);
				}
			}
		}
}


int main()
{
	int choose, flag =1, k=0;
	char code[100][8], name[100][20];
	double salary[100], allowance[100];
	
	while(flag != 0)
	{
		printMenu();
		printf("\nType the number you want to choose: ");
		scanf("%d", &choose);
		switch(choose)
		{
			case 1:{
				k = addEmp(code, name, salary, allowance, k);
				break;
			}
			case 2:{
				searchEmp(code,name, salary, allowance,k);
				break;
			}
			case 3:{
				k = Remove(code, name, salary, allowance, k);
				break;
			}
			case 4:{
				SortDes(code, name,salary,allowance, &k);
				printString(code, name, salary, allowance, &k);
				break;
			}
			default:{
				flag = 0;
				break;
			}
		}
		getch();
		system("cls");
	}
	return 0;
}
