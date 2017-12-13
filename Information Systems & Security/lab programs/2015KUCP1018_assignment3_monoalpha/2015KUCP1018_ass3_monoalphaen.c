#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	char pt[32],ct[32],dt[32];
	//key for caps only
	char str1[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char str2[]="QWERTYUIOPASDFGHJKLZXCVBNM";
	printf("Enter Plain Text to Encrypt: ");
	fgets(pt,32,stdin);
	int i,n=strlen(pt),k;
	if (pt[n-1] == '\n')
    	pt[n-1] = '\0';
    n--;	
	ct[n]='\0';
	//encrypt
	for(i=0;i<n;i++)
	{
		if(isalpha(pt[i]))
		{
			k=strchr(str1,toupper(pt[i]))-str1;
			ct[i]=str2[k];
		}
		else
		{
			ct[i]=pt[i];
		}
	}
	printf("Cipher Text: %s\n",ct);
	
	return 0;	
}
