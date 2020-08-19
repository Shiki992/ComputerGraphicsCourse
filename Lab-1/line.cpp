//2)	Given two points (x1, y1) and (x2, y2) of a line, and also a point p (x, y), check if p lies below or above  or on  the line
#include<iostream>
using namespace std;
struct point
{
    float x;
    float y;
};
class line
{
    private:
    struct point a , b;
    float m,c;
    public:
    int getval(int x1,int x2,int y1,int y2)
    {
        a.x=x1;
        b.x=x2;
        a.y=y1;
        b.y=y2;
        cout<<"The Co-ordinates for point A are: ("<<a.x<<" , "<<a.y<<")\n";
        cout<<"The Co-ordinates for point B are: ("<<b.x<<" , "<<b.y<<")\n";
        if (b.x == a.x)
        {
            m = __INT_MAX__;
            c = __INT_MAX__;
        }
        else 
        {
            m = (b.y - a.y)/(b.x - a.x);
            c = a.y -(m*a.x);
        }
        return m;
    }
    int point(struct point p){
        int Y;
        if (m == 0 || m == __INT_MAX__)
        {
            if (m == 0)
            {
                if(p.y == a.y ){
                    if((p.x >= a.x && p.x <= b.x) ||(p.x >= b.x && p.x <= a.x))
                    {
                        return 0;
                    }
                    else if ((p.x < a.x && p.x < b.x)|| (p.x > a.x && p.x > b.x))
                    {
                        return 3;
                    }
                    
                    
                }
                else if (p.y> a.y)
                {
                    return 2;
                }
                else
                {
                    return 1;
                }
                
                
            }
            else
            {
                if(p.x == a.x ){
                    if((p.y >= a.y && p.y <= b.y) ||(p.y >= b.y && p.y <= a.y))
                    {
                        return 0;
                    }
                    else if ((p.y < a.y && p.y < b.y)|| (p.y > a.y && p.y > b.y))
                    {
                        return 3;
                    }
                    
                    
                }
                else if (p.x> a.x)
                {
                    return 2;
                }
                else
                {
                    return 1;
                }
                
            }
            
        }
        else
        {
        Y=m*p.x + c;
        if (Y==p.y)
        {
            return 0;
        }
        else if(Y > p.y)
        {
            return 1;
        }
        else
        {
            return 2;
        }
        }  
    }
};





int main(){
    int x1, x2, y1, y2;
    float m;
    struct point p;
    cout<<"Please enter x1, x2, y1, y2 respectively to form the line"<<endl;
    cin>>x1>>x2>>y1>>y2;
    cout<<"Please enter x, y respectively to check whether the named point is above, below or on the line"<<endl;
    cin>>p.x>>p.y;
    line l1;
    m = l1.getval(x1, x2, y1, y2);
    cout<<"Slope of this line is: "<<m<<endl;
    int result = l1.point(p);
    switch (result)
    {
    case 0:
        cout<<"The point, p("<<p.x<<" , "<<p.y<<")is on the line"<<endl;
        break;
    case 2:
        cout<<"The point, p("<<p.x<<" , "<<p.y<<")is above the line"<<endl;
        break;
    case 1:
        cout<<"The point, p("<<p.x<<" , "<<p.y<<")is below the line"<<endl;
        break;
    case 3:
        cout<<"The point, p("<<p.x<<" , "<<p.y<<")is on the same plane as the line but it does not fall on the line"<<endl;
        break;
    default:
        break;
    }
    return 0;
}