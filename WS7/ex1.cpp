
#include<stdio.h>
#include <conio.h>
#include<string.h>
#include <ctype.h>

void printMenu()
{
	printf("=========LIST OF STUDENT========");
	printf("\n1. Add a student !");
	printf("\n2.Remove a student !");
	printf("\n3.Search a student !");
	printf("\n4.Print the list of student in ascending order !");
	printf("\n5. Quit !");
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

//int nhapMang(char s[][30], int n)
//{
//	int i;
//	fflush(stdin);
//	for(i = 0; i<n; i++){
//		
//		printf("\nEnter the names of student %d/%d", i+1, n);
//		
//		scanf("%[^\n]", (s[i]));
//		trim(s[i]);
//		strupr(s[i]);
//		break;
//	}
//	return i;	
//}

void xuatMang(char s[][30], int *k)
{
	int i;
	for(i = 0; i<*k;i++){
		puts(s[i]);
	}
}


void sapXep(char names[][30], int *k)
{
	int i, j;
	char t[31];
	for (i = 0; i < *k - 1; i++) {
		for (j = *k- 1; j>i; j--) {
			if (strcmp(names[j], names[j - 1]) < 0) {
				strcpy(t, names[j]);
				strcpy(names[j], names[j - 1]);
				strcpy(names[j - 1], t);
			}
		}
	}
}

void sapXep1(char names[][30], int *k)
{
	int i, j;
	char t[31];
	for (i = 0; i < *k - 1; i++) {
		for (j = *k- 1; j>i; j--) {
			if (strcmp(names[j], names[j - 1]) > 0) {
				strcpy(t, names[j]);
				strcpy(names[j], names[j - 1]);
				strcpy(names[j - 1], t);
			}
		}
	}
}

int Remove(char name[][30], int k)
{
				char remove[30];
				fflush(stdin);
				printf("\nType name of student you want to remove: ");
				scanf("%[^\n]", remove);
				strupr(remove);
				
				for(int i = 0; i<=k; i++){
					if(strcmp(remove, name[i])==0){
						strcpy(name[i], name[i+1]);
						k--;
					
					}
			}
			//	xuatMang(name, &k);
		return k;	
}

int nhap(char name[][30], int k)
{
	fflush(stdin);
				printf("Nhap ten sv: ");
				scanf("%[^\n]", (name[k]));
				trim(name[k]);
				strupr(name[k]);
				k++;
				return k;
}

int main()
{
	printMenu();
	char name[100][30];
	int n=100;
	int choose, flag = 1, i, k= 0;
	while (flag != 0) {
		printf("\nType your choice: ");
		scanf("%d", &choose);
		switch (choose) {
			case 1: {
				k = nhap(name, k);
//				fflush(stdin);
//				printf("Nhap ten sv: ");
//				scanf("%[^\n]", (name[k]));
//				trim(name[k]);
//				strupr(name[k]);
//				k++;
				break;
			}
			
			case 2:{
			k=	Remove(name, k);
//				char remove[30];
//				fflush(stdin);
//				printf("\nType name of student you want to remove: ");
//				scanf("%[^\n]", remove);
//				strupr(remove);
//				
//				for(int i = 0; i<=k; i++){
//					if(strcmp(remove, name[i])==0){
//						strcpy(name[i], name[i+1]);
//						k--;
//					}
//				}
			

				break;
			}
			
			case 3:{
				char search[30];
				fflush(stdin);
				printf("\nType name of student you want to find: ");
				scanf("%[^\n]", search);
				strupr(search);
				char*ptr;
				
				for(i = 0; i<=k; i++){
				
					 ptr = strstr(name[i], search);
					if(ptr != NULL){
						printf("\nFound: ");
						puts(name[i]);
						printf("at line %d", i+1);
						break;
					}
					

				}
				if(ptr ==NULL)
						printf("\nNot found !");
				break;
			}
			
			
			
			case 4:{
				sapXep1(name, &k);
				xuatMang(name,&k);
				break;
			}
			case 5:{
				flag = 0;
				break;
			}
		}
	}

	getch();
	return 0;
}

