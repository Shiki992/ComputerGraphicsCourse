#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 
using namespace std;
int xx1,yy1,a,b,theta;

void ellipse5 (void) 
{ 
	
	float i1,j1;
	

	
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		
	
	glColor3f(1.0, 1.0, 1.0);
	gluOrtho2D(-780, 780, -420, 420);
	
	int t1,t2;
	glBegin(GL_POINTS);
 for(int i=0;i<360;i=i+5)
		{
			xx1=a*cos((pi*i)/180);
			yy1=b*sin((pi*i)/180);
            i1=round(xx1);
            j1 = round (yy1);
			
			glVertex2f(i1,j1);
		}
      glEnd();
	
	glFlush(); 
} 



void ellipse4 (void) 
{ 
	
	float i1,j1;
	
	
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		
	
	glColor3f(1.0, 1.0, 1.0);
	gluOrtho2D(-780, 780, -420, 420);
	
	
	
	glBegin(GL_POINTS);
    for(int i=0;i<360;i=i+4)
		{
			xx1=a*cos((pi*i)/180);
			yy1=b*sin((pi*i)/180);
            i1=round(xx1);
            j1 = round (yy1);
			
			glVertex2f(i1,j1);
		}
     	
      glEnd();
      glFlush(); 
}

void ellipse3 (void) {
float i1,j1;
	

	
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		
	
	glColor3f(1.0, 1.0, 1.0);
	gluOrtho2D(-780, 780, -420, 420);
	
	int t1,t2;
	glBegin(GL_POINTS);
 for(int i=0;i<360;i=i+3)
		{
			xx1=a*cos((pi*i)/180);
			yy1=b*sin((pi*i)/180);
            i1=round(xx1);
            j1 = round (yy1);
			
			glVertex2f(i1,j1);
		}
      glEnd();
	
	glFlush(); 
}


void ellipse2 (void) {
float i1,j1;
	

	
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		
	
	glColor3f(1.0, 1.0, 1.0);
	gluOrtho2D(-780, 780, -420, 420);
	
	int t1,t2;
	glBegin(GL_POINTS);
 for(int i=0;i<360;i=i+2)
		{
			xx1=a*cos((pi*i)/180);
			yy1=b*sin((pi*i)/180);
            i1=round(xx1);
            j1 = round (yy1);
			
			glVertex2f(i1,j1);
		}
      glEnd();
	
	glFlush(); 
} 

void ellipse1 (void) 
{
float i1,j1;
	
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		
	
	glColor3f(1.0, 1.0, 1.0);
	gluOrtho2D(-780, 780, -420, 420);
	
	int t1,t2;
	glBegin(GL_POINTS);
 for(int i=0;i<360;i++)
		{
			xx1=a*cos((pi*i)/180);
			yy1=b*sin((pi*i)/180);
            i1=round(xx1);
            j1 = round (yy1);
			
			glVertex2f(i1,j1);
		}
      glEnd();
	
	glFlush(); 
} 


int main (int argc, char** argv) 
{ 
	glutInit(&argc, argv); 						  
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	
    a = atoi(argv[1]);
	b = atoi(argv[2]);
	
	float m,b,q,j;

	glutInitWindowSize(1366, 768);  
	glutInitWindowPosition(0, 0); 	
	

	glutCreateWindow("ellipse 5"); 			//step size = 5
	glutDisplayFunc(ellipse5); 
	
	glutCreateWindow("ellipse 4"); 			//step size = 4	
	glutDisplayFunc(ellipse4); 
	
	glutCreateWindow("ellipse 3"); 			//step size = 3
	glutDisplayFunc(ellipse3); 
	
	glutCreateWindow("ellipse 2"); 			//step size = 2
	glutDisplayFunc(ellipse2);
	
	glutCreateWindow("ellipse 1"); 			//step size = 1
	glutDisplayFunc(ellipse1);  
	
	
	glutMainLoop(); 
} 

