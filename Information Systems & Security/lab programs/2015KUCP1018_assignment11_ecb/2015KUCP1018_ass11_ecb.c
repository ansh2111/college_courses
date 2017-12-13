#include<stdio.h>
#include<string.h>

int main()
{
	char pt[128];
	printf("Enter Plain Text: ");
	scanf("%[^\n]s",pt);
	int n=strlen(pt),i;	
	
	//add padding 0 if pt less than 64 bit block
	if(n%8!=0)
	{
		for(i=0;i<8-(n%8);i++)
			pt[n+i]=0;
	}
	
	char key[100];
	printf("Enter Key: ");
	scanf(" %[^\n]s",key);
	int l=strlen(key);
	
	//add padding 0 if key less than 64 bits
	if(l%8!=0 && l<8)
	{
		for(i=0;i<8-(l%8);i++)
			pt[l+i]=0;
	}
	
	//Calculate XOR for CT
	char ct[n];
	printf("Cipher Text:\nASCII :\tCHAR\n");
	for(i=0;i<n;i++)
	{
		ct[i]=pt[i]^key[i%8];
		printf("%d :\t%c\n",ct[i],ct[i]);
	}
	ct[n]='\0';
	
	//Calculate XOR for DT
	char dt[n];
	for(i=0;i<n;i++)
	{
		dt[i]=ct[i]^key[i%8];
	}
	dt[n]='\0';
	printf("Decipher Text: %s\n",dt);
}
