#include<graphics.h>
#include<iostream>
// #include<dos.h>
using namespace std;
int main(){
    int gd = DETECT,gm;
    // int arr[8]={250,100,300,187,200,187,250,100};
    initgraph(&gd,&gm,NULL);
    // // line(100,0,0,300);
    setcolor(YELLOW);
    // setfillstyle(SOLID_FILL,YELLOW);
    circle(250,158, 50);
    floodfill(250,158,WHITE);
    setcolor(BLACK);
    // setfillstyle(SOLID_FILL,YELLOW);
    circle(225,148, 10);
    floodfill(225,148,BLACK);
        setcolor(BLACK);
    // setfillstyle(SOLID_FILL,YELLOW);
    circle(275,148, 10);
    floodfill(275,148,BLACK);
    setcolor(BLACK);
    rectangle(215,170,285,180);
    floodfill(216,171,BLACK);

    // setcolor(BLUE);
    // drawpoly(4, arr);
    // setcolor(GREEN);
    // circle(250, 158, 27);
    //     //    drawpoint(x,y);
           delay(5000);
           closegraph();
    return 0;
}