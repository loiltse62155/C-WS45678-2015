#include<stdio.h>
#include<conio.h>
#include<string.h>
void fileToArray(char *filename, char name[4][30], char address[4][100], int*mark)
{
	int i;
	char c[30], add[100];
	FILE*f=fopen(filename, "r");
	for (int j = 0; j<4; j++){
		for(int i = 0; i<30; i++)
		{
			fscanf(f, "%c", &name[j][i]);
			if (name[j][i] == ';'){
				break;
			}
				
		}
		for(int i = 0; i<35; i++)
		{
			fscanf(f, "%c", &address[j][i]);
			if (address[j][i] == ';'){
				break;
			}
				
		}
		fscanf(f, "%d", &mark[j]);
	
	}
	fclose(f);
}


void print(char name[][30], char address[][100], int*mark){
	for(int j = 0; j <4; j++)
		{	printf("\n%s", name[j]);
			printf("\n%s", address[j]);
			printf("\n%d", mark[j]);
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
	char t[30];
	strcpy(t, a);
	strcpy(a, b);
	strcpy(b, t);	
}

void swap3(char a[], char b[])
{
	char t[100];
	strcpy(t, a);
	strcpy(a, b);
	strcpy(b, t);	
}
void sortDescending(char name[][30], char address[][100], int*mark)
{
	int i;
	for(i = 0; i<3; i++){
		for(int j = i+1; j<4; j++){
			if(mark[i] < mark[j]){
				swap(mark+i, mark+j);
				swap2(name[i], name[j]);
				swap3(address[i], address[j]);
			}	
		}
	}
}

void printToFile(char *filename, char name[4][30], char address[4][100], int*mark)
{
	int i;

	FILE*f=fopen(filename, "w");
	
	for(int i = 0; i<4; i++)
	{
		fprintf(f, "%s", name[i]);
		fprintf(f, "%s", address[i]);
		fprintf(f, "%d\n", mark[i]);	
	}
	
	fclose(f);

}

int main()
{
	char filename[] = "students.txt";
	char filename2[] = "students_2.txt";
	char name[4][30];
	char address[4][100];
	int mark[4];
	fileToArray(filename, name, address, mark);
	sortDescending(name, address, mark);
	
	print(name, address, mark);
	printToFile(filename2, name, address, mark);
	getch();
	return 0;	
}
