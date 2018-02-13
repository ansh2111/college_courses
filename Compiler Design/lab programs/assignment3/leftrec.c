//wap to remove left recurrsion in a given grammar.
/*2015KUCP1018
	ANANT SHARMA
	COMPILER DESIGN LAB
	
		Compilation: gcc leftrec.c
	Execution: ./a.out 
	*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int i=0,f,i1,i2,k=0,g=0;
	FILE *fp=fopen("input.txt","r");
	char st[100],ch,s1[100],s2[100],s3[100];
	char *tk,*tk1,*tk2,*tk3;
	const char l1[3]="->",l2[2]="/";
	while(1)
	{
		fgets(st,sizeof(st),fp);
		if(feof(fp))
			break;	
		f=0;
		g=0;
		st[strlen(st)-1]='\0';
		memset(s1,'\0',strlen(s1));
		memset(s2,'\0',strlen(s2));
		tk=strtok(st,l1);
		tk1=strtok(NULL,l1);
		strcpy(s1,tk);
		
		tk3=strstr(tk1,tk);

		strcat(s1,"->");
		tk1=strtok(tk1,l2);
		sprintf(s3,"Z%d",k);
		
		while(tk1!=NULL)
		{
			
			tk2=strstr(tk1,tk);
			if(tk2==NULL || tk1[0]!=tk[0])
			{
				if(f!=0)
					strcat(s1,"/");
				else
					f++;
					
				strcat(s1,tk1);
				if(tk3!=NULL)
				{	
				strcat(s1,s3);
				}
			}
			else
			{
				i1=tk1-tk2+1;
				if(g==0)
				{
					strcat(s2,s3);
					strcat(s2,"->");	
				}	
				else
					strcat(s2,"/");
				strcat(s2,tk2+strlen(tk));
				strcat(s2,s3);
				//strcat(s2,"/");
				g++;
			}
			tk1=strtok(NULL,l2);
			
		}
		if(!(s1[strlen(s1)-1]=='>' && s1[strlen(s1)-2]=='-'))
			printf("%s\n",s1);
		if(g>0)	
		{
			strcat(s2,"/NULL");
			printf("%s\n",s2);
		}	
		k++;	
	}
	return 0;
}
