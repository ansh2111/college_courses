#include<stdio.h>
#include<string.h>
#include<math.h>
void char2bin(int a[],char ch)
{
	int no=(int)ch,mask=128,i;
	for(i=0;i<8;i++)
	{
		if(mask&no)
			a[i]=1;
		else
			a[i]=0;
		mask>>=1;
	}	
}
void dividept(int a[],int b[4][16])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<16;j++)
        {
            b[i][j]=a[16*i+j];
        }
    }
}
void kcopy(int a[],int b[])
{
    int i;
    for(i=0;i<128;i++)
        a[i]=b[i];
}
void pcopy(int a[4][16],int b[4][16])
{
    int i,j;
    for(i=0;i<4;i++)
        for(j=0;j<16;j++)
            a[i][j]=b[i][j];
}
int bin2int(int a[])
{
    int sum=0,i;
	for(i=0;i<16;i++)
	{
	    sum+=(int)pow(2,15-i)*a[i];
	}
	return sum;
}
void int2bin(int a[],int x)
{
	int mask=32768,i;
	for(i=0;i<16;i++)
	{
		if((mask&x)==0)
			a[i]=0;
		else
			a[i]=1;
		mask>>=1;
	}	
}
void mult(int a[],int b[],int c[])
{
    int m=(bin2int(a)*bin2int(b))%65537;
    int2bin(c,m);
}
void add(int a[],int b[],int c[])
{
    int s=(bin2int(a)+bin2int(b))%65536;
    int2bin(c,s);
}
void bitxor(int a[],int b[],int c[])
{
    int i;
    for(i=0;i<16;i++)
    {
        if(a[i]==b[i])
            c[i]=0;
        else
            c[i]=1;
    }
}
void roundstep(int p[4][16],int k[6][16],int r[4][16])
{
    int it[10][16];
    mult(p[0],k[0],it[0]);
    add(p[1],k[1],it[1]);
    add(p[2],k[2],it[2]);
    mult(p[3],k[3],it[3]);
    
    bitxor(it[0],it[2],it[4]);
    bitxor(it[1],it[3],it[5]);
   
    mult(it[4],k[4],it[6]);
    add(it[5],it[6],it[7]);
    mult(it[7],k[5],it[8]);
    add(it[6],it[8],it[9]);
   
    bitxor(it[0],it[8],r[0]);
    bitxor(it[2],it[8],r[1]);
    bitxor(it[1],it[9],r[2]);
    bitxor(it[3],it[9],r[3]);
}
void lcshift(int a[])
{
    int i,j,tmp;
    for(i=0;i<26;i++)
    {
        tmp=a[0];
        for(j=126;j>=0;j--)
        {
            a[j]=a[j+1];
        }
        a[127]=tmp;
    }
}
void combine(int a[],int b[4][16])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<16;j++)
        {
            a[i*16+j]=b[i][j];
        }
    }
}
int main()
{
    int i,n,j,m,ro=0,un,i1,i2;
    char s[9],k[17];
    int pt[64]={0,1,1,0,0,0,1,1,0,1,1,0,1,1,1,1,0,1,1,0,1,1,0,1,0,1,1,1,0,0,0,0,0,1,1,1,0,1,0,1,0,1,1,1,0,1,0,0,0,1,1,0,0,1,0,1,0,1,1,1,0,0,1,0};    
    int ct[64];
    int key[128]={0,1,1,0,1,0,0,0,0,1,1,0,0,1,0,1,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,1,1,0,0,1,0,0,0,0,0,0,1,1,1,0,1,1,1,0,1,1,0,1,1,1,1,0,1,1,1,0,0,1,0,0,1,1,0,1,1,0,0,0,1,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,0,0,1,0,1,1,0,1,1,1,0,0,1,1,1,0,1,0,1};
    int p[4][16],r[4][16],c[4][16],ke[6][16];
    //divide pt in 4 sets of p
    dividept(pt,p);
    int key1[128];
    //copy key
    kcopy(key1,key);
    //copy plain text
    pcopy(r,p);
    un=0;
    for(ro=0;ro<8;ro++)
    {
    	//store unsused bits
        for(i1=0;i1<un;i1++)
        {
            for(i2=0;i2<16;i2++)
            {
                ke[i1][i2]=key1[(8+i1-un)*16+i2];
            }
        }
        if(ro%4!=0)
            lcshift(key1);
        //store bits from new key     
        for(i1=0;i1<6-un;i1++)
        {
            for(i2=0;i2<16;i2++)
            {
                ke[i1+un][i2]=key1[(i1)*16+i2];
            }
        }
        //perform the procedure for each round
        roundstep(r,ke,r);
        //update unsused bits
        un+=2;
        un%=8;
    }
    //define key bits for output transform
    for(i1=0;i1<4;i1++)
    {
        for(i2=0;i2<16;i2++)
        {
            ke[i1][i2]=key[i1*16+i2];
        }
    }
    //apply the steps on r to generate c
    mult(r[0],ke[0],c[0]);
    add(r[1],ke[1],c[1]);
    add(r[2],ke[2],c[2]);
    mult(r[3],ke[3],c[3]);
    //generate resultant cipher text
    combine(ct,c);
    //print ct
    for(i=0;i<64;i++)
    {
        printf("%d ",ct[i]);
    }
    printf("\n");
    return 0;
}
