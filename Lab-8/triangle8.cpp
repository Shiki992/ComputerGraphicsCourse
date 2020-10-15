 #include <GL/glut.h> 
 #include<math.h> 
  int ww = 600, wh = 500;  
  float fillCol[3] = {0.99,0.0,0.0};  
  float borderCol[3] = {0.0,0.0,0.0};  
  GLfloat x1=100.0,  Y1= 100.0 ,  x2= 400.0,  y2= 100.0 ,  x3= 325.0,  y3= 200.0;
  void setPixel(float pointx, float pointy, float f[3])  
  {  
       glBegin(GL_POINTS);  
           glColor3fv(f);  
           glVertex2f(pointx,pointy);  
       glEnd();  
       glFlush();  
  }  
  void getPixel(float x, float y, float pixels[3])  
  {  
       glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,pixels);  
  }  
  void line1 (float xx1, float yy1, float xx2, float yy2) 
{ 
	float m,b,q,j;
	float i1,j1;
	
	if(xx1!=xx2)
	{
		m = (yy2-yy1)/(xx2-xx1);
		b=yy2-(m*xx2);
	}
	
	
	
	// glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		
	
	glColor3f(0.0, 0.0, 0.0);
	// gluOrtho2D(-780, 780, -420, 420);
	
	
	int t1,t2;
	glBegin(GL_POINTS);
     	if((yy1==yy2) || (xx1==xx2))
     	{
     		if(yy1==yy2)
     		{	
	     		if(xx1>xx2)
			{
				t1=xx2;
				t2=xx1;
			}
			else
			{
				t1=xx1;
				t2=xx2;
			}
	     		for(int i=t1;i<t2;i=i+1)
	     		{
	     			j=yy1;
				i1=round(i);
				j1=round(j);
      
				glVertex2f(i1,j1);
	     		}
     		
     		}
     		else if(xx1==xx2)
     		{	
	     		if(yy1>yy2)
			{
				t1=yy2;
				t2=yy1;
			}
			else
			{
				t1=yy1;
				t2=yy2;
			}
	     		for(int i=t1;i<t2;i=i+1)
	     		{
	     			j=xx1;
				i1=round(j);
				j1=round(i);
      
				glVertex2f(i1,j1);
	     		}
     		
     		}
     		
     	}
     	else
     	{
		if(xx1>xx2)
			{
				t1=xx2;
				t2=xx1;
			}
		else
			{
				t1=xx1;
				t2=xx2;
			}
		for(int i=t1;i<t2;i=i+1)
		{
			j=(m*i)+b;
			i1=round(i);
			j1=round(j);
			
			glVertex2f(i1,j1);
		}
 	}
      glEnd();
    //   glFlush(); 
}
  void drawPolygon()  
  {       
       glColor3f(1.0,1.0,1.0);  
       glBegin(GL_POLYGON);
       glPolygonMode(GL_FRONT_AND_BACK,GL_POINTS);
    // glEnable(GL_POLYGON_STIPPLE);
    //    glColor3f(0.0,0.0,0.0);
glVertex2f(x1,Y1);
glVertex2f(x2, y2);
glVertex2f(x3, y3);
glVertex2f(x1, Y1);
glEnd();
       glBegin(GL_LINES);  
       glColor3f(0.0,0.0,0.0); 
            glVertex2f(x1+5, Y1+5);  
            glVertex2f(x2+5, y2+5);   
       glEnd(); 
       glBegin(GL_LINES);  
       glColor3f(0.0,0.0,0.0); 
            glVertex2f(x1+4, Y1+4);  
            glVertex2f(x2+4, y2+4);   
       glEnd();

       glBegin(GL_POINTS);
       glColor3f(0.0,0.0,0.0); 
       glVertex2f(x1+1, Y1);
       glVertex2f(x1-1, Y1);
       glVertex2f(x1, Y1+1);
       glVertex2f(x1, Y1-1);
       glVertex2f(x2+1, y2);
       glVertex2f(x2-1, y2);
       glVertex2f(x2, y2+1);
       glVertex2f(x2, y2-1);
       glEnd(); 
       glBegin(GL_LINES);  
       glColor3f(0.0,0.0,0.0); 
            glVertex2f(x3+5, y3+5);  
            glVertex2f(x2+5, y2+5);  
       glEnd();
              glBegin(GL_LINES);  
       glColor3f(0.0,0.0,0.0); 
            glVertex2f(x3+6, y3+6);  
            glVertex2f(x2+6, y2+6);  
       glEnd();
       

       glBegin(GL_POINTS);
       glColor3f(0.0,0.0,0.0); 
       glVertex2f(x3+1, y3);
       glVertex2f(x3-1, y3);
       glVertex2f(x3, y3+1);
       glVertex2f(x3, y3-1);
       glVertex2f(x2+1, y2);
       glVertex2f(x2-1, y2);
       glVertex2f(x2, y2+1);
       glVertex2f(x2, y2-1);
       glEnd();   
       glBegin(GL_LINES);
       glColor3f(0.0,0.0,0.0);   
            glVertex2f(x1+5, Y1+5);  
            glVertex2f(x3+5, y3+5);  
       glEnd();
              glBegin(GL_LINES);
       glColor3f(0.0,0.0,0.0);   
            glVertex2f(x1+4, Y1+4);  
            glVertex2f(x3+4, y3+4);  
       glEnd();
       glBegin(GL_POINTS);
       glColor3f(0.0,0.0,0.0); 
       glVertex2f(x1+1, Y1);
       glVertex2f(x1+1, Y1+1);
       glVertex2f(x1+1, Y1-1);
       glVertex2f(x1-1, Y1);
       glVertex2f(x1-1, Y1+1);
       glVertex2f(x1-1, Y1-1);
       glVertex2f(x1, Y1+1);
       glVertex2f(x1, Y1-1);
       glVertex2f(x3+1, y3);
       glVertex2f(x3-1, y3);
       glVertex2f(x3, y3+1);
       glVertex2f(x3, y3-1);
       glEnd();   
         
       glFlush();  
  }  
  void display()  
  {  
       glClearColor(1.0,1.0,1.0, 1.0);  
       glClear(GL_COLOR_BUFFER_BIT);  
       drawPolygon();  
       glFlush();  
  }  
  void boundaryFill4(float x,float y,float fillColor[3],float borderColor[3])  
  {  
       float interiorColor[3];  
       getPixel(x,y,interiorColor);  
       if((interiorColor[0]!=borderColor[0] && (interiorColor[1])!=borderColor[1] && (interiorColor[2])!=borderColor[2]) && (interiorColor[0]!=fillColor[0] && (interiorColor[1])!=fillColor[1] && (interiorColor[2])!=fillColor[2]) )  
       {  
            setPixel(x,y,fillColor);  
        boundaryFill4(x + 1, y, fillColor, borderColor);
        boundaryFill4(x, y + 1, fillColor, borderColor);
        boundaryFill4(x - 1, y, fillColor, borderColor);
        boundaryFill4(x, y - 1, fillColor, borderColor);
        boundaryFill4(x - 1, y - 1, fillColor, borderColor);
        boundaryFill4(x - 1, y + 1, fillColor, borderColor);
        boundaryFill4(x + 1, y - 1, fillColor, borderColor);
        boundaryFill4(x + 1, y + 1, fillColor, borderColor);
       }  
  }  
  void mouse(int btn, int state, int x, int y)  
  {  
       if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN)   
       {  
            int xi = x;  
            int yi = (wh-y);  
            boundaryFill4(xi,yi,fillCol,borderCol);  
       }  
  }  
  void myinit()  
  {        
       glViewport(0,0,ww,wh);  
       glMatrixMode(GL_PROJECTION);  
       glLoadIdentity();
        gluOrtho2D(0.0,(GLdouble)ww,0.0,(GLdouble)wh);  
       glMatrixMode(GL_MODELVIEW);  
  }  
  int main(int argc, char** argv)  
  {  
       glutInit(&argc,argv);  
       glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);  
       glutInitWindowSize(ww,wh);  
       glutCreateWindow("Boundary-Fill 8 neighbours");  
       glutDisplayFunc(display);  
       myinit();  
       glutMouseFunc(mouse);  
       glutMainLoop();  
       return 0;  
  }  
