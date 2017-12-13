#include<stdio.h>
#include<graphics.h>
void floodfillalgo4(int x,int y,int fc,int bc)
{
	int now=getpixel(x,y);
	if(now!=fc && now!=bc)
	{
		putpixel(x,y,fc);
		floodfillalgo4(x+1,y,fc,bc);
		floodfillalgo4(x-1,y,fc,bc);
		floodfillalgo4(x,y+1,fc,bc);
		floodfillalgo4(x,y-1,fc,bc);		
	}
}
void floodfillalgo8(int x,int y,int fc,int bc)
{
	int now=getpixel(x,y);
	if(now!=fc && now!=bc)
	{
		putpixel(x,y,fc);
		floodfillalgo8(x+1,y,fc,bc);
		floodfillalgo8(x-1,y,fc,bc);
		floodfillalgo8(x,y+1,fc,bc);
		floodfillalgo8(x,y-1,fc,bc);	
		floodfillalgo8(x+1,y-1,fc,bc);
		floodfillalgo8(x+1,y+1,fc,bc);
		floodfillalgo8(x-1,y+1,fc,bc);
		floodfillalgo8(x-1,y-1,fc,bc);	
	}
}
int main(){
	int gd=DETECT,gm=VGA,n,i;
	
	printf("Enter no. of sides of polygon:");
	scanf("%d",&n);
	int x[n],y[n],xc,yc,r;
	printf("Enter coordinates in clockwise direction\n");
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&x[i],&y[i]);
	}
	printf("Enter center coordinates and radius of circle\n");
	scanf("%d %d %d",&xc,&yc,&r);
	initgraph(&gd,&gm,NULL);
	
	for(i=0;i<n;i++)
	{
		line(x[i],y[i],x[(i+1)%n],y[(i+1)%n]);
	}
	floodfillalgo8(50,75,BLUE,WHITE);
	circle(xc,yc,r);
	floodfillalgo4(xc,yc,RED,WHITE);
	delay(500000);
	closegraph();
}
