#include<GL/glut.h>
#include<iostream>
using namespace std;

void House(void){
    glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2d(-0.45f,0.5f);
    glVertex2d(-0.095f,0.85f);
    glVertex2d(0.25f,0.5f);
    // glVertex2d(0.0f,0.0f);
    glEnd();
    
    glColor3f(0.0f,0.0f,1.0f);
    glBegin(GL_QUAD_STRIP);
    glVertex2d(-0.45f,0.5f);
    glVertex2d(-0.45f,-0.25f);
    glVertex2d(0.25f,0.5f);
    glVertex2d(0.25f,-0.25f);
    glEnd();

    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_QUAD_STRIP);
    glVertex2d(-0.17f,-0.25f);
    glVertex2d(-0.02f,-0.25f);
    glVertex2d(-0.17f,0.05f);
    glVertex2d(-0.02f,0.05f);
    glEnd();

    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_QUADS);
    glVertex2d(-0.4f,0.05f);
    glVertex2d(-0.25f,0.05f);
    glVertex2d(-0.25f,0.2f);
    glVertex2d(-0.4f,0.2f);
    glEnd();

        glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_QUADS);
    glVertex2d(0.05f,0.05f);
    glVertex2d(0.2f,0.05f);
    glVertex2d(0.2f,0.2f);
    glVertex2d(0.05f,0.2f);
    glEnd();
    glFlush();
}

int main(int argc, char** argv){
glutInit(&argc, argv);
glutInitDisplayMode( GLUT_SINGLE );
glutInitWindowSize(1000,1000);
glutInitWindowPosition(0,0);
glutCreateWindow("House");

glutDisplayFunc( House );
glutMainLoop();
return 0;

}