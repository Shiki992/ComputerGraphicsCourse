#include<iostream>
#include<math.h>
#include<GL/glut.h>
using namespace std;

void car(void){

       glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_QUAD_STRIP);
    glVertex2d(-0.55f,-0.5f);
    glVertex2d(-0.55f,-0.25f);
    glVertex2d(0.25f,-0.5f);
    glVertex2d(0.25f,-0.25f);
    glEnd();

    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_QUAD_STRIP);
    glVertex2d(-0.15f,0.005f); //point A
    glVertex2d(-0.3f,-0.25f); //point B
    glVertex2d(0.18f,0.005f); //point D
    glVertex2d(0.25f,-0.25f); //point C
    glEnd();

        glColor3f(0.0f,1.0f,1.0f);
    glBegin(GL_QUAD_STRIP);
    glVertex2d(-0.13f,-0.01f); //point A
    glVertex2d(-0.28f,-0.25f); //point B
    glVertex2d(0.01f,-0.01f); //point D
    glVertex2d(0.01f,-0.25f); //point C
    glEnd();

        glColor3f(0.0f,1.0f,1.0f);
    glBegin(GL_QUAD_STRIP);
    glVertex2d(0.02f,-0.01f); //point A
    glVertex2d(0.02f,-0.25f); //point B
    glVertex2d(0.16f,-0.01f); //point D
    glVertex2d(0.230f,-0.25f); //point C
    glEnd();

   glColor3f(0.3f,0.3f,0.3f);

glBegin(GL_TRIANGLE_FAN);
glVertex2f(-0.4f,-0.5f);

for (float angle=1.0f;angle<361;angle+=0.2)
{
    float x2 = -0.4f+sin(angle)*0.1;
    float y2 = -0.5f+cos(angle)*0.1;
    glVertex2f(x2,y2);
}

glEnd();

  glColor3f(0.3f,0.3f,0.3f);

glBegin(GL_TRIANGLE_FAN);
glVertex2f(0.1f,-0.5f);

for (float angle=1.0f;angle<361;angle+=0.2)
{
    float x2 = 0.1f+sin(angle)*0.1;
    float y2 = -0.5f+cos(angle)*0.1;
    glVertex2f(x2,y2);
}

glEnd();
    glFlush();
}

int main(int argc, char** argv){
glutInit(&argc, argv);
glutInitDisplayMode( GLUT_SINGLE );
glutInitWindowSize(1000,1000);
glutInitWindowPosition(0,0);
glutCreateWindow("car");
glutDisplayFunc(car);
glutMainLoop();
return 0;

}