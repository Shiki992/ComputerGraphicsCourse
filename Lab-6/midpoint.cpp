#include<bits/stdc++.h>
#include<GL/glut.h>  
using namespace std; 
int X0, Y0, X1 , Y1;
void midpoint() 
{  
	int dx = X1 - X0; 
	int dy = Y1 - Y0; 
	int d = dy - (dx/2); 
	int x = X0, y = Y0; 
    glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		
	glColor3f(1.0, 1.0, 1.0);
	gluOrtho2D(-780, 780, -420, 420);



    glBegin(GL_POINTS);
	while (x < X1) 
	{ 
		x++; 

		// E or East is chosen 
		if (d < 0) 
			d = d + dy; 

		// NE or North East is chosen 
		else
		{ 
			d += (dy - dx); 
			y++; 
		}  
		cout << x << "," << y << "\n"; 
        glVertex2f(x,y); 
	} 
    glEnd();
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
	glutInitWindowPosition(0, 0); 	
	

	glutCreateWindow("line"); 		
	glutDisplayFunc(midpoint); 
	
	glutMainLoop(); 
	return 0; 
} 

