#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
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
void computeip(int p[8][8],int pos[8][8],int l[4][8],int r[4][8])
{
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<8;j++)
		{
			l[i][j]=*(*p+pos[i][j]-1);
			//printf("%d ",l[i][j]);
		}
		//printf("\n");
	}
	for(i=4;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			r[i-4][j]=*(*p+pos[i][j]-1);
			//printf("%d ",r[i-4][j]);
		}
		//printf("\n");
	}
}
void generatekey(int k[8][8],int c[4][7],int pos1[4][7])
{
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<7;j++)
		{
			c[i][j]=*(*k+pos1[i][j]-1);
			//printf("%d ",c[i][j]);
		}
		//printf("\n");
	}
}
void leftcshift(int c[4][7],int k)
{
	int i,j,tmp;
	while(k--)
	{
		tmp=c[0][0];
		for(i=0;i<4;i++)
		{
			for(j=0;j<7;j++)
			{
				if(j==6)
				{
					if(i==3)
						c[i][j]=tmp;
					else	
						c[i][j]=c[(i+1)%4][0];
				}
				else
				{
					c[i][j]=c[i][j+1];
				}
				//printf("%d ",c[i][j]);
			}
			//printf("\n");
		}
	}
}
void generatekey2(int k1[8][6],int c[4][7],int d[4][7],int pos2[8][6])
{
	int i,j;
	for(i=0;i<8;i++)
	{
		for(j=0;j<6;j++)
		{
			if(pos2[i][j]<29)
				k1[i][j]=*(*c+pos2[i][j]-1);
			else
				k1[i][j]=*(*d+pos2[i][j]-1-28);				
			//printf("%d ",k1[i][j]);
		}
		//printf("\n");
		
	}
}
void ebitselection(int ip[4][8],int eip[8][6])
{
	int i,j;
	int st[8][6];
	for(i=0;i<8;i++)
	{
		for(j=2;j<6;j++)
		{
			st[i][j]=i*4+j;
			if(j==5 && i==7)
				st[i][j]%=32;
		}
	}
	for(i=0;i<8;i++)
	{
		for(j=0;j<2;j++)
		{
			st[i][j]=st[(i+7)%8][j+4];
		}
	}
	for(i=0;i<8;i++)
	{
		for(j=0;j<6;j++)
		{
			eip[i][j]=*(*ip + st[i][j]-1);
			//printf("%d ",eip[i][j]);
		}
		//printf("\n");
	}
}
void compxor(int a[8][6],int b[8][6])
{
	int i,j;
	for(i=0;i<8;i++)
	{
		for(j=0;j<6;j++)
		{
			a[i][j]=a[i][j]^b[i][j];
			//printf("%d ",a[i][j]);
		}
		//printf("\n");
	}
}
int srow(int x,int y)
{
	return (2*x+1*y);
}
int scol(int col[])
{
	int i,n=4,sum=0;
	for(i=0;i<n;i++)
	{
		sum+=col[i]*pow(2,n-i-1);
	}
	return sum;
}
void num2bin(int a[],int x)
{
	int mask=8,i;
	for(i=0;i<4;i++)
	{
		if(mask&x)
			a[i]=1;
		else
			a[i]=0;
		mask>>=1;
	}	
}
void sbox(int sip[8][6],int pip[8][4])
{
	int sb[8][4][16],i,j,l,val,r1,c1;
	FILE *fp=fopen("sbox.txt","r");
	for(i=0;i<8;i++)
	{
		for(j=0;j<4;j++)
		{
			for(l=0;l<16;l++)
			{
				fscanf(fp,"%d",&sb[i][j][l]);
			}
		}
		r1=srow(sip[i][0],sip[i][5]);
		c1=scol(&sip[i][1]);
		val=sb[i][r1][c1];
		num2bin(pip[i],val);
		//printf("%d ",val);
	}
	fclose(fp);
}
void pbox(int a[8][4],int b[8][4])
{
	int i,j;
	int pb[8][4]={	{16,7,20,21},{29,12,28,17},
					{1,15,23,26},{5,18,31,1},
					{2,8,24,14},{32,27,3,9},
					{19,13,30,6},{22,11,4,25}};
	for(i=0;i<8;i++)
	{
		for(j=0;j<4;j++)
		{
			b[i][j]=*(*a+pb[i][j]-1);
			//printf("%d ",b[i][j]);
		}
		//printf("\n");
	}
}
void rotate(int a[8][4],int b[4][8])
{
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<8;j++)
		{
			b[i][j]=a[7-j][i];
			//printf("%d ",b[i][j]);
		}
		//printf("\n");
	}
}
void compxor2(int a[4][8],int b[4][8])
{
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<8;j++)
		{
			a[i][j]=a[i][j]^b[i][j];
			//printf("%d ",a[i][j]);
		}
		//printf("\n");
	}
}
void swaplrip(int l[4][8],int r[4][8])
{
	int i,j,tmp;
	for(i=0;i<4;i++)
	{
		for(j=0;j<8;j++)
		{
			tmp=r[i][j];
			r[i][j]=l[i][j];
			l[i][j]=tmp;
		}
	}
}
void inverseip(int a[4][8],int b[4][8],int c[8][8])
{
	int ipi[8][8]={	{40,8,48,16,56,24,64,32},
					{39,7,47,15,55,23,63,31},
					{38,6,46,14,54,22,62,30},
					{37,5,45,13,53,21,61,29},
					{36,4,44,12,52,20,60,28},
					{35,3,43,11,51,19,59,27},
					{34,2,42,10,50,18,58,26},
					{33,1,41,9,49,17,57,25}};
	int i,j;
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			if(ipi[i][j]<33)
				c[i][j]=*(*a+ipi[i][j]-1);
			else
				c[i][j]=*(*b+ipi[i][j]-1-32);
			//printf("%d ",c[i][j]);	
		}
		//printf("\n");
	}
}
int bin2hex(int a[])
{
	int i,n=8,x=0;
	for(i=0;i<n;i++)
	{
		x+=a[i]*pow(2,n-1-i);
	}
	return x;
}
int main()
{
	int i,j,n,it;
	char s[100];
	printf("Enter Plain Text(8-bytes):");
	fgets(s,100,stdin);
	n=strlen(s);
	if(s[n-1]=='\n')
		s[n-1]=='\0';
	n--;	
	char c[8];
	int p[8][8],lip[4][8],rip[4][8];
	printf("Enter Key(8-bytes):");
	for(i=0;i<8;i++)
	{
		char2bin(p[i],s[i]);
	}
	/*int k[8][8]={	{0,0,1,1,0,1,0,0},
					{0,0,1,0,1,1,0,1},
					{1,0,1,1,0,1,0,1},
					{1,0,1,0,1,0,0,0},
					{0,0,0,1,1,1,0,1},
					{1,1,0,1,1,0,1,1},
					{1,0,0,1,0,0,0,0},
					{0,0,0,0,0,1,0,0}};*/
    char key[8];
    int k[8][8];
    fgets(key,8,stdin);
    for(i=0;i<8;i++)
	{
		char2bin(k[i],key[i]);
	}
	int pos[8][8]={	{58,50,42,34,26,18,10,2},
					{60,52,44,36,28,20,12,4},
					{62,54,46,38,30,22,14,6},
					{64,56,48,40,32,24,16,8},
					{57,49,41,33,25,17,9,1},
					{59,51,43,35,27,19,11,3},
					{61,53,45,37,29,21,13,5},
					{63,55,47,39,31,23,15,7}};
	
	computeip(p,pos,lip,rip);
	int pos1[4][7]={{57,49,41,33,25,17,9},
					{1,58,50,42,34,26,18},
					{10,2,59,51,43,35,27},
					{19,11,3,60,52,44,36}};
					
	int pos2[4][7]={{63,55,47,39,31,23,15},
					{7,62,54,46,38,30,22},
					{14,6,61,53,45,37,29},
					{21,13,5,28,20,12,4}};	
	
	int ck[4][7],dk[4][7];
	int round[16]={1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
	int pos3[8][6]={{14,17,11,24,1,5},
					{3,28,15,6,21,10},
					{23,19,12,4,26,8},
					{16,7,27,20,13,2},
					{41,52,31,37,47,55},
					{30,40,51,45,33,48},
					{44,49,39,56,34,53},
					{46,42,50,36,29,32}};	
	int k1[8][6];					
	int eip[8][6];
	int pip[8][4],pbip[8][4];	
	int roip[4][8];

		generatekey(k,ck,pos1);
		generatekey(k,dk,pos2);
		
	for(it=0;it<16;it++)
	{	
		leftcshift(ck,round[it]);
		leftcshift(dk,round[it]);
	
		generatekey2(k1,ck,dk,pos3);
		
		ebitselection(rip,eip);
		
		compxor(eip,k1);
	
		sbox(eip,pip);
		pbox(pip,pbip);
	
		rotate(pbip,roip);
		for(i=0;i<4;i++)
		{
			for(j=0;j<8;j++)
			{
				rip[i][j]=roip[i][j];
			}
		}
		compxor2(lip,roip);
		swaplrip(lip,rip);
	}
	int ct[8][8];
	inverseip(rip,lip,ct);
	char r[8];
	printf("ASCII Values of Cipher Text:\n");
	for(i=0;i<8;i++)
	{
		r[i]=bin2hex(ct[i]);
		printf("%d %c\n",bin2hex(ct[i]),r[i]);
	}
	r[i]='\0';
	printf("Cipher Text: %s\n",r);
}
