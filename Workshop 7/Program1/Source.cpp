#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <conio.h>
#include<string.h>
#include <ctype.h>

void printMenu()
{
	printf("=========LIST OF STUDENT========");
	printf("\nAdd a student !");
	printf("\nRemove a student !");
	printf("\nSearch a student !");
	printf("\nPrint the list of student in ascending order !");
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


int main()
{
	printMenu();
	char student_name[5][30];
	int choose, flag = 1, i;
	while (flag != 0) {
		printf("\nType your choice: ");
		scanf_s("%d", &choose);
		switch (choose) {
		case 1: {
			for (i = 0; i < 5; i++) {
				printf("\nEnter a string %d: ", i + 1);
				scanf_s("%[^\n]", student_name[i]);
				trim(student_name[i]);
				printf("%s", student_name);
			}
			break;
		}
		case 2: {
			printf("\nType the student name you want to remove: ");
			scanf_s("%d", &i);
			for (i; i < 5;i++) {
				strcpy(student_name[i - 1], student_name[i]);
			}
			break;
		}
		/*case 3: {
			char s[30];
			printf("\nType name of student: ");
			scanf("%d[^\n]", s);
			char *ptr = strstr(student_name, s);
			break;
		}*/
		}
	}

	_getch();
	return 0;
}