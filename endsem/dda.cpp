#include<stdio.h> 
#include<iostream>
#include<GL/glut.h> 
#include<math.h>
using namespace std;
int X0, Y0, X1 , Y1;
int abs (int n) 
{ 
	return ( (n>0) ? n : ( n * (-1))); 
} 

void DDA(int x1,int y11,int x2,int y2) 
{ 
	int dx = x2 - x1; 
	int dy = y2 - y11; 


	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); 

	float Xa = dx /(float)steps; 
	float Ya = dy /(float)steps; 

	float X = x1; 
	float Y = y11;
    glBegin(GL_POINTS); 
	for (int i = 0; i <= steps; i++) 
	{ 
		glVertex2f(X,Y); 		
        X += round(Xa); 
		Y += round(Ya);		 
         
	} 
    glEnd();
	
} 
 
 void dda(void){
         glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		
	
	glColor3f(1.0, 1.0, 1.0);
	gluOrtho2D(-780, 780, -420, 420);
    DDA(X0,Y0,X0,Y1);
    DDA(X0,Y1,X1,Y1);
    DDA(X1,Y1,X1,Y0);
    DDA(X1,Y0,X0,Y0);



 glFlush();
 }


int main(int argc, char** argv) 
{ 
	glutInit(&argc, argv); 						  
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	
	X0=atoi(argv[1]);
	Y0=atoi(argv[2]);
	X1=atoi(argv[3]);
	Y1=atoi(argv[4]);

	glutInitWindowSize(1366, 768);  
	glutInitWindowPosition(100, 100); 	
	

	glutCreateWindow("Rectangle"); 		
	glutDisplayFunc(dda); 
	
	glutMainLoop(); 
	return 0; 
} 
