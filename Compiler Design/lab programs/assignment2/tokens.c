/*2015KUCP1018
	ANANT SHARMA
	COMPILER DESIGN LAB
	
		Compilation: gcc tokens.c
	Execution: ./a.out ipcode.txt
	*/
	
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
	if(argc<2)
		return 0;
	FILE *fp;
	fp=fopen(argv[1],"r");
	int n,i,ct=0,tk=0;
	char ch,st[100],ch1;
	int wd=0;
	char kw[][20]={"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","int",
"long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};
	while(!feof(fp))
	{
		fscanf(fp,"%c",&ch);
		if(isalnum(ch) || ch=='_')
		{
			//identifiers
			memset(st,'\0',sizeof(st));
			int i3=0,numb=0,numb1=0,i2=0,keyw=0;
			while(isalnum(ch) || ch=='_')
			{
				st[i3++]=ch;
				//printf("%c\n",ch);
				if(isdigit(ch) || ch=='.')
					numb++;
				if(isdigit(ch) && i3-1==0)
					numb1=-10000000;
				fscanf(fp,"%c",&ch);
			}	
			st[i3]='\0';
			for(i2=0;i2<32;i2++)
			{
				if(strcmp(st,kw[i2])==0)
				{
					printf("%d:	%s\tKeyword\n",tk,st);
					keyw=1;
					break;
				}
			}
			
			if(numb1<0 && numb!=i3)
				printf("%d:	%s\tInvalid Identifier\n",tk,st);
				
			else if(numb==i3)
				printf("%d:	%s\tNumeric Constant\n",tk,st);
				
			else if(keyw!=1)
				printf("%d:	%s\tValid Identifier\n",tk,st);
			//printf("%s",st);
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
			if((ch=='+' && ch1=='+') || (ch=='-' && ch1=='-'))
			{
				printf("%d:\t%c%c\tIncrement/Decrement Operator\n",tk,ch,ch1);
				tk++;
			}
			else if((ch=='|' && ch1=='|') || (ch=='&' && ch1=='&'))
			{
				printf("%d:\t%c%c\tLogical Operator\n",tk,ch,ch1);
				tk++;
			}
			else if((ch=='<' && ch1=='<') || (ch=='>' && ch1=='>'))
			{
				printf("%d:\t%c%c\tBitwise Operator\n",tk,ch,ch1);
				tk++;
			}
			else if(ch=='-' && ch1=='>')
			{
				printf("%d:\t%c%c\tMember selection via pointer Operator\n",tk,ch,ch1);
				tk++;
			}
			//Assignment Operators	
			else if(ch1=='=' && ispunct(ch))
			{
				if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='%' || ch=='&' || ch=='|' || ch=='^' || ch=='~')
					printf("%d:\t%c%c\tAssignment Operator\n",tk,ch,ch1);
				else if(ch=='=' || ch=='>' || ch=='<' || ch=='!')
					printf("%d:\t%c%c\tRelational Operator\n",tk,ch,ch1);	
				tk++;
			}
			else if(ch==34)
			{
				//content within double quotes
				memset(st,'\0',sizeof(st));
				int i3=0;
				st[i3++]=ch;
				while(ch1!=34)
				{
					st[i3++]=ch1;
					fscanf(fp,"%c",&ch1);
				}
				st[i3++]=34;
				st[i3]='\0';
				printf("%d:\t%s\tString Constant\n",tk,st);
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
				if(isalpha(ch1) && ch=='*' || ch=='&')
				{
					memset(st,'\0',sizeof(st));
					int i3=0;
					st[i3++]=ch;
					while(isalpha(ch1) || ch1=='_')
					{
						st[i3++]=ch1;
						//printf("point");
						fscanf(fp,"%c",&ch1);
					}
					st[i3]='\0';
					printf("%d:\t%s\tPointer/Address of Variable\n",tk,st);
				}
				else if(ch==',' || ch==';')
					printf("%d:\t%c\tSeparator\n",tk,ch);
					
				else if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='%')
					printf("%d:\t%c\tArithematic Operator\n",tk,ch);
					
				else if(ch=='>' || ch=='<')
					printf("%d:\t%c\tRelational Operator\n",tk,ch);
					
				else if(ch=='!')
					printf("%d:\t%c\tLogical Operator\n",tk,ch);
					
				else if(ch=='=')
					printf("%d:\t%c\tAssignment Operator\n",tk,ch);	
					
				else if(ch=='&' || ch=='|' || ch=='^' || ch=='~')
					printf("%d:\t%c\tBitwise Operator\n",tk,ch);	
				else
					printf("%d:\t%c\tDelimiter\n",tk,ch);
					
				tk++;
				fseek(fp,-1,SEEK_CUR);
			}
		}
		//printf("%c %d\n",ch,tk);
	}
	printf("Number of Tokens in the Program %s= %d\n",argv[1],tk);
	fclose(fp);	
	

}
