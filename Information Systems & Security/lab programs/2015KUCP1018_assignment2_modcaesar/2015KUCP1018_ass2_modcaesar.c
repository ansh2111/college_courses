#include<stdio.h>
#include<string.h>
#include<ctype.h>

void enc(char *pt,char *ct,int k)
{
	int i,n=strlen(pt);
	for(i=0;i<n;i++)
	{
		if(isalpha(pt[i]))
		{
			if(islower(pt[i]))
			{
				ct[i]=((pt[i]-97+k)%26)+97;
			}
			else if(isupper(pt[i]))
			{
				ct[i]=((pt[i]-65+k)%26)+65;
			}
		}
		else
		{
			ct[i]=pt[i];
		}
	}
	ct[n]='\0';
}
void dec(char *ct,char *dt,char *pt)
{
	int i,j,n=strlen(ct);
	dt[n]='\0';
	for(j=0;j<26;j++)
	{
		for(i=0;i<n;i++)
		{
			if(isalpha(ct[i]))
			{
				if(islower(ct[i]))
				{
					dt[i]=((ct[i]-122-j)%26)+122;
				}
				else if(isupper(ct[i]))
				{
					dt[i]=((ct[i]-90-j)%26)+90;
				}
			}
			else
			{
				dt[i]=ct[i];
			}
		}
		dt[n]='\0';
		if(strcmp(pt,dt)==0)
		{
			printf("Found the Decipher Text: %s using Key: %d\n",dt,j);
		}	
	}
}
int main()
{
	char pt[32],ct[32],dt[32];
	int k;
	printf("Enter Plain Text: ");
	fgets(pt,32,stdin);
	int i,n=strlen(pt);
	if (pt[n-1] == '\n')
    	pt[n-1] = '\0';
    n--;
    
	printf("Enter Key: ");
	scanf("%d",&k);
	if(k<0)
		k+=26;
	//encryption
	enc(pt,ct,k);	
	printf("Cipher Text: %s\n",ct);
	//decryption: finding the key
	dec(ct,dt,pt);
	return 0;	
}