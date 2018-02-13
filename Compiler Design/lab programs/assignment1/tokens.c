/*2015KUCP1018
	ANANT SHARMA
	COMPILER DESIGN LAB
	
		Compilation: gcc tokens.c
	Execution: ./a.out ipcode.txt
	*/
	
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(int argc,char *argv[])
{
	if(argc<2)
		return 0;
	FILE *fp;
	fp=fopen(argv[1],"r");
	int n,i,ct=0,tk=0;
	char ch,st[100],ch1;
	int wd=0;
	while(!feof(fp))
	{
		fscanf(fp,"%c",&ch);
		if(isalnum(ch) || ch=='_')
		{
			//identifiers
			while(isalnum(ch) || ch=='_')
				fscanf(fp,"%c",&ch);
			tk++;	
		}
		if(isspace(ch))
		{
			//blanck spaces
			continue;
		}
		if(ispunct(ch))
		{
			fscanf(fp,"%c",&ch1);
			//consecutive operators: Increment Decrement
			if((ch=='+' && ch1=='+') || (ch=='-' && ch1=='-') || (ch=='|' && ch1=='|') || (ch=='&' && ch1=='&') || (ch=='<' && ch1=='<') || (ch=='>' && ch1=='>'))
			{
				tk++;
			}	
			//Assignment Operators	
			else if(ch1=='=' && ispunct(ch))
			{
				tk++;
			}
			else if(ch==34)
			{
				//content within double quotes
				while(ch1!=34)
					fscanf(fp,"%c",&ch1);
				tk++;
			}
			else if(ch=='/' && ch1=='*')
			{
				//multi line comments
				while(ch!='*' && ch1!='/')
				{
					fscanf(fp,"%c%c",&ch,&ch1);
				}
			}
			else if(ch=='/' && ch1=='/')
			{
				//single line comments
				while(ch!='\n')
				{
					fscanf(fp,"%c",&ch);
				}
			}
			else if(ispunct(ch))
			{
				//punctuation marks
				tk++;
				fseek(fp,-1,SEEK_CUR);
			}
		}
		printf("%c %d\n",ch,tk);
	}
	printf("Number of Tokens in the Program %s= %d\n",argv[1],tk);
	fclose(fp);	
	

}
