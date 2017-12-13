#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define k 3
void enc(char *pt,char *ct)
{
	int i,j,n=strlen(pt);
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
int main()
{
	char pt[32],ct[32];
	printf("Enter Plain Text to Encrypt: ");
	fgets(pt,32,stdin);
	int i,n=strlen(pt);
	if (pt[n-1] == '\n')
    	pt[n-1] = '\0';
    n--;	
	enc(pt,ct);
	printf("Cipher Text: %s\n",ct);
	return 0;	
}
