#include<stdio.h>
#include<graphics.h>
double findpkplus1(double pk,double xk,double yk,double xk_1,double yk_1)
{
	return pk+(2*(xk+1))+((yk_1*yk_1)-(yk*yk))-(yk_1-yk)+1;

}
double findxkplus1(double xk)
{
	return xk+1;
}
double findykplus1(double yk,double pk)
{
	if(pk<0)
		return yk;
	else 
		return yk-1;
}
void draw(double a[],double b[],int n)
{
	int gd=DETECT,gm,i;
	initgraph(&gd,&gm,NULL);
	//loop through array of points to plot them
	for(i=0;i<n;i++)
	{
		putpixel(a[i]+300,b[i]+140,WHITE);
	}
	delay(50000);
	closegraph();
}
int main()
{
	//take input
	printf("Enter radius of circle:");
	double r,pk,xk[10000],yk[10000],pk_1;
	scanf("%lf",&r);
	//initialize p0 and (x0,y0)
	pk=1-r;
	//printf("%lf",r);
	xk[0]=0,yk[0]=r;
	int i=0,n;
	//calculate points (x,y) and pk+1	
	while(xk[i]<=yk[i])
	{
		//printf("(%.2lf,%.2lf)\n",xk[i],yk[i]);
		xk[i+1]=findxkplus1(xk[i]);
		yk[i+1]=findykplus1(yk[i],pk);
		pk=findpkplus1(pk,xk[i],yk[i],xk[i+1],yk[i+1]);				
		i++;
	}
	//printf("%d",i);
	n=i;
	//calculate for remaining arc in 1st quadrant
	for(i=0;i<n;i++)
	{
		xk[n+i]=yk[n-1-i];
		yk[n+i]=xk[n-1-i];
	}
	n=n+n;
	//calculate points in 2nd quadrant
	for(i=0;i<n;i++)
	{
		xk[n+i]=-xk[n-1-i];
		yk[n+i]=yk[n-1-i];
	}
	n=n+n;
	//calculate points in 3rd, 4th quadrant
	for(i=0;i<n;i++)
	{
		xk[n+i]=xk[n-1-i];
		yk[n+i]=-yk[n-1-i];
	}
	n=n+n;
	printf("(xk,yk)\n");
	for(i=0;i<n;i++)
	{
		printf("(%.2lf,%.2lf)\n",xk[i],yk[i]);
	}
	//plot the points
	draw(xk,yk,n);

}
