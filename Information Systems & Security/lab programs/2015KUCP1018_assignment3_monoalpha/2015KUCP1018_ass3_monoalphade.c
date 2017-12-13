#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	char ct[32],dt[32];
	//key for caps only
	char str1[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char str2[]="QWERTYUIOPASDFGHJKLZXCVBNM";
	printf("Enter Cipher Text to Decrypt: ");
	fgets(ct,32,stdin);
	int i,n=strlen(ct),k;
	if (ct[n-1] == '\n')
    	ct[n-1] = '\0';
    n--;	
	dt[n]='\0';
	//decrypt
	for(i=0;i<n;i++)
	{
		if(isalpha(ct[i]))
		{
			k=strchr(str2,toupper(ct[i]))-str2;
			dt[i]=str1[k];
		}
		else
		{
			dt[i]=ct[i];
		}
	}
	printf("Decipher Text: %s\n",dt);
	
	return 0;	
}
