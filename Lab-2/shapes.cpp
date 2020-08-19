#include<iostream>
#include<graphics.h>
using namespace std;
// int main(){
//     int gd = DETECT, gm; 
//     initgraph(&gd, &gm, NULL); 
//     // line for x1, y1, x2, y2 
//     line(150, 150, 450, 150);
//     line(150, 200, 450, 200);
//     line(150, 250, 450, 250);;
//     // getch();
//     closegraph();
//     return 0;

  
// }
int drawpoint(int x,int y){
    line(x,y,x,y);
    return 1;
    
}
int drawline(float slope, float length){
    float x = length+100;
    float y = slope*length+100;
    line(100,100,x,y);
    return 1;
}
int drawcircle(float radius){
    circle(100, 100, radius);
    return 1;
}
int drawellipse(int a , int b){
    ellipse(200, 200, 0, 360, a, b);
    return 1;
}
int drawtriangle(int arr[]){
    drawpoly(4, arr); 
    return 1;
}
int drawrectangle(int length, int breadth){
    rectangle(100,100,length+100,breadth+100);
    return 1;
}
int main()
{
   int gd = DETECT,gm,x= 300,y=150,radius=50;
   
   int br=0,choice,arr[8];
   while (br==0)
   {
       cout<<"Please enter a shape of your choice according to the serial number:\n 1. Point\n 2. Line\n 3. Circle\n 4. Ellipse\n 5. Triangle\n 6. Rectangle\n 7. Exit\n";
       cin>>choice;
       switch (choice)
       {
       case 1:
           cout<<"Please enter x and y co-ordinates respectively \n";
           cin>>x>>y;
           initgraph(&gd,&gm,NULL);
           drawpoint(x,y);
           delay(5000);
           closegraph();
           break;
        case 2:
           cout<<"Please enter slope and length of the line respectively \n";
           cin>>x>>y;
           initgraph(&gd,&gm,NULL);
           drawline(x,y);
           delay(5000);
           closegraph();
           break;
       case 3:
           cout<<"Please enter radius of the circle\n";
           cin>>radius;
           initgraph(&gd,&gm,NULL);
           drawcircle(radius);
           delay(5000);
           closegraph();
           break;
       case 4:
           cout<<"Please enter major and minor radii of the ellipse respectively \n";
           cin>>x>>y;
           initgraph(&gd,&gm,NULL);
           drawellipse(x,y);
           delay(5000);
           closegraph();
           break;
        case 5:
           cout<<"Please enter 3 x and y coordinates of the triangle:\n";
           for (int i = 0; i <= 5; i++)
           {
            cin>>arr[i];
           }
           arr[6]=arr[0];
           arr[7]=arr[1];
           initgraph(&gd,&gm,NULL);
           drawpoly(4, arr);
           delay(5000);
           closegraph();
           break;
       case 6:
           cout<<"Please enter length and breadth of the rectangle respectively \n";
           cin>>x>>y;
           initgraph(&gd,&gm,NULL);
           drawrectangle(x,y);
           delay(5000);
           closegraph();
           break;

       default:
           cout<<"Please choose a correct choice.. press 1 if you want to quit, 0 to try again\n";
           cin>>br;
           break;
       }
   }
   
//    rectangle(left, top, right, bottom);
//    circle(x, y, radius);
//    bar(left + 300, top, right + 300, bottom);
//    line(100, 100, 300, 300);
//    ellipse(x, y + 200, 0, 360, 100, 50);
//    outtextxy(left + 100, top + 325,"NULL");


   return 0;
}