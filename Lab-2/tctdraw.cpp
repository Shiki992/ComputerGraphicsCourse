#include<graphics.h>
#include<iostream>
using namespace std;
int main(){
    int gd = DETECT,gm;
    int arr[8]={250,100,300,187,200,187,250,100};
    initgraph(&gd,&gm,NULL);
    // line(100,0,0,300);
    setcolor(GREEN);
    circle(250,158, 57);
    setcolor(BLUE);
    drawpoly(4, arr);
    setcolor(GREEN);
    circle(250, 158, 27);
        //    drawpoint(x,y);
           delay(5000);
           closegraph();
    return 0;
}