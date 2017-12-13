#include<stdio.h>
#include<string.h>
#include<ctype.h>
int row(char mat[5][5],char ch)
{
	int i1,i2;
	for(i1=0;i1<5;i1++)
	{
		for(i2=0;i2<5;i2++)
		{
			if(mat[i1][i2]==ch)
				return i1;
		}
	}
}
int col(char mat[5][5],char ch)
{
	int i1,i2;
	for(i1=0;i1<5;i1++)
	{
		for(i2=0;i2<5;i2++)
		{
			if(mat[i1][i2]==ch)
				return i2;
		}
	}
}
int main()
{
	char mat[5][5];
	char ij;
	char key[100];
	printf("Enter Key Text(Uppercase Alphabets): ");
	fgets(key,100,stdin);
	int k=strlen(key),i,j;
	int arr[26];
	for(i=0;i<26;i++)
	{
		arr[i]=0;
	}	
	int a=0,b=0;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(a<k)
			{
				while(arr[key[a]-65]!=0)
				{
					a++;
				}
				if(a<k)
				{
					mat[i][j]=key[a];
					if(key[a]=='I')
					{
						arr['J'-65]++;
						ij='I';
					}
					else if(key[a]=='J')
					{
						arr['I'-65]++;
						ij='J';
					}
					arr[key[a]-65]++;
					a++;
				}
			}
			if(b>=0 && a>=k)
			{
				while(arr[b]!=0)
					b++;
				if(arr[b]==0 && arr[b+1]==0 && b==8)
				{
					mat[i][j]='I';
					ij='I';
					arr[b+1]=1;
				}
				else
					mat[i][j]=b+65;
				b++;
			}
		}
	}
	char PT[500];
	printf("Enter Plain Text(Alphabets):");
	fgets(PT,500,stdin);
	int p=strlen(PT);
	if(PT[p-1]=='\n')
		PT[p-1]=='\0';
	p--;
	int c=p;
	if(p%2==1)
	{
		c++;
	}
	char CT[c];
	CT[c]='\0';
	if(c==p+1)
		CT[c-1]='X';
	for(i=0;i<p;i++)
	{
		CT[i]=toupper(PT[i]);
	}

	for(i=0;i<c;i+=2)
	{
		if(CT[i]==CT[i+1])
			CT[i+1]='X';
	}
	//printf("%s\n",CT);
	int r1,r2,c1,c2;
	for(i=0;i<c;i+=2)
	{
		if(CT[i]=='J' || CT[i]=='I')
		{
			r1=row(mat,ij);
			c1=col(mat,ij);
		}
		else
		{
			r1=row(mat,CT[i]);
			c1=col(mat,CT[i]);
		}
		if(CT[i+1]=='J' || CT[i+1]=='I')
		{
			r2=row(mat,ij);
			c2=col(mat,ij);
		}
		else
		{
			r2=row(mat,CT[i+1]);
			c2=col(mat,CT[i+1]);
		}
		//printf("%d,%d %d,%d\n",r1,c1,r2,c2);
		if(r1==r2)
		{
			CT[i]=mat[r1][(c1+1)%5];
			CT[i+1]=mat[r2][(c2+1)%5];
		}
		if(c1==c2)
		{
			CT[i]=mat[(r1+1)%5][c1];
			CT[i+1]=mat[(r2+1)%5][c2];
		}
		if(r1!=r2 && c1!=c2)
		{
			CT[i]=mat[r1][c2];
			CT[i+1]=mat[r2][c1];
		}
	}
	printf("Cipher Text: %s\n",CT);
	return 0;
}
