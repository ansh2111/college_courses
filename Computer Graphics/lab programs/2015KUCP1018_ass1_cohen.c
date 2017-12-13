#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<graphics.h>
void calccode(int c[],float x1,float y1,float xmin,float xmax,float ymin,float ymax)
{
	if(y1>ymax)
		c[0]=1;	
	else
		c[0]=0;
	if(y1<ymin)
		c[1]=1;	
	else
		c[1]=0;	
	if(x1>xmax)
		c[2]=1;	
	else
		c[2]=0;
	if(x1<xmin)
		c[3]=1;	
	else
		c[3]=0;			
}
int check(int c1[],int c2[])
{
	int c3[4];
	int i,z=0,z1=0;
	for(i=0;i<4;i++)
	{
		c3[i]=c1[i]&c2[i];
		if(c3[i]==0)
			z++;
		if(c1[i]==0 && c2[i]==0)
			z1++;
	}
	if(z1==4)
		return 0;
	else if(z==4)
		return 1;
	else 
		return 2;
}
void cp(int a[],int b[])
{
	int i;
	for(i=0;i<4;i++)
		a[i]=b[i];
}
void draw(float x1,float y1,float x2,float y2,float xw_min,float xw_max,float yw_min,float yw_max,int ch)
{
	
	int gd = DETECT,gm=VGAMAX;
	int offx,offy,s;
	float w,l;
	initgraph(&gd,&gm,NULL);
	offx=getmaxx()/2-50;
	offy=getmaxy()/2-50;
	s=20;
	char co[100],q;

	rectangle(xw_min*s+offx,yw_min*s+offy,xw_max*s+offx,yw_max*s+offy);

	snprintf(co,20,"(%.1f,%.1f)",xw_min,yw_max);
	outtextxy(xw_min*s+offx-10,yw_min*s+offy-10, co);
	snprintf(co,20,"(%.1f,%.1f)",xw_min,yw_min);
	outtextxy(xw_min*s+offx-10,yw_max*s+offy+10, co);
	snprintf(co,20,"(%.1f,%.1f)",xw_max,yw_max);
	outtextxy(xw_max*s+offx-10,yw_min*s+offy-10, co);
	snprintf(co,20,"(%.1f,%.1f)",xw_max,yw_min);
	outtextxy(xw_max*s+offx-10,yw_max*s+offy+10, co);

	l=xw_max-xw_min;
	w=yw_max-yw_min;
	if(ch==2)
		setcolor(BLUE);
	else
		setcolor(RED);
	line(x1*s+offx,(y1+l)*s+offy,x2*s+offx,(l-y2)*s+offy);

	snprintf(co,20,"(%.1f,%.1f)",x1,y1);
	outtextxy(x1*s+offx-20,(y1+l)*s+offy, co);
	snprintf(co,20,"(%.1f,%.1f)",x2,y2);
	outtextxy(x2*s+offx-10,(l-y2)*s+offy, co);
	
	delay(5000000);
	closegraph();
}
int main()
{
	int code1[4],code2[4],cd[4],i,flag=0;
	float xw_min,xw_max,yw_min,yw_max,x1,x2,y1,y2;
	
	

	printf("Enter the coordinates of window\n");
	printf("xmin, xmax, ymin, ymax:");
	scanf("%f %f %f %f",&xw_min,&xw_max,&yw_min,&yw_max);
	printf("Enter cordinates of the line\n");
	printf("x1, y1, x2, y2:");
	scanf("%f %f %f %f",&x1,&y1,&x2,&y2);
	printf("Press Ctrl+C to Continue or Quit\n");
	draw(x1,y1,x2,y2,xw_min,xw_max,yw_min,yw_max,1);
	calccode(code1,x1,y1,xw_min,xw_max,yw_min,yw_max);
	calccode(code2,x2,y2,xw_min,xw_max,yw_min,yw_max);
	/*for(i=0;i<4;i++)
		printf("%d ",code1[i]);
	for(i=0;i<4;i++)
		printf("%d ",code2[i]);*/
	float a,b,c,d,m;

	while(1)
	{
		if(check(code1,code2)==0)
		{
			printf("Line Accepted from (%.2f,%.2f) to (%.2f,%.2f).\n",x1,y1,x2,y2);	
			break;
		}
		else if(check(code1,code2)==2)
		{
			printf("Line Rejected\n");
			break;
		}
		else
		{
			m=(y2-y1)/(x2-x1);
			if(!(code1[0]==0 && code1[1]==0 && code1[2]==0 && code1[3]==0))
			{
				cp(cd,code1);
				flag=1;
			}
			else
			{
				cp(cd,code2);
				flag=2;
			}
			if(cd[0]==1)
			{
					b=yw_max;
			}
			else if(cd[1]==1)
			{
					b=yw_min;
			}
			if(cd[2]==1)
			{
					a=xw_max;
			}
			else if(cd[3]==1)
			{
					a=xw_min;
			}

			if(cd[0]!=1 && cd[1]!=1)
			{
					b=y1+m*(a-x1);
			}
			else if(cd[1]!=1 && cd[2]!=1)
			{
					a=x1+(b-y1)/m;
			}
			if(flag==1)
			{
					x1=a;
					y1=b;
					calccode(code1,x1,y1,xw_min,xw_max,yw_min,yw_max);
			}
			else
			{
					x2=a;
					y2=b;
					calccode(code2,x2,y2,xw_min,xw_max,yw_min,yw_max);
			}
		}
	}
	printf("Press Ctrl+C to Continue or Quit\n");
	draw(x1,y1,x2,y2,xw_min,xw_max,yw_min,yw_max,2);
	return 0;
}
