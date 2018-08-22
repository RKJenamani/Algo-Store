#include<stdio.h>
#include<stdlib.h>


void main(int agrc,char *agrv[])
{
	char input[100];
	FILE *fp,*fp1;
	fp=fopen(agrv[1],"r");
	fp1=fopen(agrv[2],"a");
	fseek(fp,1L,SEEK_CUR);
	fscanf(fp,"%[^\n]",input);
	while(!feof(fp))
	{
		fseek(fp,1L,SEEK_CUR);
		fprintf(fp1,"%s",input);
		fprintf(fp1,"%s","\nkukoo\n");
		printf("%s",input);
		fscanf(fp," %[^\n]",input);
	}	
	fclose(fp);
	fclose(fp1);
}