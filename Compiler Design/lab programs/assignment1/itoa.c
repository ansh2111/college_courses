/*2015KUCP1018
	ANANT SHARMA
	COMPILER DESIGN LAB
	
	Compilation: gcc itoa.c
	Execution: ./a.out 
	*/
	
#include<stdio.h>

int main()
{
	int i,n,d=0,n1;
	//Number to be converted to string
	n=12980;
	char st[100];
	n1=n;
	if(n==0)
	{
		st[0]='0';
		st[1]='\0';
		printf("%s\n",st);
		return 0;
	}
	while(n1!=0)
	{
		n1=n1/10;
		d++;
	}
	n1=n;
	for(i=0;i<d;i++)
	{
			st[d-1-i]=(n1%10)+48;
			n1/=10;
	}
	st[d]='\0';
	// itoa(n)
	printf("%s\n",st);
}
