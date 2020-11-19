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



void Translate() {
	glTranslatef(d11, d12, 0);
    glColor3f(0.0, 0.5, 1.0);
    glBegin(GL_POLYGON);
	glVertex2i(100, 100);
	glVertex2i(300, 100);
	glVertex2i(300, 300);
	glVertex2i(100, 300);
	glEnd();	
    glColor3f(0.0, 0.0, 0.5);
     glBegin(GL_POLYGON);
	glVertex2i(125, 225);
	glVertex2i(175, 225);
	glVertex2i(175, 250);
	glVertex2i(125, 250);
	glEnd();
    glColor3f(0.0, 0.0, 0.5);
     glBegin(GL_POLYGON);
	glVertex2i(225, 225);
	glVertex2i(275, 225);
	glVertex2i(275, 250);
	glVertex2i(225, 250);
	glEnd();
        glColor3f(0.0, 0.0, 0.5);
     glBegin(GL_POLYGON);
	glVertex2i(150, 150);
	glVertex2i(250, 150);
	glVertex2i(250, 175);
	glVertex2i(150, 175);
	glEnd();
	glFlush();

}

void Rotate() {
	glTranslatef(150, 150, 0);
	glRotatef(d2, 0, 0, 1);
	glTranslatef(-100, -100, 0);
    // glColor3f(0.0, 0.0, 0.0);
	glColor3f(0.0, 0.5, 1.0);
    glBegin(GL_POLYGON);
	glVertex2i(100, 100);
	glVertex2i(300, 100);
	glVertex2i(300, 300);
	glVertex2i(100, 300);
	glEnd();	
    glColor3f(0.0, 0.0, 0.5);
     glBegin(GL_POLYGON);
	glVertex2i(125, 225);
	glVertex2i(175, 225);
	glVertex2i(175, 250);
	glVertex2i(125, 250);
	glEnd();
    glColor3f(0.0, 0.0, 0.5);
     glBegin(GL_POLYGON);
	glVertex2i(225, 225);
	glVertex2i(275, 225);
	glVertex2i(275, 250);
	glVertex2i(225, 250);
	glEnd();
        glColor3f(0.0, 0.0, 0.5);
     glBegin(GL_POLYGON);
	glVertex2i(150, 150);
	glVertex2i(250, 150);
	glVertex2i(250, 175);
	glVertex2i(150, 175);
	glEnd();	
	glFlush();

}

void Scale() {
	glTranslatef(100, 100, 0);
	glScalef(d3, d3, 1);
	glTranslatef(-100, -100, 0);
    glColor3f(0.0, 0.5, 1.0);
    glBegin(GL_POLYGON);
	glVertex2i(100, 100);
	glVertex2i(300, 100);
	glVertex2i(300, 300);
	glVertex2i(100, 300);
	glEnd();	
    glColor3f(0.0, 0.0, 0.5);
     glBegin(GL_POLYGON);
	glVertex2i(125, 225);
	glVertex2i(175, 225);
	glVertex2i(175, 250);
	glVertex2i(125, 250);
	glEnd();
    glColor3f(0.0, 0.0, 0.5);
     glBegin(GL_POLYGON);
	glVertex2i(225, 225);
	glVertex2i(275, 225);
	glVertex2i(275, 250);
	glVertex2i(225, 250);
	glEnd();
        glColor3f(0.0, 0.0, 0.5);
     glBegin(GL_POLYGON);
	glVertex2i(150, 150);
	glVertex2i(250, 150);
	glVertex2i(250, 175);
	glVertex2i(150, 175);
	glEnd();	
	glFlush();

}


void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	if (choice == 1)
		Translate();
	else if (choice == 2)
		Rotate();
	else
		Scale();
	glEnd();
	glFlush();
}

int main(int argc, char** argv){
	
	
	cout<<"Enter \n1:Translation\n2:Rotation\n3:Scaling\n";
	cin >> choice;
	if (choice == 1) 
		{
            cout<<"Enter translation parameter dx and dy respectively:\n";
            cin >> d11 >> d12;
        }
	else if (choice == 2)
    {
        cout<<"Enter Rotation Angle (Theta):\n";
        cin >> d2;

    }
		
	else 
		{
        cout<<"Enter Scaling factor:\n";
        cin >> d3;

    }
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Robot Face - SB original");
	init();
	glutDisplayFunc(display);
	
	glutMainLoop();
	return 0;
}