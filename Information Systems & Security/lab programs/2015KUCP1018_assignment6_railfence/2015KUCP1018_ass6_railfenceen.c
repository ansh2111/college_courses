#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,k,n;
    char pt[1000];
    printf("Enter Plain Text to Encrypt:");
    fgets(pt,1000,stdin);
    n=strlen(pt);
    if(pt[n-1]=='\n')
        pt[n-1]='\0';
    n--;    
    char ct[n];
    ct[n]='\0';
    for(i=0,j=0;i<(n+1)/2;i++,j+=2)
    {
            ct[i]=pt[j];
    }
    for(i=(n+1)/2,j=1;i<n;i++,j+=2)
    {
            ct[i]=pt[j];
    }
    printf("Cipher Text: %s\n",ct);
}