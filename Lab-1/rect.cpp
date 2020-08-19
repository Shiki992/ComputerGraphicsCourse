//1)	Given four corners of a rectangle, and also a point p, check if p lies inside the rectangle
#include<iostream>
using namespace std;

struct point
{
    float x;
    float y;
};
class rect
{
private:
    struct point a,b,c,d;
public:
    // struct point a,b,c,d;
    int getval(int x1,int x2,int y1,int y2){
    a.x=x1;
    b.x=x2;
    c.x=x2;
    d.x=x1;
    a.y=y1;
    b.y=y1;
    c.y=y2;
    d.y=y2;
    cout<<"The Co-ordinates for point A are: ("<<a.x<<" , "<<a.y<<")\n";
    cout<<"The Co-ordinates for point B are: ("<<b.x<<" , "<<b.y<<")\n";
    cout<<"The Co-ordinates for point C are: ("<<c.x<<" , "<<c.y<<")\n";
    cout<<"The Co-ordinates for point D are: ("<<d.x<<" , "<<d.y<<")\n";
    return 0;
}
    int point(struct point p){
        int grx = c.x - a.x;
        int gry = c.y - a.y;
        int ch;
        if (grx > 0 && gry > 0)
        {
           ch = 0;
        }
        else if(grx > 0 && gry < 0)
        {
            ch = 1;
        }
        else if (grx < 0 && gry < 0)
        {
            ch = 2;
        }
        else if (grx < 0 && gry > 0)
        {
            ch = 3;
        }
        
        cout<<"point to locate, P = ("<<p.x<<" , "<<p.y<<")"<<endl; 
        switch (ch)
        {
        case 0:
            if (p.x>=a.x && p.x<=c.x)
            {
                if (p.y>=a.y && p.y<=c.y)
                {
                    // cout<<"reached 0+";
                    return 1;
                }
                else
                {
                    return 0;
                }
                
            }
            break;
        case 1:
            if (p.x>=a.x && p.x<=c.x)
            {
                if (p.y>=c.y && p.y<=a.y)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
                
            }
            break;
        case 2:
            if (p.x>=c.x && p.x<=a.x)
            {
                if (p.y>=c.y && p.y<=a.y)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
                
            }
            break;
        case 3:
            if (p.x>=c.x && p.x<=a.x)
            {
                if (p.y>=a.y && p.y<=c.y)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
                
            }
            break;
        
        default:
            cout<<"Co-ordinates are invalid... Please try again with separate set of co-ordinates\n";
            return 2;
            break;
        }
    }

};

int main(){
    int x1, x2, y1, y2;
    struct point p;
    cout<<"Please enter x1, x2, y1, y2 respectively to form the rectangle"<<endl;
    cin>>x1>>x2>>y1>>y2;
    cout<<"Please enter x, y respectively to check whether the named point is in the rectangle or not"<<endl;
    cin>>p.x>>p.y;
    rect r1;
    r1.getval(x1, x2, y1, y2);
    int result = r1.point(p);
    cout<<result<<endl;
    if(result == 1){cout<<"The point lies in the rectangle specified\n";}
    else
    {
        cout<<"The point lies outside the rectangle specified\n";
    }
    return 0;
}