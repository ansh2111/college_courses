#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
long int gcd(long int a,long int b)
{
    if(a==b)
        return a;
    else if(a>b)
        return gcd(a-b,b);
    else
        return gcd(a,b-a);
}
int main()
{
    long int p,q,n,m,i,j,c=0;
    char pt[1001];
    
    printf("Enter Plain Text: ");
    fgets(pt,1000,stdin);
    
    int p1=strlen(pt);
    if(pt[p1-1]=='\n')
    {    pt[p1-1]='\0';
        p1--;   }
    
    int ct[p1];
    char dt[p1];
    
    printf("Enter 2 Prime numbers p and q: ");
    scanf("%ld %ld",&p,&q);
    
    n=p*q;
    m=(p-1)*(q-1);
    long int e[m],d[m];
    
    for(i=2;i<m;i++)
    {
        if(gcd(i,m)==1)
        {
            e[c]=i;
            for(j=2;j<m;j++)
            {
                if((j*e[c])%m==1 && j!=i)
                {
                    d[c]=j;
                    //printf("%ld,%ld\n",e[c],d[c]);
                    break;
                }
            }
            c++;
        }
    }
    
    long int r=rand()%c;
    long int E=e[r],D=d[r];
    //printf("E:%ld D:%ld\n",E,D);
    long long int x=1,y;
    
    printf("Encrypted Message: ");
    for(i=0;i<p1;i++)
    {
        y=E;
        x=1;
        while(y!=0)
        {
            if(y>=2)
            {
                x=(x*(long long int)pow((int)pt[i],2)%n)%n;
                y=y-2;
            }
            else
            {
                x=(x*(long long int)pow((int)pt[i],y)%n)%n;
                y=y-y;
            }
        }
        ct[i]=x;
        printf("%d ",ct[i]);
    }
    printf("\n");
    
    printf("Decrypted Message: ");
    for(i=0;i<p1;i++)
    {
        y=D;
        x=1;
        while(y!=0)
        {
            if(y>=2)
            {
                x=(x*(long long int)pow(ct[i],2)%n)%n;
                y=y-2;
            }
            else
            {
                x=(x*(long long int)pow(ct[i],y)%n)%n;
                y=y-y;
            }
        }
        dt[i]=x;
        printf("%c",dt[i]);
    }
    printf("\n");
    
}
