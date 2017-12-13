#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<graphics.h>
float max(float a,float b)
{
	return a>b?a:b;
}
float min(float a,float b)
{
	return a<b?a:b;
}
void draw(float x1,float y1,float x2,float y2,float xw_min,float xw_max,float yw_min,float yw_max,int ch)
{
	
	int gd = DETECT,gm=VGAMAX;
	int offx,offy,s;
	float w,l;
	initgraph(&gd,&gm,NULL);
	offx=150;
	offy=150;
	s=20;
	char co[100],q;
	rectangle(xw_min*s+offx,yw_min*s+offy,xw_max*s+offx,yw_max*s+offy);

	snprintf(co,20,"(%.1f,%.1f)",xw_min,yw_min);
	outtextxy(xw_min*s+offx-10,yw_min*s+offy-10, co);
	snprintf(co,20,"(%.1f,%.1f)",xw_min,yw_max);
	outtextxy(xw_min*s+offx-10,yw_max*s+offy+10, co);
	snprintf(co,20,"(%.1f,%.1f)",xw_max,yw_max);
	outtextxy(xw_max*s+offx-10,yw_max*s+offy+10, co);
	snprintf(co,20,"(%.1f,%.1f)",xw_max,yw_min);
	outtextxy(xw_max*s+offx-10,yw_min*s+offy-10, co);

	if(ch==2)
		setcolor(BLUE);
	else
		setcolor(RED);
	line(x1*s+offx,(y1)*s+offy,x2*s+offx,(y2)*s+offy);

	snprintf(co,20,"(%.1f,%.1f)",x1,y1);
	outtextxy(x1*s+offx,(y1)*s+offy-10, co);
	snprintf(co,20,"(%.1f,%.1f)",x2,y2);
	outtextxy(x2*s+offx,(y2)*s+offy-10, co);
	
	delay(5000000);
	closegraph();
}
int main()
{
	int i,k;
	float xw_min,xw_max,yw_min,yw_max,x1,x2,y1,y2;

	printf("Enter the coordinates of window\n");
	printf("xmin, xmax, ymin, ymax:");
	scanf("%f %f %f %f",&xw_min,&xw_max,&yw_min,&yw_max);
	printf("Enter cordinates of the line\n");
	printf("x1, y1, x2, y2:");
	scanf("%f %f %f %f",&x1,&y1,&x2,&y2);
	float dx=x2-x1;
	float dy=y2-y1;
	float p[4],q[4];
	p[0]=-dx;
	p[1]=dx;
	p[2]=-dy;
	p[3]=dy;
	q[0]=x1-xw_min;
	q[1]=xw_max-x1;
	q[2]=y1-yw_min;
	q[3]=yw_max-y1;
    float t1=0,t2=1,a,b,c,d;
    printf("Press Ctrl+C to Continue or Quit\n");
    draw(x1,y1,x2,y2,xw_min,xw_max,yw_min,yw_max,1);
    for(k=0;k<4;k++)
    {
        if(p[k]==0)
        {
        	printf("Line is Parallel to the Window.\n");
        	if(q[k]<0)
        	{
        		printf("Line is Outside the Window.\n");
        		exit(1);
        	}
        }
        else
        {
        	if(p[k]<0)
        	{
        		t1=max(t1,q[k]/p[k]);        	
        	}
        	if(p[k]>0)
        	{
        		t2=min(t2,q[k]/p[k]);
        	}
        }
     }   
        if(t1>t2)
        {
        	printf("Line is Completely Outside, Rejected.\n");
        	exit(1);
        }
        else
        {
        	a=x1+t1*dx;
        	b=x1+t2*dx;
        	c=y1+t1*dy;
        	d=y1+t2*dy;
        }
    printf("t1=%.2f t2=%.2f\n",t1,t2);
    printf("Line Accepted From (%.2f,%.2f) to (%.2f,%.2f).\n",a,c,b,d);
    printf("Press Ctrl+C to Continue or Quit\n");
    draw(a,c,b,d,xw_min,xw_max,yw_min,yw_max,2);
	return 0;
}
