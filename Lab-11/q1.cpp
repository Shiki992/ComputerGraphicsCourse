#define GL_SILENCE_DEPRECATION
#include<bits/stdc++.h>
using namespace std;
#include<GL/glut.h>
int xp[100],yp[100],points,xymax = 150,xymin = 100;

void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480);
}
void chk(int xx, int yy){
    if (xx<=xymax && xx>=xymin)
    {
        if (yy<=xymax && yy>=xymin)
        {
            glBegin(GL_POINTS);  
           glColor3f(1.0,0.0,0.0);  
           glVertex2i(xx,yy);
           glVertex2i(xx+1,yy+1);
           glVertex2i(xx-1,yy-1);
           glVertex2i(xx-1,yy+1);
           glVertex2i(xx+1,yy-1);
           glVertex2i(xx,yy+1);
           glVertex2i(xx,yy-1);
           glVertex2i(xx+1,yy);
           glVertex2i(xx-1,yy);  
       glEnd();  
    //    glFlush();
        }
        
    }
    
}
void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f,0.0f,1.0f);
    glBegin(GL_POLYGON);
    glVertex2i(xymin, xymin);
	glVertex2i(xymax, xymin);
	glVertex2i(xymax, xymax);
	glVertex2i(xymin, xymax);
    glEnd();
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_POLYGON);
    glVertex2i(xymin+5, xymin+5);
	glVertex2i(xymax-5, xymin+5);
	glVertex2i(xymax-5, xymax-5);
	glVertex2i(xymin+5, xymax-5);
    glEnd();
    for (size_t i = 0; i < points; i++)
    {
        chk(xp[i],yp[i]);
    }
    
    glFlush();
}

int main(int argc, char** argv){
    xymax= atoi(argv[1]);
    xymin= atoi(argv[2]);
	
	cout<<"How many points do you want to test?\n";
    cin>>points;
    for (size_t i = 0; i < points; i++)
    {
        xp[i] = rand()%(xymax+5);
        yp[i] = rand()%(xymax+5);
        cout<<"x"<<i+1<<"= "<<xp[i]<<"\ty"<<i+1<<"= "<<yp[i]<<endl;
    }
    

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