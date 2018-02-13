/*2015KUCP1018
	ANANT SHARMA
	COMPILER DESIGN LAB
	
	Compilation: gcc keywords.c
	Execution: ./a.out ipkw.txt
	*/
	
	
#include<stdio.h>
#include<string.h>

int main(int argc,char *argv[])
{
	if(argc<2)
		return 0;
	
	FILE *fp;
	fp=fopen(argv[1],"r");
	
	int n,i,l=0,k=32,j=0,i1,i2;
	
	//get number of strings
	fscanf(fp,"%d",&n);
	
	char str[100];
	//store all inbuilt keywords
	char kw[][20]={"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","int",
"long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};

	int k1[k];
	k1[0]=0;
	for(i=1;i<k;i++)
	{
		//an array which indicates if the next keyword has same 1st letter as current keyword
		if(kw[i][0]==kw[i-1][0])
		{
			k1[i]=1;
		}
		else
		{
			k1[i]=0;
		}
		//printf("%d ",k1[i]);
	}
	
	for(i=0;i<n;i++)
	{
		//scan the string from file
		fscanf(fp,"%s",str);
		
		l=strlen(str);
		j=0;
		
		for(i1=0;i1<k;i1++)
		{
			//check 1st letter
			if(str[j]==kw[i1][j])
			{
				//check remaining letters
				for(i2=j+1;i2<strlen(str);i2++)
				{
					if(str[i2]==kw[i1][i2])
					{
						if(i2==strlen(str)-1 && i2==strlen(kw[i1])-1)
						{
							printf("Valid Keyword %s\n",kw[i1]);
							goto l1;
						}
					}
					else if(k1[i1+1]==1)
					{
						//consider next keyword if 1st letter matches
						i1++;
					}
					else
					{
						printf("Invalid Keyword %s\n",str);
						goto l1;
					}
				}
				
			}
		}
		printf("Invalid Keyword %s\n",str);
		l1:1+1;
		//printf("%s ",str);
	}
	
	fclose(fp);	


}
