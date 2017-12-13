#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,k,n;
    char ct[1000];
    printf("Enter Cipher Text to Decrypt:");
    fgets(ct,1000,stdin);
    n=strlen(ct);
    if(ct[n-1]=='\n')
        ct[n-1]='\0';
    n--;    
    char dt[n];
    dt[n]='\0';
    for(i=0,j=0;i<(n+1)/2;i++,j+=2)
    {
        dt[j]=ct[i];
    }
    for(i=(n+1)/2,j=1;i<n;i++,j+=2)
    {
        dt[j]=ct[i];
    }
    printf("Decipher Text: %s\n",dt);
}