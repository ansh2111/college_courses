#include<stdio.h>
#include<graphics.h>
double findpkplus1(double pk,double xk,double yk,double xk_1,double yk_1,double ry,double rx)
{
	return pk+(2*ry*ry*(xk+1))+ry*ry+rx*rx*(((yk_1-0.5)*(yk_1-0.5))-((yk-0.5)*(yk-0.5)));

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
double findpkplus12(double pk,double xk,double yk,double xk_1,double yk_1,double ry,double rx)
{
	return pk-(2*rx*rx*(yk-1))+rx*rx+ry*ry*(((xk_1+0.5)*(xk_1+0.5))-((xk+0.5)*(xk+0.5)));

}
double findxkplus12(double xk,double pk)
{
	if(pk>0)
		return xk;
	else 
		return xk+1;
}
double findykplus12(double yk)
{
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
	printf("Enter radii of ellipse:");
	double rx,ry,pk,xk[10000],yk[10000],pk_2;
	scanf("%lf %lf",&rx,&ry);

	//initialize p0 and (x0,y0)
	pk=(ry*ry)+(rx*rx)/4-(rx*rx*ry);
	//printf("%lf",r);
	xk[0]=0,yk[0]=ry;
	int i=0,n;

	//calculate points (x,y) and pk+1	
	while(2*ry*ry*xk[i]<=2*rx*rx*yk[i])
	{
		xk[i+1]=findxkplus1(xk[i]);
		yk[i+1]=findykplus1(yk[i],pk);
		pk=findpkplus1(pk,xk[i],yk[i],xk[i+1],yk[i+1],ry,rx);				
		i++;
		//printf("%lf\n",pk);
	}
	
	n=i+1;
	pk_2=(ry*ry*(xk[n-1]+0.5)*(xk[n-1]+0.5))+(rx*rx*(yk[n-1]-1)*(yk[n-1]-1))-(rx*rx*ry*ry);	
	i=n-1;	
	while(yk[i]!=0)
	{
		xk[i+1]=findxkplus12(xk[i],pk_2);
		yk[i+1]=findykplus12(yk[i]);
		pk_2=findpkplus12(pk_2,xk[i],yk[i],xk[i+1],yk[i+1],ry,rx);		
		i++;
	}
	n=i+1;
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
