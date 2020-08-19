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
        
        // cout<<"point to locate, P = ("<<p.x<<" , "<<p.y<<")"<<endl; 
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

class triangle{
    private:
    line ab,bc,ca;
    rect R;
    public:
    void gettriangle(int x1,int x2, int x3, int y1, int y2, int y3){
        ab.getval(x1,x2,y1,y2);
        bc.getval(x2,x3,y2,y3);
        ca.getval(x3,x1,y3,y1);
        R.getval(x3,x2,y3,y1);
        cout<<"The Co-ordinates for point A are: ("<<x1<<" , "<<y1<<")\n";
        cout<<"The Co-ordinates for point B are: ("<<x2<<" , "<<y2<<")\n";
        cout<<"The Co-ordinates for point C are: ("<<x3<<" , "<<y3<<")\n";
    }
    int chkpoint(struct point p){
        int res1,res2,res3,Rres;
        Rres=R.point(p);
        if (Rres == 1)
        {
            res1=ab.point(p);
            res2=bc.point(p);
            res3=ca.point(p);
            if(res1==0 || res2==0 || res3==0){
                return 0;
            }
            else
            {
                if (res1==1 && res3==1 && res2==2)
                {
                    return 1;
                }
                else
                {
                    return 3;
                }
                
            }
        }
        else
        {
            return 3;
        }
        
        
        
    }

};

int main(){
    int x1, x2, x3, y1, y2, y3;
    struct point p;
    cout<<"Please enter x1, x2, x3, y1, y2, y3 respectively to form the triangle"<<endl;
    cin>>x1>>x2>>x3>>y1>>y2>>y3;
    cout<<"Please enter x, y respectively to check whether the named point is in the triangle or not"<<endl;
    cin>>p.x>>p.y;
    triangle t;
    t.gettriangle(x1, x2, x3, y1, y2, y3);
    int result = t.chkpoint(p);
    switch (result)
    {
    case 0:
        cout<<"The point, p("<<p.x<<" , "<<p.y<<")is on an edge of the triangle"<<endl;
        break;
    case 1:
        cout<<"The point, p("<<p.x<<" , "<<p.y<<")is in the triangle"<<endl;
        break;
    case 3:
        cout<<"The point, p("<<p.x<<" , "<<p.y<<")is not in the triangle"<<endl;
        break;
    default:
        break;
    }
}