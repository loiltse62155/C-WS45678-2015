#include<stdio.h>
int main()
{
	char fName[] = "test_rewind.txt";
	char c;
	int i;
	FILE *f = fopen(fName, "r");
	for(i =0; i<'N'; i++)
	{
		putchar(fgetc(f));
		
	}
	rewind(f);
	printf("\nAfter rewind: \n");
	while((c=fgetc(f))!= EOF)
	{
		putchar(c);
	}
	fclose(f);
	getchar();
	return 0;
}
