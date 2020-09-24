#include <math.h>
#include <GL/glut.h>
 int ww = 600, wh = 500;
struct Point {
	GLint x;
	GLint y;
};

struct Color {
	GLfloat r;
	GLfloat g;
	GLfloat b;
};

void init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(1.0);
    glViewport(0,0,ww,wh);  
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity();
    gluOrtho2D(0.0,(GLdouble)ww,0.0,(GLdouble)wh);  
    glMatrixMode(GL_MODELVIEW);
}

Color getPixelColor(GLint x, GLint y) {
	Color color;
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &color);
	return color;
}

void setPixelColor(GLint x, GLint y, Color color) {
	glColor3f(color.r, color.g, color.b);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
    
}

void floodFill(GLint x, GLint y, Color oldColor, Color newColor) {
	Color color;
	color = getPixelColor(x, y);

	if(color.r == oldColor.r && color.g == oldColor.g && color.b == oldColor.b)
	{
		setPixelColor(x, y, newColor);
		floodFill(x+1, y, oldColor, newColor);
        floodFill(x+1, y+1, oldColor, newColor);
		floodFill(x, y+1, oldColor, newColor);
        floodFill(x+1, y-1, oldColor, newColor);
		floodFill(x-1, y, oldColor, newColor);
        floodFill(x-1, y+1, oldColor, newColor);
		floodFill(x, y-1, oldColor, newColor);
        floodFill(x-1, y-1, oldColor, newColor);
	}
	return;
}

void mouse(int btn, int state, int x, int y)  
  { 
      	Color newColor = {0.0f, 1.0f, 0.0f};
	Color oldColor = {1.0f, 0.0f, 0.0f}; 
       if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN)   
       {  
            int xi = x;  
            int yi = (wh-y);  
            floodFill(xi,yi,oldColor,newColor);  
       }
  } 

void drawPolygon( int xx1, int yy1, int xx2, int yy2 ) {
      
      
       glColor3f(1.0,0.0,0.0);
    //    glClearColor(1.0,0.0,0.0,1.0);  
       glBegin(GL_POLYGON);
glVertex2i(xx1,yy1);
glVertex2i(xx1, yy2);
glVertex2i(xx2, yy2);
glVertex2i(xx2, yy1);
glVertex2i(xx1,yy1);
glEnd();

       glBegin(GL_LINES); 
             glColor3f(0.0,0.0,0.0); 
            glVertex2i(xx1, yy1);  
            glVertex2i(xx1, yy2);   
       glEnd();  
       glBegin(GL_LINES);  
            glColor3f(0.0,0.0,0.0);
            glVertex2i(xx2, yy1);  
            glVertex2i(xx2, yy2);  
       glEnd();  
       glBegin(GL_LINES);  
            glColor3f(0.0,0.0,0.0);
            glVertex2i(xx1, yy1);  
            glVertex2i(xx2, yy1);  
       glEnd();  
       glBegin(GL_LINES);
       glColor3f(0.0,0.0,0.0);  
            glVertex2i(xx1, yy2);  
            glVertex2i(xx2, yy2);  
       glEnd();   
       glFlush();  
  
}

void display(void) {

	glClear(GL_COLOR_BUFFER_BIT);
	drawPolygon(10,10,150,150);
}

int main(int argc, char** argv)
{
           glutInit(&argc,argv);  
       glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);  
       glutInitWindowSize(ww,wh);  
       glutCreateWindow("Boundary-Fill 8 neighbors");  
       glutDisplayFunc(display);  
       init();  
       glutMouseFunc(mouse);  
       glutMainLoop();  
       return 0; 
}