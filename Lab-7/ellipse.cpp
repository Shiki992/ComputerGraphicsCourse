#include<GL/glut.h>
#include <bits/stdc++.h> 
using namespace std;
int rx,ry, xc, yc;
void midptellipse() 
{ 
	float dx, dy, d1, d2, x, y; 
	x = 0; 
	y = ry; 
    glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		
	glColor3f(1.0, 1.0, 0.0);
	gluOrtho2D(-780, 780, -420, 420); 
    glBegin(GL_POINTS);

	// Initial decision parameter of region 1 
	d1 = (ry * ry) - (rx * rx * ry) + 
					(0.25 * rx * rx); 
	dx = 2 * ry * ry * x; 
	dy = 2 * rx * rx * y; 

	// For region 1 
	while (dx < dy) 
	{ 

		// Print points based on 4-way symmetry 
		 
        glVertex2f(x + xc,y + yc);
		 
		glVertex2f(-x + xc,y + yc);
         
		glVertex2f(x + xc,-y + yc);
         
        glVertex2f(-x + xc,-y + yc);
		// Checking and updating value of 
		// decision parameter based on algorithm 
		if (d1 < 0) 
		{ 
			x++; 
			dx = dx + (2 * ry * ry); 
			d1 = d1 + dx + (ry * ry); 
		} 
		else
		{ 
			x++; 
			y--; 
			dx = dx + (2 * ry * ry); 
			dy = dy - (2 * rx * rx); 
			d1 = d1 + dx - dy + (ry * ry); 
		} 
	} 

	// Decision parameter of region 2 
	d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) + 
		((rx * rx) * ((y - 1) * (y - 1))) - 
		(rx * rx * ry * ry); 

	// Plotting points of region 2 
	while (y >= 0) 
	{ 

		// Print points based on 4-way symmetry 
		 
        glVertex2f(x + xc,y + yc);
		
		glVertex2f(-x + xc,y + yc);
        
		glVertex2f(x + xc,-y + yc);
         
        glVertex2f(-x + xc,-y + yc);
		// Checking and updating parameter 
		// value based on algorithm 
		if (d2 > 0) 
		{ 
			y--; 
			dy = dy - (2 * rx * rx); 
			d2 = d2 + (rx * rx) - dy; 
		} 
		else
		{ 
			y--; 
			x++; 
			dx = dx + (2 * ry * ry); 
			dy = dy - (2 * rx * rx); 
			d2 = d2 + dx - dy + (rx * rx); 
		} 
	} 
    glEnd();
	glFlush();
} 

int main(int argc, char** argv) 
{ 
	glutInit(&argc, argv); 						  
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	
	xc=atoi(argv[1]);
	yc=atoi(argv[2]);
	rx=atoi(argv[3]);
    ry=atoi(argv[4]);

	glutInitWindowSize(1366, 768);  
	glutInitWindowPosition(0, 0); 	
	

	glutCreateWindow("Ellipse using Midpoints"); 		
	glutDisplayFunc(midptellipse); 
	
	glutMainLoop(); 
	return 0; 
} 

