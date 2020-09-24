 #include <GL/glut.h>  
  int ww = 600, wh = 500;  
  float fillCol[3] = {0.99,0.0,0.0};  
  float borderCol[3] = {0.0,0.0,0.0};  
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
  void drawPolygon(float x1, float y1, float x2, float y2, float x3, float y3)  
  {       
    //    glColor3f(0.0,0.0,0.0);  
       glBegin(GL_POLYGON);
       glPolygonMode(GL_FRONT,GL_FILL);
       glPolygonMode(GL_BACK,GL_LINE);
    glEnable(GL_POLYGON_STIPPLE);
       glColor3f(1.0,1.0,1.0);
glVertex2f(x1,y1);
glVertex2f(x2, y2);
glVertex2f(x3, y3);
glVertex2f(x1, y1);
glEnd();
       glBegin(GL_LINES);  
       glColor3f(0.0,0.0,0.0); 
            glVertex2f(x1, y1);  
            glVertex2f(x2, y2);   
       glEnd(); 
       glBegin(GL_POINTS);
       glColor3f(0.0,0.0,0.0); 
       glVertex2f(x1+1, y1);
       glVertex2f(x1-1, y1);
       glVertex2f(x1, y1+1);
       glVertex2f(x1, y1-1);
       glVertex2f(x2+1, y2);
       glVertex2f(x2-1, y2);
       glVertex2f(x2, y2+1);
       glVertex2f(x2, y2-1);
       glEnd(); 
       glBegin(GL_LINES);  
       glColor3f(0.0,0.0,0.0); 
            glVertex2f(x3, y3);  
            glVertex2f(x2, y2);  
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
            glVertex2f(x1, y1);  
            glVertex2f(x3, y3);  
       glEnd();
       glBegin(GL_POINTS);
       glColor3f(0.0,0.0,0.0); 
       glVertex2f(x1+1, y1);
       glVertex2f(x1-1, y1);
       glVertex2f(x1, y1+1);
       glVertex2f(x1, y1-1);
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
       drawPolygon(100, 100 ,400, 100 , 325, 200);  
       glFlush();  
  }  
  void boundaryFill4(float x,float y,float fillColor[3],float borderColor[3])  
  {  
       float interiorColor[3];  
       getPixel(x,y,interiorColor);  
       if((interiorColor[0]!=borderColor[0] && (interiorColor[1])!=borderColor[1] && (interiorColor[2])!=borderColor[2]) && (interiorColor[0]!=fillColor[0] && (interiorColor[1])!=fillColor[1] && (interiorColor[2])!=fillColor[2]))  
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
