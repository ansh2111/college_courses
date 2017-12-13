#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define k 3
void dec(char *ct,char *dt)
{
	int i,j,n=strlen(ct);
	for(i=0;i<n;i++)
	{
		if(isalpha(ct[i]))
		{
			if(islower(ct[i]))
			{
				dt[i]=((ct[i]-122-k)%26)+122;
			}
			else if(isupper(ct[i]))
			{
				dt[i]=((ct[i]-90-k)%26)+90;
			}
		}
		else
		{
			dt[i]=ct[i];
		}
	}
	dt[n]='\0';
}
int main()
{
	char ct[32],dt[32];
	printf("Enter Cipher Text to Decrypt: ");
	fgets(ct,32,stdin);
	int i,n=strlen(ct);
	if (ct[n-1] == '\n')
    	ct[n-1] = '\0';
    n--;
    dec(ct,dt);
	printf("Decipher Text: %s\n",dt);
	return 0;	
}
