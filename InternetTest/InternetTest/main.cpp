//#include<dos.h>
#include<math.h>
#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<stdlib>
#include<process>
#include<graphics>

void movement(int&,int&,int);
void bubbles(int,int,int,int);
void clearbubbles(int,int,int);


void main()
{
    int gdriver = DETECT,gmode;
    initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
    int x[10],y[10],r=40,d[10],i,j,k,l,c[10],n=10,t=100;
    randomize();
    // Initial Position, Direction & Color of Bubbles
    for(i=0;i<n;i++)
    {
        x[i]=random(getmaxx()-80)+41;
        y[i]=random(getmaxy()-80)+41;
        d[i] = random(8);
        c[i] = random(15)+1;
    }
    
    // Everything else
    
    for(i=0;i<=t;i++) 	// Motiton of Bubbles
    {
        for(j=0;j<n;j++)        // Number of Bubbles
        {
            clearbubbles(x[j],y[j],r);
            // Checking Bubble Boundary Limits
            while(x[j] <= 1 || y[j] <= 1 || x[j] >= getmaxx()-1 || y[j] >= getmaxy()-1)
            {
                d[j] = random(8);
                movement(x[j],y[j],d[j]);
            }
            
            
            // Checking Collasion of Bubbles
            for(k=0;k<=n;k++)
            {
                clearbubbles(x[j],y[j],r);
                l = sqrt(((x[j]-x[k])*(x[j]-x[k]))+((y[j]-y[k])*(y[j]-y[k])));
                if(j != k)
                {
                    while(l <= 2*r)
                    {
                        d[j] = random(8);
                        movement(x[j],y[j],d[j]);
                        l = sqrt(((x[j]-x[k])*(x[j]-x[k]))+((y[j]-y[k])*(y[j]-y[k])));
                    }
                }
                movement(x[j],y[j],d[j]);
                bubbles(x[j],y[j],r,c[j]);
            }
        }
    }
    getch();
    closegraph();
    
    
}


void movement(int &x,int &y,int d)
{
    switch(d)
    {
        case 0: // Top Direction
            y = y - 1;
            break;
        case 1: // Top Right Direction
            x = x + 1;
            y = y - 1;
            break;
        case 2: // Right Direction
            x =x +1;
            break;
        case 3: // Bottom Right Direction
            x=x+1;
            y=y+1;
            break;
        case 4: // Bottom Direction
            y = y + 1;
            break;
        case 5: // Bottom Left Direction
            x = x-1;
            y=y+1;
            break;
        case 6: // Left Direction
            x=x-1;
            break;
        case 7: // Top Left Direction
            x=x-1;
            y=y-1;
            break;
    }
}

void bubbles(int x,int y,int r,int c)
{
    setcolor(c);
    circle(x,y,r);
}

void clearbubbles(int x,int y,int r)
{
    setcolor(BLACK);
    circle(x,y,r);
}

