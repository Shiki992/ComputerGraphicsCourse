#include<GL/glut.h>
#include <bits/stdc++.h> 
using namespace std; 
  int X,Y,R;
// Implementing Mid-Point Circle Drawing Algorithm 
void midPointCircleDraw() 
{ 
    int x = R, y = 0;
    glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		
	glColor3f(1.0, 0.0, 0.0);
	gluOrtho2D(-780, 780, -420, 420); 
    glBegin(GL_POINTS);
    glVertex2f(x + X,y + Y);
      
    // When radius is zero only a single 
    // point will be printed 
    if (R > 0) 
    { 

        glVertex2f(x + X,-y + Y);
        glVertex2f(y + X, x + Y);
        glVertex2f(-y + X,x + Y);
    } 
      
    // Initialising the value of P 
    int P = 1 - R; 
    while (x > y) 
    {  
        y++; 
          
        // Mid-point is inside or on the perimeter 
        if (P <= 0) 
            P = P + 2*y + 1; 
        // Mid-point is outside the perimeter 
        else
        { 
            x--; 
            P = P + 2*y - 2*x + 1; 
        } 
          
        // All the perimeter points have already been printed 
        if (x < y) 
            break; 
          
        // Printing the generated point and its reflection 
        // in the other octants after translation 
        glVertex2f(x + X,y + Y); 

        glVertex2f(-x + X,y + Y);

        glVertex2f(x + X,-y + Y); 
        glVertex2f(-x + X,-y + Y);  
        // If the generated point is on the line x = y then  
        // the perimeter points have already been printed 
        if (x != y) 
        { 
            glVertex2f(y + X,x + Y);
            glVertex2f( -y + X, x + Y);
            glVertex2f(y + X, -x + Y); 
            glVertex2f(-y + X, -x + Y);
        } 
    } 
        glEnd();
	glFlush();
} 
  
int main(int argc, char** argv) 
{ 
	glutInit(&argc, argv); 						  
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	
	X=atoi(argv[1]);
	Y=atoi(argv[2]);
	R=atoi(argv[3]);

	glutInitWindowSize(1366, 768);  
	glutInitWindowPosition(0, 0); 	
	

	glutCreateWindow("Circle using Midpoints"); 		
	glutDisplayFunc(midPointCircleDraw); 
	
	glutMainLoop(); 
	return 0; 
} 
