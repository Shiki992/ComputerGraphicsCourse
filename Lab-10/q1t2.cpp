#define GL_SILENCE_DEPRECATION
#include<bits/stdc++.h>
using namespace std;
#include<GL/glut.h>

int d11, d12;
int d2;
int d3;
int choice;
void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480);
}


int roundPt(float x) {
	return floor(x + 0.5);
}


void DrawPoint(int x, int y) {

	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();

}



void driver1() {
	glTranslatef(d11, d12, 0);
	glBegin(GL_POLYGON);
	glVertex2i(100, 100);
	glVertex2i(150, 100);
	glVertex2i(150, 150);
	glVertex2i(100, 150);
	glVertex2i(50, 175);
	glEnd();	
	glFlush();

}

void driver2() {
	glTranslatef(100, 100, 0);
	glRotatef(d2, 0, 0, 1);
	glTranslatef(-100, -100, 0);
	glBegin(GL_POLYGON);
	glVertex2i(100, 100);
	glVertex2i(150, 100);
	glVertex2i(150, 150);
	glVertex2i(100, 150);
	glVertex2i(50, 175);
	glEnd();	
	glFlush();

}

void driver3() {
	glTranslatef(100, 100, 0);
	glScalef(d3, 1, 1);
	glTranslatef(-100, -100, 0);
	glBegin(GL_POLYGON);
	glVertex2i(100, 100);
	glVertex2i(150, 100);
	glVertex2i(150, 150);
	glVertex2i(100, 150);
	glVertex2i(50, 175);
	glEnd();	
	glFlush();

}


void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	if (choice == 1)
		driver1();
	else if (choice == 2)
		driver2();
	else
		driver3();
	glEnd();
	glFlush();
}

int main(int argc, char** argv){
	
	
	
	cin >> choice;
	if (choice == 1) 
		cin >> d11 >> d12;
	else if (choice == 2)
		cin >> d2;
	else 
		cin >> d3;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Polygon");
	init();
	glutDisplayFunc(display);
	
	glutMainLoop();
	return 0;
}